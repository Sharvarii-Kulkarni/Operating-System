#include<stdio.h>
int arr[10], tat[10], wt[10], pr[10], bt[10], ct[10] = {0}, flag[10] = {0}, k;

void Accepttimes(int *a, int n) 
{
    int i;
    printf("\n Enter values:");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
}

void schedule(int n) 
{
    int i = 0, count = 0;
    while (count < n) 
	{
        int min = 100, minindex = -1;
        for (int l = 0; l < n; l++) 
		{
            if (flag[l] == 0 && arr[l] <= i && bt[l] < min) 
			{
                min = bt[l];
                minindex = l;
            }
        }
        if (minindex != -1) 
		{
            bt[minindex]--;
            if (bt[minindex] == 0) 
			{
                ct[minindex] = i + 1;
                flag[minindex] = 1;
                tat[minindex] = ct[minindex] - arr[minindex];
                wt[minindex] = tat[minindex] - bt[minindex];
                k++;
                count++;
            }
        }
        i++;
    }
}

void displaytimes(int *a, int n) 
{
    int i;
    printf("\t");
    for (i = 0; i < n; i++) 
	{
        printf("\n %d", a[i]);
    }
}

int main() 
{
    int i, n,;
    printf("\n Enter number of processes to execute:");
    scanf("%d", &n);
    printf("\n Accepting arrival time:");
    Accepttimes(arr, n);
    printf("\n Accepting Burst time");
    Accepttimes(bt, n);

    k = 0;
    schedule(n);

    printf("\n Success");
    printf("\n Completion time is: ");
    printf("\n");
    printf("\t Turnaround time is");
    displaytimes(tat, n);
    printf("\t Waiting times");
    displaytimes(wt, n);
    printf("\n Average turnaround time");
    int sum = 0;
    for (i = 0; i < n; i++) 
	{
        sum += tat[i];
    }
    float atat = (float) sum / n;
    printf("\t %.2f", atat);
    sum = 0;
    printf("\n Average waiting time");
    for (i = 0; i < n; i++) 
	{
        sum += wt[i];
    }
    float awt = (float) sum / n;
    printf("\t %.2f", awt);
    printf("\n Gantt chart is :");

    for (i = 0; i < n; i++) 
	{
        printf("\t p%d", i + 1);
    }
    printf("\n");
    printf("\t 0\t");
    for (i = 0; i < n; i++) 
	{
        printf("\t %d", ct[i]);
    }
    return 0;
}