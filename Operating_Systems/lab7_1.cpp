#include <bits/stdc++.h>
using namespace std;

void fcfs_sim(queue<pair<int,int>> proc){
    int global_time=0;
    int wait_g=0;
    int turn_g=0;
    int num=proc.size();
    for(int i=0;i<num;i++){
        if(i==0)global_time=proc.front().first;
        int arr=proc.front().first;
        int burst=proc.front().second;
        proc.pop();
        global_time+=burst;
        cout<<endl;
        cout<<"Process "<<i<<": Arrival:"<<arr<<" Burst:"<<burst<<endl;
        int wait=global_time-arr-burst;
        int turn=wait+burst;
        wait_g+=wait;
        turn_g+=turn;
        cout<<"Wait time:"<<wait<<" Turnaround time:"<<turn<<endl;
        cout<<endl;

    }
    cout<<"Average waiting:"<<(float)wait_g/num<<endl;
    cout<<"Average turnaround:"<<(float)turn_g/num<<endl;

}

int main(){
    queue<pair<int,int>> proc;
    int n;
    cout<<"Enter no of proc:";
    cin>>n;
    for(int i=0;i<n;i++){
        pair<int,int> temp;
        cout<<"Enter {arrival,burst} for "<<i<<":";
        cin>>temp.first;
        cin>>temp.second;
        proc.push(temp);
    }
    fcfs_sim(proc);
    return 0;
}
