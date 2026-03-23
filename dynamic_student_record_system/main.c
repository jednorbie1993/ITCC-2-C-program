#include <stdio.h>
#include <string.h>

#define MAX 100

struct student {
    int id;
    char name[50];
};

struct student students[MAX];
int count = 0;

void addstudent() {
    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name); //" %[^\n]" whole name if %s lang putol kapag may space na

    count++;
}

void viewStudents() {
    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s\n", students[i].id, students[i].name);

    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Student\n2. View Students\n3. Exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            addstudent();
        }
        else if(choice == 2) {
            viewStudents();
        }
    } while(choice != 3);

    return 0;
}


/*
Best beginner project ideas:
1. 📊 Dynamic Student Record System

👉 (Ito pinaka recommended ko)

Features:

add student
view students
delete student
search student
gumagamit ng malloc/realloc

💥 bakit solid to:

may arrays
may pointers
may dynamic memory
parang mini database
*/