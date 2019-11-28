static const char white[]           = "#E3E3E3";
static const char vanilla[]         = "#D9D5A6";
static const char red[]             = "#CC939B";
static const char black[]           = "#27292A";
static const char cyan[]            = "#7EC5B5";
static const char titlefg[]         = "#AFC5B5";
static const char *colors[][7]      = {
	/*               fg            bg           border   */
	[SchemeNorm]   = { white,      black,      black },
	[SchemeSel]    = { black,      vanilla,    red   },
    [SchemeUrg]    = { black,      red,        white },
    [SchemeTitle]  = { titlefg,    black,      black },
    [SchemeStaon]  = { cyan,       black,      black },
    [SchemeStaoff] = { red,        black,      black },
    [SchemePowel]  = { cyan,       black,      black },
};
