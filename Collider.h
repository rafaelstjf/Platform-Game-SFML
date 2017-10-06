#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Collider
{
public:
    Collider(sf::RectangleShape& body);
    virtual ~Collider();
    void move(float dx, float dy){ body.move(dx, dy);}
    bool checkCollision(Collider& other,sf::Vector2f& direction, float push);//push = capacidade de um objeto empurrar o outro
    sf::Vector2f getPosition() { return body.getPosition();};
    sf::Vector2f getHalfSize() { return body.getPosition() / 2.0f;};
private:
    sf::RectangleShape& body;
};

#endif // Collider_H
