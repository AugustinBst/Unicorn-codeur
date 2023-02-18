/*
** EPITECH PROJECT, 2023
** pokemon.h
** File description:
** pokemon.h
*/
#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef POKEMON_H_
    #define POKEMON_H_

    typedef struct window_struct_s {
        sfVideoMode param;
        sfRenderWindow *window;
        sfSprite *sprite_bg;
        sfTexture *texture_bg;
        sfSprite *sprite_land;
        sfTexture *texture_land;
        sfSprite *sprite_start;
        sfTexture *texture_start;
        sfSprite *sprite_quit;
        sfTexture *texture_quit;
        bool display;
        sfEvent event;
        int coord_mouse_y;
        int coord_mouse_x;
        } window_struct_t;

    int open_file(char *buffer);

#endif /* !POKEMON_H_ */
