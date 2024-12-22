#pragma once

#include <stdint.h>

// Define GPIO Pins
#define LCD_MOSI_PIN        5
#define LCD_CLK_PIN         6
#define LCD_CS_PIN          7
#define LCD_DC_PIN          8
#define LCD_RST_PIN         9

// Define LCD Parameters
#define LCD_WIDTH           240
#define LCD_HEIGHT          240

// Define Tilemap Parameters
#define TILE_SIZE           16
#define TILEMAP_WIDTH       (LCD_WIDTH / TILE_SIZE)
#define TILEMAP_HEIGHT      (LCD_HEIGHT / TILE_SIZE)


// Define LCD Methods
void lcdInit();
void lcdDrawTile(uint8_t screenTileX, uint8_t screenTileY, uint8_t tilemapX, uint8_t tilemapY);