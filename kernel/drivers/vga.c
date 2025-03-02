// kernel/drivers/vga.c

#include <stdint.h>

// Define constants for VGA
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000
#define VGA_COLOR_WHITE 0x0F
#define VGA_COLOR_BLACK 0x00

unsigned short* const VGA = (unsigned short*)VGA_MEMORY;  // VGA text buffer base address

void vga_wrt_char(char c, int x, int y, unsigned char color) {
    unsigned short* location = VGA + (y * VGA_WIDTH + x);
    *location = (color << 8) | c;  // Combine color and character into one short
}

void vga_wrt_string(const char* str, unsigned char color) {
    int x = 0, y = 0;

    while (*str) {
        if (*str == '\n') {
            x = 0;
            y++;
        } else {
            vga_wrt_char(*str, x, y, color);
            x++;
        }

        if (x >= VGA_WIDTH) {
            x = 0;
            y++;
        }

        if (y >= VGA_HEIGHT) {
            y = 0;
        }

        str++;
    }
}

void vga_clear() {
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        VGA[i] = (VGA_COLOR_BLACK << 8) | ' ';  // Clear with black background and spaces
    }
}

