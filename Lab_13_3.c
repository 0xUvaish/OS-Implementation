#include<stdio.h>
int main()
{
  int t[20], d[20], h, i, j, n, temp, k, r, atr[20], tot, p, sum=0;
  printf("Enter the no of tracks to be traversed: ");
      scanf("%d",&n);
  printf("Enter the position of head: ");
      scanf("%d",&h);
  t[0]=h;
  printf("Enter the tracks: ");
  for(i=1;i<n+1;i++)
      scanf("%d",&t[i]);


  for(i=0;i<n+1;i++)    //sorting
         {
               for(j=0;j<(n+1)-i-1;j++)
                {
                    if(t[j]>t[j+1])
                       {
                         temp=t[j];
                          t[j]=t[j+1];
                          t[j+1]=temp;
                        }
                 }
       }


for(i=0;i<n+1;i++)   //searching for head
       {
          if(t[i]==h)
               {
                  j=i; k=i;
                 break; 
               }
         }

p=0;
while(j!=0)     //direction is towards 0 upto last request in this direction
       {
             atr[p]=t[j];
              j--;
             p++;
      }

atr[p]=t[j];
r=n;
while(r>=k+1)      //from last element to last request in direction towards 0
       {
          atr[++p]=t[r];
          r--;
        }

 for(j=1;j<n+1;j++)
 {
           if(atr[j]>atr[j-1])
                   d[j]=atr[j]-atr[j-1];
           else
           d[j]=atr[j-1]-atr[j];
      sum+=d[j];
   }
printf("Direction is towards 0\n");
printf("Tracks traversed\tDifference between tracks\n");
for(i=0;i<n+1;i++)
            printf("%d\t\t\t%d\n",atr[i],d[i]);
printf("\nTotal head movements: %d",sum);
printf("\nAverage head movements: %.2f",(float)sum/n);
return 0;
}