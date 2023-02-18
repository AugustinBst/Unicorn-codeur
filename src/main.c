/*
** EPITECH PROJECT, 2023
** main
** File description:
** maion
*/
#include <SFML/Graphics.h>
#include "../include/pokemon.h"
#include <stdlib.h>

int mouse_pos(window_struct_t *stru_wind)
{
    sfVector2i hunter_mous_pos =
    sfMouse_getPositionRenderWindow(stru_wind->window);
    sfVector2f pos_start = sfSprite_getPosition(stru_wind->sprite_start);
    sfVector2u size_start = sfTexture_getSize(stru_wind->texture_start);
    sfVector2f pos_quit = sfSprite_getPosition(stru_wind->sprite_quit);
    sfVector2u size_quit = sfTexture_getSize(stru_wind->texture_quit);

    if ( pos_start.x <= hunter_mous_pos.x && hunter_mous_pos.x <= pos_start.x + size_start.x * 0.25 &&
    pos_start.y <= hunter_mous_pos.y && hunter_mous_pos.y <= pos_start.y + size_start.y * 0.25) {
        stru_wind->display = false;
    }
    if ( pos_quit.x <= hunter_mous_pos.x && hunter_mous_pos.x <= pos_quit.x + size_quit.x * 0.25 &&
    pos_quit.y <= hunter_mous_pos.y && hunter_mous_pos.y <= pos_quit.y + size_quit.y * 0.25) {
        return 1;
    }
    return 0;
}        sfSprite *sprite_land;
        sfTexture *texture_land;


int init_land(window_struct_t *stru_wind)
{
    stru_wind->texture_land =
    sfTexture_createFromFile("assets/land.png", NULL);
    stru_wind->sprite_land = sfSprite_create();
    sfSprite_setTexture(stru_wind->sprite_land,
    stru_wind->texture_land, sfTrue);
    sfSprite_setScale(stru_wind->sprite_land, (sfVector2f){ 1.2, 1.5});

    return 0;
}

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

int button_menu(window_struct_t *stru_wind)
{
    stru_wind->texture_start =
    sfTexture_createFromFile("assets/button_start.png", NULL);
    stru_wind->sprite_start = sfSprite_create();
    sfSprite_setTexture(stru_wind->sprite_start,
    stru_wind->texture_start, sfTrue);
    sfSprite_setScale(stru_wind->sprite_start, (sfVector2f){ 0.3, 0.3});
    sfSprite_setPosition(stru_wind->sprite_start, (sfVector2f){100, 450});

//-----------boutton Quit
    stru_wind->texture_quit =
    sfTexture_createFromFile("assets/quit_button.png", NULL);
    stru_wind->sprite_quit = sfSprite_create();
    sfSprite_setTexture(stru_wind->sprite_quit,
    stru_wind->texture_quit, sfTrue);
    sfSprite_setScale(stru_wind->sprite_quit, (sfVector2f){ 0.3, 0.3});
    sfSprite_setPosition(stru_wind->sprite_quit, (sfVector2f){500, 450});
    return 0;
}

int destroy_package(window_struct_t *stru_wind)
{
    sfSprite_destroy(stru_wind->sprite_bg);
    sfTexture_destroy(stru_wind->texture_bg);
    sfSprite_destroy(stru_wind->sprite_start);
    sfTexture_destroy(stru_wind->texture_start);
    sfSprite_destroy(stru_wind->sprite_quit);
    sfTexture_destroy(stru_wind->texture_quit);
    return 0;
}

int all_event_menu(window_struct_t *stru_wind)
{
    sfEvent event;
    int indice = 0;
    while (sfRenderWindow_pollEvent(stru_wind->window, &event)) {
        if (event.type == sfEvtClosed ) {
            sfRenderWindow_close(stru_wind->window);
            return 1;
            }
        if (event.type == sfEvtMouseButtonPressed && stru_wind->display != false) {
            if (mouse_pos(stru_wind) == 1) {
                sfRenderWindow_close(stru_wind->window);
            }
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

int draw_land(window_struct_t *stru_wind)
{
    sfRenderWindow_drawSprite(stru_wind->window,
    stru_wind->sprite_land, NULL);
    return 0;
}

int draw_menu(window_struct_t *stru_wind)
{
    sfRenderWindow_drawSprite(stru_wind->window,
    stru_wind->sprite_bg, NULL);
    sfRenderWindow_drawSprite(stru_wind->window,
    stru_wind->sprite_start, NULL);
    sfRenderWindow_drawSprite(stru_wind->window,
    stru_wind->sprite_quit, NULL);
}

int loop_menu (window_struct_t *stru_wind)
{
    while (sfRenderWindow_isOpen(stru_wind->window)) {
        sfRenderWindow_clear(stru_wind->window, sfBlue);
        if (stru_wind->display == true) {
            draw_menu(stru_wind);
        } else {
            init_land(stru_wind);
            draw_land(stru_wind);
        }
        all_event_menu(stru_wind);
        sfRenderWindow_display(stru_wind->window);
    }
    destroy_package(stru_wind);
    sfRenderWindow_destroy(stru_wind->window);
    free(stru_wind);
    return 0;
}

int main(int ac, char **av)
{
    window_struct_t *stru_wind =
    malloc(sizeof(window_struct_t));
    stru_wind->display = true;
    init_screen(stru_wind);
    button_menu(stru_wind);
    loop_menu(stru_wind);
    return (0);
}


//structure next prev sprite sheet -----------> structure global