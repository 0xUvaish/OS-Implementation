#include<stdio.h>
int main()
{

int fragment[20],b[20],p[20],i,j,nb,np,temp,greatest=-32767;
static int barray[20],parray[20];
	
printf("Enter no. of blocks: ");
scanf("%d",&nb);
printf("\nEnter size of each block:\n");
for(i=1;i<=nb;i++)
    scanf("%d",&b[i]);

printf("\nEnter no. of processes: ");
scanf("%d",&np);
printf("\nEnter size of each process:\n");
for(i=1;i<=np;i++)
    scanf("%d",&p[i]);
	
for(i=1;i<=np;i++)
	{
	for(j=1;j<=nb;j++)
		{
		if(barray[j]!=1)
			{
			temp=b[j]-p[i];
			if(temp>=0)
				if(greatest<temp)
					{
						parray[i]=j;
						greatest=temp;
					}
			}
		}

		fragment[i]=greatest;
		barray[parray[i]]=1;
		greatest=-32768;

	}
	
printf("\nProcess no.\tProcess Size\tBlock no.\tBlock Size\tFragment");
for(i=1;i<=np && parray[i]!=0;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);

return 0;
}