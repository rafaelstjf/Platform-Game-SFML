#include "Background.h"
Background::Background()
{
    texSky.loadFromFile("Texturas/Backgrounds/Sky.png");
    const sf::Texture *tSky = &texSky;
    sky.setSize(sf::Vector2f(800.0f, 600.0f));
    sf::IntRect r(0,0,800,600);
    texSky.setRepeated(true);
    texSky.setSmooth(true);
    sky.setTexture(tSky);
    sky.setTextureRect(r);
}

Background::~Background()
{
}

void Background::desenha(sf::RenderWindow &janela)
{

    janela.draw(sky);
}
