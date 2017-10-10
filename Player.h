#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Audio.hpp>
#include "PlayerAnimation.h"
#include "Collider.h"
using namespace std;
class Player
{
  private:
    sf::RectangleShape body;
    PlayerAnimation anBigMario;
    PlayerAnimation anSmallMario;
    sf::Sound jumpSound;
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
    void setPosition(sf::Vector2f pos);
    void move(sf::Vector2f dir);
    void setScale(float x, float y);
    bool getBigMario();
    Collider getCollider();
    sf::Vector2f getPosition();

    ~Player();
};
#endif
