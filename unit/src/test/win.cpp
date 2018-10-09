#include <SFML/Graphics.hpp>


void DrawTest(sf::RenderWindow& win)
{
    win.clear(sf::Color::Black);

    sf::Font font;
    font.loadFromFile("/System/Library/Fonts/Avenir.ttc");
    sf::Text text;
    text.setFont(font);
    text.setString("Text Test");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    //you will draw the text on (0,0), only Sprite can be set the position
    //win.draw(text);

    //draw shape
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    //win.draw(shape);

    //Sprite =  Texture + Entity
    //draw the text on RenderTexture
    //get Texture from RenderTexture
    //use Texture to generate a Sprite
    //set the position of Sprite
    //draw the Sprite to Window

    //Generate a Text Sprite
    sf::RenderTexture renderTexture;
    renderTexture.create(100, 100);
    renderTexture.clear();
    renderTexture.draw(text);
    //must use display();
    renderTexture.display();

    sf::Texture t = renderTexture.getTexture();
    sf::Sprite text_sprite;

    text_sprite.setTexture(t);
    text_sprite.setPosition(sf::Vector2f(300,300));
    win.draw(text_sprite);

    //Generate a Shape Sprite
    sf::Sprite png_sprite;
    sf::Sprite png_sprite_2;

    renderTexture.clear();
    renderTexture.draw(shape);
    renderTexture.display();

    sf::Texture s;
    s.loadFromFile("../../res/test.png");
    png_sprite.setTexture(s);
    png_sprite.scale(10.0f,10.0f);

    png_sprite_2.setTexture(s);
    png_sprite_2.scale(10.0f,10.0f);

    int x = 0;
    int y = 150;
    for (int i = 0; i < 4; i++)
    {
        png_sprite.setPosition(x, y);
        png_sprite_2.setPosition(y, x);

        x += 150;
        y += 150;

        win.draw(png_sprite_2);
        win.draw(png_sprite);
    }

    win.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        DrawTest(window);
    }

    return 0;
}
