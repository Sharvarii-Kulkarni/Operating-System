#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 200
#define MAX_NAME_LENGTH 20

typedef struct FileEntry {
    char name[MAX_NAME_LENGTH];
    int index_block;
    int size;
    struct FileEntry *next;
} FileEntry;

FileEntry *first = NULL;
int bit_vector[MAX_BLOCKS];
int total_blocks;

void initialize() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        bit_vector[i] = 0;
    }
}

void showBitVector() {
    printf("Bit Vector:\n");
    for (int i = 0; i < total_blocks; i++) {
        printf("%d ", bit_vector[i]);
    }
    printf("\n");
}

void createNewFile() {
    char name[MAX_NAME_LENGTH];
    int size;
    
    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter file size in blocks: ");
    scanf("%d", &size);
    
    FileEntry *newFile = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newFile->name, name);
    newFile->size = size;
    
    int index_block = -1;
    for (int i = 0; i < total_blocks; i++) {
        int consecutive_blocks = 0;
        while (i < total_blocks && bit_vector[i] == 0 && consecutive_blocks < size) {
            consecutive_blocks++;
            i++;
        }
        if (consecutive_blocks == size) {
            index_block = i - size;
            break;
        }
    }
    
    if (index_block != -1) {
        newFile->index_block = index_block;
        newFile->next = NULL;
        for (int i = index_block; i < index_block + size; i++) {
            bit_vector[i] = 1;
        }
        
        if (first == NULL) {
            first = newFile;
        } else {
            FileEntry *current = first;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newFile;
        }
        
        printf("File created successfully.\n");
    } else {
        printf("Not enough contiguous blocks available to allocate memory for the file.\n");
        free(newFile);
    }
}

void showDirectory() {
    printf("Directory:\n");
    printf("Name\tIndex Block\tSize\n");
    FileEntry *current = first;
    while (current != NULL) {
        printf("%s\t%d\t\t%d\n", current->name, current->index_block, current->size);
        current = current->next;
    }
}

void deleteFile() {
    char name[MAX_NAME_LENGTH];
    
    printf("Enter file name to delete: ");
    scanf("%s", name);
    
    FileEntry *current = first;
    FileEntry *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            for (int i = current->index_block; i < current->index_block + current->size; i++) {
                bit_vector[i] = 0;
            }
            if (prev == NULL) {
                first = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("File deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("File not found.\n");
}

int main() {
    int choice;
    
    printf("Enter total number of blocks on disk: ");
    scanf("%d", &total_blocks);
    initialize();
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Create New File Allocation\n");
        printf("3. Show Directory\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                showBitVector();
                break;
            case 2:
                createNewFile();
                break;
            case 3:
                showDirectory();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    
    return 0;
}
