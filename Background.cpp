#include "Background.h"
Background::Background(){
texSky.loadFromFile("Texturas/Backgrounds/Sky.png");
const sf::Texture *tSky = &texSky;  
sky.setSize(sf::Vector2f(800.0f,600.0f));
//sf::IntRect r(0,0,100,100);
//sky.setTextureRect(r);
texSky.setRepeated(true);
texSky.setSmooth(true);
sky.setTexture(tSky);    
}

Background::~Background(){


}

void Background::desenha(sf::RenderWindow &janela){

    janela.draw(sky);
}
