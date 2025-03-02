// kernel/include/vga.h

#ifndef VGA_H
#define VGA_H

void vga_wrt_char(char c, int x, int y, unsigned char color);
void vga_wrt_string(const char* str, unsigned char color);
void vga_clear();

#endif

