// gui.c
#include <X11/Xlib.h>
#include <unistd.h>

int main() {
    Display *d = XOpenDisplay(NULL);
    if (!d) return 1;

    int s = DefaultScreen(d);

    // Create a square window 200x200
    Window w = XCreateSimpleWindow(d, RootWindow(d, s),
                                   10, 10, 200, 200, 4,
                                   BlackPixel(d, s), WhitePixel(d, s));

    // Map window
    XMapWindow(d, w);

    // Create a graphics context
    GC gc = XCreateGC(d, w, 0, NULL);

    // Allocate some RGB colors
    Colormap cmap = DefaultColormap(d, s);
    XColor red, green, blue;
    XAllocNamedColor(d, cmap, "red", &red, &red);
    XAllocNamedColor(d, cmap, "green", &green, &green);
    XAllocNamedColor(d, cmap, "blue", &blue, &blue);

    // Fill background with red
    XSetForeground(d, gc, red.pixel);
    XFillRectangle(d, w, gc, 0, 0, 200, 200);

    // Draw a green square border
    XSetForeground(d, gc, green.pixel);
    XDrawRectangle(d, w, gc, 10, 10, 180, 180);

    // Draw a smaller blue square inside
    XSetForeground(d, gc, blue.pixel);
    XDrawRectangle(d, w, gc, 50, 50, 100, 100);

    // Flush to display
    XFlush(d);

    // Keep window visible for 5 seconds
    sleep(5);

    return 0;
}
