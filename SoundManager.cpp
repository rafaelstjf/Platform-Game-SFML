#include "SoundManager.h"

SoundManager::SoundManager()
{
    sound.setBuffer(buffer);
    menuMusic.openFromFile(menuPath);
    gameMusic.openFromFile(gamePath);

}
SoundManager::~SoundManager()
{

}

void SoundManager::playSound(string soundName)
{
    if(soundName == "jump")
    {

        buffer.loadFromFile(jumpPath);
        sound.play();
    }
    else if(soundName== "coin")
    {
        buffer.loadFromFile(coinPath);
        sound.play();
    }
    else if(soundName== "death")
    {
        buffer.loadFromFile(deathPath);
        sound.play();
    }

}

void SoundManager::playMusic(string musicName)
{
    if(musicName == "menu")
    {
        if(menuMusic.getStatus()==sf::Music::Stopped)
            menuMusic.play();
    }
    else if(musicName == "game")
    {
        if(gameMusic.getStatus() == sf::Music::Stopped)
            gameMusic.play();
    }


}
void SoundManager::stopMusic(string musicName)
{
    if(musicName == "menu")
    {
        if(menuMusic.getStatus()==sf::Music::Playing)
            menuMusic.stop();
    }
    else if(musicName == "game")
    {
        if(gameMusic.getStatus() == sf::Music::Playing)
            gameMusic.stop();
    }


}
void SoundManager::setVolume(float vol)
{

}
