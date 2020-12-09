# Atomic Text
Quick and dirty tool to scroll messages on an M5Stack Atom.

![](atomictext.jpg)

## Usage
1) Open the source folder in the [PlatformIO](https://platformio.org/) IDE
1) Set your WiFi network SSID and PASSWORD in main.cpp.
1) Upload using the PlatformIO Upload button (which will also do a build first).
1) POST to the endpoint http://atomictext.local/m with the KEY "text" and your message as the VALUE. You can also use GET (e.g. ?text=HELLO) but spaces are treated as URL ENCODED so not recommended
1) Optionally include KEY "grb" to set a fixed text colour (e.g. &grb=0x00FF00 would set the text to red - nb. GRB not RGB order)

Note: mobile devices may not support mDNS which is used to set the domain name "atomictext.local" on your network - so you may need to find the IP address on your router instead.

## Limitations
* Currently only horziontal scroll to the left is supported as [earlier revisions used the
official M5Atom library 0.0.1 animation API](https://github.com/KodeMunkie/atomictext/commit/275d73a406d903be5e75ddd3d664547467dab560#diff-25a6634263c1b1f6fc4697a04e2b9904ea4b042a89af59dc93ec1f5d44848a26) which despite supporting scroll in many 
directions appears to have a memory corruption issue and would crash with messages of more than
a few words (about 20 characters).

* The font used in this library could do with work - any improvements on design and usage 
appreciated (bear in mind it's 5x5 pixels)! You are restricted to the alphabet in [dict.h](https://github.com/KodeMunkie/atomictext/blob/main/src/dict.h).

* There _was_ an interrupt bug causing the LEDs to flicker slightly on scroll caused by the WiFi and display threads running on the same core which is [another 
limitation in the M5Atom library 0.0.1](https://github.com/m5stack/M5Atom/issues/15). To workaround it the display is initialised directly in setup() and the
core explicitly chosen, instead of using M5.begin() for this purpose. This may caused incompatibility when the M5Atom library updates if not removed.
