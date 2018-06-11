#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw something ...
    glColor3f(0.5f, 1.0f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glutSwapBuffers();

}

static void keyboard(unsigned char key, int x, int y) {
    if(key == 'q') {
        printf("pressed %c key\n", key);
        exit(0);
    }
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(512,512);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // create a window with an OpenGL context
    glutCreateWindow("Glut Test");


    printf("OpenGL version = %s\n", glGetString(GL_VERSION));

    // Initialize GLEW
    GLenum err = glewInit();
    if(GLEW_OK != err) {
            printf("Error in GLEW initialization = %s\n", glewGetErrorString(err));
    }
    printf("Glew version = %s\n", glewGetString(GLEW_VERSION));

    // Register GLUT callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glClearColor(1.0, 0.0, 0.0, 1.0);

    glutMainLoop();


    return 0;
}
