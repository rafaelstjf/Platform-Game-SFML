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
#include "Background.h"
#include "Coin.h"

using namespace std;

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
    sf::Clock clock;

    //Cria a window e a view
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Janela", sf::Style::Titlebar | sf::Style::Close);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

    //Inicializa os objetos
    //(float speed, float switchTime, float jumpHeight, sf::Vector2f initPosition)
    Player mario(100.0f, switchTime, 100, sf::Vector2f(50.0f,50.0f));
    SuperMushroom m(sf::Vector2f(28.0f, 50.0f), 1);
    Coin c(sf::Vector2f(10.0f, 50.0f), switchTime);
    vector <Coin> coins;
    for( int i =0; i<10; i++){
        coins.push_back(Coin(sf::Vector2f(float(82.0 + 32.0*i), 50.0f), switchTime));
    }
    //Background backg;
   // backg.loadTileset();

    //executa uma sequencia de eventos enquanto a window esta aberta
    while (window.isOpen())
    {
        sf::Event evento;
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.f)
            deltaTime = 1.0f / 20.0f;
        while (window.pollEvent(evento))
        {
            switch (evento.type)
            {
            //fecha a window
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyReleased:
                break;
            case sf::Event::Resized:
                resizeWindow(window, view);
                break;
            }
        }
        //update
        mario.update(deltaTime, window);
        for( int i =0; i<10; i++)
            coins[i].update(deltaTime);
        c.update(deltaTime);
        //controle da view
        view.setCenter(mario.getPosition());
        window.setView(view);

        //draw
        window.clear();
       // backg.draw(window);
            for( int i =0; i<10; i++)
                coins[i].draw(window);
        c.draw(window);
        m.draw(window);
        mario.draw(window);
        window.display();
    }
    return 0;
}
