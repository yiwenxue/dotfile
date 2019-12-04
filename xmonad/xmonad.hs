import XMonad
import XMonad.Util.EZConfig
import XMonad.Layout.BinarySpacePartition
import XMonad.Layout.Spacing
import XMonad.Layout.Gaps
import XMonad.Layout.NoFrillsDecoration

myTheme = defaultTheme { activeColor = "#f7a050",
						 inactiveColor = "#ff8267",
						 activeBorderColor = "#f7a050",
						 inactiveBorderColor = "#ff8267",
						 activeTextColor = "#24262b",
						 inactiveTextColor = "#24262b",
						 decoHeight = 24,
						 fontName = "xft:Liberation Mono For Powerline:size=9" }

myLayout = noFrillsDeco shrinkText myTheme $ gaps [(U,50), (D,50), (L,75), (R,75)] $ spacing 10 $ emptyBSP

main = xmonad $ defaultConfig
	{ terminal = "urxvt",
	  layoutHook = myLayout,
	  borderWidth = 0,
	  normalBorderColor = "#100D0F",
	  focusedBorderColor = "#433B32"}
	  `additionalKeysP`
	  [ -- apps
	    ("M-c", spawn "urxvt"),
		("M-r", spawn "rofi -show run"),

	    -- window control
	    ("M-x", kill),
	    ("M-<Space>", sendMessage Swap),
	    ("M-<Return>", sendMessage Rotate),
	    ("M-h", sendMessage $ ExpandTowards L),
	    ("M-j", sendMessage $ ExpandTowards D),
	    ("M-k", sendMessage $ ExpandTowards U),
	    ("M-l", sendMessage $ ExpandTowards R)]

