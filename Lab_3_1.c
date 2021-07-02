#include<stdio.h>
int n,tq,time = 0;
int queue[100]={0},front = 0, rear = 0;
void sort( );
void roundr();
int select(int t);
void push(int q);
int pop();

struct data
{
  int pid,at,bt1,bt,wt,tat,ct;
}t;

int select(int j)
  {
  if(time == 0)
      return j;
  else
    {
    j=pop();
    return j;
     }
  }

int pop()
  {
    int x;
    x = queue[front++];
    return x;
  }

void push(int q)
  {
  queue[rear++]=q;
  }

int main()
{
 int i;
 float avg1=0,avg2=0;
 printf("Enter number of Processes in Round Robin Scheduling: ");
 scanf("%d",&n);
 struct data aa[n];
 printf("Enter Arrival time and Burst time for Each Process: \n\n");
 for(i=0;i<n;i++)
 {
    printf("Arrival time of Process[%d] ",i+1);
    scanf("%d",&aa[i].at);
    printf("Burst time of Process[%d] ",i+1);
    scanf("%d",&aa[i].bt);
    aa[i].pid=i+1;
    aa[i].bt1=aa[i].bt;
 }
 printf("Enter Time Quantum: ");
 scanf("%d",&tq);
 sort(aa);
 roundr(aa);

printf("\n     ProcessID     Arrival Time     Burst Time    Completion Time     Waiting Time     TurnAroundTime");
for(i=0;i<n;i++)
{
 printf("\n \tp[%d]\t \t%d\t \t%d \t\t%d \t \t%d\t \t\t%d\t ",aa[i].pid,aa[i].at,aa[i].bt1,aa[i].ct,aa[i].wt,aa[i].tat);
avg1+=aa[i].wt;
avg2+=aa[i].tat;
}
printf("\nAverage Waiting Time: %f\nAverage TurnAround Time: %f",avg1/n,avg2/n);
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
void roundr(struct data a[])
{
 int i=1,j=0,x;
 x=n;
 while(x!=0)
 {
  j=select(j);
  if( a[j].bt<=tq && a[j].bt>0)
  {
   time = time + a[j].bt;
   a[j].bt = 0;
  }
  else if(a[j].bt > 0)
  {
   a[j].bt = a[j].bt - tq;
   time = time + tq;
  }
         while( a[i].at<=time && i<n )
  {
       push(i);
       i++;
  }
         if(a[j].bt == 0)
  {
   x--;
   a[j].wt = time - a[j].at - a[j].bt1;
   a[j].tat= a[j].wt+a[j].bt1;
   a[j].ct=time;
  }
                else
                   push(j);                
 }
}