#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ids = NULL;
char (*names)[50] = NULL;

int count = 0;

// ADD (realloc ginagamit dito)
void addStudent() {
    ids = realloc(ids, (count + 1) * sizeof(int));
    names = realloc(names, (count + 1) * sizeof(*names));

    printf("Enter ID: ");
    scanf("%d", &ids[count]);

    printf("Enter Name: ");
    scanf(" %[^\n]", names[count]);

    count++;
}

// VIEW
void viewStudents() {
    if(count == 0) {
        printf("No students yet!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s\n", ids[i], names[i]);
    }
}

// SEARCH
void searchStudent() {
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(ids[i] == id) {
            printf("Found: ID: %d | Name: %s\n", ids[i], names[i]);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Student not found!\n");
    }
}

// DELETE
void deleteStudent() {
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(ids[i] == id) {

            // SHIFT LEFT
            for(int j = i; j < count - 1; j++) {
                ids[j] = ids[j + 1];
                strcpy(names[j], names[j + 1]);
            }

            count--;

            // OPTIONAL: paliitin memory
            ids = realloc(ids, count * sizeof(int));
            names = realloc(names, count * sizeof(*names));

            printf("Student deleted!\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Student not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== DYNAMIC STUDENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1) addStudent();
        else if(choice == 2) viewStudents();
        else if(choice == 3) searchStudent();
        else if(choice == 4) deleteStudent();

    } while(choice != 5);

    // FREE MEMORY (important!)
    free(ids);
    free(names);

    return 0;
}

/*
reviewed

march 23, 2026
*/