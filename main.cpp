#include <string>
#include <iostream>
#include <vector>
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

using namespace std;

static const string coinTPath = "Textures/General/Coin.png";
static const string sMushroomTPath = "Textures/General/SuperMushroom.png";
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
    //Inicializa as variaveis
    float deltaTime = 0.0f;
    sf::Music menuMusic;
    menuMusic.openFromFile("Audio/menu.ogg");
    bool gameOpen = true;
    bool inMenu = true;
    sf::Clock clock;
    sf::Vector2f direction;
    int pontuacao = 0;
    int vidas = 0;
    //Cria a window e a view
    sf::RenderWindow game;
    sf::RenderWindow menu;
    sf::Font font;
    font.loadFromFile("Extra/font.ttf");
    //Carrega a textura de alguns objetos
    sf::Texture coinTexture;
    coinTexture.loadFromFile(coinTPath);
    sf::Texture sMushroomTexture;
    sMushroomTexture.loadFromFile(sMushroomTPath);


    //Inicializa os objetos
    Player mario(100.0f, switchTime, 100, sf::Vector2f(50.0f,50.0f));
    SuperMushroom m(sf::Vector2f(28.0f, 50.0f), 1, sMushroomTexture);
    Coin c(sf::Vector2f(10.0f, 50.0f), switchTime, coinTexture);
    vector <Coin> coins;
    for( int i =0; i<10; i++)
    {
        coins.push_back(Coin(sf::Vector2f(float(82.0 + 33.0*i), 50.0f), switchTime, coinTexture));
    }
    Platform p1(sf::Vector2f(1600.0f,32.0f), sf::Vector2f(0,600-16));


    //executa uma sequencia de eventos enquanto a janela esta aberta
    while(gameOpen)
    {
        if(inMenu)
        {
            menu.create(sf::VideoMode(800,600), "Menu", sf::Style::Titlebar | sf::Style::Close);
            sf::Texture logoT;
            logoT.loadFromFile("Textures/General/logo.png");
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
                if(menuMusic.getStatus()==sf::Music::Stopped)
                    menuMusic.play();
                sf::Event evento;
                deltaTime = clock.restart().asSeconds();
                if (deltaTime > 1.0f / 20.f)
                    deltaTime = 1.0f / 20.0f;
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
                            menuMusic.stop();
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
            //Controle do jogo
            game.create(sf::VideoMode(800, 600), "Janela", sf::Style::Titlebar | sf::Style::Close);
            sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));
            while (game.isOpen())
            {
                sf::Event evento;
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
                //update
                mario.update(deltaTime, game);
                m.update(deltaTime);
                for( int i =0; i<10; i++)
                    coins[i].update(deltaTime);

                //Colisao
                if(p1.getCollider().checkCollision(mario.getCollider(), direction, 1.0f))
                {
                    mario.onCollision(direction);
                    cout << direction.x << " " << direction.y << endl;
                }
                if(m.getCollider().checkCollision(p1.getCollider(), direction, 1.0f))
                    m.onCollision(direction);
                //controle da view
                view.setCenter((int)mario.getPosition().x, 300);
                game.setView(view);
                //draw
                game.clear(sf::Color::Blue);
                p1.draw(game);
                for( int i =0; i<10; i++)
                    coins[i].draw(game);
                mario.draw(game);
                m.draw(game);
                game.display();
            }
        }
    }
    return 0;
}
