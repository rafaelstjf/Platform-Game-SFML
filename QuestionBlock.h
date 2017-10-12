#ifndef QUESTIONBLOCK_H
#define QUESTIONBLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"

using namespace std;

class QuestionBlock
{
public:
    QuestionBlock(sf::Vector2f initPosition);
    virtual ~QuestionBlock();
    bool getActivate();
    Collider getCollider();
    void onCollision(sf::Vector2f direction);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();

protected:

private:
    sf::Texture texture;
    sf::RectangleShape body;
    bool activate;
};

#endif // QUESTIONBLOCK_H
