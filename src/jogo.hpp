#ifndef F3F4E2AE_EF7C_4ED9_8E06_896FEA969271
#define F3F4E2AE_EF7C_4ED9_8E06_896FEA969271 

#ifndef INCLUDES
#define INCLUDES

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string> 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>

#endif
// Includes
#include "cubo.hpp"

// Indica a função para utiliza-la antes de seu corpo
void aplicarLetterbox(int windowWidth, int windowHeight);

// Variaveis //
// Window
sf::ContextSettings settings;
sf::RenderWindow window;
sf::VideoMode desktopMode;
float aspectRatio;
unsigned int screenWidth;
unsigned int screenHeight;
bool isCursorVisible;

// Jogo
sf::View basicView;
float rotationX = 0.0f, rotationY = 0.0f;

int setupJogo()
{
    isCursorVisible = false;

    basicView = sf::View(sf::FloatRect(0, 0, screenWidth, screenHeight));

    inicializaOpenGL();

    return 0;
}

void eventosJogo()
{
    // Eventos
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close(); 
        }

        // Detecta redimensionamento da janela
        if (event.type == sf::Event::Resized)
        {
            // Aplicar "letterbox" para manter a proporção
            aplicarLetterbox(event.size.width, event.size.height);
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Period)
            {
                isCursorVisible = !isCursorVisible;
                window.setMouseCursorVisible(isCursorVisible);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                rotationY -= 1.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                rotationY += 1.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rotationX -= 1.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rotationX += 1.0f;
        }
    }
}

void desenhaJogo()
{
    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Desenha o cubo
    drawCube();

    // Troca o buffer
    window.display();
}

void loopJogo()
{
    // Eventos
    eventosJogo();

    // Atualiza a rotação do cubo
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

    // Desenha
    desenhaJogo();
}

// Fecha o jogo
int fechaJogo()
{
    // Deleta ponteiros

    return 0;
}

// Função para manter a proporção da view com "letterboxing"
void aplicarLetterbox(int windowWidth, int windowHeight)
{
    sf::View view(sf::FloatRect(0, 0, 1280, 720));
    float windowRatio = (float)windowWidth / (float)windowHeight;
    float viewRatio = view.getSize().x / view.getSize().y;
    float sizeX = 1.0f;
    float sizeY = 1.0f;
    float posX = 0.0f;
    float posY = 0.0f;

    if (windowRatio > viewRatio)
    {
        sizeX = viewRatio / windowRatio;
        posX = (1.0f - sizeX) / 2.0f;
    }
    else
    {
        sizeY = windowRatio / viewRatio;
        posY = (1.0f - sizeY) / 2.0f;
    }

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
}


#endif /* F3F4E2AE_EF7C_4ED9_8E06_896FEA969271 */
