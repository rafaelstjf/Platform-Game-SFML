#include "Animation.h"
Animation::Animation()
{
}
Animation::Animation(sf::Texture &texture, sf::Vector2u imageCount, float switchTime)
{

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0;
    currentImage.x = 0;
    uvRect.width = texture.getSize().x / float(imageCount.x);
    uvRect.height = texture.getSize().y / float(imageCount.y);
}
void Animation::update(int row, float deltaTime, bool faceRight, bool idle)
{
    /*if (currentImage.x == 0 && currentImage.y != 0)
        currentImage.y = row;
    else if (currentImage.y == 0)
        currentImage.y = row;*/
    currentImage.y = row;
    totalTime += deltaTime;
    if (!idle)
    {
        if (totalTime >= switchTime)
        {
            totalTime -= switchTime; //animacao mais suave
            currentImage.x++;
            /*if (currentImage.x == 0)
                currentImage.x++;*/
            if (currentImage.x >= imageCount.x)
            {
                currentImage.x = 0;
            }
        }
    }
    else
    {
        currentImage.x = 0;
    }
    
    uvRect.top = currentImage.y * uvRect.height;
    uvRect.width = abs(uvRect.width);

    if (faceRight)
        uvRect.left = currentImage.x * uvRect.width;
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}

Animation::~Animation()
{
}