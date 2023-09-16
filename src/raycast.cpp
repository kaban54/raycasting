#include "raytracing.h"
#include <cmath>
#include <iostream>
#include <stdio.h>

const int W = 1200;
const int H = 1200;

void RayCastSph (sf::Image& img, const Camera& cam, const Light& light, const Sphere& sph);

int main () {
    sf::RenderWindow window (sf::VideoMode (W, H), "eee vector");
    window.setFramerateLimit (120);

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Image img;
    img.create (W, H);

    Camera cam (Vec (0, 0, 100), CoordSys (-10, -10, 90, 20./W));
    Light light (Vec (100, 100, 200));

    Sphere sph (0, 0, 0, 30, Vec (0, 1, 0));

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

        RayCastSph (img, cam, light, sph);
        
        texture.loadFromImage (img);
        sprite.setTexture (texture);

        window.clear ();
        window.draw (sprite);

        window.display();
    }

    return 0;
}


void RayCastSph (sf::Image& img, const Camera& cam, const Light& light, const Sphere& sph) {
    
    for (int pix_y = 0; pix_y < H; pix_y++) {
        for (int pix_x = 0; pix_x < W; pix_x++) {
            
            Ray ray = cam.GetRay (pix_x, pix_y);
            Vec col_pnt (0, 0, 0);

            if (sph.Collides (ray, col_pnt)) {

                Vec normal = sph.GetNormal (col_pnt);
                Vec light_dir = !(light.pos - col_pnt);
                double brightness_d = (normal, light_dir);
                if (brightness_d < 0) brightness_d = 0;

                Vec cam_dir = !(cam.pos - col_pnt);
                Vec light_dir_r = 2 * normal * (normal, light_dir) - light_dir;
                double brightness_s = (cam_dir, light_dir_r);
                if (brightness_s < 0) brightness_s = 0;
                else brightness_s = std::pow (brightness_s, 30);
                
                double brightness_a = 0.1;

                Vec col = (light.col ^ sph.color) * (brightness_d + brightness_a) + light.col * brightness_s;

                img.setPixel (pix_x, pix_y, GetsfColor (col));
            }
        }
    }
}