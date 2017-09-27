#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Animation.h"
using namespace std;
class Jogador{
private:
   sf::RectangleShape corpo;
   Animation anBigMario;
   Animation anSmallMario;
   float velocidade;
   int linha;
   bool direita;
    sf::Texture sMario;
    sf::Texture bMario;
    sf::Vector2u sMarioCount = {2,2};
    sf::Vector2u bMarioCount = {2,4};
   bool flower;
   bool idle;
   bool noChao;
   bool marioBig;
   bool emPulo;
   float tempoTroca;
public:
    Jogador(float tempoTroca, float velocidade);
    void desenha(sf::RenderWindow &window);
    sf::Rect<float> getGlobalBounds();
    void setBigMario(bool marioBig);
    void setFireMario(bool flower);        
    void atualiza(float deltaTime, sf::RenderWindow &window);

    ~Jogador();
};
#endif
