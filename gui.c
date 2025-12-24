// gui.c
#include <X11/Xlib.h>
#include <unistd.h>

int main() {
    Display *d = XOpenDisplay(NULL);
    if (!d) return 1;

    int s = DefaultScreen(d);
    Window w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 200, 100, 1,
                                   BlackPixel(d, s), WhitePixel(d, s));
    XMapWindow(d, w);
    XFlush(d);

    sleep(5);
    return 0;
}
