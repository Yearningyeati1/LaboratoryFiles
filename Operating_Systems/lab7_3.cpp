#include <bits/stdc++.h>
using namespace std;

void priority_scheduling(queue<vector<int>> &proc) {
    int global_time = 0;           
    int wait_g = 0;                
    int turn_g = 0;                
    int num = proc.size();         

    vector<int> remaining_burst(num); 
    vector<int> wait(num, 0);         
    vector<int> turn(num, 0);         
    vector<int> arrival(num);         
    vector<int> burst(num);           
    vector<int> priority(num);        

   
    for (int i = 0; i < num; i++) {
        vector<int> cur = proc.front(); 
        proc.pop();
        arrival[i] = cur[1];          
        burst[i] = cur[2];            
        priority[i] = cur[3];         
        remaining_burst[i] = cur[2];  
        proc.push(cur);
    }

    int completed = 0;               
    vector<bool> is_completed(num, false);  

    while (completed < num) {
        int highest_priority = -1;
        int min_priority = INT_MAX;

        
        for (int i = 0; i < num; i++) {
            if (arrival[i] <= global_time && !is_completed[i] && priority[i] < min_priority) {
                min_priority = priority[i];
                highest_priority = i;
            }
        }

        if (highest_priority == -1) {
            global_time++;
            continue;
        }

        remaining_burst[highest_priority]--;
        global_time++;

        if (remaining_burst[highest_priority] == 0) {
            is_completed[highest_priority] = true;
            completed++;
            int finish_time = global_time;

            turn[highest_priority] = finish_time - arrival[highest_priority];
            wait[highest_priority] = turn[highest_priority] - burst[highest_priority];

            wait_g += wait[highest_priority];
            turn_g += turn[highest_priority];

            cout << "Process " << highest_priority << ": Arrival = " << arrival[highest_priority]
                 << ", Burst = " << burst[highest_priority] << ", Priority = " << priority[highest_priority] << endl;
            cout << "Wait time = " << wait[highest_priority]
                 << ", Turnaround time = " << turn[highest_priority] << endl << endl;
        }
    }

    cout << "Average waiting time: " << (float)wait_g / num << endl;
    cout << "Average turnaround time: " << (float)turn_g / num << endl;
}

int main() {
    queue<vector<int>> proc;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> temp(4);
        cout << "Enter arrival time, burst time, and priority for process " << i << ": ";
        cin >> temp[1]; 
        cin >> temp[2]; 
        cin >> temp[3]; 
        temp[0] = 0;    
        proc.push(temp);
    }

    priority_scheduling(proc);
    return 0;
}
