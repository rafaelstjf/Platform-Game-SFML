#include "NormalBlock.h"

NormalBlock::NormalBlock(sf::Texture& texture, sf::Vector2f initPosition)
{
    sound = new SoundManager();
    this->texture = texture;
    const sf::Texture *pTexture = &texture;
    body.setTexture(pTexture);
    body.setSize(sf::Vector2f(32.0f,32.0f));
    activate = true;
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(initPosition);

}

Collider NormalBlock::getCollider()
{
    return Collider(body);
}
NormalBlock::~NormalBlock()
{
    //dtor
}
void NormalBlock::draw(sf::RenderWindow &window)
{
    window.draw(body);
}
bool NormalBlock::onCollision(sf::Vector2f direction, Player mario)
{
    if(direction.y>0&& direction.x==0 && mario.getBigMario())
    {
        sound->playSound("breakBlock");
        return true;
    }
    else return false;
}
sf::Vector2f NormalBlock::getPosition()
{
    return body.getPosition();
}

