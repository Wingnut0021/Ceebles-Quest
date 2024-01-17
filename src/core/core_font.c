#include <gb/gb.h>
#include <gbdk/font.h>

void loadFont(void) {
    font_t min_font;
    font_init();
    min_font = font_load(font_min); 
    font_set(min_font);
}