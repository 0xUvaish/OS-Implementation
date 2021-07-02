#include<stdio.h>

void main() 
{ int i,j,n,bu[10],ibu[10],wa[10],tat[10],t,max,p[50], g=0;
 float awt=0,att=0,temp=0; 
 
 printf("Enter the no of processes -- ");
  scanf("%d",&n); 
  
  for(i=0;i<n;i++) {
   printf("\nEnter Burst Time for process %d -- ", i); 
   scanf("%d",&bu[i]);
   ibu[i]=bu[i];
   } 
   
   printf("\nEnter the size of time slice -- "); 
   scanf("%d",&t);
   max=bu[0]; 
   
   for(i=1;i<n;i++) {
   if(max<bu[i])
    max=bu[i];

   }
    
   for(j=0;j<(max/t)+1;j++)
   for(i=0;i<n;i++)
   if(bu[i]!=0)
   if(bu[i]<=t)
    {
     tat[i]=temp+bu[i];
     temp=temp+bu[i];
     bu[i]=0; 
     p[g++]=i;
    }

    else { 
     bu[i]=bu[i]-t; 
     temp=temp+t; 
     p[g++]=i;
    } 
    
    for(i=0;i<n;i++)
    { 
      wa[i]=tat[i]-ibu[i];
      att+=tat[i];
      awt+=wa[i];
    } 
printf("\nThe Average Turnaround time is -- %f",att/n); 
printf("\nThe Average Waiting time is -- %f ",awt/n);

printf("\n");
for(i=0;i<g;i++){
printf("pid - >%d --",p[i]);
}

printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
	printf("\t%d \t %d \t\t %d \t\t %d \n",i,ibu[i],wa[i],tat[i]);
}