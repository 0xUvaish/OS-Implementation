#include<stdio.h>
void main() 
{ 
// qp is Queue Prioriy, cwt is Cummulative Waiting Time, and ctat is Cummulative Turn Around Time
int pid[20],bt[20], qp[20], wt[20],tat[20],i, k, n, temp; 
float cwt, ctat; 
printf("Enter the number of processes --- "); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
	pid[i] = i; 
	printf("Enter the Burst Time of Process %d --- ", i); 
	scanf("%d",&bt[i]); 
	printf("System/User Process (0/1) ? --- "); 
	scanf("%d", &qp[i]); 
} 


for(i=0;i<n;i++) 
for(k=i+1;k<n;k++) 
	if(qp[i] > qp[k]) 
	{ 
		temp=pid[i]; 
		pid[i]=pid[k]; 
		pid[k]=temp; 
			
		temp=bt[i]; 
		bt[i]=bt[k]; 
		bt[k]=temp; 
			
		temp=qp[i]; 
		qp[i]=qp[k]; 
		qp[k]=temp; 
	} 


for(i=0;i<n;i++) 
for(k=i+1;k<n;k++) 
	{
		if(qp[i]==0 && qp[k]==0 && bt[i]>bt[k])
		{
			temp=pid[i]; 
			pid[i]=pid[k]; 
			pid[k]=temp; 
			
			temp=bt[i]; 
			bt[i]=bt[k]; 
			bt[k]=temp; 
			
			temp=qp[i]; 
			qp[i]=qp[k]; 
			qp[k]=temp; 
		}

elseif (qp[i]==1 && qp[k]==1 && pid[i]>pid[k])	
		{
			temp=pid[i]; 
			pid[i]=pid[k]; 
			pid[k]=temp; 
			
			temp=bt[i]; 
			bt[i]=bt[k]; 
			bt[k]=temp; 
			
			temp=qp[i]; 
			qp[i]=qp[k]; 
			qp[k]=temp; 
		}	
	}


cwt = wt[0] = 0; 
ctat = tat[0] = bt[0]; 
for(i=1;i<n;i++) 
{ 
	wt[i] = wt[i-1] + bt[i-1]; 
	tat[i] = tat[i-1] + bt[i];
	
	cwt = cwt + wt[i]; 
	ctat = ctat + tat[i]; 
} 
printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME"); 
for(i=0;i<n;i++) 
	printf("\n%d \t\t\t\t %d \t\t %d \t\t %d \t\t %d ",pid[i],qp[i],bt[i],wt[i],tat[i]); 
	
printf("\nAverage Waiting Time is --- %f",cwt/n); 
printf("\nAverage Turnaround Time is --- %f",ctat/n); 
}