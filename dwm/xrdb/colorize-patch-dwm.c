--- dwm.c
+++ dwm.c
@@ -35,6 +35,7 @@
 #include <X11/Xatom.h>
 #include <X11/Xlib.h>
 #include <X11/Xproto.h>
+#include <X11/Xresource.h>
 #include <X11/Xutil.h>
 #ifdef XINERAMA
 #include <X11/extensions/Xinerama.h>
@@ -56,6 +57,21 @@
 #define HEIGHT(X)               ((X)->h + 2 * (X)->bw)
 #define TAGMASK                 ((1 << LENGTH(tags)) - 1)
 #define TEXTW(X)                (drw_fontset_getwidth(drw, (X)) + lrpad)
+#define XRDB_LOAD_COLOR(R,V)    if (XrmGetResource(xrdb, R, NULL, &type, &value) == True) { \
+                                  if (value.addr != NULL && strnlen(value.addr, 8) == 7 && value.addr[0] == '#') { \
+                                    int i = 1; \
+                                    for (; i <= 6; i++) { \
+                                      if (value.addr[i] < 48) break; \
+                                      if (value.addr[i] > 57 && value.addr[i] < 65) break; \
+                                      if (value.addr[i] > 70 && value.addr[i] < 97) break; \
+                                      if (value.addr[i] > 102) break; \
+                                    } \
+                                    if (i == 7) { \
+                                      strncpy(V, value.addr, 7); \
+                                      V[7] = '\0'; \
+                                    } \
+                                  } \
+                                }
 
 /* enums */
 enum { CurNormal, CurResize, CurMove, CurLast }; /* cursor */
@@ -177,6 +193,7 @@ static void grabkeys(void);
 static void incnmaster(const Arg *arg);
 static void keypress(XEvent *e);
 static void killclient(const Arg *arg);
+static void loadxrdb(void);
 static void manage(Window w, XWindowAttributes *wa);
 static void mappingnotify(XEvent *e);
 static void maprequest(XEvent *e);
@@ -232,6 +249,7 @@ static Monitor *wintomon(Window w);
 static int xerror(Display *dpy, XErrorEvent *ee);
 static int xerrordummy(Display *dpy, XErrorEvent *ee);
 static int xerrorstart(Display *dpy, XErrorEvent *ee);
+static void xrdb(const Arg *arg);
 static void zoom(const Arg *arg);
 
 /* variables */
@@ -1014,6 +1032,37 @@ killclient(const Arg *arg)
 	}
 }
 
+void
+loadxrdb()
+{
+  Display *display;
+  char * resm;
+  XrmDatabase xrdb;
+  char *type;
+  XrmValue value;
+
+  display = XOpenDisplay(NULL);
+
+  if (display != NULL) {
+    resm = XResourceManagerString(display);
+
+    if (resm != NULL) {
+      xrdb = XrmGetStringDatabase(resm);
+
+      if (xrdb != NULL) {
+        XRDB_LOAD_COLOR("dwm.normbordercolor", normbordercolor);
+        XRDB_LOAD_COLOR("dwm.normbgcolor", normbgcolor);
+        XRDB_LOAD_COLOR("dwm.normfgcolor", normfgcolor);
+        XRDB_LOAD_COLOR("dwm.selbordercolor", selbordercolor);
+        XRDB_LOAD_COLOR("dwm.selbgcolor", selbgcolor);
+        XRDB_LOAD_COLOR("dwm.selfgcolor", selfgcolor);
+      }
+    }
+  }
+
+  XCloseDisplay(display);
+}
+
 void
 manage(Window w, XWindowAttributes *wa)
 {
@@ -2110,6 +2159,17 @@ xerrorstart(Display *dpy, XErrorEvent *ee)
 	return -1;
 }
 
+void
+xrdb(const Arg *arg)
+{
+  loadxrdb();
+  int i;
+  for (i = 0; i < LENGTH(colors); i++)
+                scheme[i] = drw_scm_create(drw, colors[i], 3);
+  focus(NULL);
+  arrange(NULL);
+}
+
 void
 zoom(const Arg *arg)
 {
@@ -2136,6 +2196,8 @@ main(int argc, char *argv[])
 	if (!(dpy = XOpenDisplay(NULL)))
 		die("dwm: cannot open display");
 	checkotherwm();
+        XrmInitialize();
+        loadxrdb();
 	setup();
 #ifdef __OpenBSD__
 	if (pledge("stdio rpath proc exec", NULL) == -1)
