/*
** EPITECH PROJECT, 2023
** pokemon.h
** File description:
** pokemon.h
*/
#include <SFML/Graphics.h>

#ifndef POKEMON_H_
    #define POKEMON_H_

    typedef struct window_struct_s {
        sfVideoMode param;
        sfRenderWindow *window;
        sfSprite *sprite_bg;
        sfTexture *texture_bg;
        sfSprite *sprite_start;
        sfTexture *texture_start;
        sfSprite *sprite_quit;
        sfTexture *texture_quit;
    } window_struct_t;

#endif /* !POKEMON_H_ */
