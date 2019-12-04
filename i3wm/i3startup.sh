#!/bin/sh

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -u $USER -x polybar >/dev/null; do sleep 1; done

# Launch Polybar, using default config location ~/.config/polybar/config
polybar top &

echo "Polybar launched..."

feh --bg-scale ~/Pictures/bg.jpeg

xrdb ~/.Xresources

compton --config ~/.config/compton.conf
