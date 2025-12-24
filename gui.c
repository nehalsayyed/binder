// gui.c
#include <X11/Xlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    Display *d = XOpenDisplay(NULL);
    if (!d) {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    int s = DefaultScreen(d);

    // Create a square window 200x200
    Window w = XCreateSimpleWindow(d, RootWindow(d, s),
                                   10, 10, 200, 200, 4,
                                   BlackPixel(d, s), WhitePixel(d, s));

    // Select input events so we get Expose
    XSelectInput(d, w, ExposureMask);

    // Map window
    XMapWindow(d, w);

    // Create a graphics context
    GC gc = XCreateGC(d, w, 0, NULL);

    // Allocate colors
    Colormap cmap = DefaultColormap(d, s);
    XColor red, green, blue;
    XAllocNamedColor(d, cmap, "red", &red, &red);
    XAllocNamedColor(d, cmap, "green", &green, &green);
    XAllocNamedColor(d, cmap, "blue", &blue, &blue);

    // Event loop: wait for expose then draw
    for (;;) {
        XEvent e;
        XNextEvent(d, &e);
        if (e.type == Expose) {
            // Fill background red
            XSetForeground(d, gc, red.pixel);
            XFillRectangle(d, w, gc, 0, 0, 200, 200);

            // Draw green border
            XSetForeground(d, gc, green.pixel);
            XDrawRectangle(d, w, gc, 10, 10, 180, 180);

            // Draw blue inner square
            XSetForeground(d, gc, blue.pixel);
            XDrawRectangle(d, w, gc, 50, 50, 100, 100);

            XFlush(d);
            break; // done drawing once
        }
    }

    sleep(5); // keep window visible
    return 0;
}
