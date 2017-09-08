#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
class Jogador{
private:
    sf::Texture textura[4];
    // sf::RectangleShape jogador;
    sf::Sprite jogador;
public:
    Jogador(sf::Vector2f tamanho);
    void desenha(sf::RenderWindow &window);
    void move(sf::Vector2f distancia);
    void setPos(sf::Vector2f posicao);
    void atFrame(int ind);    
    double getRotacao();
    void transforma(double val);

    ~Jogador();
};
#endif