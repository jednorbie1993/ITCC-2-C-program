#include <stdio.h>

int main() {
    int password;
    int choice;
    int score = 0;

    // LOGIN
    printf("Enter password (1234): ");
    scanf("%d", &password);

    if (password != 1234) {
        printf("Wrong password. Exit.\n");
        return 0;
    }

    printf("Login successful!\n");

    // MENU
    printf("\n=== MENU ===\n");
    printf("1. Play Game\n");
    printf("2. Show Score\n");
    printf("3. Exit\n");

    printf("Choose: ");
    scanf("%d", &choice);

    // SIMPLE LOGIC
    if (choice == 1) {
        printf("You played the game! +10 points\n");
        score = 10;
    }
    else if (choice == 2) {
        printf("Your score is: %d\n", score);
    }
    else {
        printf("Goodbye!\n");
    }

    return 0;
}
