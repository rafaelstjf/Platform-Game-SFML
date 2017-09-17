#include "Jogador.h"

Jogador::Jogador(sf::Texture &textura, sf::Vector2u imageCount, float velocidade, float tempoTroca):
animation(textura, imageCount, tempoTroca)
{
    this->velocidade = velocidade;
    linha = 0;
    direita = true;
    corpo.setSize(sf::Vector2f(100.0, 100.0));
    corpo.setPosition(50.0, 50.0);
    corpo.setTexture(textura);
}
Jogador::~Jogador()
{
}

void Jogador::desenha(sf::RenderWindow &window)
//desenha o jogador na janela passada como referencia
{
    window.draw(jogador);
}
void Jogador::atualiza(float deltaTime)
{
    sf::Vector2f movimento(0.0f, 0.0f); //vetor de movimento do player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movimento.x += velocidade * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movimento.x -= velocidade * deltaTime;
    if (movement.x == 0)
        row = 0; //animacao de idle
    else
    {
        if (movimento.x > 0)
            direita = true;
        else
            direita = false;
    }
    animation.update(linha, deltaTime, direita);
    corpo.setTextureRect(animation.uvRect);
    corpo.move(movimento);
}