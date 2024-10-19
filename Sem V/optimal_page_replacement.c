#include <stdio.h>
#include <stdbool.h>
// function to identify if the page is present in the frame or not
bool isPageInFrame(int key, int frame[], int numOfFrames)
{
    for (int i = 0; i < numOfFrames; i++)
    {
        if (frame[i] == key)
           return true;
    }
    return false;
}
// function that will identify the frame which has its demand very late in the future

int predictPageToReplace(int pages[], int numPages, int frame[], int numOfFrames, int index)
{
    printf("Index = %d",index); 
    int result = -1, farthest = index;
    for (int i = 0; i < numOfFrames; i++)
    {
        int j;
        for (j = index; j < numPages; j++)
        {
            if (frame[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == numPages)
            return i;
    }
    return (result == -1) ? 0 : result;
}
void optimalPageReplacement(int pages[], int numPages, int numOfFrames)
{
     // an array for all the frames
    int frame[numOfFrames];
    int hit = 0;
    int index = 0;
    //Check for page fault or page hit
    for (int i = 0; i < numPages; i++)
    {
        if (isPageInFrame(pages[i], frame, numOfFrames))
        {
            hit++;
            continue;
        }
        if (index < numOfFrames)
            frame[index++] = pages[i];
        else
        {
            int j = predictPageToReplace(pages, numPages, frame, numOfFrames, i + 1);
            frame[j] = pages[i];
        }
    }
    printf("The total number of page hit is %d\n", hit);
    printf("The total number of page fault is %d\n", (numPages - hit));
}
// main function
int main()
{
    int pages[] = {1, 3, 2, 4, 2, 3, 1, 4, 2, 4, 1, 3};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    int numOfFrames = 3;
    optimalPageReplacement(pages, numPages, numOfFrames);
    return 0;
}