#ifndef QUEST_H
#define QUEST_H

#include <gb/gb.h>
#include <quest_list.h>

#define MAX_DESCRIPTION_LENGTH 64

struct Quest;

typedef struct Quest {
    QuestName const questName;
    uint8_t id;
    char description[MAX_DESCRIPTION_LENGTH];
    uint8_t completed;
} Quest;


#endif