#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int score = 0;

    FILE *fptr;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Play Game\n");
        printf("2. Save Game\n");
        printf("3. Load Game\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                // simple game (random score)
                score = rand() % 100;
                printf("You played! Your score: %d\n", score);
                break;

            case 2:
                fptr = fopen("save.txt", "w");

                if (fptr == NULL) {
                    printf("Error saving file!\n");
                    break;
                }

                fprintf(fptr, "%d", score);
                fclose(fptr);

                printf("Game Saved!\n");
                break;

            case 3:
                fptr = fopen("save.txt", "r");

                if (fptr == NULL) {
                    printf("No save file found!\n");
                    break;
                }

                fscanf(fptr, "%d", &score);
                fclose(fptr);

                printf("Game Loaded! Score: %d\n", score);
                break;

            case 4:
                printf("Exiting game...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}