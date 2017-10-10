#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class HUD
{
    public:
        HUD();
        void draw(sf::RenderWindow& window);
        void update(string coinsN, string lifeN, sf::Vector2f position);
        virtual ~HUD();
    private:
        sf::RectangleShape coin;
        sf::Texture coinTex;
        sf::RectangleShape lifes;
        sf::Texture lifesTex;
        sf::Text coinCount;
        sf::Text lifesCount;
        sf::Font font;
};

#endif // HUD_H
