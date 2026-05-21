#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/obsidian.h"

void redirect_std(void) {
    cr_redirect_stdout();
    cr_redirect_stdin();
    setvbuf(stdout, NULL, _IONBF, 0);
}

Test(set_reactor_power, valid_power)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "500\n");
    set_reactor_power();
    cr_assert_stdout_eq_str(
        "Enter reactor power level: "
        "Reactor power set to: 1500\n"
        "Reactor operating within safe parameters.\n"
    );
    fclose(fin);
}

Test(set_reactor_power, limit_overflow)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "2147483647\n");
    set_reactor_power();
    cr_assert_stdout_eq_str(
        "Enter reactor power level: "
        "Invalid reactor power level. Input rejected.\n"
    );
    fclose(fin);
}

Test(set_reactor_power, negative_power)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "-50\n");
    set_reactor_power();
    cr_assert_stdout_eq_str(
        "Enter reactor power level: "
        "Invalid reactor power level. Input rejected.\n"
    );
    fclose(fin);
}

Test(set_reactor_power, empty_input)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "\n");
    set_reactor_power();
    cr_assert_stdout_eq_str(
        "Enter reactor power level: "
        "Invalid reactor power level. Input rejected.\n"
    );
    fclose(fin);
}

Test(set_reactor_power, non_numeric_input)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "abc\n");
    set_reactor_power();
    cr_assert_stdout_eq_str(
        "Enter reactor power level: "
        "Invalid reactor power level. Input rejected.\n"
    );
    fclose(fin);
}
