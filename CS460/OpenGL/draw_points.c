#include <windows.h>  // use as needed for your system
#include <GL/glu.h>
#include <GL/Gl.h>
#include <GL/glut.h>
//#include <GL/glext.h>
//#include <GL/glcorearb.h>
//#include <GL/glxext.h>
//#include <GL/wglext.h>

void myInit (void)
{
     glClearColor ( 1.0, 1.0, 1.0, 1.0 );
     glColor3f ( 1.0f, 0.0f, 0.0f );
     glPointSize ( 4.0 );
     glMatrixMode ( GL_PROJECTION );
     glLoadIdentity ( );
     gluOrtho2D ( 0.0, 400.0, 1.0, 400.0 );
}


void myDisplay ( void )
{
     glClear ( GL_COLOR_BUFFER_BIT );
     glBegin ( GL_POINTS );
          glVertex2i ( 100, 50 );
          glVertex2i ( 100, 150 );
          glVertex2i ( 150, 150 );
     glEnd ( );
     glFlush ( );
}



void main ( int argc, char** argv )
{
     glutInit ( &argc, argv );
     glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
     glutInitWindowSize ( 400, 400 );
     glutInitWindowPosition ( 200, 100 );
     glutCreateWindow ( "window" );
     glutDisplayFunc ( myDisplay );
     myInit ( );
     glutMainLoop ( );
}
