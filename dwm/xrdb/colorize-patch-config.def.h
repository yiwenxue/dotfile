--- config.def.h
+++ config.def.h
@@ -7,15 +7,16 @@ static const int showbar            = 1;        /* 0 means no bar */
 static const int topbar             = 1;        /* 0 means bottom bar */
 static const char *fonts[]          = { "monospace:size=10" };
 static const char dmenufont[]       = "monospace:size=10";
-static const char col_gray1[]       = "#222222";
-static const char col_gray2[]       = "#444444";
-static const char col_gray3[]       = "#bbbbbb";
-static const char col_gray4[]       = "#eeeeee";
-static const char col_cyan[]        = "#005577";
-static const char *colors[][3]      = {
-	/*               fg         bg         border   */
-	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
-	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
+static char normbgcolor[]           = "#222222";
+static char normbordercolor[]       = "#444444";
+static char normfgcolor[]           = "#bbbbbb";
+static char selfgcolor[]            = "#eeeeee";
+static char selbordercolor[]        = "#005577";
+static char selbgcolor[]            = "#005577";
+static char *colors[][3] = {
+       /*               fg           bg           border   */
+       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
+       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
 };
 
 /* tagging */
@@ -56,7 +57,7 @@ static const Layout layouts[] = {
 
 /* commands */
 static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
-static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
+static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
 static const char *termcmd[]  = { "st", NULL };
 
 static Key keys[] = {
@@ -84,6 +85,7 @@ static Key keys[] = {
 	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
+	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
 	TAGKEYS(                        XK_1,                      0)
 	TAGKEYS(                        XK_2,                      1)
 	TAGKEYS(                        XK_3,                      2)
