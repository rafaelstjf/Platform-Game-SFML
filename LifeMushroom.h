#ifndef LIFEMUSHROOM_H
#define LIFEMUSHROOM_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class LifeMushroom{
private:
sf::RectangleShape corpo;
sf::Texture textura;
float velocidade;
sf::Vector2f imageCount;
float tempoTroca;
bool direita;
bool noChao;
public:
    LifeMushroom(sf::Vector2f posicaoInicial);
    void desenha(sf::RenderWindow &window);
    void atualiza(float deltaTime);
    sf::Rect<float> getGlobalBounds();        
    ~LifeMushroom();

};
#endif
