#include<bits/stdc++.h>
#include<tuple>
using namespace std;

bool sortbybt(const tuple<int, int, int>& a, const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) < get<2>(b)||// smaller bt
    	(get<2>(a) == get<2>(b) && (get<1>(a) < get<1>(b)) || //samller at if bt same  
    	(get<2>(a) == get<2>(b) && (get<1>(a) == get<1>(b) && (get<1>(a) <get<1>(b) ))))); //smaller pid if at and b are same
}

int main()
{
	//taking arrival time of each process as input
	
	int n;
	cout<<"\n Enter the number of processes:\t";
	cin>>n;
	vector<tuple<int,int,int>> v(n); //<pid,at,bt>
	float cwt=0.0,ctat=0.0;
	int ct[n],wt[n],tat[n];
	for(int i=0;i<n;i++)
	{
		int at,bt;
		cout<<"\nEnter Arrival Time of Process"<<i+1<<":\t";
		cin>>at;
		cout<<"Enter Burst Time of Process"<<i+1<<":\t";
		cin>>bt;
		v[i]=make_tuple(i+1,at,bt);
	}
	tuple<int ,int ,int> sett = v[0];
	sort(v.begin()+1,v.end(),sortbybt);// sort by burst time in O(nlog n) time	
	ct[0]=get<2>(sett) - get<1>(sett);
	for(int i =1;i<n;i++)
	{
		ct[i]=ct[i-1] + get<2>(v[i]) ;
	}
	for(int i=0;i<n;i++)
	{
		tat[i]= ct[i]- get<1>(v[i]); // TAT = CT - AT
		(tat[i]- get<2>(v[i])>0) ? wt[i]=tat[i]- get<2>(v[i]) : wt[i]=0;//WT = TAT - BT
		cwt+=wt[i];
		ctat+=tat[i];
	}
	printf("\t PROCESS \tARRIVAL TIME \tBURST TIME \tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
	for(int i=0;i<n;i++)
	{
		printf("\n\tP%d \t\t%d \t\t%d \t\t%d \t\t\t%d \t\t%d ",get<0>(v[i]),get<1>(v[i]),get<2>(v[i]),ct[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting Time = %f",cwt/n);
	printf("\nAverage TurnAround Time = %f",ctat/n);
	cout<<"\n";

}
