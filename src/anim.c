/*
** EPITECH PROJECT, 2023
** anim
** File description:
** anim
*/

#include "../include/pokemon.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int name_way(char *buffer, int *count, int *line)
{
    char *word = malloc(sizeof(char) * *count);
    char *separ = malloc(sizeof(char) * *count);
    char **animation = malloc(sizeof(char*) * *line);
    int i = 0, nb = 0;
    char **name = malloc(sizeof(char*) * *count);
    char **way = malloc(sizeof(char*) * *count);


    while (word = strtok_r(buffer, "\n", &buffer)) {
        animation[i] = word;
        i++;
    }
    separ = animation[0];
    i--;
    for (int j = 0; i >= 0; i--, j++) {
        while (word = strtok_r(animation[i], "@", &animation[i])) {
            if (nb == 0)
                name[j] = word;
            else
                way[j] = word;
            nb++;
        }
        nb = 0;
    }
    return 0;
}

int nb_word(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '@' || buffer[i] == '\n')
            count++;
    }
    return count;
}

int nb_line(char *buffer, int *line)
{
    for (int i = 0; buffer[i] != '\n' && buffer; i++)
        *line = *line + 1;
    return 0;
}

int count_char(char *buffer, int *count)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        *count = *count + 1;
    }
    return *count;
}

int open_file(char *buffer)
{
    int fd, count = 0, line, chara;

    fd = open("assets/animations_sprite/name_anim.txt", O_RDONLY);
    if (fd == -1) {
        printf("This file doesn't exist!");
        return 84;
    }
    else {
        read(fd, buffer, 32000);
        line = nb_line(buffer, &line);
        chara = count_char(buffer, &count);
        count = nb_word(buffer);
        name_way(buffer, &count, &line);
        close(fd);
    }
    return 0;
}

