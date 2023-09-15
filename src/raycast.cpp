#include "vec.h"
#include "coordsys.h"
#include "shapes.h"
#include <SFML/Graphics.hpp>

const int W = 1200;
const int H = 1200;

int main () {
    sf::RenderWindow window (sf::VideoMode (W, H), "eee vector");
    window.setFramerateLimit (120);

    sf::Clock clk;
    double dt = 0;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Image img;
    img.create (W, H);


    Vec cam_pos (0, 0, 100);


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        texture.loadFromImage (img);
        sprite.setTexture (texture);

        window.clear ();
        window.draw (sprite);

        window.display();
    }

    return 0;
}