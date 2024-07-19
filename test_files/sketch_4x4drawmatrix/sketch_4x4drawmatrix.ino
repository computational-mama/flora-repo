// SPDX-FileCopyrightText: 2019 Anne Barela for Adafruit Industries
//
// SPDX-License-Identifier: MIT

/********************************************************************* 
 Basic snowflake code (without Bluetooth)
 
  Accompanies the Adafruit guide 
  https://learn.adafruit.com/neopixel-matrix-snowflake-sweater

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!
 
 MIT license, check LICENSE for more information
 All text above, and the splash screen below must be included in
 any redistribution
*********************************************************************/
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
/*=========================================================================
    APPLICATION SETTINGS
                              
    MATRIX DECLARATION        Parameter 1 = width of NeoPixel matrix
                              Parameter 2 = height of matrix
                              Parameter 3 = pin number (most are valid)
                              Parameter 4 = matrix layout flags, add together as needed:
    NEO_MATRIX_TOP,
    NEO_MATRIX_BOTTOM,
    NEO_MATRIX_LEFT,
    NEO_MATRIX_RIGHT          Position of the FIRST LED in the matrix; pick two, e.g.
                              NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
                              NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
                              rows or in vertical columns, respectively; pick one or the other.
    NEO_MATRIX_PROGRESSIVE,
    NEO_MATRIX_ZIGZAG         all rows/columns proceed in the same order, 
                              or alternate lines reverse direction; pick one.
 
                              See example below for these values in action.
    
    Parameter 5 = pixel type flags, add together as needed:
                              
    NEO_KHZ800                800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    NEO_KHZ400                400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    NEO_GRB                   Pixels are wired for GRB bitstream (most NeoPixel products)
    NEO_RGB                   Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    -----------------------------------------------------------------------*/
    #define FACTORYRESET_ENABLE     1
 
    #define PIN                     6   // Which pin on the Arduino is connected to the NeoPixels?
 
// Example for NeoPixel 8x8 Matrix.  In this application we'd like to use it 
// with the back text positioned along the bottom edge.
// When held that way, the first pixel is at the top left, and
// lines are arranged in columns, zigzag order.  The 8x8 matrix uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(4, 4, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
/*=========================================================================*/
 
void setup(void)
{
  matrix.begin();
  matrix.setBrightness(50);
 
  matrix.fillScreen(0);
  matrix.show(); // This sends the updated pixel colors to the hardware.
}
 
void loop(void)
{

        // matrix.fillScreen(0);
        // SnowFlake1(matrix.Color(200, 70, 80));
        // matrix.show(); // This sends the updated pixel colors to the hardware.
        // delay(500);
        matrix.fillScreen(0);
        H1(matrix.Color(145, 0, 40));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        A(matrix.Color(0, 255, 0));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        P(matrix.Color(200, 200, 200));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        P(matrix.Color(255, 0, 0));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        Y(matrix.Color(0, 255, 0));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
         matrix.fillScreen(0);
        B(matrix.Color(145, 0, 40));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        D(matrix.Color(0, 255, 0));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        A(matrix.Color(200, 200, 200));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        matrix.fillScreen(0);
        Y(matrix.Color(0, 255, 0));
        matrix.show(); // This sends the updated pixel colors to the hardware.
        delay(500);
        // matrix.fillScreen(0);
        // SnowFlake7(matrix.Color(200, 200, 200));
        // matrix.show(); // This sends the updated pixel colors to the hardware.
        // matrix.fillScreen(0);
        // SnowFlake8(matrix.Color(255, 0, 0));
        // matrix.show(); // This sends the updated pixel colors to the hardware.
        // delay(500);       
}

void H1(uint32_t c){
  matrix.drawLine(0, 0, 0, 3, c); // x0, y0, x1, y1, color
  matrix.drawLine(3, 0, 3, 3, c); // x0, y0, x1, y1, color
  matrix.drawLine(0, 2, 3, 2, c); // x0, y0, x1, y1, color
}

void A(uint32_t c){
  matrix.drawLine(0, 3, 1, 0, c); // Left diagonal
  matrix.drawLine(1, 0, 2, 0, c); // Top horizontal
  matrix.drawLine(2, 0, 3, 3, c); // Right diagonal
  matrix.drawLine(0, 2, 3, 2, c); // Middle horizontal
}

void P(uint32_t c){
  matrix.drawLine(0, 0, 0, 3, c); // Vertical line
  matrix.drawLine(0, 0, 2, 0, c); // Top horizontal line
  matrix.drawLine(2, 0, 2, 2, c); // Right vertical line
  matrix.drawLine(0, 2, 2, 2, c); // Middle horizontal line
}

void Y(uint32_t c){
  matrix.drawLine(0, 0, 1, 1, c); // Left diagonal
  matrix.drawLine(3, 0, 2, 1, c); // Right diagonal
  matrix.drawLine(1, 1, 1, 3, c); // Vertical line down
}

void B(uint32_t c){
  matrix.drawLine(0, 0, 0, 3, c); // Vertical line
  matrix.drawLine(0, 0, 2, 0, c); // Top horizontal line
  matrix.drawLine(2, 0, 2, 2, c); // Right vertical line (top part)
  matrix.drawLine(0, 2, 2, 2, c); // Middle horizontal line
  matrix.drawLine(2, 2, 2, 3, c); // Right vertical line (bottom part)
  matrix.drawLine(0, 3, 2, 3, c); // Bottom horizontal line
}

void D(uint32_t c){
  matrix.drawLine(0, 0, 0, 3, c); // Vertical line
  matrix.drawLine(0, 0, 2, 0, c); // Top horizontal line
  matrix.drawLine(2, 0, 2, 3, c); // Right vertical line
  matrix.drawLine(0, 3, 2, 3, c); // Bottom horizontal line
}

