#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation{
    private:
    //usa vector2u pois nunca vai ser menor do que zero
    sf::Vector2u imageCount; //guarda a quantidade de imagens em cada coluna
    sf::Vector2u currentImage;
    float totalTime;
    float switchTime;
    public:
    sf::IntRect uvRect;
    void update(int row, float deltaTime, bool faceRight, bool idle );
    Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
    Animation();
    ~Animation();
};
#endif