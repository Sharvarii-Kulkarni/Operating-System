Black Box ai

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BLOCKS 1000

int bitVector[MAX_BLOCKS/8 + 1];

// Function to initialize the bit vector
void initializeBitVector() {
    int i;
    for(i = 0; i < MAX_BLOCKS/8 + 1; i++) {
        bitVector[i] = 0;
    }
}

// Function to display the bit vector
void showBitVector() {
    int i, j;
    for(i = 0; i < MAX_BLOCKS/8 + 1; i++) {
        printf("Block %d : ", i*8);
        for(j = 7; j >= 0; j--) {
            (bitVector[i] & (1 << j))? printf("1 "): printf("0 ");
        }
        printf("\n");
    }
}

// Function to allocate a block
void allocateBlock(int block) {
    if(block >= 0 && block < MAX_BLOCKS) {
        int index = block/8;
        int offset = block%8;
        bitVector[index] = bitVector[index] | (1 << offset);
    }
}

// Function to deallocate a block
void deallocateBlock(int block) {
    if(block >= 0 && block < MAX_BLOCKS) {
        int index = block/8;
        int offset = block%8;
        bitVector[index] = bitVector[index] & ~(1 << offset);
    }
}

// Function to create a new file
void createNewFile(int n) {
    int i;
    for(i = 0; i < n; i++) {
        int block = rand() % MAX_BLOCKS;
        allocateBlock(block);
    }
}

// Function to display the directory
void showDirectory() {
    int i, count = 0;
    for(i = 0; i < MAX_BLOCKS/8 + 1; i++) {
        int j;
        for(j = 7; j >= 0; j--) {
            if(bitVector[i] & (1 << j)) {
                count++;
            }
        }
    }
    printf("Number of allocated blocks : %d\n", count);
}

int main() {
    int choice, n;
    srand(time(0));
    initializeBitVector();
    while(1) {
        printf("\n1. Show Bit Vector\n2. Create New File\n3. Show Directory\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                showBitVector();
                break;
            case 2:
                printf("Enter number of blocks : ");
                scanf("%d", &n);
                createNewFile(n);
                break;
            case 3:
                showDirectory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}