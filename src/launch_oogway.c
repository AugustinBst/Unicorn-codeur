/*
** EPITECH PROJECT, 2023
** SRC
** File description:
** launch_oogway
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/pokemon.h"
#include "../include/oog.h"

int launch_oogway(window_struct_t *win, oog_t *oog)
{
    sfRenderWindow_drawSprite(win->window, oog->background.back_sprite, NULL);
    sfRenderWindow_drawSprite(win->window, oog->oogway.oog_sprite, NULL);
    sfRenderWindow_drawSprite(win->window, oog->carapuce.carap_sprite, NULL);
    return 0;
}
