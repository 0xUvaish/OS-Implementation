#include<bits/stdc++.h>
using namespace std;
struct SortbyPrt{
	bool operator()(const vector<int>& a, const vector<int>& b) 
	{ 
	    return ((a[3] < b[3] || (a[3] == b[3] && a[2] > b[2] ))); 
	}
};
int main()
{
	int n;
	cout<<"Enter the no. of processes:\t";
	cin>>n;
	
	int wt[n],tat[n];
	// min heap is mplemented in c++ as priority queue
	priority_queue<vector<int>,vector<vector<int>>,SortbyPrt> Process;// vectors of size 4  pid ,at ,bt ,prt, 
																      //ct,num_of_times for storing bt;
	vector<vector<int>> info;
	//info = < PID, AT, PRT, BT, CT, backup_BT>
	float atat=0.0,awt=0.0;

	int t=0;
	for(int i=0;i<n;i++)
	{
		vector<int> v(6,1),holder;
		v[0]=i+1;
		cout<<"Enter Arrival Time of process "<<1+i<<" :\t";
		cin>>v[1];
		cout<<"Enter Burst Time of process   "<<1+i<<" :\t";
		cin>>v[2];
		v[5] =v[2];
		cout<<"Enter   Priority of process   "<<1+i<<" :\t";
		cin>>v[3];

		Process.push(v);
		holder = Process.top();
		if(holder[2]>0)
		{
			Process.pop();//pop process from RQ
			holder[2]-=1; //run for 1 unit time
			t++;
			holder[4] =t;//store corresponding ct
			Process.push(holder);// re enter the process into RQ
		}
		else if(holder[2]==0)
		{
			Process.pop();//if bt =0, remove the process
			info.push_back(holder);
		}
	}
	// once every process enter RQ, Pre-emption kind of stops
	// as no more process( of potentially priority) is expected to arrive
	// the current process (with highest priority) will be
	// scheduled by the STS.
	vector<int> holder;
	while(!Process.empty())
	{
		holder = Process.top();
		t+=holder[2];
		holder[2]=0;
		holder[4]=t;
		if(holder[2]==0) Process.pop();
		info.push_back(holder);
	}
	for(int i=0;i<n;i++)
	{
		tat[i] =info[i][4]-info[i][1]; //tat = ct -at
		tat[i] - info[i][5] >0 ? wt[i] = tat[i] - info[i][5] : wt[0]=0; //wt =tat - bt
	
      	awt+=wt[i];
      	atat+=tat[i];
    }
	cout<<" PROCESS \tARRIVAL TIME\t PRIORITY\tBURST TIME\tCOMPLETION TIME\t WAITING TIME\tTURNAROUND TIME\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<info[i][0]<<"\t\t"<<info[i][1]<<"\t\t"<<info[i][3]<<"\t\t"<<info[i][5]<<"\t  \t"<<info[i][4]<<"\t  \t"<<wt[i]<<"\t  \t"<<tat[i]<<"\n";
	}
	printf("\nAverage Waiting Time=\t%f",awt/n);
	printf("\nAverage TurnAround Time=\t%f",atat/n);
}