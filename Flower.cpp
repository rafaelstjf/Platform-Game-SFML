#include "Flower.h"

Flower::Flower(sf::Vector2f posicaoInicial){
    direita = false;
    textura.loadFromFile("Texturas/General/Flower.png");
    imageCount = {1,1};
    tempoTroca = 0.3f;
    velocidade = 100;
    const sf::Texture *pTexture = &textura;   
    corpo.setTexture(pTexture);    
    corpo.setSize(sf::Vector2f(32.0f,32.0f));
    corpo.setPosition(posicaoInicial);
    noChao = false;
}
Flower::~Flower(){

}
void Flower::desenha(sf::RenderWindow &window){
    window.draw(corpo);
}
void Flower::atualiza(float deltaTime){
  
}
sf::Rect<float> Flower::getGlobalBounds(){
    return corpo.getGlobalBounds();
}