#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void fcfs_disk_scheduling(int requests[], int n, int head_position) {
    int total_seek_time = 0;
    printf("Sequence of disk accesses:\n");

    // Calculate seek time for each request
    for (int i = 0; i < n; i++) {
        printf("%d -> ", requests[i]);
        total_seek_time += abs(head_position - requests[i]);
        head_position = requests[i];
    }
    printf("\nTotal seek time: %d\n", total_seek_time);
}

int main() {
    int requests[MAX_REQUESTS];
    int n, head_position;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head_position);

    // Menu
    int choice;
    do {
        printf("\nFCFS Disk Scheduling Algorithm Menu\n");
        printf("1. Run FCFS Disk Scheduling\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fcfs_disk_scheduling(requests, n, head_position);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
