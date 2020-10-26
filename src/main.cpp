#include "renderEngine.h"
#include <M5Atom.h>

String message = "ATOMIC TEXT - COPYRIGHT SILENT SOFTWARE 2020 ";
bool stopAnim = false;
bool started = false;

bool stop() {
    //M5.dis.clear();
    return stopAnim;
}
 
void setup()
{
    M5.begin(true, false, true);
    M5.dis.setBrightness(20);
    displayText(message, stop); 
}

bool (*stopFnPtr)() = &stop;
void loop()
{
    // TODO: Bluetooth update of message will stop this
    // execution and start a new one       
    M5.update();
}