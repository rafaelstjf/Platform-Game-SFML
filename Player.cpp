#include "Player.h"

Player::Player(float speed, float switchTime, float jumpHeight, sf::Vector2f initPosition)
{
    this->speed = speed;
    this->switchTime = switchTime;
    this->jumpHeight = jumpHeight;
    flower = false;
    faceRight = true;
    isBig = false;
    canJump = true;
    sMario.loadFromFile("Textures/Player/sMario.png");
    bMario.loadFromFile("Textures/Player/bMario.png");
    const sf::Texture *pTexture = &sMario;
    body.setSize(sf::Vector2f(32.0, 32.0));
    //body.setScale(2, 2);
    body.setPosition(initPosition);
    body.setTexture(pTexture);
    body.setOrigin(body.getSize() / 2.0f);
    row = 0;
    anBigMario = PlayerAnimation(bMario, bMarioCount, switchTime);
    anSmallMario = PlayerAnimation(sMario, sMarioCount, switchTime);
}
Player::~Player()
{
}

void Player::draw(sf::RenderWindow &window)
//draw o jogador na janela passada como referencia
{
    window.draw(body);
}
void Player::update(float deltaTime, sf::RenderWindow &window)
{
    velocity.x *= 0.5f;
    idle = false;
    if (isBig)
    {

        const sf::Texture *pTexture = &bMario;
        body.setTexture(pTexture);
        if (flower)
            row = 2;
        else
            row = 0;
    }
    else
    {
        const sf::Texture *pTexture = &sMario;
        body.setTexture(pTexture);
        row = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x += speed;
        faceRight = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= speed;
        faceRight = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= 2 * speed;
        faceRight = false;
    }
    else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x += 2 * speed;
        faceRight = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
    {
        canJump = false;
        velocity.y = -sqrt(2.0f * 981.0 * jumpHeight);

        if (isBig)
        {
            if (flower)
                row = 3;
            else
                row = 1;
        }
        else
            row = 1;
    }
    velocity.y += 981.0f * deltaTime;
    if (velocity.x == 0)
    {
        faceRight = true;
        idle = true;
    }
    if (isBig)
    {
        anBigMario.update(row, deltaTime, faceRight, idle);
        body.setTextureRect(anBigMario.uvRect);
    }
    else
    {
        anSmallMario.update(row, deltaTime, faceRight, idle);
        body.setTextureRect(anSmallMario.uvRect);
    }
    body.move(velocity * deltaTime);
}
void Player::onCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //Left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        //Right
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        //Bottom
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        //Above
        velocity.y = 0.0f;
    }
}
sf::Rect<float> Player::getGlobalBounds()
{
    return body.getGlobalBounds();
}
void Player::setBigMario(bool isBig)
{
    this->isBig = isBig;
}
void Player::setFireMario(bool flower)
{
    this->flower = flower;
}
Collider Player::getCollider()
{
    return Collider(body);
}
sf::Vector2f Player::getPosition()
{
    return body.getPosition();
}
