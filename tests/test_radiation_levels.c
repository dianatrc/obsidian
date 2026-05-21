#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/obsidian.h"

void redirect_std(void) {
    cr_redirect_stdout();
    cr_redirect_stdin();
    setvbuf(stdout, NULL, _IONBF, 0);
}

Test(monitor_radiation_levels, check_null_function_pointer)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "10\n");
    monitor_radiation_levels();
    cr_assert_stdout_eq_str(
        "Enter radiation levels: "
        "Radiation Levels: 10\n"
        "Function Pointer: (nil)\n"
    );
    fclose(fin);
}

Test(monitor_radiation_levels, max_buffer_input)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "1111111111111111111111111111111\n");
    monitor_radiation_levels();
    cr_assert_stdout_eq_str(
        "Enter radiation levels: "
        "Radiation Levels: 1111111111111111111111111111111\n"
        "Function Pointer: (nil)\n"
    );
    fclose(fin);
}

Test(monitor_radiation_levels, empty_input)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "\n");
    monitor_radiation_levels();
    cr_assert_stdout_eq_str(
        "Enter radiation levels: "
        "Radiation Levels: \n"
        "Function Pointer: (nil)\n"
    );
    fclose(fin);
}

Test(monitor_radiation_levels, overflow_input)
{
    FILE *fin = NULL;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "1111111111111111111111111111111111\n");
    monitor_radiation_levels();
    cr_assert_stdout_eq_str(
        "Enter radiation levels: "
        "Radiation Levels: 1111111111111111111111111111111\n"
        "Function Pointer: (nil)\n"
    );
    fclose(fin);
}
