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
#include <M5Atom.h>

String message = "ATOMIC TEXT - SILENT SOFTWARE 2020 ";
 
/**
 * Initialise the Atom, kick off animation thread
 */
void setup()
{
    M5.begin(true, false, true);
    initialise(160, RainbowColors_p);
    displayText(message); 
}

void loop()
{
    // TODO: Wifi/POST update of message     
    M5.update();
}