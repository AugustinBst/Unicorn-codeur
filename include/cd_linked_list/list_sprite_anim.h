/*
** EPITECH PROJECT, 2023
** list_sprite_anim
** File description:
** list_sprite_anim
*/

#ifndef LST_SPRITE_ANIME
    #define LST_SPRITE_ANIME

    #include "sprite_struct.h"

typedef struct m_sprite_lst {
    s_sprite_anim sprite;
    struct m_sprite_lst *next; 
    struct m_sprite_lst *prev;
} m_sprite_lst;

#endif /* !LST_SPRITE_ANIME */
