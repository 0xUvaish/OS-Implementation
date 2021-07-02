#include<stdio.h>
int n,i,j,total_time=0,process[20];
float avgtat=0,avgwt=0;
struct data
{
	int at,bt,ct,tat,wt;
	int pr,pid;
}temp,t;
void calculate(struct data a[]);
void display(struct data a[]);
void sort(struct data a[]);

int main()
{
	printf("Enter the no of process: ");
	scanf("%d", &n);
	struct data aa[n];
	printf("Enter Priority, Arrival Time and Burst Time\n");
	for(i=0;i<n;i++)
	{
		printf("Enter for Process %d\n", i+1);
		scanf("%d", &aa[i].pr);
		scanf("%d%d", &aa[i].at, &aa[i].bt);
		aa[i].pid=i+1;
	}
sort(aa);
total_time += aa[0].at + aa[0].bt;
for(i=1;i<n;i++)
{
	if(aa[i].at>total_time)
		total_time = aa[i].at;
	total_time += aa[i].bt;
}

calculate(aa);
return 0;
}

void sort( struct data a[])
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<n-i-1;j++)
  if(a[j].at>a[j+1].at)
  {
   t=a[j];
   a[j]=a[j+1];
   a[j+1]=t;
  }

}
void display(struct data a[])
{
	for(i=0;i<n;i++)
	{
		a[i].tat = a[i].ct - a[i].at;
		a[i].wt = a[i].tat - a[i].bt;
	}
	for(i=0;i<n;i++)
	{
		avgtat += a[i].tat;
		avgwt += a[i].wt;
	}

	avgtat = avgtat/n;
	avgwt = avgwt/n;
	printf("\nPr\tPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i].pr,a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
	printf("AvgTAT: %f\nAvgWT: %f",avgtat, avgwt);
}
void calculate(struct data a[])
{
	int x,time=0;
while(time<total_time)
{
	j=0;
	for(i=0;i<n;i++)
		if(a[i].at<=time)
			j=i+1;
	if(j>0)
	{
		int x=0,min_pr=a[0].pr;
		for(i=1;i<j;i++)
		{
			if(min_pr>a[i].pr)
			{
				x=i;
				min_pr=a[i].pr;
			}
			else if(min_pr==a[i].pr)
			{
				if(a[x].at>a[i].at)
				{
					x=1;
					min_pr=a[i].at;
				}
				else if(a[x].at == a[i].bt)
				{
					if(a[x].bt>a[i].bt)
					{
						x=i;
						min_pr=a[i].pr;
					}
				}
			}
		}
		time += a[x].bt;
		a[x].ct = time;
		a[x].pr += 1000;
		a[x].at += 1000;
	}
	else
	{
		time++;
	}
}
	for(i=0;i<n;i++)
	{
		a[i].pr -= 1000;
		a[i].at -= 1000;
	}
display(a);
}