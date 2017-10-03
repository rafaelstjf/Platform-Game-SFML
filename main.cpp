#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jogador.h"
#include "LifeMushroom.h"
#include "Flower.h"
#include "Background.h"

using namespace std;
sf::Text drawText(string str, sf::Font font, int size, int x, int y, int t)
{

    sf::Text text(str.c_str(), font);
    text.setCharacterSize(size);
    text.setColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(x, y);
    text.setRotation(t);
    return text;
}
int main()
{
    //Inicializa as variaveis
    float deltaTime = 0.0f;
    sf::Clock clock;
    //Carrega as texturas
    //sf::View view1(sf::FloatRect(200, 200, 300, 200));
    //Cria a janela
    sf::RenderWindow janela;
    janela.create(sf::VideoMode(800, 600), "Janela", sf::Style::Titlebar | sf::Style::Close);
    // janela.setPosition({100, 100});

    //Inicializa os objetos
    Jogador jogador(100.0f, 0.1f);
    LifeMushroom monster({100.0, 100.0});
    Flower flor({190.0, 100.0});
    Background backg;
    backg.loadTileset();
    //executa uma sequencia de eventos enquanto a janela est� aberta
    while (janela.isOpen())
    {
        sf::Event evento;
        deltaTime = clock.restart().asSeconds();
        while (janela.pollEvent(evento))
        {
            switch (evento.type)
            {
            //fecha a janela
            case sf::Event::Closed:
                janela.close();
                break;

            case sf::Event::KeyReleased:
                jogador.setPulo(false);
                break;
            }
        }
        //Colisao Cogumelo
        if (jogador.getGlobalBounds().intersects(monster.getGlobalBounds()))
            jogador.setBigMario(true);
        if (jogador.getGlobalBounds().intersects(flor.getGlobalBounds()))
            jogador.setFireMario(true);
        jogador.atualiza(deltaTime, janela);
        monster.atualiza(deltaTime);
        janela.clear();
        // backg.desenha(janela);
        monster.desenha(janela);
        jogador.desenha(janela);
        flor.desenha(janela);
        janela.display();
    }
    return 0;
}
