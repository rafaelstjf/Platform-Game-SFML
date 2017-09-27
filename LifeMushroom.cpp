#include "LifeMushroom.h"

LifeMushroom::LifeMushroom(sf::Vector2f posicaoInicial){
    direita = false;
    textura.loadFromFile("Texturas/General/Life.png");
    imageCount = {1,1};
    tempoTroca = 0.3f;
    velocidade = 100;
    const sf::Texture *pTexture = &textura;   
    corpo.setTexture(pTexture);    
    corpo.setSize(sf::Vector2f(32.0f,32.0f));
    //corpo.setScale(2,2);
    corpo.setPosition(posicaoInicial);
    noChao = false;
}
LifeMushroom::~LifeMushroom(){

}
void LifeMushroom::desenha(sf::RenderWindow &window){
    window.draw(corpo);
}
void LifeMushroom::atualiza(float deltaTime){
    sf::Vector2f movimento(0.0f, 0.0f);
    sf::Vector2f gravidade(0.0f, 80.0f);    
   if(corpo.getPosition().x > 0.0 && !direita)
    {
     movimento.x -= velocidade*deltaTime;
    }else if(corpo.getPosition().x<=0.0){
        movimento.x += velocidade*deltaTime;
        direita = true;
    }else if(corpo.getPosition().x > 0 && direita && corpo.getPosition().x < 800.0)
        movimento.x += velocidade*deltaTime;
    else if( corpo.getPosition().x >= 800.0){
        direita = false;        
        movimento.x -= velocidade*deltaTime;
        
    }
    if(!noChao){
        
                //movimento.y+=gravidade.y*deltaTime;
            }
    /*if(corpo.getPosition().x+movimento.x > 0 && ){
        movimento.x += velocidade*deltaTime;
        direita = false;        
    }*/
    corpo.move(movimento);    
}
sf::Rect<float> LifeMushroom::getGlobalBounds(){
    return corpo.getGlobalBounds();
}