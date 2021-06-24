#include<stdio.h>
int main()
{
int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf=0;

printf("\nEnter the length of reference string -- ");
scanf("%d",&m);

printf("\nEnter the reference string -- ");
for(i=0;i<m;i++)
  scanf("%d",&rs[i]);

printf("\nEnter the number of frames -- ");
scanf("%d",&f);

for(i=0;i<f;i++)
{
cntr[i]=0;
a[i]=-1;
}

printf(“\nThe Page Replacement Process is – \n“);

for(i=0;i<m;i++)
{
for(j=0;j<f;j++)
if(rs[i]==a[j])
{
cntr[j]++;
break;
}
if(j==f)
{
min = 0;

for(k=1;k<f;k++)
  if(cntr[k]<cntr[min])
      min=k;

a[min]=rs[i];
cntr[min]=1;
pf++;
}


printf("\n");

for(k=0;k<f;k++)
  printf("\t%d",a[k]);

if(j==f)
  printf(“\tPF No. %d”,pf);
}

printf("\n\nThe number of page faults using LFU are %d\n",pf);
return 0;
}