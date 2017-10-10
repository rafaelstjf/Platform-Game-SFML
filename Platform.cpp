#include "Platform.h"
Platform::Platform(sf::Vector2f size, sf::Vector2f initPosition)
{
    texture.loadFromFile("Textures/Background/Ground.png");
    body.setSize(size);
    body.setPosition(initPosition);
    texture.setRepeated(true);
    const sf::Texture *pTexture = &texture;
    body.setTextureRect(sf::IntRect(0, 0, size.x, 32));
    body.setTexture(pTexture);
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
