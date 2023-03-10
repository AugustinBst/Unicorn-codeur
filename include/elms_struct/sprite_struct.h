/*
** EPITECH PROJECT, 2023
** sprite_struct
** File description:
** sprite_struct
*/

#ifndef SPRITE_STRUCT_
    #define SPRITE_STRUCT_

    #include <SFML/Graphics.h>

typedef struct m_sprite_struct{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int nb_rect;
} s_sprite_anim;

s_sprite_anim init_attack(char *path);

#endif /* !SPRITE_STRUCT_ */
