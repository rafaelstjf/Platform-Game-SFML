#include "Background.h"
Background::Background()
{
    texSky.loadFromFile("Textures/Background/Sky.png");
    const sf::Texture *tSky = &texSky;
    sky.setSize(sf::Vector2f(800.0f, 600.0f));
    sf::IntRect r(0, 0, 800, 600);
    texSky.setRepeated(false);
    texSky.setSmooth(true);
    sky.setTexture(tSky);
    sky.setTextureRect(r);
}
void Background::loadTileset()
{
}

Background::~Background()
{
}

void Background::draw(sf::RenderWindow &window)
{
    window.draw(sky);
}
