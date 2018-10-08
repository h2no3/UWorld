#include <iostream>
#include <fstream>
#include <cstring>

enum
{
    map_normal,
    map_trap,
    map_transport
};

struct Item
{
    int x, y;
    int type;
    double damge;
    int aim_x, aim_y;
    //[2] : [0]: group-id, [1]: character-id
    char aim_character[16][2];
};

int main()
{
    Item map[16][16];

    for (int i = 1; i < 16; i++)
    {
        for (int j = 1; j < 16; j++)
        {
            Item item;
            item.x = j;
            item.y = i;
            item.type = map_normal;
            map[i][j] = item;
        }
    }

    map[1][1].type = map_trap;

    std::ofstream file("map");
    file << map;
    file.close();

    std::ifstream file2("map");
    std::string data;
    file2 >> data;

    std::memcpy(map, data.c_str(), data.size());
    for (int i = 1; i < 16; i++)
    {
        for (int j = 1; j < 16; j++)
        {
            Item item = map[i][j];
            std::cout << item.y << "-" << item.x << ":" << item.type << std::endl;
        }
    }
    return 0;
}
