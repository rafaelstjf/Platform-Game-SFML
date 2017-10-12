#include "QuestionBlock.h"

QuestionBlock::QuestionBlock(sf::Vector2f initPosition)
{
    texture.loadFromFile("Textures/General/Qblock0.png");
    const sf::Texture *pTexture = &texture;
    body.setTexture(pTexture);
    body.setSize(sf::Vector2f(32.0f,32.0f));
    activate = true;
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
bool QuestionBlock::onCollision(sf::Vector2f direction)
{
    if(activate && direction.y>0&& direction.x==0)
        {
            activate = false;
            texture.loadFromFile("Textures/General/QBlock1.png");
            const sf::Texture *pTexture = &texture;
            body.setTexture(pTexture);
            return true;
        }
    return false;
}
sf::Vector2f QuestionBlock::getPosition(){
return body.getPosition();
}

