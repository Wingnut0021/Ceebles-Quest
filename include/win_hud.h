#ifndef WIN_HUD_H
#define WIN_HUD_H


void initializeHud(void);
void displayInventoryItems(void);
void hideInventoryItems(void);
void hidePlayer(void);
void moveHud(uint8_t targetPosition, int8_t scrollStep);
void updateHud(void);

#endif