/*
** EPITECH PROJECT, 2023
** init_linked_list
** File description:
** init_linked_list
*/

#include "list_sprite_anim.h"
#include "lst_path.h"

int init_linked_list(char **elms, m_sprite_lst *anim_lst, m_path *path_lst)
{
    int state = 0;
    int nb_elm = 0;

    for (; elms[nb_elm] != NULL; nb_elm += 2){
        if (state == 0){
            set_fnode_path(&elms[nb_elm], path_lst);
            set_fnode_anim(path_lst, &anim_lst);
            state++;
        }
        set_node_path(&elms[nb_elm], &path_lst);
        set_node_anim(path_lst, &anim_lst);
    }
    return (0);
}
