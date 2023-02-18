/*
** EPITECH PROJECT, 2023
** set_node
** File description:
** set_node
*/

#include "lst_path.h"
#include "list_sprite_anim.h"

void set_node_path(char **elms,  m_path **lst)
{
    m_path *path = malloc(sizeof(m_path));
    path->name = strdup(elms[0]);
    path->path = strndup(elms[1], strlen(elms[1] - 1));
    path->next = (*lst);
    path->prev = (*lst)->prev;
    path->prev->next = path;
    (*lst)->prev = path;
    (*lst) = (*lst)->prev;
}

void set_node_anim(m_path **path, m_sprite_lst **anim)
{
    m_sprite_lst *elm_anim = malloc(sizeof(m_sprite_lst));
    s_sprite_anim sprite = init_attack((*path)->path);
    elm_anim->sprite = sprite;
    elm_anim->next = (*anim);
    elm_anim->prev = (*anim)->prev;
    elm_anim->prev->next = elm_anim;
    (*anim)->prev = elm_anim;
    (*anim) = (*anim)->prev;
}
