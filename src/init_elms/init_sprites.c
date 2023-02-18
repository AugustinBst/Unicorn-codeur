/*
** EPITECH PROJECT, 2023
** init_sprites
** File description:
** init_sprites
*/

#include <stdlib.h>
#include "sprite_struct.h"

static void define_rect(s_sprite_anim *my_sprite)
{
    sfFloatRect size = sfSprite_getGlobalBounds(my_sprite->sprite);
    my_sprite->rect.left = 0;
    my_sprite->rect.top = 0;
    my_sprite->nb_rect = size.height / 100;
    my_sprite->rect.height = 100;
    my_sprite->rect.width = 100;
}

static void define_clock(s_sprite_anim *my_sprite)
{
    my_sprite->clock = sfClock_create () ;
    my_sprite->time = sfClock_getElapsedTime(my_sprite->clock);
    my_sprite->seconds = my_sprite->time . microseconds / 1000000.0;
}

s_sprite_anim init_attack(char *path)
{
    s_sprite_anim my_sprite;

    my_sprite.texture = sfTexture_createFromFile(path, NULL);
    my_sprite.sprite = sfSprite_create();
    my_sprite.pos.x = 475;
    my_sprite.pos.y = 360;
    define_rect(&my_sprite);
    define_clock(&my_sprite);
    sfSprite_setTexture(my_sprite.sprite, my_sprite.texture, sfTrue);
    sfSprite_setPosition(my_sprite.sprite, my_sprite.pos);
    sfSprite_setTextureRect(my_sprite.sprite, my_sprite.rect);
    return (my_sprite);
}
