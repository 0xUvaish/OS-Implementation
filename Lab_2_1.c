#include<stdio.h>
int main()
{

	int bt[10]={0},at[10]={0},p[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,temp,temp1,temp2;
	float totalTAT=0,totalWT=0;

	printf("Enter number of Processes in FCFS Scheduling:	");
	scanf("%d",&n);
	printf("Enter arrival time and burst time for each process: \n\n");
	for(int i=0;i<n;i++)
	{
		printf("Arrival time of Process[%d]	",i+1);
		scanf("%d",&at[i]);
		printf("Burst time of Process[%d]	",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
		printf("\n");
	}
	
	for(int i=1;i<n;i++)       //Sorting arrival time in ascending order
	{
		temp=at[i];
		temp1=bt[i];
		temp2=p[i];
		int j=i-1;
		while((temp<at[j])&&j>=0)
		{
			at[j+1]=at[j];
			bt[j+1]=bt[j];
			p[j+1]=p[j];
			j=j-1;
		}
		at[j+1]=temp;
		bt[j+1]=temp1;
		p[j+1]=temp2;
	}

	int sum=at[0];
		
	for(int j=0;j<n;j++)		//Completion time of processes 
	{
		sum+=bt[j];
		ct[j]+=sum;
	}	

	for(int k=0;k<n;k++)		//Turn around times and waiting times 
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}

	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}
	
	printf("Solution: \n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	
	for(int i=0;i<n;i++)
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);		
	printf("\n\nAverage TAT = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	
	return 0;
}