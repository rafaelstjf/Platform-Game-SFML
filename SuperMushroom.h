#ifndef SUPERMUSHROOM_H
#define SUPERMUSHROOM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"

using namespace std;

class SuperMushroom{
private:
sf::RectangleShape body;
sf::Texture texture;
float speed;
sf::Vector2f imageCount;
sf::Vector2f velocity;
public:
    SuperMushroom(sf::Vector2f initPosition, float speed, sf::Texture& texture);
    void draw(sf::RenderWindow &window);
    void update(float deltaTime);
    void onCollision(sf::Vector2f direction);
    sf::Rect<float> getGlobalBounds();
    Collider getCollider();
    sf::Vector2f getPosition();
    ~SuperMushroom();

};
#endif
