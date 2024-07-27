#include <gbdk/font.h>

void loadFont(void) {
    font_init();
    const font_t min_font = font_load(font_min);
    font_set(min_font);
}