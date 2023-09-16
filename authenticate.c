#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

typedef struct User User;

User users[MAX_USERS];
int userCount = 0;

// Function to save user data to a file
void saveUserDataToFile() {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

// Function to load user data from a file
void loadUserDataFromFile() {
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        return; // No existing user data file
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (fscanf(file, "%s %s", username, password) != EOF) {
        strcpy(users[userCount].username, username);
        strcpy(users[userCount].password, password);
        userCount++;
    }

    fclose(file);
}

// Function to check if a username is already taken
int isUsernameTaken(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1; // Username is taken
        }
    }
    return 0; // Username is not taken
}

// Function to sign up a new user
void signup() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a new username: ");
    scanf("%s", username);

    if (isUsernameTaken(username)) {
        printf("Username is already taken. Please choose a different one.\n");
        return;
    }

    printf("Enter a password: ");
    scanf("%s", password);

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;

    printf("Signup successful! You can now log in.\n");

    // Save the updated user data to the file
    saveUserDataToFile();
}

// Function to log in a user
void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful! Welcome, %s!\n", username);
            return;
        }
    }

    printf("Login failed. Please check your username and password.\n");
}

int main() {
    // Load user data from the file at the start of the program
    loadUserDataFromFile();

    int choice;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
