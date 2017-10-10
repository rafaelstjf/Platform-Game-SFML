#include "HUD.h"

HUD::HUD()
{
    font.loadFromFile("Extra/font.ttf");
    coinCount.setFont(font);
    lifesCount.setFont(font);
    coinCount.setPosition(26.0f, 17.0f);
    lifesCount.setPosition(166.0f, 17.0f);
    coinCount.setCharacterSize(18);
    lifesCount.setCharacterSize(18);
    coinTex.loadFromFile("Textures/General/CoinS.png");
    coin.setSize(sf::Vector2f(32.0f,32.0f));
    coin.setOrigin(coin.getSize()/2.0f);
    coin.setPosition(sf::Vector2f(10.0f,17.0f));
    const sf::Texture *pcoin = &coinTex;
    coin.setTexture(pcoin);
    lifesTex.loadFromFile("Textures/General/Face.png");
    lifes.setSize(sf::Vector2f(32.0f,32.0f));
    lifes.setOrigin(coin.getSize()/2.0f);
    lifes.setPosition(sf::Vector2f(150.0f,17.0f));
    const sf::Texture *plifes = &lifesTex;
    lifes.setTexture(plifes);
}

HUD::~HUD()
{
    //dtor
}
void HUD::update(string coinN, string lifesN, sf::Vector2f position)
{
    coinCount.setString(coinN);
    lifesCount.setString(lifesN);
    coin.setPosition(position.x - 332.0, 17.0f);
    coinCount.setPosition(position.x - 300.0,17.0f);
    lifes.setPosition(position.x - 168, 17.0f);
    lifesCount.setPosition(position.x - 136, 17.0f);

}
void HUD::draw(sf::RenderWindow& window)
{
    window.draw(coin);
    window.draw(lifes);
    window.draw(coinCount);
    window.draw(lifesCount);
}
