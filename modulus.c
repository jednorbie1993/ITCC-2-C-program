#include <stdio.h>

int main() {
    int total_seconds;
    int hours, minutes, seconds;

    printf("Enter total seconds: ");
    scanf("%d", &total_seconds);

    hours = total_seconds / 3600;
    minutes = (total_seconds % 3600) / 60;
    seconds = total_seconds % 60;

    printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    return 0;
}
