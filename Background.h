#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Background
{
private:
  sf::RectangleShape sky;
  sf::Texture texSky;
  const sf::Vector2u tileSize{12, 12};
  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
  int tiles[25*19];
public:
  Background();
  void loadTileset();
  void draw(sf::RenderWindow &window);
  ~Background();
};
#endif
