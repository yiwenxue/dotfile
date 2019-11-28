# dwmfu

custom build of dwm 6.1 forked from the suckless repo https://dwm.suckless.org/

## Requirements
In order to build dwm you need the Xlib header files.
- `libmpdclient` is needed for mpdcontrol support

## Patches
patches applied on this custom are as follows :
* dwm-6.1-pertag_without_bar.diff
* dwm-center-6.1.diff
* dwm-centeredmaster-6.1.diff
* dwm-deck-20170909-ceac8c9.diff
* dwm-movestack-6.1.diff
* dwm-r1615-mpdcontrol.diff
* dwm-scratchpad-20170207-bb3bd6f.diff
* dwm-uselessgap-6.1.diff
* rounded corners patch (MitchWeaver)
* dwm-statuscolors-nopad-20180103-db22360.diff (jgrar)

### Installation
see also [dwm-README](dwm-README)

Edit `config.mk` and `config.h` to match your local setup (dwm is installed into
the `/usr/local` namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as **root**):

```
    make clean install
```
and put `exec dwm` on the last line of your `~/.xinitrc`
- for arch user `PKGBUILD` is also included in case you want to build a local package, edit it to suits your setup, and make sure to clean up the previous dwm installation if exist `sudo make clean uninstall`

### Usage
everything should be written on the `config.h`, edit color scheme in `scheme.h`

### About rounded patch
you can set up in which rounded corner should be applied on the opened window by issuing `isfloating` and/or `iscentered` rules in `config.h` . Do note that original rules remains apply `isfloating` will make window floating and `iscentered` will make window centered respectively.

quirks and behaviour you might expect :
* case `round_all=0`, view usage examples in `config.h`
* case `round_all=1`
    - everythings will be rounded (but it also draws rounded corners in a `fullscreen` mode resulting in ugly corners)

## Useless trivia
- fu stands for forked by nub, just so you know what you might want to expect from this custom build

## License
Original dwm license - see the [LICENSE](LICENSE) file for details

## Sauce
* [dwm - dynamic window manager for X](https://dwm.suckless.org/)
* [patches](https://dwm.suckless.org/patches/)
* [MitchWeaver's rounded patch](https://github.com/MitchWeaver/dotfiles/blob/8d76e479715e7fa7b4df153719d3d25144f9f7f2/suckless-tools/dwm/dwm/dwm.c#L938)
* [jgrar's statuscolors patch](https://github.com/jgrar/dwm-patches/blob/master/statuscolors/dwm-statuscolors-nopad-20180103-db22360.diff)
