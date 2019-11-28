/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        // border pixel of windows
static const unsigned int snap      = 32;       // snap pixel
static const unsigned int gappx     = 4;        // useless gap
static const int showbar            = 1;        // 0 means no bar
static const int topbar             = 1;        // 0 means bottom bar
static const int round_radius       = 5;        // rounded corners radius
static const int round_all          = 0;        // whether or not to round everything up, reminder that fullscreen mode will also be included
static const char *fonts[]          = { "PT Sans Narrow:style=Bold:size=11", "inconsolata for powerline:pixelsize=22" };

// color scheme
#include "scheme.h" // current

// tagging
static const char *tags[] = { "001", "010", "011", "100", "101" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class,           instance,    title,    tags mask,   is(c)entered,   is(f)loating,  monitor,  |    (c,f) rounded corner behaviour example    */
    { "Chrome",         NULL,        NULL,     1 << 3,	    0,              0,             -1 },     //   (0,0) NOT
    { "Code",           NULL,        NULL,     1 << 2,	    0,              0,             -1 },     //   (0,0) NOT
    { "Sxiv",           NULL,        NULL,     0,           1,              1,             -1 },     //   (1,1) NOT
    { "Color-picker",   NULL,        NULL,     0,           0,              1,             -1 },     //   (0,1) rounded
    { "XFontSel",       NULL,        NULL,     0,           1,              1,             -1 },     //   (1,1) NOT
    { "Xfd",            NULL,        NULL,     0,           1,              1,             -1 },     //   (1,1) NOT
    { "tabbed",         NULL,        NULL,     0,           0,              1,             -1 },     //   (1,0) rounded ONLY on mouse resize 
    { "st",             NULL,        NULL,     0,           0,              1,             -1 },     //   (1,1) NOT
    { "mpv",            NULL,        NULL,     0,           1,         	    1,             -1 },     //   (1,1) NOT
};

// layout(s)
static const float mfact     = 0.55; // factor of master area size [0.05..0.95]
static const int nmaster     = 1;    // number of clients in master area
static const int resizehints = 0;    // 1 means respect size hints in tiled resizals

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "T",      tile },     // ☍ first entry is default
	{ "F",      NULL },     // ⚮ no layout function means floating behavior
	{ "M",      monocle },  // ☌
	{ "D",      deck },     // ≗
	{ "CT",     centeredmaster },
	{ "CF",     centeredfloatingmaster },
};

// key definitions
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ Mod4Mask,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ Mod4Mask|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Mod4Mask|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Mod4Mask|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// helper for spawning shell commands in the pre dwm-5.0 fashion
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#include <XF86keysym.h>

// commands
static const char  *scriptcmd[]  = { "sclauncher", NULL }; // dmneu scriptlauncher
static const char  *clipb[]      = { "clipboard", NULL }; // cdown's clipmenu see (github.com/cdown/clipmenu)
static const char  *termcmd[]    = { "tabbed", "-c", "-n", "tabbed_st", "-t", "#9B0D2E", "-u", "#870A27", "st", "-w", NULL };
static const char  scratchname[] = "scratchpad";
static const char  *scratchcmd[] = { "st", "-t", scratchname, "-g", "80x35", NULL };
static const char  *vscmd[]      = { "code", NULL };
static const char  *rebootcmd[]  = { "reboot", NULL };
static const char  *killcmd[]    = { "shutdown", "now", NULL };

#include "movestack.c"
#include "mpdcontrol.c"
static Key keys[] = {
	/* modifier                       key				function               		 argument */
        { Mod4Mask,                     XK_s,                 spawn,                   {.v = scriptcmd } },
        { Mod4Mask,                     XK_c,                 spawn,                   {.v = clipb } },
	{ MODKEY,                       XK_Return,            spawn,                   {.v = termcmd } },
        { MODKEY,                       XK_grave,             togglescratch,           {.v = scratchcmd } },
	{ Mod4Mask,                     XK_e,                 spawn,                   {.v = vscmd } },
	{ Mod4Mask,                     XK_w,                 spawn,                   {.v = chromecmd } },
	{ MODKEY,                       XK_p,                 mpdchange,               {.i = -1} },
	{ MODKEY,                       XK_n,                 mpdchange,               {.i = +1} },
	{ MODKEY,                       XK_Escape,            mpdcontrol,              {0} },
	{ MODKEY,                       XK_b,                 togglebar,               {0} },
	{ Mod4Mask,                     XK_a,                 focusstack,              {.i = +1 } },
	{ Mod4Mask,                     XK_x,                 focusstack,              {.i = -1 } },
	{ Mod4Mask,                     XK_n,                 movestack,               {.i = +1 } },
	{ Mod4Mask,                     XK_p,                 movestack,               {.i = -1 } },
	{ MODKEY,                       XK_i,                 incnmaster,              {.i = +1 } },
	{ MODKEY,                       XK_o,                 incnmaster,              {.i = -1 } },
	{ Mod4Mask,                     XK_h,                 setmfact,                {.f = -0.05} },
	{ Mod4Mask,                     XK_l,                 setmfact,                {.f = +0.05} },
	{ Mod4Mask,                     XK_z,                 zoom,                    {0} },
	{ Mod4Mask,                     XK_Tab,               view,                    {0} },
	{ Mod4Mask,                     XK_q,                 killclient,              {0} },
	{ Mod4Mask,                     XK_t,                 setlayout,               {.v = &layouts[0]} },
	{ Mod4Mask,                     XK_f,                 setlayout,               {.v = &layouts[1]} },
	{ Mod4Mask,                     XK_m,                 setlayout,               {.v = &layouts[2]} },
	{ Mod4Mask,                     XK_d,                 setlayout,               {.v = &layouts[3]} },
        { Mod4Mask,                     XK_i,                 setlayout,               {.v = &layouts[4]} },
        { Mod4Mask,                     XK_o,                 setlayout,               {.v = &layouts[5]} },
	{ Mod4Mask,                     XK_v,                 setlayout,               {0} },
	{ Mod4Mask|ShiftMask,           XK_f,                 togglefloating,          {0} },
	{ MODKEY,                       XK_0,                 view,                    {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                 tag,                     {.ui = ~0 } },
	{ MODKEY,                       XK_comma,             focusmon,                {.i = -1 } },
	{ MODKEY,                       XK_period,            focusmon,                {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,             tagmon,                  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,            tagmon,                  {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ MODKEY|ControlMask,			XK_Delete,            quit,                     {0} },
	{ Mod4Mask|ShiftMask,           XK_End,               spawn,                    {.v = rebootcmd } },
	{ Mod4Mask,                     XK_End,               spawn,                    {.v = killcmd } },
};

// button definitions
// click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         Mod4Mask,       Button1,        movemouse,      {0} },
	{ ClkClientWin,         Mod4Mask,       Button2,        togglefloating, {0} },
	{ ClkClientWin,         Mod4Mask,       Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
