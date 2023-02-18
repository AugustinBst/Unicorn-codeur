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

char **name_way(char *buffer, int *count, int *line)
{
    char *word = malloc(sizeof(char) * *count);
    char **animation = malloc(sizeof(char*) * (*count * 2) + 1);
    int i = 0;

    while (word = strtok_r(buffer, "@\n", &buffer)) {
        animation[i] = word;
        i++;
    }
    printf("%s\n", animation[2]);
    return animation;
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