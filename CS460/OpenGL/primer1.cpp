#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

//    glBegin(GL_POLYGON);
//        glVertex2f(-0.5, -0.5);
//        glVertex2f(-0.5, 0.5);
//        glVertex2f(0.5, 0.5);
//        glVertex2f(0.5, -0.5);
//    glEnd();

//    glBegin(GL_POINTS);
//        glColor3f(1.0,1.0,1.0);
//        glVertex2f(-0.5, -0.5);
//        glColor3f(1.0,0.0,0.0);
//        glVertex2f(-0.5, 0.5);
//        glColor3f(0.0,0.0,1.0);
//        glVertex2f(0.5, 0.5);
//        glColor3f(0.0,1.0,0.0);
//        glVertex2f(0.5, -0.5);
//    glEnd();

//    glBegin(GL_LINES);
//        glVertex2f(-0.5, -0.5);
//        glVertex2f(-0.5, 0.5);
//        glVertex2f(0.5, 0.5);
//        glVertex2f(0.5, -0.5);
//    glEnd();

//    glBegin(GL_LINE_STRIP);
//        glVertex2f(-0.5, -0.5);
//        glVertex2f(-0.5, 0.5);
//        glVertex2f(0.5, 0.5);
//        glVertex2f(0.5, -0.5);
//    glEnd();

    glBegin(GL_LINE_LOOP);

        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();


    glFlush();

}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);

    glColor3f(1.0,1.0,1.0);

    glEnable(GL_LINE_STIPPLE);
    glColor3f(1.0,1.0,0.0);
    glLineWidth(2.0);
    glLineStipple(3, 0xcccc);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Primer1");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}
