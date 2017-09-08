#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jogador.h"

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
void anda(Jogador &jogador);
int main()
{
    Jogador jogador({32, 32});

    //Cria a janela
    sf::RenderWindow janela;
    janela.create(sf::VideoMode(800, 600), "Janela", sf::Style::Titlebar | sf::Style::Close);
    // janela.setPosition({100, 100});

    //executa uma sequencia de eventos enquanto a janela está aberta
    while (janela.isOpen())
    {
        sf::Event evento;
        anda(jogador);
        while (janela.pollEvent(evento))
        {
            switch (evento.type)
            {
            //fecha a janela
            case sf::Event::Closed:
                janela.close();
            }
        }
        janela.clear();

        jogador.desenha(janela);
        janela.display();
    }
    return 0;
}

void anda(Jogador &jogador)
{
    const float movespeed = 0.1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        jogador.move({movespeed, 0});
        jogador.atFrame(1);
        jogador.atFrame(2);
        jogador.atFrame(3);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        jogador.transforma(90);
        jogador.move({-movespeed, 0});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        jogador.move({0, -movespeed});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        jogador.move({0, movespeed});
    }else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        jogador.atFrame(0);
        
    }
}
