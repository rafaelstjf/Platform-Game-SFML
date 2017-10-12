#include "QuestionBlock.h"

QuestionBlock::QuestionBlock(sf::Vector2f initPosition)
{
    texture.loadFromFile("Textures/General/Qblock0.png");
    const sf::Texture *pTexture = &texture;
    body.setTexture(pTexture);
    body.setSize(sf::Vector2f(32.0f,32.0f));
    activate = false;
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(initPosition);

}
bool QuestionBlock::getActivate()
{
    return activate;
}

Collider QuestionBlock::getCollider()
{
    return Collider(body);
}
QuestionBlock::~QuestionBlock()
{
    //dtor
}
void QuestionBlock::draw(sf::RenderWindow &window){
window.draw(body);
}
void QuestionBlock::onCollision(sf::Vector2f direction)
{
    if(activate)
        {
            activate = false;
            texture.loadFromFile("Textures/General/QBlock1.png");
            const sf::Texture *pTexture = &texture;
            body.setTexture(pTexture);
        }
}
sf::Vector2f QuestionBlock::getPosition(){
return body.getPosition();
}

