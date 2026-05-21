/*
** EPITECH PROJECT, 2026
** Obsidian
** File description:
** Unit tests for the run_diagnostic command
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "obsidian.h"

bool IS_ADMIN = false;

void redirect_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stdin();
    setvbuf(stdout, NULL, _IONBF, 0);
}

Test(run_diagnostic, debug_mode_regular_user)
{
    FILE *fin = NULL;

    redirect_std();
    IS_ADMIN = false;
    fin = cr_get_redirected_stdin();
    fprintf(fin, "debug\n");
    run_diagnostic();
    cr_assert_stdout_eq_str(
        "Enter diagnostic mode (normal/debug/advanced): "
        "Running diagnostic...\n"
        "Diagnostic result: Code 1001\n"
        "Performing system health check...\n"
        "System health: OK\n"
        "Diagnostic complete.\n"
    );
    fclose(fin);
}

Test(run_diagnostic, debug_mode_admin_user)
{
    FILE *fin = NULL;

    redirect_std();
    IS_ADMIN = true;
    fin = cr_get_redirected_stdin();
    fprintf(fin, "debug\n");
    run_diagnostic();
    cr_assert_stdout_eq_str(
        "Enter diagnostic mode (normal/debug/advanced): "
        "Running diagnostic...\n"
        "Diagnostic result: {SECRET DIAGNOSTIC KEY}\n"
        "Performing system health check...\n"
        "System health: OK\n"
        "Diagnostic complete.\n"
    );
    fclose(fin);
}

Test(run_diagnostic, normal_mode_normal_user)
{
    FILE *fin = NULL;

    redirect_std();
    IS_ADMIN = false;
    fin = cr_get_redirected_stdin();
    fprintf(fin, "normal\n");
    run_diagnostic();
    cr_assert_stdout_eq_str(
        "Enter diagnostic mode (normal/debug/advanced): "
        "Running diagnostic...\n"
        "Error: Diagnostic data is unavailable (NULL pointer).\n"
        "Performing system health check...\n"
        "System health: OK\n"
        "Diagnostic complete.\n"
    );
    fclose(fin);
}

Test(run_diagnostic, normal_mode_admin_user)
{
    FILE *fin = NULL;

    redirect_std();
    IS_ADMIN = true;
    fin = cr_get_redirected_stdin();
    fprintf(fin, "normal\n");
    run_diagnostic();
    cr_assert_stdout_eq_str(
        "Enter diagnostic mode (normal/debug/advanced): "
        "Running diagnostic...\n"
        "Error: Diagnostic data is unavailable (NULL pointer).\n"
        "Performing system health check...\n"
        "System health: OK\n"
        "Diagnostic complete.\n"
    );
    fclose(fin);
}
