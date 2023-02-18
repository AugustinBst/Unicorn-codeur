/*
** EPITECH PROJECT, 2023
** oog
** File description:
** ogg
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef OOG_H
    #define OOG_H


typedef struct oog_sprite {
    sfVector2f pos;
    sfSprite *oog_sprite;
    sfTexture *oog_texture;
} oog_s;

typedef struct carap_sprite {
    sfVector2f pos;
    sfSprite *carap_sprite;
    sfTexture *carap_texture;
} carap_s;

typedef struct box_sprite {
    sfVector2f pos;
    sfSprite *box_sprite;
    sfTexture *box_texture;
} box_s;

typedef struct background_sprite {
    sfSprite *back_sprite;
    sfTexture *back_texture;
} back_s;

typedef struct oog_struct {
    oog_s oogway;
    carap_s carapuce;
    box_s box;
    back_s background;
} oog_t;

    int launch_oogway(window_struct_t *win, oog_t *oog);

#endif /* !OOG_H */
