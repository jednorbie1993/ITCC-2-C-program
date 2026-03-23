#include <stdio.h>
#include <string.h>

#define MAX 100

int ids[MAX];
char names[MAX][50];

int count = 0;

// ADD
void addStudent() {
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
    int id;
    int found = 0;

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
    int id;
    int found = 0;

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
        printf("\n===== STUDENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            addStudent();
        }
        else if(choice == 2) {
            viewStudents();
        }
        else if(choice == 3) {
            searchStudent();
        }
        else if(choice == 4) {
            deleteStudent();
        }

    } while(choice != 5);

    return 0;
}

/*
reviewed

march 23, 2026 1 times
*/