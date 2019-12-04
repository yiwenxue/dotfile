--- config.def.h	2019-11-29 18:56:25.743408000 +0000
+++ config.def.1.h	2019-11-29 19:09:43.183711000 +0000
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
 static const char col_gray1[]       = "#222222";
 static const char col_gray2[]       = "#444444";
 static const char col_gray3[]       = "#bbbbbb";
@@ -29,6 +29,7 @@
 	/* class      instance    title       tags mask     isfloating   monitor */
 	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
 	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
+	{ "mupdf",    NULL,       NULL,       0,            1,           -1 },
 };
 
 /* layout(s) */
@@ -44,7 +45,7 @@
 };
 
 /* key definitions */
-#define MODKEY Mod1Mask
+#define MODKEY Mod4Mask
 #define TAGKEYS(KEY,TAG) \
 	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
 	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
@@ -56,12 +57,13 @@
 
 /* commands */
 static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
+static char *roficmd = {"rofi", "show", "run"};
 static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
-static const char *termcmd[]  = { "st", NULL };
+static const char *termcmd[]  = { "urxvt", NULL };
 
 static Key keys[] = {
 	/* modifier                     key        function        argument */
-	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
+	{ MODKEY,                       XK_p,      spawn,          {.v = roficmd } },
 	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
 	{ MODKEY,                       XK_b,      togglebar,      {0} },
 	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
