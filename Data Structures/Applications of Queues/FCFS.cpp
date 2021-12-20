#include<iostream>
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
    int waitingTime[num];
    int turnAroundTime[num];
    waitingTime[0]=0;
    //Finding Waiting time for all the processes
    for(int i=1;i<num;i++){
        waitingTime[i]=burstTime[i-1]+waitingTime[i-1];
    }
    //Finding turnaround time for all the processes
    for(int i=0;i<num;i++){
        turnAroundTime[i]=waitingTime[i]+burstTime[i];
    }
    float TotalWaitingTime=0;
    float TotalTurnAroundTime=0;
    for(int i=0;i<num;i++){
        TotalWaitingTime+=waitingTime[i];
        TotalTurnAroundTime+=turnAroundTime[i];
    }
    cout<<"\nProcess\t\tBurstTime\t\tWaitingTime\t\tTurnAroundTime\n";
    for(int i=0;i<num;i++){
        cout<<i+1<<"\t\t"<<burstTime[i]<<"\t\t\t"<<waitingTime[i]<<"\t\t\t"<<turnAroundTime[i]<<"\t\t"<<"\n";
    }
    cout<<"\n"<<"Average Waiting Time : "<<(TotalWaitingTime)/num;
    cout<<"\n"<<"Average TurnAround Time : "<<(TotalTurnAroundTime)/num;
}


