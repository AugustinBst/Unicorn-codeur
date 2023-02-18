/*
** EPITECH PROJECT, 2023
** move_list
** File description:
** move_list
*/

#include "lst_path.h"
#include "list_sprite_anim.h"

void move_list_forward(m_path **lst_path, m_sprite_lst **ani_lst)
{
    (*lst_path) = (*lst_path)->next;
    (*ani_lst) = (*ani_lst)->next;
}

void move_list_backward(m_path **lst_path, m_sprite_lst **ani_lst)
{
    (*lst_path) = (*lst_path)->prev;
    (*ani_lst) = (*ani_lst)->prev;
}
