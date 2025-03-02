// kernel/include/vga.h

#ifndef VGA_H
#define VGA_H


#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000
#define VGA_COLOR_WHITE 0x0F
#define VGA_COLOR_BLACK 0x00

void vga_wrt_char(char c, int x, int y, unsigned char color);
void vga_wrt_string(const char *str, unsigned char color)_string(const char* str, unsigned char color);
void vga_clear();

#endif

