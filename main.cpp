#include <cmath>

//Open GL libs
#include <GL/gl.h>
#include <GL/glut.h>

struct asteroid {
    float radius;
    GLFloat color;
};

void drawAsteroid() {

}


void display() {

}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Gravity Sim");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

