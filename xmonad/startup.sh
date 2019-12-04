#!/bin/bash

xinput set-prop "Synaptics TM3276-022" "libinput Tapping Enabled" 1
xinput set-prop "Synaptics TM3276-022" "libinput Accel Speed" 0.3
xinput set-prop "Synaptics TM3276-022" "libinput Natural Scrolling Enabled" 1

feh --bg-scale ~/Pictures/bg.png

xrdb ~/.Xresources

compton --config ~/.config/compton.conf
