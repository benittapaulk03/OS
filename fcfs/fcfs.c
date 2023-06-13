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
void asort()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(p[i].at>p[j].at)
		{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(p[i].at==p[j].at)
		{
			if(p[i].pid>p[j].pid)
			{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			}
		}
		}
	}
}
void fcfs()
{
	float sum1=0,sum2=0;
	asort();
	p[0].ct=p[0].at+p[0].bt;
	for(int i=0;i<n;i++)
	{
	if(p[i+1].at>p[i].ct)
	p[i+1].ct=p[i+1].at+p[i+1].bt;
	else
	p[i+1].ct=p[i].ct+p[i+1].bt;
	p[i].tat=p[i].ct-p[i].at;
	sum1+=p[i].tat;
	p[i].wt=p[i].tat-p[i].bt;
	sum2+=p[i].wt;
	}
	printf("FCFS: \n");
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
	fcfs();
}

