#include<stdio.h>
int main()
{
int t[20], n, i, j, tohm[20], tot=0;
float avhm;
printf("Enter the no.of tracks: ");
scanf("%d",&n);
t[0]=0;
printf("Enter initial head position: ");
scanf("%d",&t[1]);
printf("Enter the tracks to be traversed: ");
for(i=2;i<n+2;i++)
    scanf(“%d”,&t[i]);
tohm[1]=0;

for(i=2;i<n+2;i++)
{
tohm[i]=t[i]-t[i-1];
if(tohm[i]<0)
tohm[i]=tohm[i]*(-1);
}
for(i=2;i<n+2;i++)
    tot+=tohm[i];
avhm=(float)tot/n;
printf(“Tracks traversed\tDifference between tracks\n”);
for(i=1;i<n+2;i++)
    printf(“%d\t\t\t%d\n”,t[i],tohm[i]);
printf("\nTotal head movements: %d",tot);
printf("\nAverage head movements: %.2f",avhm);
return 0;
}