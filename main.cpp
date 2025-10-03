#include <cmath>

//OpenGL libs
#include <GL/glut.h>


struct Asteroid {
    double radius;
    float angle;
};

Asteroid bodies[1];

void drawAsteroid(const Asteroid& a) {
    int n = 20;
    
    glPushMatrix();
    glRotatef(a.angle, 1.0, 0, 0);
    glRotatef(a.angle, 0, 1.0, 0);
    glScalef(a.radius, a.radius, a.radius);
    glColor3f(220.0f/255.0f, 20.0f/255.0f, 60.0f/255.0f);
    
    for(int i=0; i<2*n; i++) {
        for(int j=0; j<n; j++) {
            double x1 = sin(i * M_PI / n) * sin(j * M_PI / n);
            double y1 = cos(i * M_PI / n) * sin(j * M_PI / n);
            double z1 = cos(j * M_PI / n);

            double x2 = sin((i + 1) * M_PI / n) * sin(j * M_PI / n);
            double y2 = cos((i + 1) * M_PI / n) * sin(j * M_PI / n);
            double z2 = cos(j * M_PI / n);

            double x3 = sin((i + 1) * M_PI / n) * sin((j + 1) * M_PI / n);
            double y3 = cos((i + 1) * M_PI / n) * sin((j + 1) * M_PI / n);
            double z3 = cos((j + 1) * M_PI / n);

            double x4 = sin(i * M_PI / n) * sin((j + 1) * M_PI / n);
            double y4 = cos(i * M_PI / n) * sin((j + 1) * M_PI / n);
            double z4 = cos((j + 1) * M_PI / n);
            
            glBegin(GL_POLYGON);
                glVertex3d(x1, y1, z1);
                glVertex3d(x2, y2, z2);
                glVertex3d(x3, y3, z3);
                glVertex3d(x4, y4, z4);
            glEnd();
        }
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Asteroid test{2.0, 60.0};
    bodies[0] = test;

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawAsteroid(bodies[0]);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glFlush();
}

void idle() {
    bodies[0].angle += 0.2f;
    if (bodies[0].angle > 360.0f) bodies[0].angle -= 360.0f;
    glutPostRedisplay();
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 800.0/600.0, 1.0, 100.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5, 0,0,0, 0,1,0); 
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Gravity Sim");
    glEnable(GL_DEPTH_TEST);
    
    initGL();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
