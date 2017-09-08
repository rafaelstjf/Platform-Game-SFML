#include "Jogador.h"

Jogador::Jogador(sf::Vector2f tamanho)
{
    string caminho = "Texturas/Jogador/";
    string extensao = ".png";
    //jogador.setSize({32, 32}); //cria o retangulo do tamanho desejado
    /*if (!textura.loadFromFile("Texturas/idle.png"))
        cout << "Erro ao carregar textura!" << endl;
        */
    for (int i = 0; i < 4; i++)
    {
        textura[i].loadFromFile( caminho+ to_string(i) + extensao);
    }
    jogador.setTexture(textura[0]);
    jogador.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
Jogador::~Jogador()
{
}

void Jogador::desenha(sf::RenderWindow &window)
//desenha o jogador na janela passada como referencia
{
    window.draw(jogador);
}
void Jogador::move(sf::Vector2f distancia)
// move o jogador até as coordenadas do vetor
{
    jogador.move(distancia);
}
void Jogador::setPos(sf::Vector2f posicao)
//coloca o jogador na posicao das coordenadas do vetor
{
    jogador.setPosition(posicao);
}
void Jogador::atFrame(int ind)
{
    jogador.setTexture(textura[ind]);
}
double Jogador::getRotacao(){
    return jogador.getRotation();
}
void Jogador::transforma(double val){
    jogador.transform(val);
}