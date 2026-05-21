/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** activate_emergency_protocols
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/obsidian.h"

int main(void) {
    setenv("ADMIN_PASSWORD", "admin123", 1);
    printf("succes\n");
    return 0;
}