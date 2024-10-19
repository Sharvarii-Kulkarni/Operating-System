#include<stdio.h>
#include<stdlib.h>
struct frame
{
	int value,cnt;
}fr[20];
int frame[20],rs[20],cf=0;
int nf,lrs;
void accept()
{
	int rs1=0;
	printf("\nEnter total number of frames : ");
	scanf("%d",&nf);
	printf("\nEnter reference string :");
	while(rs1!=-1)
	{
		scanf("%d",&rs1);
		rs[lrs++]=rs1;
	}
}
void display()
{
	int i;
	printf("\nTotal Number of Frames : %d",nf);
	printf("\nReferences String :");
	for(i=0;i<lrs;i++)
		printf("%d\t",rs[i]);
	printf("\nLength of Reference String : %d\n",lrs);
}
int search_page_lru(int rs)
{
	int i=0;
	for(i=0;i<nf;i++)
		if(rs==fr[i].value)
			return i;
	return -1;
}
int getLRU()
{
	int min=999,i,val;
	for(i=0;i<=nf;i++)
	{
		if(fr[i].cnt<=min)
		{
			min=fr[i].cnt;
			val=i;
		}
	}
	return val;
}
lru()
{
	int i,k,j,time=1,page_fault=0,d;
	for(i=0,k=0;i<lrs-1;i++)
	{
		j=search_page_lru(rs[i]);
		if(j==-1)
		{
			fr[k].value=rs[i];
			fr[k].cnt=time;
			page_fault++;
			k++;
			time++;
			if(k == nf)
			   break;
		}
		else
		{
			fr[j].cnt=time;
			time++;
		}
		for(d=0;d<nf;d++)
			printf("%d\t",fr[d].value);
		printf("\n");
	}
	while(i<lrs-1)
	{
		j=search_page_lru(rs[i]);
		if(j==-1)
		{
			k=getLRU();
			fr[k].value=rs[i];
			fr[k].cnt=time;
			page_fault++;
			time++;
			i++;
		}
		else
		{
			fr[j].cnt=time;
			time++;
			i++;
		}
		for(d=0;d<nf;d++)
			printf("%d\t",fr[d].value);
		printf("\n");
	}
	printf("\nTotal no of page fault : %d\n",page_fault);
}
void main()
{
	accept();
	display();
	lru();	
}
