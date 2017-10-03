#include "Background.h"
Background::Background()
{
    texSky.loadFromFile("Texturas/Backgrounds/Sky.png");
    const sf::Texture *tSky = &texSky;
    sky.setSize(sf::Vector2f(800.0f, 600.0f));
    sf::IntRect r(0, 0, 800, 600);
    texSky.setRepeated(true);
    texSky.setSmooth(true);
    sky.setTexture(tSky);
    sky.setTextureRect(r);
}
void Background::loadTileset()
{
    int height = 600, width = 800;
    string linha;
    fstream arquivo;
    //Aloca a matriz com o mapa das texturas
    //Carrega o mapa de texturas
    arquivo.open("Texturas/Backgrounds/tileMap.txt", fstream::in);
    if (arquivo.is_open())
    {
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                getline(arquivo, linha, ',');
                tiles[(i + j * 25)] = atoi(linha.c_str());
            }
        }
    }
    m_tileset.loadFromFile("Texturas/Backgrounds/Tileset.png");
    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(25 * 19 * 4);

    // populate the vertex array, with one quad per tile
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            // get the current tile number
           // int tileNumber = tiles[i][j];

            // find its position in the tileset texture
          //  int tu = 0;
           // int tv = 0;

            // get a pointer to the current tile's quad
            sf::Vertex *quad = &m_vertices[(i + j * 25) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
           /* quad[0].texCoords = sf::Vector2f(tu * m_tileset.getSize().x / 12, tv * m_tileset.getSize().y / 12);
            quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileset.getSize().x / 12, tv * m_tileset.getSize().y / 12);
            quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileset.getSize().x / 12, (tv + 1) * m_tileset.getSize().y / 12);
            quad[3].texCoords = sf::Vector2f(tu * m_tileset.getSize().x / 12, (tv + 1) * m_tileset.getSize().y / 12);
        
            quad[0].texCoords = sf::Vector2f({0,0});
            quad[1].texCoords = sf::Vector2f({32,0});
            quad[2].texCoords = sf::Vector2f({32,32});
            quad[3].texCoords = sf::Vector2f({0,32});
        */
        }
    }
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < width / tileSize.x; j++)
        {
            cout << tiles[i][j] << " ";
        }
        cout << endl;
    }
}

Background::~Background()
{
}

void Background::desenha(sf::RenderWindow &janela)
{
    janela.draw(sky);
    janela.draw(m_vertices);
}