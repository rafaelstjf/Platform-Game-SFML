#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"
using namespace std;
class Platform
{
private:
  sf::RectangleShape body;
public:
  Platform(sf::Vector2f size, sf::Vector2f initPosition);
  Collider getCollider();
  sf::Vector2f getPosition();
  void draw(sf::RenderWindow &window);
  ~Platform();
};
#endif
