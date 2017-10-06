#include "Coin.h"

Coin::Coin(sf::Vector2f initPosition, float switchTime){
    imageCount = {3,1};
    this->switchTime = switchTime;
    totalTime = 0;
    currentImage.x = 0;
    texture.loadFromFile("Textures/General/Coin.png");
    uvRect.width = texture.getSize().x / float(imageCount.x);
    uvRect.height = texture.getSize().y / float(imageCount.y);
    const sf::Texture *pTexture = &texture;
    body.setTexture(pTexture);
    body.setSize(sf::Vector2f(32.0f,32.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(initPosition);
}
Coin::~Coin(){

}
void Coin::draw(sf::RenderWindow &window){
    window.draw(body);
}
void Coin::update(float deltaTime){
    currentImage.y = 0;
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

}
sf::Rect<float> Coin::getGlobalBounds(){
    return body.getGlobalBounds();
}
Collider Coin::getCollider()
{
    return Collider(body);
}
sf::Vector2f Coin::getPosition()
{
    return body.getPosition();
}
void Coin::onCollision(sf::Vector2f direction)
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
