#include<bits/stdc++.h>
#include<tuple>
using namespace std;
typedef struct comparator{
bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) > get<2>(b)||
    	(get<2>(a) == get<2>(b) && (get<1>(a) > get<1>(b)) || 
    	(get<2>(a) == get<2>(b) && (get<1>(a) == get<1>(b) && (get<1>(a) > get<1>(b) ))))); 
}
}sort_by_bt;
int main()
{
	//taking arrival time of each process as input
	
	int n;
	cout<<"\n Enter the number of processes:\t";
	cin>>n;
	//priority queue is the manifestation of max heap in C++ STL 
	// with slight modifications, it can implement min heap as well  
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, sort_by_bt> process; //<pid,at,bt>
	vector<tuple<int,int,int>> v(1);
	
	int ct[n],wt[n],tat[n];
	for(int i=0;i<n;i++)
	{
		int at,bt;
		cout<<"\nEnter Arrival Time of Process"<<i+1<<":\t";
		cin>>at;
		cout<<"Enter Burst Time of Process"<<i+1<<":\t";
		cin>>bt;
		if(i==0)
		{
		 	ct[0] = bt -at;//fisrt processs will always be scheduled first to prevent CPU from being idle
		 	tat[0] = ct[0] - at;// this is a drawback of SJF as it in many cases can cause Convoy Effect
			wt[0] = tat[0] - bt;// this is a drawback of SJF as it in many cases can cause Convoy Effect

			v[0]= make_tuple(i+1,at,bt);
		}
 		else
 		{
 			process.push(make_tuple(i+1,at,bt));
 		}
		//the priorty queue takes care of the ordering of elements 
	}
	
	float cwt=wt[0],ctat=tat[0];
	for(int i =1;i<n;i++)
	{
		ct[i]=ct[i-1] + get<2>(process.top()) ;
	
		tat[i]= ct[i]- get<1>(process.top()); // TAT = CT - AT

		(tat[i]- get<2>(process.top())>0) ? wt[i]=tat[i]- get<2>(process.top()) : wt[i]=0;//WT = TAT - BT
	    v.push_back(process.top());
		process.pop();
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
