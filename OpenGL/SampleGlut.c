#include <GL\glut.h>

#pragma comment(a,"libfreeglut.a")

int windowWidth=800;
int windowHeight=800;

void init()
{}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(0.0,1.0,0.0);
    glEnd();

    glutSwapBuffers();
}


int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowWidth,windowHeight);
    glutCreateWindow("GLUT Sample");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
}