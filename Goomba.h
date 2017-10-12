#ifndef GOOMBA_H
#define GOOMBA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Player.h"
#include "SoundManager.h"
using namespace std;

class Goomba{
private:
sf::RectangleShape body;
sf::Texture texture;
sf::Vector2f imageCount;
float switchTime;
sf::Vector2u currentImage;
float speed;
float totalTime;
sf::IntRect uvRect;
sf::Vector2f velocity;
SoundManager *sound;
public:
    Goomba(sf::Vector2f initPosition, float switchTime, sf::Texture& texture);
    void draw(sf::RenderWindow &window);
    void update(float deltaTime);
    sf::Rect<float> getGlobalBounds();
    Collider getCollider();
    void onCollision(sf::Vector2f direction);
    bool onCollisionPlayer(sf::Vector2f direction, Player& mario);
    void setPosition(sf::Vector2f position);
    void bounce();
    sf::Vector2f getPosition();
    ~Goomba();

};
#endif
