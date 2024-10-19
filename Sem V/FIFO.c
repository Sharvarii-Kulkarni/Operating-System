#include <stdio.h>
#include <stdlib.h>

int frame[20], rs[20];
int nf, lrs = 0, i, j, k = 0, rs1 = 0;
int pagefault = 0;

void displayfifo(int frame[]);

void accept()
{
    printf("\nEnter total number of frames : ");
    scanf("%d", &nf);
    printf("\nEnter reference string (enter -1 to end) : ");

    while (1)
    {
        scanf("%d", &rs1);
        if (rs1 == -1)
            break;

        rs[lrs++] = rs1;
    }
}
void display()
{
    printf("\nTotal Number of Frames : %d", nf);
    printf("\nReferences String :");
    for (i = 0; i < lrs; i++)
        printf("%d\t", rs[i]);
    printf("\nLength of Reference String : %d", lrs);
}
int searchpage(int rs)
{
    for (i = 0; i < nf; i++)
        if (rs == frame[i])
            return 1; // Return the index where the page is found
    return -1;      // Page not found
}


void displayfifo(int frame[])
{
    printf("\n");
    for (i = 0; i < nf; i++)
    {
        if (frame[i] != -1) // Check if the frame is valid
            printf("%d\t", frame[i]);
        else
            printf(" \t"); // Print a space for an empty frame
    }
    printf("\n");
}

void fifo()
{
    int i;
    pagefault = 0;
    for (i = 0; i < lrs; i++)
    {
        j = searchpage(rs[i]);
        if (j == -1)
        {
            frame[k] = rs[i];
            pagefault++;
        }
        displayfifo(frame);
        k = (k + 1) % nf;
    }
    printf("\nTotal no of page fault: %d\n", pagefault);
}

int main()
{
    accept();
    display();
    fifo();
    return 0;
}

