#include<bits/stdc++.h>
using namespace std;



vector<tuple<int ,int , int,int,int>> SYSTEM; //<PID, AT, Priority, BT,process type>

vector<tuple<int ,int , int, int>> USER; //<PID, AT, BT,process type>

bool SortbyPrt(const tuple<int, int, int,int,int>& a, const tuple<int, int, int,int,int>& b) 
{ 
    return ((get<2>(a) > get<2>(b)) || 
    	(get<2>(a) == get<2>(b) && (get<1>(a) < get<1>(b) ))); 
}
tuple<int, int, int,int,int> optimal(int t)
{
	for(int i=0;i<SYSTEM.size();i++)
		if(get<1>(SYSTEM[i])<=t) return SYSTEM[i];
}


bool SortbyAT(const tuple<int, int, int,int>& a, const tuple<int, int, int,int>& b) 
{ 
    return ((get<1>(a) < get<1>(b)) || //samller AT  
    	(get<1>(a) == get<1>(b) && (get<0>(a) <get<0>(b) ))); //smaller pid if AT is same
}


int main()
{
	//we will use round robin for user processes
	//and priority scheduling for system processes (non preemptive)
	//Cpu processes will be scheduled first then user processes
	int n;
	cout<<"Enter number of processes:\t";
	cin>>n;
	int type;
	int ct[n],wt[n],tat[n];
	
	float atat=0.0,awt=0.0;


	for(int i=0;i<n;i++)
	{
		cout<<"\nSystem/User process(0/1):\t";
		cin>>type;
		if(type==0)
		{
			int at,bt,pr;
			cout<<"Enter Arrival Time of process "<<1+i<<" :\t";
			cin>>at;
			cout<<"Enter   Burst Time of process "<<1+i<<" :\t";
			cin>>bt;
			cout<<"Enter   Priority of process   "<<1+i<<" :\t";
			cin>>pr;
			SYSTEM.push_back(make_tuple(i+1,at,bt,pr,0));
		}

		if(type==1)
		{
			int at,bt;
			cout<<"Enter Arrival Time of process "<<1+i<<" :\t";
			cin>>at;
			cout<<"Enter   Burst Time of process "<<1+i<<" :\t";
			cin>>bt;
			USER.push_back(make_tuple(i+1,at,bt,1));
		}
		cout<<"\n======================================================================";
	}
	//=========================================Priority scheduling for system processes===================
	vector<tuple<int,int,int,int,int,int,int,int>> info; //avoid mismatch;
	ct[0] = get<2>(SYSTEM[0]) - get<1>(SYSTEM[0]);
	wt[0]=0;
	tat[0]= ct[0] - get<1>(SYSTEM[0]);
	
	info.push_back(make_tuple(get<0>(SYSTEM[0]),get<1>(SYSTEM[0]),
		get<2>(SYSTEM[0]),get<3>(SYSTEM[0]),0,ct[0],wt[0],tat[0]));

	int t=get<2>(SYSTEM[0]);

	SYSTEM.erase(SYSTEM.begin()+0);

	sort(SYSTEM.begin(),SYSTEM.end(),SortbyPrt);

	for(int i=1;i<=SYSTEM.size();i++)
	{
		tuple<int, int, int,int,int> a = optimal(t); 
		ct[i]= get<2>(a) + ct[i-1]; 
		tat[i] = ct[i] - get<1>(a); // tat =ct-at; 
		wt[i] = tat[i] - get<2>(a); // wt = tat-bt;
		t+= get<3>(a);
		remove(SYSTEM.begin(),SYSTEM.end(),a);
		info.push_back(make_tuple(get<0>(a),get<1>(a),get<2>(a),get<3>(a),0,ct[i],wt[i],tat[i]));
	}
      for(int i=0;i<n;i++)
      {
      	awt+=wt[i];
      	atat+=tat[i];
      }


      
      //===========================RR scheduling for user processes===============================

    sort(USER.begin(),USER.end(),SortbyAT);
    int rct[n],rwt[n],rtat[n],remt[n];
	for(int i=0;i<USER.size();i++) remt[i] = get<2>(USER[i]);

	int tq;
	cout<<"\nEnter time quantum for rr scheduling of user processes:\t"; cin>>tq;
	while(true)
	{
		bool done =true;
		for(int i=0;i<USER.size();i++)
		{
			if(remt[i] > 0)
			{
				done=false;
				if(remt[i] > tq && get<1>(USER[i])<=t)
				{
					t+=tq;
					remt[i]-=tq;
					
				}
				
				else
				{
					if(get<1>(USER[i])<=t)
					{
						t+= remt[i];
						rct[i] = t;
						remt[i]=0; 
						
					}
				}
			}
		}
	if(done == true) break;	
	}

	for(int i=0;i<USER.size();i++)
	{
		rtat[i]= rct[i]  - get<1>(USER[i]);//tat =ct-at
		rwt[i] = rtat[i] - get<2>(USER[i]); //wt=tat-bt
		awt+=rwt[i];
		atat+=rtat[i];
	}
cout<<"=========================System Process============================================================";
	cout<<"\nPROCESS \tARRIVAL TIME\tBURST TIME\tPRIORITY\tTYPE\tCOMPLETION TIME\t WAITING TIME\tTURNAROUND TIME\n";
	for(int i=0;i<info.size();i++)
	{
		cout<<get<0>(info[i])<<"\t\t"<<get<1>(info[i])<<"\t\t"<<get<2>(info[i])<<"\t\t"<<get<3>(info[i])<<"\t\t"
		<<get<4>(info[i])<<"\t\t"<<get<5>(info[i])<<"\t\t"<<get<6>(info[i])<<"\t\t"<<get<7>(info[i])<<"\n";
	}
cout<<"=========================USER Process=======================================================";
	cout<<"\n PROCESS \tARRIVAL TIME\tBURST TIME\tTYPE\tCOMPLETION TIME\t WAITING TIME\tTURNAROUND TIME\n";
	for(int i=0;i<USER.size();i++)
	{
		cout<<get<0>(USER[i])<<"\t\t"<<get<1>(USER[i])<<"\t\t"<<get<2>(USER[i])
		<<"\t\t"<<1<<"\t\t"<<rct[i]<<"\t\t"<<rwt[i]<<"\t\t"<<rtat[i]<<"\n";
	}
	printf("\nAverage Waiting Time=\t%f",(awt/n));
	printf("\nAverage TurnAround Time=\t%f",(atat/n));


}