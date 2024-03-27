#include <GL/glut.h>
#include <math.h>
#include "./headers/lighting.h"
#include "./headers/generateTeapot.h"
#include <stdio.h>
#include <stdbool.h>

int viewportWidth = 400;
int viewportHeight = 400;

float teapotTetha = 0.0;

int init() {
    glClearColor(0.9f, 0.8f, 0.7f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0); 

    lighting();
}

void update(int value) {

    teapotTetha += 5;
    glutPostRedisplay();
    glutTimerFunc(32, update, 0);  
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);    

    glViewport(0, viewportHeight/2, viewportWidth / 2, viewportHeight / 2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 2.5, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(teapotTetha, 0.0, 1.0, 0.0);
    displayTeapot();
    glPopMatrix();

    glViewport(0, 0, viewportWidth / 2, viewportHeight / 2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    displayTeapot();

    glViewport(viewportWidth / 2, 0, viewportWidth / 2, viewportHeight / 2);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, -1.0);
    glPushMatrix();
    displayTeapot();
    glPopMatrix();

    glViewport(viewportWidth / 2, viewportHeight / 2, viewportWidth / 2, viewportHeight / 2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, -5.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, 1.0);
    glPushMatrix();
    glRotatef(teapotTetha, 0.0, 1.0, 0.0);
    displayTeapot();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200,0);
    glutInitWindowSize(400,400);
    glutCreateWindow("Projeto de Computação Gráfica");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);  
    glutMainLoop();
    return 0; 
}