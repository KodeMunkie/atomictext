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

#include <WiFiClient.h>
#include <ESP32WebServer.h>
#include <WiFi.h>
#include <ESPmDNS.h>

const String CONTENT_TYPE = "text/plain";
const String MESSAGE_KEY = "text";
const String RGB_KEY = "GRB"; // Actually GRB order :(

ESP32WebServer server(80);
void(*setMessage)(String);
void(*setRgb)(String);

/**
 * Handle the message post request and 
 * set the message on the call back
 */
void handleMessage() {
  for (int i=0; i<server.args(); ++i) {
    if (server.arg(i).length() > 0 && MESSAGE_KEY.equalsIgnoreCase(server.argName(i))) {
      setMessage(server.arg(i));
    }
    if (server.arg(i).length() > 0 && RGB_KEY.equalsIgnoreCase(server.argName(i))) {
      setRgb(server.arg(i));
    }
  }
  server.send(200, CONTENT_TYPE, "Message uploaded!\n\n");
}

/**
 * Handle all other cases as 404
 */
void handleNotFound() {
  server.send(404, CONTENT_TYPE, "File Not Found\n\n");
}

/**
 * Setup the WiFI connection and HTTP server handlers
 */ 
void setupServer(const char* ssid, const char* password, void(*callback)(String), void(*rgbCallback)(String)) {
  setMessage = callback;
  setRgb = rgbCallback;
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  MDNS.begin("atomictext");
  server.on("/m", handleMessage);
  server.onNotFound(handleNotFound);
  server.begin();
}

/**
 * Poll for a client request
 */
void handleClient() {
  server.handleClient();
}