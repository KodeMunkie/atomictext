#pragma once
#include "M5Atom.h"
#include "dict.h"

const int HEADER_LENGTH = 2;
const int RGB_FIELDS = 3;
const int COLS_PER_CHAR = 6;
const int ROWS_PER_CHAR = 5;
const int PIXELS_PER_CHAR = COLS_PER_CHAR*ROWS_PER_CHAR;

int copyLetterToOutput (const bool* letter, bool* output, int startIndex) {
    for (int i=0; i<30; ++i) {
        output[startIndex++] = letter[i];
    }
    return startIndex;
}

void fontArrayToRGB(bool* data, uint8_t* rgbData, int letters) { 
    int pixelCount = PIXELS_PER_CHAR * letters;
    int rgbCount = 0;
    rgbData[rgbCount++] = COLS_PER_CHAR * letters;
    rgbData[rgbCount++] = ROWS_PER_CHAR;
    for (int i=0; i<pixelCount; ++i) {
        rgbData[rgbCount++] = data[i]?0xFF:0x00;
        rgbData[rgbCount++] = data[i]?0xFF:0x00;
        rgbData[rgbCount++] = data[i]?0xFF:0x00;
    }
}

void transposeToAtomLayout(const bool* data, bool* reformattedData, int letterCount) {
    int count = 0;

    // For each row in the final output
    for (int row=0; row<ROWS_PER_CHAR; row++) {

        // Repeating the following for each character in the array
        for (int i=0; i<letterCount; i++) {

            // Copy 6 columns worth of data from the correct position to a row
            int startIndex = (i*PIXELS_PER_CHAR)+(row*COLS_PER_CHAR);
            for (int index=startIndex; index<startIndex+COLS_PER_CHAR; index++) {
                reformattedData[count++] = data[index];
            }
        }
    } 
}

void stringToFontArray (String text, bool* output, int pixelCount) {
    int startIndex = 0;
    
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

void textToRGB(String text, uint8_t* rgbData, int pixelCount) {
    bool reformattedArray[pixelCount];
    {
        bool fontArray[pixelCount];
        stringToFontArray(text, fontArray, pixelCount);
        transposeToAtomLayout(fontArray, reformattedArray, text.length());
    }
    fontArrayToRGB(reformattedArray, rgbData, text.length());
}

void displayText(String text, bool (*stopFnPtr)()) {
    int pixelCount = PIXELS_PER_CHAR*text.length();
    int rgbLength = HEADER_LENGTH+(RGB_FIELDS*pixelCount);
    uint8_t rgbData[rgbLength];
    textToRGB(text, rgbData, pixelCount);
    M5.dis.animation(rgbData, 150, LED_DisPlay::kMoveLeft, -1);
    while (1) {
        if ((*stopFnPtr)()) {
            return;
        }
        delay(1000);
    }
}

