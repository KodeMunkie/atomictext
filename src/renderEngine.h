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

#include "WString.h"
#include "stdint.h"
#include <FastLED.h>

const int COLS_PER_CHAR = 6;
const int ROWS_PER_CHAR = 5;
const int PIXELS_PER_CHAR = COLS_PER_CHAR*ROWS_PER_CHAR;
const int ATOM_X_LEDS = 5;
const int ATOM_Y_LEDS = 5;
const int SCROLL_PAUSE = 160;

/**
 * Initialise the engine with a scroll pause (in milliseconds) and a palette
 */
void setupEngine(int pause, CRGBPalette16 palette);

/**
 * Resets the banner's scroll (window) position
 */
void resetPosition();

/**
 * Renders an individual frame (window) of the text at the 
 * given x "pixel" coordinate.
 * @param rowLength the number of columns in the text data
 * @param text the message to render
 */
void renderFrame(int rowLength, String text, CRGB rgb);