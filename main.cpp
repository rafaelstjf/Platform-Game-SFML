#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#ifdef __linux__
#include <cstring>
#endif
//SFML Libraries
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Game Libraries
#include "Player.h"
#include "SuperMushroom.h"
#include "Flower.h"
#include "Platform.h"
#include "Coin.h"
#include "HUD.h"
#include "SoundManager.h"
#include "QuestionBlock.h"
#include "NormalBlock.h"
#include "Goomba.h"
namespace patch //Correcao da funcao to_string
{
template <typename T>
std::string to_string(const T &n)
{
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
}
using namespace std;

static const string coinTPath = "Textures/General/Coin.png";
static const string sMushroomTPath = "Textures/General/SuperMushroom.png";
static const string groundTPath = "Textures/Background/Ground.png";
static const string logoTPath = "Textures/General/logo.png";
static const string bigTubeTPath = "Textures/Background/Transparent.png";
static const string tube2TPath = "Textures/Background/Tube2.png";
static const string tube1TPath = "Textures/Background/Tube1.png";
static const string normalBlockTPath = "Textures/General/NBlock.png";
static const string goombaTPath = "Textures/General/Goomba.png";
static const string questionBlockTPath = "Textures/General/Qblock0.png";

const float switchTime = 0.1f;
static const float VIEW_HEIGHT = 600.0f;
static const float VIEW_WIDTH = 800.0f;

void resizeWindow(sf::RenderWindow &window, sf::View &view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_WIDTH * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    cout << "Controles: \n Setas direcionais movimentam \n setas+A corre" << endl;
    //Inicializa as variaveis
    float deltaTime = 0.0f;
    bool gameOpen = true;
    bool inMenu = true;
    sf::Clock clock;
    sf::Vector2f direction;
    int pontuacao = 0;
    int vidas = 0;

    //Cria a window e a view
    sf::RenderWindow game;
    sf::RenderWindow menu;

    //Carrega a fonte
    sf::Font font;
    font.loadFromFile("Extra/font.ttf");

    //Carrega a textura de alguns objetos
    sf::Texture coinTexture;
    sf::Texture normalBlockTexture;
    sf::Texture bigTubeTexture;
    sf::Texture sMushroomTexture;
    sf::Texture groundTexture;
    sf::Texture tube2Texture;
    sf::Texture goombaTexture;
    sf::Texture questionBlockTexture;
    questionBlockTexture.loadFromFile(questionBlockTPath);
    goombaTexture.loadFromFile(goombaTPath);
    normalBlockTexture.loadFromFile(normalBlockTPath);
    bigTubeTexture.loadFromFile(bigTubeTPath);
    coinTexture.loadFromFile(coinTPath);
    tube2Texture.loadFromFile(tube2TPath);
    groundTexture.loadFromFile(groundTPath);
    sMushroomTexture.loadFromFile(sMushroomTPath);

    //Inicializa os objetos
    SoundManager sound;
    Player mario(100.0f, switchTime, 100, sf::Vector2f(16.0f,300.0f));
    HUD hud;

    //Inicializa os vetores de objetos
    vector <Coin> coins;
    vector<Platform> platforms;
    vector<QuestionBlock> questionBlocks;
    vector <SuperMushroom> smushrooms;
    vector<NormalBlock> nblocks;
    vector<Goomba> goombas;





    //executa uma sequencia de eventos enquanto a janela esta aberta
    while(gameOpen)
    {
        if(inMenu)
        {
            menu.create(sf::VideoMode(800,600), "Menu", sf::Style::Titlebar | sf::Style::Close);
            sf::Texture logoT;
            logoT.loadFromFile(logoTPath);
            sf::RectangleShape logo;
            const sf::Texture *plogoT = &logoT;
            logo.setSize(sf::Vector2f(logoT.getSize().x, logoT.getSize().y));
            logo.setPosition(VIEW_WIDTH/2.0f, 100);
            logo.setTexture(plogoT);
            logo.setOrigin(logo.getSize()/2.0f);
            bool op1 = true;
            bool op2 = false;
            sf::Text textOp1;
            sf::Text textOp2;
            textOp1.setFont(font);
            textOp2.setFont(font);
            textOp1.setString("Start");
            textOp2.setString("Quit");
            textOp1.setPosition(250, 300);
            textOp2.setPosition(250, 400);
            textOp1.setCharacterSize(100);
            textOp2.setCharacterSize(100);
            while (menu.isOpen())
            {
                sound.playMusic("menu");
                sf::Event evento;
                deltaTime = clock.restart().asSeconds();
                if (deltaTime > 1.0f / 60.f)
                    deltaTime = 1.0f / 60.0f;
                while (menu.pollEvent(evento))
                {
                    //fecha a janela
                    if(evento.type == sf::Event::Closed)
                    {
                        menu.close();
                        gameOpen = false;
                    }

                    if (evento.type== sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Up)
                    {
                        op1 = !op1;
                        op2 = !op2;
                    }
                    else if(evento.type==sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Down)
                    {
                        op1 = !op1;
                        op2 = !op2;
                    }
                    else if(evento.type==sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Return)
                    {
                        //Verifica se vai para o jogo ou sai dele quando aperta enter
                        if(op2)
                        {
                            menu.close();
                            gameOpen = false;
                        }
                        if(op1)
                        {
                            sound.stopMusic("menu");
                            menu.close();
                            inMenu = false;

                        }
                    }

                }
                //Muda a cor do texto de acordo com a opcao selecionada
                if(op1)
                    textOp1.setFillColor(sf::Color::Yellow);
                else
                    textOp1.setFillColor(sf::Color::White);
                if(op2)
                    textOp2.setFillColor(sf::Color::Yellow);
                else
                    textOp2.setFillColor(sf::Color::White);

                menu.clear(sf::Color::Blue);
                menu.draw(logo);
                menu.draw(textOp1);
                menu.draw(textOp2);
                menu.display();

            }
            inMenu = false;
        }
        else
        {
            //remove todos os elementos anteriores
            coins.clear();
            platforms.clear();
            questionBlocks.clear();
            smushrooms.clear();
            goombas.clear();
            nblocks.clear();

            //Coloca o mario na posicao inicial e reseta as vidas e os pontos
            mario.setPosition( sf::Vector2f(5.0f,300.0f));
            mario.setBigMario(false);
            vidas = 3;
            pontuacao = 0;

            //carrega os elementos
            platforms.push_back( Platform(bigTubeTexture, sf::Vector2f(40.0f, 600.0f), sf::Vector2f(-18.0f, 300.0f) ) );
            nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(80.0,450.0f)));
            nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(112.0,450.0f)));
            nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(144.0,450.0f)));
            questionBlocks.push_back(QuestionBlock(questionBlockTexture, sf::Vector2f(176.0,450.0f)));
            nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(208.0,450.0f)));
            platforms.push_back( Platform(groundTexture, sf::Vector2f(1500.0f,32.0f), sf::Vector2f(750,600-16) ) );
            for( int i = 0; i<3; i++)
                coins.push_back(Coin(sf::Vector2f(float(208.0 + 33.0*i), 450.0f), switchTime, coinTexture));
            platforms.push_back( Platform(tube2Texture, sf::Vector2f(40.0f, 28.0f), sf::Vector2f(238, 600-46.0f) ) );
            goombas.push_back(Goomba(sf::Vector2f(390.0f,500.0f), switchTime, goombaTexture));
            platforms.push_back( Platform(tube2Texture, sf::Vector2f(40.0f, 28.0f), sf::Vector2f(400, 600-46.0f) ) );
            goombas.push_back(Goomba(sf::Vector2f(480.0f,500.0f), switchTime, goombaTexture));
            for(int i=0; i<5; i++)
            {
                nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(450+32*i,470.0f)));
                if(i>0&& i<4)
                    nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(450+32*i,400.0f)));

            }
            questionBlocks.push_back(QuestionBlock(questionBlockTexture, sf::Vector2f(450+32*2,300.0f)));
            for(int i = 0; i<10; i++)
                coins.push_back(Coin(sf::Vector2f(float(600.0 + 33.0*i), 600-50.0f), switchTime, coinTexture));
            goombas.push_back(Goomba(sf::Vector2f(670.0f,500.0f), switchTime, goombaTexture));
            platforms.push_back( Platform(tube2Texture, sf::Vector2f(40.0f, 28.0f), sf::Vector2f(960, 600-46.0f) ) );

            for(int i = 0; i<5; i++)
            {
                platforms.push_back( Platform(groundTexture, sf::Vector2f(32.0f,32.0f), sf::Vector2f(1500+100*i,600-16) ) );
                for(int j = 0; j<3; j++)
                {
                    nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(1500+100*i,600-48-33*j)));
                }
            }
            for(int i= 0; i<7; i++)
            {
                for(int j=0; j<4; j++)
                {
                    coins.push_back(Coin(sf::Vector2f(float(2000.0 + 33.0*i), 450-33*j), switchTime, coinTexture));
                }
            }
            platforms.push_back( Platform(groundTexture, sf::Vector2f(2000.0f,32.0f), sf::Vector2f(3200,600-16) ) );
            for(int i = 10; i>0; i--)
            {
                for(int j = i; j>0; j--)
                {
                    nblocks.push_back(NormalBlock(normalBlockTexture, sf::Vector2f(3300+33*i,584-33*j)));
                }
            }
            platforms.push_back( Platform(bigTubeTexture, sf::Vector2f(40.0f, 600.0f), sf::Vector2f(4215.0f, 300.0f) ) );

            //Cria a tela do jogo
            game.create(sf::VideoMode(800, 600), "Janela", sf::Style::Titlebar | sf::Style::Close);
            sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

            while (game.isOpen())
            {
                sf::Event evento;
                sound.playMusic("game");
                deltaTime = clock.restart().asSeconds();
                if (deltaTime > 1.0f / 20.f)
                    deltaTime = 1.0f / 20.0f;
                while (game.pollEvent(evento))
                {
                    switch (evento.type)
                    {
                    //fecha a window
                    case sf::Event::Closed:
                        game.close();
                        gameOpen = false;
                        break;
                    case sf::Event::KeyReleased:
                        break;
                    case sf::Event::Resized:
                        resizeWindow(game, view);
                        break;
                    }
                }
                //updates
                mario.update(deltaTime, game);
                hud.update(patch::to_string(pontuacao), patch::to_string(vidas), mario.getPosition());
                for( int i =0; i<smushrooms.size(); i++)
                    smushrooms[i].update(deltaTime);
                for( int i =0; i<coins.size(); i++)
                    coins[i].update(deltaTime);
                for( int i =0; i<goombas.size(); i++)
                    goombas[i].update(deltaTime);

                //Colisoes

                //colisao objetos-plataformas
                for(int i =0; i<platforms.size(); i++)
                {
                    if(mario.getCollider().checkCollision(platforms[i].getCollider(), direction, 0.0f))
                        mario.onCollision(direction);
                    for(int j = 0; j<smushrooms.size(); j++)
                        if(smushrooms[j].getCollider().checkCollision(platforms[i].getCollider(), direction, 0.0f))
                            smushrooms[j].onCollision(direction);
                    for(int j = 0; j<goombas.size(); j++)
                        if(goombas[j].getCollider().checkCollision(platforms[i].getCollider(), direction, 0.0f))
                            goombas[j].onCollision(direction);
                }

                //colisao mario-moedas
                for( int i =0; i<coins.size(); i++)
                {
                    if(mario.getCollider().checkCollision(coins[i].getCollider(), direction, 0.0f))
                    {
                        coins.erase(coins.begin()+i);
                        sound.playSound("coin");
                        pontuacao++;
                    }
                }

                //colisao mario-cogumelos
                for(int i = 0; i<smushrooms.size(); i++)
                {
                    if(mario.getCollider().checkCollision(smushrooms[i].getCollider(), direction, 0.0f))
                    {
                        smushrooms[i].onCollisionPlayer(mario);
                        pontuacao+=100;
                        smushrooms.erase(smushrooms.begin()+i);
                    }
                }

                //colisao mario-goombas
                for(int i = 0; i<goombas.size(); i++)
                {
                    if(mario.getCollider().checkCollision(goombas[i].getCollider(), direction, 0.0f))
                    {
                        if(goombas[i].onCollisionPlayer(sf::Vector2f(-1*direction.x, -1*direction.y), mario))
                        {
                            pontuacao+=150;
                            goombas.erase(goombas.begin()+i);

                        }
                        else if(direction.y==0)
                        {
                            if(direction.x ==1 || direction.x == -1)
                            {

                                if(!mario.getBigMario())
                                {
                                    vidas--;
                                    sound.playSound("death");
                                    mario.setPosition(sf::Vector2f(5.0f, 300.0f));
                                }
                                else
                                {

                                    mario.setBigMario(false);
                                    mario.setScale(0.83,0.83);
                                    goombas[i].setPosition(sf::Vector2f(mario.getPosition().x+64, mario.getPosition().y));
                                    goombas[i].bounce();

                                }
                            }

                        }

                    }
                }

                //colisao mario-question blocks cogumelos-questionblocks e goombas-questionblocks
                for(int i = 0; i<questionBlocks.size(); i++)
                {
                    if(mario.getCollider().checkCollision(questionBlocks[i].getCollider(), direction, 0.0f))
                    {
                        mario.onCollision(direction);
                        if(questionBlocks[i].getActivate() && questionBlocks[i].onCollision(sf::Vector2f(-1*direction.x, -1*direction.y)))
                            smushrooms.push_back(SuperMushroom(sf::Vector2f(questionBlocks[i].getPosition().x, questionBlocks[i].getPosition().y-32), 50, sMushroomTexture));


                    }
                    for(int j = 0; j<smushrooms.size(); j++)
                        if(smushrooms[j].getCollider().checkCollision(questionBlocks[i].getCollider(), direction, 0.0f))
                            smushrooms[j].onCollision(direction);
                    for(int j = 0; j<goombas.size(); j++)
                        if(goombas[j].getCollider().checkCollision(questionBlocks[i].getCollider(), direction, 0.0f))
                            goombas[j].onCollision(direction);
                }

                //colisao mario-normal blocks  cogumelos-normal blocks e goombas-normal blocks
                for(int i = 0; i<nblocks.size(); i++)
                {
                    if(mario.getCollider().checkCollision(nblocks[i].getCollider(), direction, 0.0f))
                    {
                        mario.onCollision(direction);
                        if(nblocks[i].onCollision(sf::Vector2f(-1*direction.x, -1*direction.y), mario))
                            nblocks.erase(nblocks.begin()+i);
                    }
                    for(int j = 0; j<smushrooms.size(); j++)
                        if(smushrooms[j].getCollider().checkCollision(nblocks[i].getCollider(), direction, 0.0f))
                            smushrooms[j].onCollision(direction);
                    for(int j = 0; j<goombas.size(); j++)
                        if(goombas[j].getCollider().checkCollision(nblocks[i].getCollider(), direction, 0.0f))
                            goombas[j].onCollision(direction);
                }


                //Controle de queda do cenario
                if(mario.getPosition().y > 600)
                {
                    sound.playSound("death");
                    vidas--;
                    if(vidas>0)
                    {
                        mario.setPosition(sf::Vector2f(5.0f, 300.0f));
                        if(mario.getBigMario())
                        {
                            mario.setBigMario(false);
                            mario.setScale(0.83,0.83);
                        }

                    }
                }
                //Verifica se as vidas acabaram
                if(vidas<=0)
                {
                    inMenu = true;
                    game.close();
                    break;
                }

                //controle da view
                view.setCenter((int)mario.getPosition().x, 300);
                game.setView(view);

                //draw
                game.clear(sf::Color::Blue);
                for( int i =0; i<platforms.size(); i++)
                    platforms[i].draw(game);
                for( int i =0; i<coins.size(); i++)
                    coins[i].draw(game);
                for(int i =0; i<questionBlocks.size(); i++)
                    questionBlocks[i].draw(game);
                for(int i =0; i<nblocks.size(); i++)
                    nblocks[i].draw(game);
                for(int i =0; i<goombas.size(); i++)
                    goombas[i].draw(game);
                for( int i =0; i<smushrooms.size(); i++)
                    smushrooms[i].draw(game);
                mario.draw(game);
                hud.draw(game);
                game.display();
            }
        }
    }
    return 0;
}
