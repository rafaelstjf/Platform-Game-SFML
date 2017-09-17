#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
class Jogador{
private:
   sf::RectangleShape corpo;
   Animation animation;
   float velocidade;
   unsigned int linha;
   bool direita;
public:
    Jogador(sf::Texture &textura, sf::Vector2u imageCount, float tempoTroca, float velocidade);
    void desenha(sf::RenderWindow &window);
    void atualiza(float deltaTime);

    ~Jogador();
};
#endif