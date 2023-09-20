#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Define a structure for user credentials
struct UserCredential {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct UserCredential *next; // Pointer to the next user in the list
};

// Function to add a new user to the list
struct UserCredential *addUser(struct UserCredential *head, const char *username, const char *password) {
    struct UserCredential *newUser = malloc(sizeof(struct UserCredential));
    if (newUser == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1); // Terminate the program in case of an allocation error
    }

    strncpy(newUser->username, username, MAX_USERNAME_LENGTH - 1);
    strncpy(newUser->password, password, MAX_PASSWORD_LENGTH - 1);
    newUser->username[MAX_USERNAME_LENGTH - 1] = '\0';
    newUser->password[MAX_PASSWORD_LENGTH - 1] = '\0';
    newUser->next = NULL;

    if (head == NULL) {
        return newUser;
    }

    // Find the last user in the list and link the new user
    struct UserCredential *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newUser;
    return head;
}

// Function to print all user credentials in the list
void printUsers(struct UserCredential *head) {
    struct UserCredential *current = head;
    int userCount = 1;

    while (current != NULL) {
        printf("User %d:\n", userCount++);
        printf("Username: %s\n", current->username);
        printf("Password: %s\n\n", current->password);
        current = current->next;
    }
}

// Function to free memory used by the list
void freeUsers(struct UserCredential *head) {
    struct UserCredential *current = head;
    while (current != NULL) {
        struct UserCredential *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct UserCredential *userList = NULL;
    int numUsers;

    // Prompt the user for the number of users they want to enter
    printf("Enter the number of users (0 to exit): ");
    scanf("%d", &numUsers);

    while (numUsers > 0) {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];

        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        // Add the user to the list
        userList = addUser(userList, username, password);

        // Prompt for the next user or exit
        printf("Enter the number of users (0 to exit): ");
        scanf("%d", &numUsers);
    }

    // Print all user credentials
    printUsers(userList);

    // Free memory used by the list
    freeUsers(userList);

    return 0;
}
