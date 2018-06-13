#include<windows.h>  // use as needed for your system
#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<GL/Gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int n;
int m;

int *image;

void myInit (void)
{
     glClearColor ( 1.0, 1.0, 1.0 , 1.0); // Not sure
     glColor3f ( 1.0f, 0.0f, 0.0f ); // Red dots
     glPointSize ( 7.0 ); // Dot size
     glMatrixMode ( GL_PROJECTION ); // Not sure

     glLoadIdentity(); // Not sure
     gluOrtho2D(0.0, 400.0, 1.0, 400.0); // Not sure
}


void display(void)
{


	// Draw the map
	glClear(GL_COLOR_BUFFER_BIT); // Turns screen white
	glRasterPos2i(0,0); // Not sure
	glDrawPixels(n,m,GL_RGB, GL_UNSIGNED_INT, image); // Draws map
    glFlush(); // Not sure

    /// Draw the points [Wrap this in a function!]
    glBegin ( GL_POINTS );
    glVertex2i ( 300, 250 );
    glVertex2i ( 200, 350 );
    glVertex2i ( 450, 550 );
    glEnd();
    glFlush();

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

	image = (int*) malloc(3*sizeof(GLint)*nm);

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
	glutCreateWindow("CS460 Final Project - Anton Rasmussen");
	glutReshapeFunc(myreshape);
	glutDisplayFunc(display);

	glPixelTransferf(GL_RED_SCALE, s);
	glPixelTransferf(GL_GREEN_SCALE, s);
	glPixelTransferf(GL_BLUE_SCALE, s);

	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	myInit();


    glutMainLoop ( );
}
