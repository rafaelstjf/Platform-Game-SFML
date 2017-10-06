#include "Flower.h"

Flower::Flower(sf::Vector2f initPosition){
    texture.loadFromFile("Texturas/General/Flower.png");
    imageCount = {1,1};
    const sf::Texture *pTexture = &texture;   
    body.setTexture(pTexture);    
    body.setSize(sf::Vector2f(32.0f,32.0f));
    body.setPosition(initPosition);
}
Flower::~Flower(){

}
void Flower::draw(sf::RenderWindow &window){
    window.draw(body);
}
sf::Rect<float> Flower::getGlobalBounds(){
    return body.getGlobalBounds();
}