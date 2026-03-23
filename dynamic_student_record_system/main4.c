#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
};

struct Student *students = NULL;
int count = 0;

// LOAD FROM FILE
void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL) return;

    while(1) {
        struct Student temp;

        if(fscanf(fp, "%d %[^\n]", &temp.id, temp.name) != 2)
            break;

        students = realloc(students, (count + 1) * sizeof(struct Student));
        students[count] = temp;
        count++;
    }

    fclose(fp);
}

// SAVE TO FILE
void saveToFile() {
    FILE *fp = fopen("students.txt", "w");

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%d %s\n", students[i].id, students[i].name);
    }

    fclose(fp);
}

// ADD
void addStudent() {
    students = realloc(students, (count + 1) * sizeof(struct Student));

    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    count++;
}

// VIEW
void viewStudents() {
    if(count == 0) {
        printf("No students found!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s\n", students[i].id, students[i].name);
    }
}

// SEARCH
void searchStudent() {
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Found: ID: %d | Name: %s\n",
                   students[i].id, students[i].name);
            found = 1;
            break;
        }
    }

    if(!found) printf("Student not found!\n");
}

// DELETE
void deleteStudent() {
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {

            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            students = realloc(students, count * sizeof(struct Student));

            printf("Student deleted!\n");
            found = 1;
            break;
        }
    }

    if(!found) printf("Student not found!\n");
}

int main() {
    int choice;

    loadFromFile(); // auto load

    do {
        printf("\n===== STUDENT SYSTEM (FILE) =====\n");
        printf("1. Add\n2. View\n3. Search\n4. Delete\n5. Save & Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1) addStudent();
        else if(choice == 2) viewStudents();
        else if(choice == 3) searchStudent();
        else if(choice == 4) deleteStudent();
        else if(choice == 5) {
            saveToFile();
            printf("Saved to file!\n");
        }

    } while(choice != 5);

    free(students);
    return 0;
}

/*
reviewed

march 23, 2026
*/