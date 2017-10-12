#ifndef NORMALBLOCK_H
#define NORMALBLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Player.h"
#include "SoundManager.h"
using namespace std;

class NormalBlock
{
public:
    NormalBlock(sf::Texture& texture, sf::Vector2f initPosition);
    virtual ~NormalBlock();
    Collider getCollider();
    bool onCollision(sf::Vector2f direction, Player mario);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();

protected:

private:
    sf::Texture texture;
    sf::RectangleShape body;
    bool activate;
    SoundManager *sound;
};

#endif // NormalBlock_H
