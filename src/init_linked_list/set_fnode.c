/*
** EPITECH PROJECT, 2023
** set_fnode
** File description:
** set_fnode
*/

#include <string.h>
#include <stdlib.h>
#include "lst_path.h"
#include "list_sprite_anim.h"

void set_fnode_path(char **elms,  m_path **lst)
{
    m_path *path = malloc(sizeof(m_path));
    path->name = strdup(elms[0]);
    path->path = strdup(elms[1]);
    path->next = path;
    path->prev = path;
    (*lst) = path;
}

void set_fnode_anim(m_path **path, m_sprite_lst **anim)
{
    m_sprite_lst *elm_anim = malloc(sizeof(m_sprite_lst));
    s_sprite_anim sprite = init_attack((*path)->path);
    elm_anim->sprite = sprite;
    elm_anim->next = elm_anim;
    elm_anim->prev = elm_anim;
    (*anim) = elm_anim;
}
