/*
** EPITECH PROJECT, 2023
** main
** File description:
** maion
*/
#include <SFML/Graphics.h>
#include "../include/pokemon.h"
#include <stdlib.h>

int init_screen(window_struct_t *stru_wind)
{
    stru_wind->param= (sfVideoMode){950, 720, 32};
    stru_wind->window =
    sfRenderWindow_create
    (stru_wind->param, "window1", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(stru_wind->window, 60);
    stru_wind->texture_bg =
    sfTexture_createFromFile("assets/finish_bg.jpg", NULL);
    stru_wind->sprite_bg = sfSprite_create();
    sfSprite_setTexture(stru_wind->sprite_bg,
    stru_wind->texture_bg, sfTrue);
    return 0;
}

int all_event_menu(window_struct_t *stru_wind)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(stru_wind->window, &event)) {
        if (event.type == sfEvtClosed ) {
            sfRenderWindow_close(stru_wind->window);
            return 1;
            }
    //    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyL)) {
    //        plane_tower_t->statut_t = !(plane_tower_t->statut_t);
    //    }
    //    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyL)) {
    //        plane_tower_t->statut_p = !(plane_tower_t->statut_p);
    //    }
    }
    return 0;
}

int loop_game (window_struct_t *stru_wind)
{
    while (sfRenderWindow_isOpen(stru_wind->window)) {
        sfRenderWindow_clear(stru_wind->window, sfBlue);
        button_menu(stru_wind);
        all_event_menu(stru_wind);
        sfRenderWindow_drawSprite(stru_wind->window,
        stru_wind->sprite_bg, NULL);
        sfRenderWindow_display(stru_wind->window);
    }
    sfRenderWindow_destroy(stru_wind->window);
    sfSprite_destroy(stru_wind->sprite_bg);
    sfTexture_destroy(stru_wind->texture_bg);
    free(stru_wind);
    return 0;
}

int button_menu(window_struct_t *stru_wind)
{
    stru_wind->texture_bg =
    sfTexture_createFromFile("assets/button_starts.jpg", NULL);
    stru_wind->sprite_start = sfSprite_create();
    sfSprite_setTexture(stru_wind->sprite_start,
    stru_wind->texture_start, sfTrue);
    return 0;
}

int main(int ac, char **av)
{
    window_struct_t *stru_wind =
    malloc(sizeof(window_struct_t));
    init_screen(stru_wind);
    loop_game(stru_wind);
    return (0);
}


//structure next prev sprite sheet -----------> structure global