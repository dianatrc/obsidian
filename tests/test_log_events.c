#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/obsidian.h"

bool IS_ADMIN = false;

void redirect_std(void) {
    cr_redirect_stdout();
    cr_redirect_stdin();
    setvbuf(stdout, NULL, _IONBF, 0);
}

Test(log_system_event, standard_user)
{
    FILE *fin = NULL;
    IS_ADMIN = false;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "leak\n");
    fflush(fin);
    log_system_event();
    cr_assert_stdout_eq_str(
        "Enter command: "
        "Logging event: leak\n\n"
    );
    fclose(fin);
}

Test(log_system_event, admin_user)
{
    FILE *fin = NULL;
    IS_ADMIN = true;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "leak\n");
    fflush(fin);
    log_system_event();
    cr_assert_stdout_eq_str(
        "Enter command: "
        "Logging event: leak\n\n"
    );
    fclose(fin);
}

Test(log_system_event, verify_log_file_content)
{
    FILE *fin = NULL;
    IS_ADMIN = true;

    redirect_std();
    fin = cr_get_redirected_stdin();
    fprintf(fin, "leak\n");
    log_system_event();
    fclose(fin);

    FILE *log = fopen("Data/system.log", "r");
    char buffer[256];
    bool found_leak = false;

    while (fgets(buffer, sizeof(buffer), log)) {
        if (strstr(buffer, "SECRET_KEY_LEAKED"))
            found_leak = true;
    }
    fclose(log);
    cr_assert(found_leak == true, "Admin should be able to trigger the leak");
}
