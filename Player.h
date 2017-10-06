#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "PlayerAnimation.h"
#include "Collider.h"
using namespace std;
class Player
{
  private:
    sf::RectangleShape body;
    PlayerAnimation anBigMario;
    PlayerAnimation anSmallMario;
    float speed;
    int row;
    bool faceRight;
    bool flower;
    bool idle;
    bool isBig;
    float switchTime;
    float jumpHeight;
    bool canJump;
    sf::Texture sMario;
    sf::Texture bMario;
    sf::Vector2u sMarioCount = {2, 2};
    sf::Vector2u bMarioCount = {2, 4};
    sf::Vector2f velocity;

  public:
    Player(float switchTime, float speed, float jumpHeight, sf::Vector2f initPosition);
    sf::Rect<float> getGlobalBounds();
    void draw(sf::RenderWindow &window);
    void setBigMario(bool isBig);
    void setFireMario(bool flower);
    void update(float deltaTime, sf::RenderWindow &window);
    void onCollision(sf::Vector2f direction);
    Collider getCollider();
    sf::Vector2f getPosition();

    ~Player();
};
#endif
