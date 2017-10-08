#ifndef COIN_H
#define COIN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"

using namespace std;

class Coin{
private:
sf::RectangleShape body;
sf::Texture texture;
sf::Vector2f imageCount;
float switchTime;
sf::Vector2u currentImage;
float totalTime;
sf::IntRect uvRect;
sf::Vector2f velocity;
public:
    Coin(sf::Vector2f initPosition, float switchTime, sf::Texture& texture);
    void draw(sf::RenderWindow &window);
    void update(float deltaTime);
    sf::Rect<float> getGlobalBounds();
    Collider getCollider();
    void onCollision(sf::Vector2f direction);
    sf::Vector2f getPosition();
    ~Coin();

};
#endif
