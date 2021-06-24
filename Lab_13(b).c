#include<stdio.h>
int main()
{
int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum=0;

printf("Enter the no of tracks to be traversed: ");
scanf("%d'",&n);

printf("Enter the position of head: ");
scanf("%d",&h);

t[0]=0;t[1]=h;
printf("Enter the tracks: ");

for(i=2;i<n+2;i++)
    scanf("%d",&t[i]);
for(i=0;i<n+2;i++)
{
for(j=0;j<(n+2)-i-1;j++)
{ 
if(t[j]>t[j+1])
{
temp=t[j];
t[j]=t[j+1];
t[j+1]=temp;
} 
} 
}

for(i=0;i<n+2;i++)
{
if(t[i]==h)
{
j=i; k=i;
break;
}
}

p=0;
while(t[j]!=0)
{
atr[p]=t[j];
j--;
p++;
}

atr[p]=t[j];
for(p=k+1;p<n+2;p++,k++)
    atr[p]=t[k+1];
for(j=1;j<n+2;j++)
{
    if(atr[j]>atr[j-11])
        d[j]=atr[j]-atr[j-1];
    else
        d[j]=atr[j-1]-atr[j];
    sum+=d[j];
}
printf("Direction is towards 0\n");
printf("Tracks traversed\tDifference between tracks\n");
for(i=0;i<n+2;i++)
printf("%d\t\t\t%d\n",atr[i],d[i]);

printf("\nTotal head movements: %d",sum);
printf("\nAverage head movements: %.2f",(float)sum/n);
return 0;
}