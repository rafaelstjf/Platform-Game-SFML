#include "SuperMushroom.h"

SuperMushroom::SuperMushroom(sf::Vector2f initPosition, float speed, sf::Texture& texture)
{
    sound = new SoundManager();
    imageCount = {1,1};
    this->speed = speed;
    this->texture = texture;
    const sf::Texture *pTexture = &texture;
    body.setTexture(pTexture);
    body.setSize(sf::Vector2f(32.0f,32.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(initPosition);
}
SuperMushroom::~SuperMushroom()
{

}
void SuperMushroom::draw(sf::RenderWindow &window)
{
    window.draw(body);
}
void SuperMushroom::update(float deltaTime)
{
    velocity.x*=0.8;
    if(velocity.x>=0.0f)
        velocity.x += speed;
    else
        velocity.x -=speed;
    velocity.y += 981.0f * deltaTime;
    body.move(velocity*deltaTime);
}
sf::Rect<float> SuperMushroom::getGlobalBounds()
{
    return body.getGlobalBounds();
}
Collider SuperMushroom::getCollider()
{
    return Collider(body);
}
sf::Vector2f SuperMushroom::getPosition()
{
    return body.getPosition();
}
void SuperMushroom::onCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //Left
        velocity.x = -1*velocity.x;
    }
    else if (direction.x > 0.0f)
    {
        //Right
        velocity.x = -1*velocity.x;
    }
    if (direction.y < 0.0f)
    {
        //Bottom
        velocity.y = 0.0f;
    }
    else if (direction.y > 0.0f)
    {
        //Above
        velocity.y = 0.0f;
    }
}
void SuperMushroom::onCollisionPlayer(Player& mario)
{
    if(!mario.getBigMario())
    {
        sound->playSound("powerUp");
        mario.setBigMario(true);
        mario.setScale(1.2, 1.2);
    }
}
