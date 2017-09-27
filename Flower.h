#ifndef FLOWER_H
#define FLOWER_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Flower{
private:
sf::RectangleShape corpo;
sf::Texture textura;
float velocidade;
sf::Vector2f imageCount;
float tempoTroca;
bool direita;
bool noChao;
public:
    Flower(sf::Vector2f posicaoInicial);
    void desenha(sf::RenderWindow &window);
    void atualiza(float deltaTime);
    sf::Rect<float> getGlobalBounds();        
    ~Flower();

};
#endif
