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

#include "dict.h"
#include "renderEngine.h"
#include <FastLED.h>

CRGB leds[ATOM_X_LEDS*ATOM_Y_LEDS];
CRGBPalette16 currentPalette = RainbowColors_p;
TBlendType currentBlending = NOBLEND;
int scrollPause = SCROLL_PAUSE;
int xPositionInRgbData = 0;
int8_t colourIndex = 0;

/**
 * Initialise the engine with a scroll pause (in milliseconds) and a palette
 */
void setupEngine(int pause, CRGBPalette16 palette) {

    // M5Atom specific - this framework is not tested on anything else
    FastLED.addLeds<WS2812B, 27>(leds, 25);
    scrollPause = pause;
    currentPalette = palette;
}

/**
 * Copies a single letter bool array to the output banner array
 * TODO: Update with memcpy
 */
int copyLetterToOutput (const bool* letter, bool* output, int startIndex) {
    for (int i=0; i<30; ++i) {
        output[startIndex++] = letter[i];
    }
    return startIndex;
}

/**
 * Transpose array layout from one with individual characters to a large banner.
 * E.g using 3x3 non bool chars as an example:
 * 
 * 111222333111222333 
 * becomes
 * 111111222222333333
 */
void transposeToPixelRowsLayout(const bool* data, bool* reformattedData, int letterCount) {
    int count = 0;

    // For each row in the final output
    for (int row=0; row<ROWS_PER_CHAR; row++) {

        // Repeating the following for each character in the array
        for (int i=0; i<letterCount; i++) {

            // Copy each columns worth of data from the correct position to a row
            int startIndex = (i*PIXELS_PER_CHAR)+(row*COLS_PER_CHAR);
            for (int index=startIndex; index<startIndex+COLS_PER_CHAR; index++) {
                reformattedData[count++] = data[index];
            }
        }
    } 
}

/**
 * Noddy method to match a character to a bool-pixel defined font array
 */
void stringToFontArray (String text, bool* output, int pixelCount) {
    int startIndex = 0;
    text.toUpperCase();    
    for (int i=0; i<text.length(); ++i) {
        if (text[i] == ' ') { startIndex = copyLetterToOutput(WHITESPACE, output, startIndex); }
        else if (text[i] == 'A') { startIndex = copyLetterToOutput(A, output, startIndex); }
        else if (text[i] == 'B') { startIndex = copyLetterToOutput(B, output, startIndex); }
        else if (text[i] == 'C') { startIndex = copyLetterToOutput(C, output, startIndex); }
        else if (text[i] == 'D') { startIndex = copyLetterToOutput(D, output, startIndex); }
        else if (text[i] == 'E') { startIndex = copyLetterToOutput(E, output, startIndex); }
        else if (text[i] == 'F') { startIndex = copyLetterToOutput(F, output, startIndex); }
        else if (text[i] == 'G') { startIndex = copyLetterToOutput(G, output, startIndex); }
        else if (text[i] == 'H') { startIndex = copyLetterToOutput(H, output, startIndex); }
        else if (text[i] == 'I') { startIndex = copyLetterToOutput(I, output, startIndex); }
        else if (text[i] == 'J') { startIndex = copyLetterToOutput(J, output, startIndex); }
        else if (text[i] == 'K') { startIndex = copyLetterToOutput(K, output, startIndex); }
        else if (text[i] == 'L') { startIndex = copyLetterToOutput(L, output, startIndex); }
        else if (text[i] == 'M') { startIndex = copyLetterToOutput(M, output, startIndex); }
        else if (text[i] == 'N') { startIndex = copyLetterToOutput(N, output, startIndex); }
        else if (text[i] == 'O') { startIndex = copyLetterToOutput(O, output, startIndex); }
        else if (text[i] == 'P') { startIndex = copyLetterToOutput(P, output, startIndex); }
        else if (text[i] == 'Q') { startIndex = copyLetterToOutput(Q, output, startIndex); }
        else if (text[i] == 'R') { startIndex = copyLetterToOutput(R, output, startIndex); }
        else if (text[i] == 'S') { startIndex = copyLetterToOutput(S, output, startIndex); }
        else if (text[i] == 'T') { startIndex = copyLetterToOutput(T, output, startIndex); }
        else if (text[i] == 'U') { startIndex = copyLetterToOutput(U, output, startIndex); }
        else if (text[i] == 'V') { startIndex = copyLetterToOutput(V, output, startIndex); }
        else if (text[i] == 'W') { startIndex = copyLetterToOutput(W, output, startIndex); }
        else if (text[i] == 'X') { startIndex = copyLetterToOutput(X, output, startIndex); }
        else if (text[i] == 'Y') { startIndex = copyLetterToOutput(Y, output, startIndex); }
        else if (text[i] == 'Z') { startIndex = copyLetterToOutput(Z, output, startIndex); }
        else if (text[i] == '1') { startIndex = copyLetterToOutput(ONE, output, startIndex); }
        else if (text[i] == '2') { startIndex = copyLetterToOutput(TWO, output, startIndex); }
        else if (text[i] == '3') { startIndex = copyLetterToOutput(THREE, output, startIndex); }
        else if (text[i] == '4') { startIndex = copyLetterToOutput(FOUR, output, startIndex); }
        else if (text[i] == '5') { startIndex = copyLetterToOutput(FIVE, output, startIndex); }
        else if (text[i] == '6') { startIndex = copyLetterToOutput(SIX, output, startIndex); }
        else if (text[i] == '7') { startIndex = copyLetterToOutput(SEVEN, output, startIndex); }
        else if (text[i] == '8') { startIndex = copyLetterToOutput(EIGHT, output, startIndex); }
        else if (text[i] == '9') { startIndex = copyLetterToOutput(NINE, output, startIndex); }
        else if (text[i] == '0') { startIndex = copyLetterToOutput(ZERO, output, startIndex); }
        else if (text[i] == '"') { startIndex = copyLetterToOutput(SPEECHMARK, output, startIndex); }
        else if (text[i] == '!') { startIndex = copyLetterToOutput(EXCLAMATION, output, startIndex); }
        else if (text[i] == '?') { startIndex = copyLetterToOutput(QUESTIONMARK, output, startIndex); }
        else if (text[i] == '@') { startIndex = copyLetterToOutput(AT, output, startIndex); }
        else if (text[i] == '$') { startIndex = copyLetterToOutput(DOLLAR, output, startIndex); }
        else if (text[i] == '-') { startIndex = copyLetterToOutput(DASH, output, startIndex); }
        else if (text[i] == '%') { startIndex = copyLetterToOutput(PERCENTAGE, output, startIndex); }
        else if (text[i] == '+') { startIndex = copyLetterToOutput(PLUS, output, startIndex); }
        else if (text[i] == '=') { startIndex = copyLetterToOutput(EQUALS, output, startIndex); }
        else if (text[i] == '#') { startIndex = copyLetterToOutput(OCTOTHORPE, output, startIndex); }
        else if (text[i] == '_') { startIndex = copyLetterToOutput(UNDERSCORE, output, startIndex); }
        else if (text[i] == '&') { startIndex = copyLetterToOutput(AMPERSAND, output, startIndex); }
        else if (text[i] == '\'') { startIndex = copyLetterToOutput(QUOTE, output, startIndex); }
        else {
            startIndex = copyLetterToOutput(WHITESPACE, output, startIndex);
        }
    }
}

