--- config.def.h	2019-11-29 19:35:22.216453000 +0000
+++ config.def.1.h	2019-11-29 19:53:25.348918000 +0000
@@ -1,12 +1,12 @@
 /* See LICENSE file for copyright and license details. */
 
 /* appearance */
-static const unsigned int borderpx  = 1;        /* border pixel of windows */
-static const unsigned int snap      = 32;       /* snap pixel */
+static const unsigned int borderpx  = 2;        /* border pixel of windows */
+static const unsigned int snap      = 12;       /* snap pixel */
 static const int showbar            = 1;        /* 0 means no bar */
 static const int topbar             = 1;        /* 0 means bottom bar */
-static const char *fonts[]          = { "monospace:size=10" };
-static const char dmenufont[]       = "monospace:size=10";
+static const char *fonts[]          = { "monospace:size=14" };
+static const char dmenufont[]       = "monospace:size=14";
 static char normbgcolor[]           = "#222222";
 static char normbordercolor[]       = "#444444";
 static char normfgcolor[]           = "#bbbbbb";
@@ -29,7 +29,8 @@
 	 */
 	/* class      instance    title       tags mask     isfloating   monitor */
 	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
-	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
+	{ "Firefox",  NULL,       NULL,       2 >> 9,       0,           -1 },
+	{ "mupdf",    NULL,       NULL,       0,            1,           -1 },
 };
 
 /* layout(s) */
@@ -58,7 +59,7 @@
 /* commands */
 static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
 static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
-static const char *termcmd[]  = { "st", NULL };
+static const char *termcmd[]  = { "urxvt", NULL };
 static const char *incrvol[] = { "mixer", "vol", "+1:+1", NULL};
 static const char *decrvol[] = { "mixer", "vol", "-1:-1", NULL};
 
