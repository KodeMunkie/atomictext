/* Atomic Text - Text scrolling for M5Atom
 * Copyright (C) 2020 Silent Software (Benjamin Brown)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "renderEngine.h"
#include "messageHandler.h"
#include "main.h"
#include <M5Atom.h>

/**
 * SET YOUR DEFAULTS HERE!
 */ 
const char SSID[] = "<YOUR SSID>";
const char PASSWORD[] = "<YOUR PASSWORD>";
const String DEFAULT_MESSAGE = "ATOMIC TEXT - SILENT SOFTWARE 2020";

String currentMessage = DEFAULT_MESSAGE;
CRGB currentRgb = CRGB::Black;

/**
 * Call back to set the message to be displayed
 * If there is no message in the post (an error) sets it to the default
 */
void setMessage(String newMessage) {
    if (newMessage.length() == 0) {
        newMessage = DEFAULT_MESSAGE;
    }
    // Add whitespace so next message doesn't merge with this one
    currentMessage = newMessage+" ";
    resetPosition();
}

void setRgb(String rgb) {
    currentRgb = CRGB(strtol(&rgb[0], NULL, 0));
}

/**
 * Hotfix for M5Atom 0.0.1 lib that initialises
 * any wifi/bt activity on the same core as the
 * display resulting in flicker during scroll.
 */
void setupPatchM5AtomLibToFixFlicker() {
    
    // Disable the display
    M5.begin(false, false, false);

    // Enable it but on a different core
    M5.dis.setTaskName("LEDs");
    M5.dis.setTaskPriority(2);
    M5.dis.setCore(1);
    M5.dis.start();
}

/**
 * Initialise the M5Atom, Wifi/HTTP Server and the LED rendering engine
 */
void setup() {
    setupPatchM5AtomLibToFixFlicker();
    setupServer(SSID, PASSWORD, setMessage, setRgb);
    setupEngine(200, RainbowColors_p);
}

void loop() {   
    
    // Determine how long a row of text is in pixels
    int rowLength = COLS_PER_CHAR*currentMessage.length();

    // Render the a frame of the banner (message)
    renderFrame(rowLength, currentMessage, currentRgb);

    // Listen for a HTTP POST
    handleClient();
}