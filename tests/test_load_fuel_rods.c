/*
** EPITECH PROJECT, 2026
** Obsidian
** File description:
** Unit tests for the load_fuel_rods command
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "obsidian.h"

void redirect_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stdin();
    setvbuf(stdout, NULL, _IONBF, 0);
}

Test(load_fuel_rods, two_fuel_rods)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "2\n");
    load_fuel_rods();
    cr_assert_stdout_eq_str(
        "Loading fuel rods...\n"
        "Enter the number of fuel rods to load (max 10): "
        "Fuel rod 1 loaded.\n"
        "Fuel rod 2 loaded.\n"
    );
    fclose(fin);
}

Test(load_fuel_rods, zero_fuel_rods)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "0\n");
    load_fuel_rods();
    cr_assert_stdout_eq_str(
        "Loading fuel rods...\n"
        "Enter the number of fuel rods to load (max 10): "
    );
    fclose(fin);
}

Test(load_fuel_rods, ten_fuel_rods)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "10\n");
    load_fuel_rods();
    cr_assert_stdout_eq_str(
        "Loading fuel rods...\n"
        "Enter the number of fuel rods to load (max 10): "
        "Fuel rod 1 loaded.\n"
        "Fuel rod 2 loaded.\n"
        "Fuel rod 3 loaded.\n"
        "Fuel rod 4 loaded.\n"
        "Fuel rod 5 loaded.\n"
        "Fuel rod 6 loaded.\n"
        "Fuel rod 7 loaded.\n"
        "Fuel rod 8 loaded.\n"
        "Fuel rod 9 loaded.\n"
        "Fuel rod 10 loaded.\n"
    );
    fclose(fin);
}

Test(load_fuel_rods, fifteen_fuel_rods)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "15\n");
    load_fuel_rods();
    cr_assert_stdout_eq_str(
        "Loading fuel rods...\n"
        "Enter the number of fuel rods to load (max 10): "
        "Error: Too many fuel rods!\n"
    );
    fclose(fin);
}

Test(load_fuel_rods, negative_fuel_rods)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "-1\n");
    load_fuel_rods();
    cr_assert_stdout_eq_str(
        "Loading fuel rods...\n"
        "Enter the number of fuel rods to load (max 10): "
        "Error: negative number not allowed!\n"
    );
    fclose(fin);
}
