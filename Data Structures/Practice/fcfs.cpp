#include<iostream>
#include "queues.h"
using namespace std;
int main(){
    int num;
    cout<<"Enter the number of processes : ";
    cin>>num;
    int process[num];
    int burstTime[num];
    for(int i=0;i<num;i++){
        process[i]=i+1;
    }
    cout<<"Enter the burstTime for all the processes : ";
    for(int i=0;i<num;i++){
        cin>>burstTime[i];
    }
    Queue<int> wt;
    Queue<int> tt;
    wt.input();
    tt.input();
    wt.enqueue(0);
    //Finding Waiting time for all the processes
    for(int i=1;i<num;i++){
        wt.enqueue(burstTime[i-1]+wt.p[i-1]);
    }
    //Finding turnaround time for all the processes
    for(int i=0;i<=wt.rear;i++){
        tt.enqueue(burstTime[i]+wt.p[i]);
    }
    float TotalWaitingTime=0;
    float TotalTurnAroundTime=0;
    for(int i=0;i<num;i++){
        TotalWaitingTime+=wt.p[i];
        TotalTurnAroundTime+=tt.p[i];
    }
    cout<<"\nProcess\t\tBurstTime\t\tWaitingTime\t\tTurnAroundTime\n";
    for(int i=0;i<=wt.rear;i++){
        cout<<i+1<<"\t\t"<<burstTime[i]<<"\t\t\t"<<wt.p[i]<<"\t\t\t"<<tt.p[i]<<"\t\t"<<"\n";
    }
    cout<<"\n"<<"Average Waiting Time : "<<(TotalWaitingTime)/num;
    cout<<"\n"<<"Average TurnAround Time : "<<(TotalTurnAroundTime)/num;
}