#include <stdio.h>
#include <string.h>
#include "login.h"

int login() {
    char username[50], password[50];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    return strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0;
}