/**
 * Converts text string to bool based raster 
 */
void textToPixelData(String text, bool* pixelData, int pixelCount) {
    bool fontArray[pixelCount];
    stringToFontArray(text, fontArray, pixelCount);
    transposeToPixelRowsLayout(fontArray, pixelData, text.length());
}

/**
 * Renders a moment-in-time window representing the LED display.
 * 
 * @param rgbData the window represented as a boolean raster array
 * @param rowLength the stride length of an individual window row in rgbData
 * @param x the x coordindate to seek in the rgbData
 * @param y the y coordinate to  seek in the rgbData (nb defaults to zero, untested for anything else)
 * @param width the width of the window to render (nb defaults to ATOM_X_LEDS, untested for anything else)
 * @param height the height of the window to render (nb defaults to ATOM_Y_LEDS, untested for anything else)
 * @param colour the colour to render the LEDs for the current window
 */
void renderWindow(bool* rgbData, int rowLength, int x, int y = 0, int width = ATOM_X_LEDS, int height = ATOM_Y_LEDS, CRGB colour = CRGB::WhiteSmoke) {
    int ledCount = 0;
    int offset = (rowLength*y)+x;

    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            int currentLed = offset+i;
            // If we exceed the end of the rgbData row go back to the start of it 
            // to pick up enough data to scroll the last character off the display
            if (x+i>= rowLength) {
                currentLed -= rowLength;
            }
            leds[ledCount++] = rgbData[currentLed]?colour:CRGB::Black;
        }
        offset+=rowLength;
    }
    FastLED.show();
    delay(scrollPause);
}

/**
 * Renders an individual frame (window) of the text at the 
 * given x "pixel" coordinate.
 * @param rowLength the number of columns in the text data
 * @param text the message to render
 */
void renderFrame(int rowLength, String text) {
    int pixelCount = PIXELS_PER_CHAR*text.length();
    bool rgbData[pixelCount];
    // TODO: Inefficient - re-renders the entire text each time. Find a way to
    // improve this without memory going out of scope (or using heap)
    textToPixelData(text, rgbData, pixelCount);
    CRGB colour = ColorFromPalette(currentPalette, colourIndex, 40, currentBlending);
    renderWindow(rgbData, rowLength, xPositionInRgbData, 0, ATOM_X_LEDS, ATOM_Y_LEDS, colour);
     // Increment the banner's frame window position
    ++xPositionInRgbData;
    colourIndex+=3;

    // Reset the position if the length of the banner is exceeded
    if (xPositionInRgbData > rowLength) {
        xPositionInRgbData=0;
    }
}

void resetPosition() {
    xPositionInRgbData = 0;
}

