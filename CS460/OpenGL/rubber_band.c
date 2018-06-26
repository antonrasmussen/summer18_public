//#include < X11/Xlib.h >
#include<windows.h>
#include <stdio.h>

#define FORE "light goldenrod"
#define BACK "midnight blue"

main(argc,argv)
int argc;
char **argv;
{
    Display *display;
    Window root, window;
    long fgcolor, bgcolor;
    int screen, pointx, pointy, eventmask = ExposureMask|ButtonPressMask;
    int curx, cury;
    XEvent event;
    XColor exact, apparant;
    XGCValues gcval;
    GC draw, erase;

    if (!(display = XOpenDisplay(NULL))) {
	perror("XOpenDisplay");
	exit(1);
    }

    root = RootWindow(display,screen = DefaultScreen(display));


    XAllocNamedColor(display,DefaultColormap(display,screen),
		     FORE,&apparant,&exact);
    fgcolor = apparant.pixel;
    XAllocNamedColor(display,DefaultColormap(display,screen),
		     BACK,&apparant,&exact);
    bgcolor = apparant.pixel;


    window = XCreateSimpleWindow(display,root,0,0,400,400,2,fgcolor,bgcolor);

    gcval.foreground = fgcolor;
    gcval.background = bgcolor;
    draw = XCreateGC(display,window,GCForeground|GCBackground,&gcval);

    gcval.foreground = bgcolor;
    erase= XCreateGC(display,window,GCForeground|GCBackground,&gcval);

    XSelectInput(display,window,eventmask);
    XMapWindow(display,window);


    for (;;) {
	XNextEvent(display,&event);
	switch (event.type) {
	  case Expose:
	    XClearWindow(display,window);
	    XDrawLine(display,window,draw,25,25,375,375);
	    break;
	  case ButtonPress:
	    fprintf(stderr,"point set (%d,%d)\n",event.xbutton.x,
		    event.xbutton.y);
	    if (eventmask & PointerMotionMask) {
		XDrawLine(display,window,erase,pointx,pointy,curx,cury);
		XDrawLine(display,window,draw,pointx,pointy,event.xbutton.x,
			  event.xbutton.y);
		XSelectInput(display,window,eventmask &= ~PointerMotionMask);
	    } else {
		curx = pointx = event.xbutton.x;
		cury = pointy = event.xbutton.y;
		XSelectInput(display,window,eventmask |= PointerMotionMask);
	    }
	    break;
	  case MotionNotify:
	    XDrawLine(display,window,erase,pointx,pointy,curx,cury);
	    XDrawLine(display,window,draw,pointx,pointy,curx = event.xmotion.x,
		      cury = event.xmotion.y);
	    break;
	  default:
	    fprintf(stderr,"Unexpected event: %d\n",event.type);
	}
    }
}

