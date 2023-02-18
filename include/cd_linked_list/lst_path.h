/*
** EPITECH PROJECT, 2023
** lst_path
** File description:
** lst_path
*/

#ifndef LST_PATH_
    #define LST_PATH_

typedef struct m_lst_path{
    char *name;
    char *path;
    struct m_lst_path *next;
    struct m_lst_path *prev;
} m_path;

#endif /* !LST_PATH_ */
