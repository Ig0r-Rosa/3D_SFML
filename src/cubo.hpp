#ifndef D5ABEFE4_24B8_4468_A902_A19520BC5F3E
#define D5ABEFE4_24B8_4468_A902_A19520BC5F3E

void inicializaOpenGL()
{
    // Configurações do OpenGL
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, 800.0 / 600.0, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCube()
{
    glBegin(GL_QUADS);
    // Frente
    glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // Trás
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Topo
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Base
    glColor3f(1.0f, 1.0f, 0.0f); // Amarelo
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // Direita
    glColor3f(1.0f, 0.0f, 1.0f); // Roxo
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);

    // Esquerda
    glColor3f(0.0f, 1.0f, 1.0f); // Ciano
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();
}

#endif /* D5ABEFE4_24B8_4468_A902_A19520BC5F3E */
