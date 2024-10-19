#include<stdio.h>
#include<stdlib.h>
struct frame
{
	int value,cnt,freq;
}f[20];
int frame[20],rs[20],cf=0,at[10][10];
int nf,lrs;
void accept()
{
	int rs1 = 0;
	printf("\nEnter total number of frames : ");
	scanf("%d",&nf);
	printf("\nEnter reference string : ");
	while(rs1!=-1)
	{
		scanf("%d",&rs1);
		rs[lrs++]=rs1;
	}
}
void display()
{
	int  i;
	printf("\nTotal Number of Frames : %d",nf);
	printf("\nReferences String :");
	for(i=0;i<lrs-1;i++)
		printf("%d\t",rs[i]);
	printf("\nLenght of Reference String : %d\n",lrs-1);
}
search_page_mfu(int rs)
{
	int i=0;
	for(i=0;i<nf;i++)
		if(rs==f[i].value)
			return i;
	return -1;
}
int getMFU()
{
	int fno,i=0;
	int selfno=0,tcnt=0,mini=100;
	for (fno=1; fno<nf; fno++)
	{
		if(f[fno].freq<=f[selfno].freq)
		{	
			selfno=fno;
			at[tcnt][0]=fno;
			at[tcnt][1]=f[fno].cnt;
			tcnt++;

		}
	}
	for(i=0;i<tcnt;i++)
	{
//		printf("\narrival \n\n");
//		printf("%d",at[i][1]);
		if(at[i][1]<mini)
		{
			selfno=at[i][0];
			mini=at[i][1];
		}
	}
	return selfno;
}
mfu()
{
	int time=0;
	int i,k,j,pagefault=0,d;
	for(i=0,k=0;k<nf&&i<lrs-1;i++)
	{
		j=search_page_mfu(rs[i]);
		if(j==-1)
		{
			f[k].value=rs[i];
			f[k].freq=1;
			f[k].cnt=time;
			pagefault++;
			k++;			
		}
		else
		{
			f[j].freq++;	
		}
		for(d=0;d<nf;d++)
			printf("%d (%d)\t",f[d].value,f[d].freq);
		printf("\n");
		time++;
	}
	while(i<lrs-1)
	{
		j=search_page_mfu(rs[i]);
		if(j==-1)
		{
			k=getMFU();
			f[k].value=rs[i];
			f[k].freq=1;
			f[k].cnt=time;
			pagefault++;
			i++;
		}
		else
		{
			f[j].freq++;
			i++;		
		}
		for(d=0;d<nf;d++)
			printf("%d (%d)\t",f[d].value,f[d].freq);			
		printf("\n");
		time++;
	}
	printf("\nTotal no of page fault %d\n",pagefault);
}
void main()
{
	accept();
	display();
	mfu();
}
