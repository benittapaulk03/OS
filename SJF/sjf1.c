#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pid;
	int at;
	int wt;
	int tat;
	int bt;
	int ct;
}p[20],temp;
int n;
float sum1=0,sum2=0;
void bsort(int i)
{
	int min=p[0].at;
	for(int i;i<n;i++)
	{
		if(p[i].at==min)
		{
			temp=p[0];
			p[0]=p[i];
			p[i]=temp;
			break;
		}
	}
	for(int i;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(p[i].bt>p[j].bt)
		{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		}
		}
	}
	for(int i;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(p[i].bt==p[j].bt)
		{
			if(p[i].at>p[j].at)
			{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			}
		}
		}
	}
}
void asort()
{
	int min=p[0].at;
	for(int i=1;i<n;i++)
	{
		if(p[i].at<min)
			min=p[i].at;
	}
	for(int i=0;i<n;i++)
	{
		if(p[i].at==min)
		{
			temp=p[0];
			p[0]=p[i];
			p[i]=temp;
			break;
		}
	}
	p[0].ct=p[0].at+p[0].bt;
	bsort(1);
	for(int i=0;i<n;i++)
	{int j;
	if(p[i+1].at>p[i].ct)
	{int flag=0;
		if(flag==0)
		{
		for(j=i+1;j<n;j++)
		{
			if(p[j].at<p[i].ct)
			{
			temp=p[i+1];
			p[i+1]=p[j];
			p[j]=temp;
			p[i+1].ct=p[i].ct+p[i+1].bt;
			flag=1;
			bsort(j);
			break;
			}
		}
		}
		else
		p[i+1].ct=p[i+1].at+p[i+1].bt;
	}
	else
		p[i+1].ct=p[i].ct+p[i+1].bt;
	p[i].tat=p[i].ct-p[i].at;
	sum1+=p[i].tat;
	p[i].wt=p[i].tat-p[i].bt;
	sum2+=p[i].wt;
	}
}
void sjf()
{
	
	asort();
	printf("SJF: \n");
	printf("PID\tArrival time\tBurst Time\tCompletion time\tTurnaround time\tWaiting time\n");
	for(int i=0;i<n;i++)
	{
	printf("%d\t\t",p[i].pid);
	printf("%d\t\t",p[i].at);
	printf("%d\t\t",p[i].bt);
	printf("%d\t\t",p[i].ct);
	printf("%d\t\t",p[i].tat);
	printf("%d\t\t",p[i].wt);
	printf("\n");
	}
	printf("Avg turnaround time: %f\nAvg waiting time: %f",(sum1/n),(sum2/n));
}
void main()
{
	printf("enter number of processes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	printf("enter process id: \n");
	scanf("%d",&p[i].pid);
	printf("enter arrival time: \n");
	scanf("%d",&p[i].at);
	printf("enter burst time: \n");
	scanf("%d",&p[i].bt);
	}
	sjf();
}




