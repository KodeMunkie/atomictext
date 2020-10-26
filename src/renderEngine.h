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

/**
 * Initialise the engine with a scroll pause (in milliseconds) and a palette
 */
void initialise(int pause, CRGBPalette16 palette);

/**
 * Displays the specified text as a scrolling banner on an M5Atom
 */
void displayText(String text);