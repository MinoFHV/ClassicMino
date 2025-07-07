#pragma once

#include <stdbool.h>
#include <stdint.h>

// Define GPIO Pins
#define LCD_CLK_SCL_PIN     4
#define LCD_MOSI_SDA_PIN    5
#define LCD_RST_PIN         6
#define LCD_DC_PIN          7


// Define LCD Parameters
#define LCD_WIDTH           240
#define LCD_HEIGHT          240
#define LCD_FRAME_HZ        60

// Define Tilemap Parameters
#define TILE_SIZE           20
#define TILEMAP_WIDTH       (LCD_WIDTH / TILE_SIZE)
#define TILEMAP_HEIGHT      (LCD_HEIGHT / TILE_SIZE)


// Define LCD Methods
void lcdInit();
void lcdReset();
void lcdSendCmdOrData(const uint8_t *data, uint8_t len, bool isData);
void lcdDrawTile(uint8_t screenTileX, uint8_t screenTileY, uint8_t tilemapX, uint8_t tilemapY);

// Debug LCD Methods
void draw_center_pixel();
void draw_center_line();
void lvgl_task_handler(void *arg);