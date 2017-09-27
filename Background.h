#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class Background
{
private:
  sf::RectangleShape sky;
  sf::Texture texSky;

public:
  Background();
  void desenha(sf::RenderWindow &janela);
  ~Background();
};
#endif