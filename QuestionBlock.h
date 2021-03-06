#ifndef QUESTIONBLOCK_H
#define QUESTIONBLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "SuperMushroom.h"
#include "SoundManager.h"
using namespace std;

class QuestionBlock
{
public:
    QuestionBlock(sf::Texture& texture, sf::Vector2f initPosition);
    virtual ~QuestionBlock();
    bool getActivate();
    Collider getCollider();
    bool onCollision(sf::Vector2f direction);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();

protected:

private:
    sf::Texture texture;
    sf::RectangleShape body;
    bool activate;
    SoundManager* sound;
};

#endif // QUESTIONBLOCK_H
