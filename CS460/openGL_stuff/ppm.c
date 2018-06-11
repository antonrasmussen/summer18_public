/*


It seemed that no one could use the code in the book for loading a ppm
file. So I did a little checking and found that the book's code is for
"P3" ppm files, while your image is in "P6" format.  I took the code from
the book and modified it to use the "P6" format instead.  Attached is a
copy.  I have tested it using MS Visual C++, not sure if it works in UNIX
without modification.


*/


//#include<windows.h>  // use as needed for your system
#include <stdio.h>
#include <stdlib.h>
#include<GL/gl.h>
#include<GL/freeglut.h>

int n;
int m;

int *image;

void myInit (void)
{
     glClearColor ( 1.0, 1.0, 1.0 , 1.0);
     glColor3f ( 1.0f, 0.0f, 0.0f );
     glPointSize ( 4.0 );
     glMatrixMode ( GL_PROJECTION );
     glLoadIdentity ( );
     gluOrtho2D ( 0.0, 400.0, 1.0, 400.0 );
}


void display(void)
{

	glClear ( GL_COLOR_BUFFER_BIT );
	glRasterPos2i(0,0);
	glDrawPixels(n,m,GL_RGB, GL_UNSIGNED_INT, image);
      glFlush ( );

}

void myreshape(int h, int w)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLfloat) n, 0.0, (GLfloat) m);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0,0,h,w);
}

int main(int argc, char**argv)
{
	FILE *fd;
	int k, nm;
	char c;
	char b[70];
	float s;
	char red, green, blue;
	int x, y;

	fd = fopen("lb.ppm", "r");
	if(fd == 0)
	{
		exit(0);
	}
	

	fscanf(fd, "%s", b);
	if((b[0] != 'P') || (b[1] != '6'))
	{
		printf("%s is not a PPM file!\n", b);
		exit(0);
	}

	fscanf(fd, "%c", &c);

	fscanf(fd, "%c", &c);
	while(c == '#')
	{
		fscanf(fd, "%[^\n]", b);
		printf("%s\n", b);
		fscanf(fd, "%c", &c);
		printf("%c", c);
	}

	ungetc(c,fd);

	fscanf(fd, "%d %d %d", &n, &m, &k);

	printf("%d rows  %d colums  max value = %d\n", n, m, k);

	nm = n*m;

	image = malloc(3*sizeof(GLint)*nm);

	s = 255./k;

	for(x = 0; x < m; x++)
	{
		for(y = n-1; y >= 0; y--)
		{
           fscanf(fd, "%c", &red);
    	   fscanf(fd, "%c", &green);
	       fscanf(fd, "%c", &blue);

		   image[3*nm - 3*(x*n +y) -3] = green;
		   image[3*nm - 3*(x*n +y) -2] = blue;
		   image[3*nm - 3*(x*n +y) -1] = red;

		}
	}

    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(n,m);
	glutInitWindowPosition(0,0);
	glutCreateWindow("image");
	glutReshapeFunc(myreshape);
	glutDisplayFunc(display);
	glPixelTransferf(GL_RED_SCALE, s);
	glPixelTransferf(GL_GREEN_SCALE, s);
	glPixelTransferf(GL_BLUE_SCALE, s);
	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	myInit ( );
      glutMainLoop ( );
}


