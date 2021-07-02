#include<bits/stdc++.h>
using namespace std;

//system processes follow FCFS and user processes follow SJF
//for the first tme slice system processes will be executed
// then for second time slice user processes will be executed
bool sortbyBT(const vector<int>& a, const vector<int>& b) 
{ 
    return (
    	   (a[2] < b[2])||// smaller bt
    	   ((a[2] == b[2]) && (a[1] < b[1]) )|| //samller at if bt same  
    	   ((a[2] == b[2]) && (a[1] == b[1]) && (a[0] <b[0]))
    	   ); //smaller pid if at and b are same
}

bool sortbyAT(const vector<int>& a, const vector<int>& b) 
{ 
    return (
    	   (a[1] < b[1])||// smaller at
    	   ((a[1] == b[1]) && (a[0] < b[0])) 
    	   ); //smaller pid if at is same
}
int main()
{
	int n;
	printf("Enter the number of process:\t");
	scanf("%d",&n);
	
	int type;
	float atat=0.0,awt=0.0;
								//0    1  2  3    4
	vector<vector<int>> SYSTEM;//<pid,at,bt,type,copy(bt)>
	vector<vector<int>> USER;//<pid,at,bt,type,copy(bt)>

	for(int i=0;i<n;i++)
	{
		cout<<"System/User process(0/1):\t";
		cin>>type;
		int at,bt;
		if(type==0)
		{
			vector<int> v(5);
			v[0]=i+1;
			cout<<"Enter Arrival Time of process "<<1+i<<" :\t";
			cin>>at;
			v[1]=at;
			cout<<"Enter   Burst Time of process "<<1+i<<" :\t";
			cin>>bt;
			v[2]=v[4]=bt;
			v[3]=0;
			SYSTEM.push_back(v);
		}
		if(type==1)
		{
			vector<int> v(5);
			v[0]=i+1;
			cout<<"Enter Arrival Time of process "<<1+i<<" :\t";
			cin>>at;
			v[1]=at;
			cout<<"Enter   Burst Time of process "<<1+i<<" :\t";
			cin>>bt;
			v[2]=v[4]=bt;
			v[3]=1;
			USER.push_back(v);
		}
		cout<<"================================================================================\n";
	}
	//==============================SORTING THE PROCESSES INSIDE THE QUEUES========================= 

	//sort SYSTEM Processes by Arrival Time as required for FCFS
	sort(SYSTEM.begin(),SYSTEM.end(),sortbyAT);// sort by arrival time in O(nlog n) time;

	//sort USER Processes by Burst Time as required for SJF
	sort(USER.begin(),USER.end(),sortbyBT);// sort by burst time in O(nlog n) time	

	//=========================================SCHEDULING PROCESSES=======================

	
	vector<vector<int>> OVRALL;//<pid,at,bt,type,ct,tat,wt>
	int t=0;
	int ts;
	cout<<"\n\nEnter the time slice for queues:\t";cin>>ts;
	int t1=ts,t2=ts;//alter value of reamaining time slice without changing ts itself
	int i=0,j=0,k=0;
	//run till all proceeses have been executed;
	int S_size= SYSTEM.size();
	int U_size= USER.size();
	while(OVRALL.size()<n)
	{
		if(((t+1)/ts)%2==0 && S_size>0) // execute system processes
		{
			for(;i<SYSTEM.size();)
			{
				if(SYSTEM[i][2] > t1)
				{
					t+=t1;
					SYSTEM[i][2]-=t1;
					t1=ts;
					break;
				}
				//(SYSTEM[i][2]<=t1)
				else
				{
					t+=SYSTEM[i][2];
					t1-=SYSTEM[i][2];
					SYSTEM[i][2]=0;

					vector<int> v(7,0);
					v[0]=SYSTEM[i][0];
					v[1]=SYSTEM[i][1];
					v[2]=SYSTEM[i][4];
					v[3]=SYSTEM[i][3];
					v[4] =t;
					OVRALL.push_back(v);
					S_size--;
					++i;
				}
			}
		}
		else //if(((t+1)/ts)%2!=0 && U_size>0) //execute user processes
		{
			for(;j<USER.size();)
			{
				
				if(USER[j][2] > t2)
				{
					t+=t2;
					USER[j][2]-=t2;
					t2=ts;
					break;
				}
				else
				{
					t+=USER[j][2];
					t2-=USER[j][2];
					USER[j][2]=0;
					
					vector<int> v(7,0);
					v[0]=USER[j][0];
					v[1]=USER[j][1];
					v[2]=USER[j][4];
					v[3]=USER[j][3];
					v[4] =t;
					OVRALL.push_back(v);
					U_size--;
					++j;
				}
			}
		}
	}
	for(int i=0;i<OVRALL.size();i++)
	{
		OVRALL[i][5] = OVRALL[i][4] - OVRALL[i][1];//tat = ct - at;
		OVRALL[i][6] = OVRALL[i][5] - OVRALL[i][2];//wt = tat - bt;

		awt+=OVRALL[i][6];
		atat+=OVRALL[i][5];
	}
	cout<<"\nPROCESS \tARRIVAL TIME\tBURST TIME\tTYPE\tCOMPLETION TIME\tTURNAROUND TIME\t WAITING TIME\n";
	for(int i=0;i<OVRALL.size();i++)
	{
		cout<<(OVRALL[i][0])<<"\t\t"<<(OVRALL[i][1])<<"\t\t"<<(OVRALL[i][2])
		<<"\t\t"<<OVRALL[i][3]<<"\t\t"<<OVRALL[i][4]<<"\t\t"<<OVRALL[i][5]<<"\t\t"<<OVRALL[i][6]<<"\n";
	}
	cout<<"\nAverage Waiting Time=\t"<<(awt/n);
	cout<<"\nAverage TurnAround Time=\t"<<(atat/n);
	cout<<"\n\n\n";
}