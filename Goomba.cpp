#include "Goomba.h"

Goomba::Goomba(sf::Vector2f initPosition, float switchTime, sf::Texture& texture){
    sound = new SoundManager();
    imageCount = {2,1};
    this->speed = 30;
    this->switchTime = switchTime;
    totalTime = 0;
    currentImage.x = 0;
    this->texture = texture;
    uvRect.width = texture.getSize().x / float(imageCount.x);
    uvRect.height = texture.getSize().y / float(imageCount.y);
    const sf::Texture *pTexture = &texture;
    body.setTexture(pTexture);
    body.setSize(sf::Vector2f(32.0f,32.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(initPosition);
}
Goomba::~Goomba(){

}
void Goomba::draw(sf::RenderWindow &window){
    window.draw(body);
}
void Goomba::setPosition(sf::Vector2f position){
body.setPosition(position);
}
void Goomba::bounce(){
velocity.x = -1*velocity.x;
}
void Goomba::update(float deltaTime){
    currentImage.y = 0;
    velocity.x*=0.8;
    if(velocity.x>0.0f)
        velocity.x += speed;
    else
        velocity.x -=speed;
    velocity.y += 981.0f * deltaTime;
    totalTime += deltaTime;
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime; //animacao mais suave
        currentImage.x++;
        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }
        uvRect.top = currentImage.y * uvRect.height;
        uvRect.width = abs(uvRect.width);
        uvRect.left = currentImage.x * uvRect.width;
        body.setTextureRect(uvRect);
        body.move(velocity*deltaTime);

}
sf::Rect<float> Goomba::getGlobalBounds(){
    return body.getGlobalBounds();
}
Collider Goomba::getCollider()
{
    return Collider(body);
}
sf::Vector2f Goomba::getPosition()
{
    return body.getPosition();
}
void Goomba::onCollision(sf::Vector2f direction)
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
bool Goomba::onCollisionPlayer(sf::Vector2f direction, Player& mario)
{
    if(direction.y<0)
    {
        velocity.x = 0;
        sound->playSound("stomp");
        return true;
    } else return false;
}
