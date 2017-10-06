#ifndef FLOWER_H
#define FLOWER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Flower{
private:
sf::RectangleShape body;
sf::Texture texture;
sf::Vector2f imageCount;
public:
    Flower(sf::Vector2f initPosition);
    void draw(sf::RenderWindow &window);
    sf::Rect<float> getGlobalBounds();        
    ~Flower();

};
#endif
