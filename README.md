# Atomic Text
Quick and dirty tool to scroll messages on an M5 Atom.

## Usage
Currently the text is hardcoded as message inside main.cpp however the tool should easily be
extensible to support a network message update (my future plan).
Only horziontal scroll to the left is supported currently as earlier revisions used the
official unstable M5Atom library 0.0.1 animation API which despite supporting scroll in many 
directions had memory corruption issues.
The font used in this library could do with work - any improvements on design and usage 
appreciated (bear in mind it's 5x5 pixels)!

## TODO
- Add network message post support.
- Maybe add some more configuration options (brightness is hardcoded to prevent M5Atom damage).
- Maybe add glyph support.
