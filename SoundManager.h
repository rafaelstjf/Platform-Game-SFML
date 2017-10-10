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
const string jumpPath = "";
const string menuPath = "Audio/menu.ogg";
const string gamePath = "Audio/game.ogg";
const string coinPath = "Audio/SFX/coin.wav";
const string deathPath = "Audio/SFX/death.wav";

};

#endif
