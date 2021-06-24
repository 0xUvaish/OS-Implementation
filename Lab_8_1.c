#include<stdio.h>
int main()
{
int ms, nob, ef, n, tif = 0, oop = 0;
int i, p = 0;
printf(" Enter the total memory available(in Bytes)-- ");
scanf(" %d" , &ms);
printf(" Enter the number of blocks-- ");
scanf(" %d" , &nob);

int parts[nob];
int totalPartSize = 0;
for (int i = 0; i < nob; i++) {
printf(" Enter size of partition %d: ", i + 1);
scanf("%d", &parts[i]);
totalPartSize += parts[i];
}
oop = ms - totalPartSize;
printf("\n Enter the number of processes-- ");
scanf("%d" , &n);
int process[n];
for (i = 0; i< n; i++)
{
printf(" Enter memory required for process %d(in Bytes)-- " , i + 1);
scanf(" %d" , &process[i]);
}
printf(" \nNo.of Blocks available in memory-- %d" , nob);
printf(" \n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
for (i = 0; i< n; i++)
{
	printf(" \n %d\t\t%d", i + 1, process[i]);
	for (int j = 0; j < nob; j++) 
	{
		if (process[i] <= parts[j]) 
		{
		printf(" \t\tYES\t%d", parts[j] - process[i]);
		tif = tif + parts[j] - process[i];
		parts[j] = parts[j] - process[i];
		break;
		}
		if(j==nob-1)
		printf(" \t\tNO\t-- ");
	}
}

ef = oop + tif;
if (i< n)
printf(" \nMemory is Full, Remaining Processes cannot be accomodated");
printf(" \n\nTotal Internal Fragmentation is %d" , tif);
printf(" \nTotal External Fragmentation is %d" , ef);
return 0;
}