/*
  Name:        main.cpp
  Author:      Rafael de Souza Terra & Rodrigo Coelho Villa Verde
  Release:     29/08/2013
  Description: Sistema de Colisao 2D
*/
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;
//Variaveis globais
int width = 800;
int height = 600;
int matriz[19][25];
float mousex, mousey; //posicao do jogador e do mouse
fstream arquivo;
bool mouseDown = false;
int corAtual = 0;
//funcoes
void idle();
void display();
void init();
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void desenhaMatriz();
void motion(int x, int y);

int main(int argc, char **argv)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 25; j++)
            matriz[i][j] = 0;
    }
    cout << "Comandos: \n o - Abrir arquivo para leitura \n s - Salvar em arquivo \n r - reseta \n esc - Sair " << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Desenvolvimento 1");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

void desenhaMatriz()
{
    for (int i = 0; i < 19; i++)
    {
        for (int k = 0; k < 25; k++)
        {
            if (matriz[i][k] == 6)
                glColor3f(1.0, 0.5, 0.5); //vermelho para teste
            if (matriz[i][k] == 13)
                glColor3f(0.0, 0.70, 0.0);
            if (matriz[i][k] == 14)
                glColor3f(0.0, 0.70, 0.0);
            if (matriz[i][k] == 24)
                glColor3f(0.0, 0.60, 0.0);
            if (matriz[i][k] == 25)
                glColor3f(0.0, 0.65, 0.0);
            if (matriz[i][k] == 36)
                glColor3f(0.0, 0.40, 0.0);
            if (matriz[i][k] == 37)
                glColor3f(0.0, 0.40, 0.0);
            if (matriz[i][k] == 96)
                glColor3f(.50, .50, 0.0);
            if (matriz[i][k] == 97)
                glColor3f(.60, .60, 0.0);
            if (matriz[i][k] == 98)
                glColor3f(.40, .40, 0.0);
            if (matriz[i][k] == 109)
                glColor3f(.40, .40, 1.0);
            if (matriz[i][k] == 110)
                glColor3f(.40, .40, 1.0);
            if (matriz[i][k] == 111)
                glColor3f(.40, .40, 1.0);
            if (matriz[i][k] <= 0)
                glColor3f(1.0, 1.0, 1.0);
            //vermelho para teste
            glBegin(GL_QUADS);
            glVertex2f(k * 32, i * 32);
            glVertex2f(k * 32 + 32, i * 32);
            glVertex2f(k * 32 + 32, i * 32 + 32);
            glVertex2f(k * 32, i * 32 + 32);

            glEnd();
        }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    desenhaMatriz();
    glutSwapBuffers();
}
void init()
{
    glClearColor(0.7, 0.7, 0.7, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800.0, 600.0, 0.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y)
{
    string linha;
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'o':
        cout << "Abrindo arquivo!" << endl;
        arquivo.open("tileMap.txt", fstream::in);
        if (arquivo.is_open())
        {
            for (int i = 0; i < 19; i++)
            {
                for (int k = 0; k < 25; k++)
                {
                    getline(arquivo, linha, ',');
                    matriz[i][k] = atoi(linha.c_str());
                }
            }
            arquivo.close();
        }
        break;
    case 's':
        cout << "Salvando o arquivo!" << endl;
        arquivo.open("tileMap.txt", fstream::out | fstream::trunc);
        if (arquivo.is_open())
        {
            for (int i = 0; i < 19; i++)
            {
                for (int k = 0; k < 25; k++)
                    arquivo << matriz[i][k] << ',';
                arquivo << endl;
            }
            arquivo.close();
        }
        break;
    case 'r':
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 25; j++)
                matriz[i][j] = 0;
        }
        break;
    }
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN) //botao esquerdo do mouse pressionado
        {
            if (matriz[y / 32][(int)(x / 32)] <= 0)
                matriz[y / 32][(int)(x / 32)] = 6;
            else if (matriz[y / 32][(int)(x / 32)] == 6)
                matriz[y / 32][(int)(x / 32)] = 13;
            else if (matriz[y / 32][(int)(x / 32)] == 13)
                matriz[y / 32][(int)(x / 32)] = 14;
            else if (matriz[y / 32][(int)(x / 32)] == 14)
                matriz[y / 32][(int)(x / 32)] = 24;
            else if (matriz[y / 32][(int)(x / 32)] == 24)
                matriz[y / 32][(int)(x / 32)] = 25;
            else if (matriz[y / 32][(int)(x / 32)] == 25)
                matriz[y / 32][(int)(x / 32)] = 36;
            else if (matriz[y / 32][(int)(x / 32)] == 36)
                matriz[y / 32][(int)(x / 32)] = 37;
            else if (matriz[y / 32][(int)(x / 32)] == 37)
                matriz[y / 32][(int)(x / 32)] = 96;
            else if (matriz[y / 32][(int)(x / 32)] == 96)
                matriz[y / 32][(int)(x / 32)] = 97;
            else if (matriz[y / 32][(int)(x / 32)] == 97)
                matriz[y / 32][(int)(x / 32)] = 98;
            else if (matriz[y / 32][(int)(x / 32)] == 98)
                matriz[y / 32][(int)(x / 32)] = 109;
            else if (matriz[y / 32][(int)(x / 32)] == 109)
                matriz[y / 32][(int)(x / 32)] = 110;
            else if (matriz[y / 32][(int)(x / 32)] == 110)
                matriz[y / 32][(int)(x / 32)] = 111;
            else if (matriz[y / 32][(int)(x / 32)] == 111)
                matriz[y / 32][(int)(x / 32)] = 0;
            corAtual = matriz[y / 32][(int)(x / 32)];
            mouseDown = true;
        }
        else
            mouseDown = false;
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
        { //botao esquerdo do mouse pressionado
            matriz[y / 32][(int)(x / 32)] = 0;
            corAtual = matriz[y / 32][(int)(x / 32)];
            mouseDown = true;
        }
        else
            mouseDown = false;
    }
}
void motion(int x, int y)
{
    if (mouseDown)
    {
        matriz[y / 32][(int)(x / 32)] = corAtual;
    }
}

void idle()
{
    glutPostRedisplay();
}
