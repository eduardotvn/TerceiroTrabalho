#include <GL/glut.h>

void displayTeapot() {
    glFrontFace(GL_CW);
    GLfloat teapot_ambient[] = {0.0, 0.1, 0.1, 1.0};
    GLfloat teapot_diffuse[] = {0.0, 0.5, 0.5, 1.0};
    GLfloat teapot_specular[] = {0.4, 0.4, 0.4, 1.0};
    GLfloat teapot_shininess[] = {10.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, teapot_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapot_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapot_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapot_shininess);


    glutSolidTeapot(1.0);

    glFrontFace(GL_CCW);
}