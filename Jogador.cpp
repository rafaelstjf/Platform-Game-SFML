#include "Jogador.h"

Jogador::Jogador(float velocidade, float tempoTroca)
{
    this->velocidade = velocidade;
    this->tempoTroca = tempoTroca;
    direita = true;
    sMario.loadFromFile("Texturas/Player/sMario.png");
    bMario.loadFromFile("Texturas/Player/bMario.png");
    const sf::Texture *pTexture = &sMario;
    corpo.setSize(sf::Vector2f(32.0, 32.0));
    //corpo.setScale(2, 2);
    corpo.setPosition(50.0, 150.0);
    corpo.setTexture(pTexture);
    flower = false;
    marioBig = false;
    noChao = true;
    linha = 0;
    anBigMario = PlayerAnimation(bMario, bMarioCount, tempoTroca);
    anSmallMario = PlayerAnimation(sMario, sMarioCount, tempoTroca);
}
Jogador::~Jogador()
{
}

void Jogador::desenha(sf::RenderWindow &window)
//desenha o jogador na janela passada como referencia
{
    window.draw(corpo);
}
void Jogador::atualiza(float deltaTime, sf::RenderWindow &window)
{
    sf::Vector2f gravidade(0.0f, 80.0f);
    idle = false;
    sf::Vector2f movimento(0.0f, 0.0f); //vetor de movimento do player
    if (marioBig)
    {

        const sf::Texture *pTexture = &bMario;
        corpo.setTexture(pTexture);
        if (flower)
            linha = 2;
        else
            linha = 0;
    }
    else
    {
        const sf::Texture *pTexture = &sMario;
        corpo.setTexture(pTexture);
        linha = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movimento.x += velocidade * deltaTime;
        direita = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movimento.x -= velocidade * deltaTime;
        direita = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movimento.x -= 2 * velocidade * deltaTime;
        direita = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
         movimento.y -= velocidade * deltaTime;
         noChao = false;

        if (marioBig)
        {
            if (flower)
                linha = 3;
            else
                linha = 1;
        }
        else
            linha = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        flower = !flower;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        marioBig = !marioBig;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movimento.x += 2 * velocidade * deltaTime;
        direita = true;
    }
    if (movimento.x == 0)
    {
        direita = true;
        idle = true;
    }
    if (!noChao && corpo.getPosition().y < 400)
    {

        movimento.y += gravidade.y * deltaTime;
    }
    if (marioBig)
    {
        anBigMario.update(linha, deltaTime, direita, idle);
        corpo.setTextureRect(anBigMario.uvRect);
    }
    else
    {
        anSmallMario.update(linha, deltaTime, direita, idle);
        corpo.setTextureRect(anSmallMario.uvRect);
    }
    corpo.move(movimento);
}
sf::Rect<float> Jogador::getGlobalBounds()
{
    return corpo.getGlobalBounds();
}
void Jogador::setBigMario(bool marioBig)
{
    this->marioBig = marioBig;
}
void Jogador::setFireMario(bool flower)
{
    this->flower = flower;
}
void Jogador::setPulo(bool noChao)
{
    this->noChao = noChao;
}