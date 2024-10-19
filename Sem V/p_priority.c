//preemptive_priority
#include<stdio.h>

struct Input
{
    char pname[10];
    int  bt,at,ct,tbt,p;
}tab[5];

struct Sequence
{
    int start,end;
    char pname[10];
}seq[100],seq1[20];

int finish,time,n,k,prev,q;

void getinput()
{
    int i;
    printf("\nEnter No.of Processes:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Process name:");
        scanf("%s",tab[i].pname);
        printf("Burst time:");
        scanf("%d",&tab[i].bt);
        printf("Arrival time:");
        scanf("%d",&tab[i].at);
        printf("Enter priority: ");
        scanf("%d",&tab[i].p);

        tab[i].tbt = tab[i].bt;
    }
}
void printinput()
{
    int i;

    printf("\nProcess\tBT\tAT\tpriority");
    for(i=0;i<n;i++)
        printf("\n%s\t%d\t%d\t%d",tab[i].pname,tab[i].tbt,tab[i].at,tab[i].p);
    getch();
}

void bubble()
{
    struct Input t;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j< (n-1)-i;j++)
            if(tab[j].at>tab[j+1].at)
            {
                t = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = t;
            }
}
int getmin(int t)
{
    int i,mini,min=99;
    for(i=0;i<n;i++)
        if(tab[i].at<=t && tab[i].tbt!=0 && tab[i].p<min)
        {
            min = tab[i].p;
            mini = i;
        }
    return mini;
}


void printoutput()
{
    int i;
    float AvgTAT=0,AvgWT=0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\n%s\t%d\t%d\t%d\t%d\t%d",tab[i].pname,
                              tab[i].at,
                              tab[i].bt,
                              tab[i].ct,
                              tab[i].ct-tab[i].at,
                              tab[i].ct-tab[i].at-tab[i].bt);
        AvgTAT += tab[i].ct-tab[i].at;
        AvgWT += tab[i].ct-tab[i].at-tab[i].bt;
    }
    AvgTAT/=n;
    AvgWT/=n;
    printf("\nAverage TAT = %f",AvgTAT);
    printf("\nAverage WT = %f",AvgWT);
    getch();
}

int arrived(int t)
{
    int i;
    for(i=0;i<n;i++)
        if(tab[i].at<=t && tab[i].tbt!=0)
            return 1;
    return 0;
}

void processinput()
{
    int i=0,j;
    finish = k = 0;
    while(finish!=n)
    {
        if(arrived(time))
        {
                  i=getmin(time);
                    time++;
                    tab[i].tbt--;
                    printinput();
                    seq[k].start=prev;
                    seq[k].end = time;
                    strcpy(seq[k++].pname,tab[i].pname);
                    prev = time;
                    tab[i].ct=time;
                    if(tab[i].tbt==0)
                    {
                        finish++;

                     }

        }
        else
        {
            time++;
            seq[k].start=prev;
            seq[k].end = time;
            strcpy(seq[k++].pname,"*");
            prev = time;
        }

    }
}

void ganttchart()
{
    int i,j=1;
    seq1[0] = seq[0];
    for(i=1;i<k;i++)
    {
        if(strcmp(seq1[j-1].pname,seq[i].pname)==0)
            seq1[j-1].end = seq[i].end;
        else
            seq1[j++] = seq[i];
    }
    for(i=0;i<j;i++)
        printf("\n%d\t%s\t%d",seq1[i].start,seq1[i].pname,seq1[i].end);
    getch();
}

void main()
{
    int i;
    getinput();
    printf("\nEntered data-: ");
    printinput();
    bubble();
    printf("\nData after sorting according to arrival time-: ");
    printinput();
    processinput();

    printoutput();

    ganttchart();

    
}

