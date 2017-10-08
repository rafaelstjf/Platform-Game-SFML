#include "Platform.h"
Platform::Platform(sf::Vector2f size, sf::Vector2f initPosition)
{
    body.setSize(size);
    body.setPosition(initPosition);
    body.setOrigin(size/2.0f);
}


Platform::~Platform()
{
}
Collider Platform::getCollider()
{
    return Collider(body);
}
sf::Vector2f Platform::getPosition()
{
    return body.getPosition();
}
void Platform::draw(sf::RenderWindow &window)
{
    window.draw(body);
}
