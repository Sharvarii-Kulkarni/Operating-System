Chatgpt
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct file_allocation_table {
    char name[20];
    int start, end, flag;
    struct file_allocation_table *link;
} DIR;

int d, fat[200], free_blocks;
DIR *first = NULL, *last = NULL;

void display_bit_vector() {
    printf("\nBit Vector:");
    for (int i = 0; i < d; i++) {
        printf("%d ", fat[i]);
    }
    printf("\n");
}

void display_directory() {
    DIR *p = first;
    printf("\nDirectory:");
    while (p != NULL) {
        if (p->flag == 0) {
            printf("\n%s\t%d\t%d", p->name, p->start, p->end);
        }
        p = p->link;
    }
    printf("\n");
}

int main() {
    int choice, file_size, i, j;
    char file_name[20];
    DIR *new_file;

    printf("Enter the number of disk blocks: ");
    scanf("%d", &d);

    // Initially, mark all blocks as free (-999)
    for (i = 0; i < d; i++)
        fat[i] = -999;
    
    free_blocks = d;

    while (1) {
        printf("\nMenu:\n1. Create New File\n2. Display Bit Vector\n3. Display Directory\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file size in number of blocks: ");
                scanf("%d", &file_size);

                if (file_size <= free_blocks) {
                    for (i = 0; i < d; i++) {
                        if (fat[i] == -999) {
                            file_size--;
                            break;
                        }
                    }
                    new_file = (DIR*)malloc(sizeof(DIR));
                    strcpy(new_file->name, file_name);
                    new_file->flag = 0;
                    new_file->start = j = i;
                    i++;

                    while (file_size != 0) {
                        if (fat[i] == -999) {
                            fat[j] = i;
                            j = i;
                            file_size--;
                        }
                        i++;
                    }
                    fat[j] = -1;
                    new_file->end = j;
                    new_file->link = NULL;
                    if (first == NULL)
                        first = new_file;
                    else
                        last->link = new_file;
                    last = new_file;
                    printf("File %s created successfully.\n", file_name);
                    free_blocks -= file_size;
                } else {
                    printf("Failed to create file %s. Not enough free space.\n", file_name);
                }
                break;
            case 2:
                display_bit_vector();
                break;
            case 3:
                display_directory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

