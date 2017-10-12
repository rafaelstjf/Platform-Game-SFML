#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;
class  SoundManager {

public:
SoundManager();
~SoundManager();
void playSound(string soundName);
void playMusic(string musicName);
void setVolume(float vol);
void stopMusic(string musicName);
private:
sf::Music gameMusic;
sf::Music menuMusic;
sf::SoundBuffer buffer;
sf::Sound sound;
 string menuPath = "Audio/menu.ogg";
 string gamePath = "Audio/game.ogg";
 string jumpPath = "Audio/SFX/jump.wav";
 string coinPath = "Audio/SFX/coin.wav";
 string deathPath = "Audio/SFX/death.wav";
 string powerUpPath = "Audio/SFX/powerUp.wav";
 string apPowerUpPath  = "Audio/SFX/apPowerUp.wav";
string breakBlockPath  = "Audio/SFX/breakBlock.wav";
string stompPath = "Audio/SFX/stomp.wav";

};

#endif
