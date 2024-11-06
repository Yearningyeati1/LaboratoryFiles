#include <bits/stdc++.h>
using namespace std;

void srtf_sim(queue<vector<int>> &proc) {
    int global_time = 0;           
    int wait_g = 0;                
    int turn_g = 0;                
    int num = proc.size();         
    
    vector<int> remaining_burst(num); 
    vector<int> wait(num, 0);         
    vector<int> turn(num, 0);         
    vector<int> arrival(num);         
    vector<int> burst(num);           

    
    for (int i = 0; i < num; i++) {
        vector<int> cur = proc.front(); 
        proc.pop();
        arrival[i] = cur[1];          
        burst[i] = cur[2];            
        remaining_burst[i] = cur[2];  
        proc.push(cur);
    }

    int completed = 0;               
    vector<bool> is_completed(num, false);  

    
    while (completed < num) {
        int shortest = -1;
        int min_burst = INT_MAX;

        
        for (int i = 0; i < num; i++) {
            if (arrival[i] <= global_time && !is_completed[i] && remaining_burst[i] < min_burst) {
                min_burst = remaining_burst[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            
            global_time++;
            continue;
        }

        
        remaining_burst[shortest]--;
        global_time++;

        
        if (remaining_burst[shortest] == 0) {
            is_completed[shortest] = true;
            completed++;
            int finish_time = global_time;

            
            turn[shortest] = finish_time - arrival[shortest];
            wait[shortest] = turn[shortest] - burst[shortest];

            wait_g += wait[shortest];
            turn_g += turn[shortest];

            
            cout << "Process " << shortest << ": Arrival = " << arrival[shortest]
                 << ", Burst = " << burst[shortest] << endl;
            cout << "Wait time = " << wait[shortest]
                 << ", Turnaround time = " << turn[shortest] << endl << endl;
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
        vector<int> temp(3);
        cout << "Enter arrival and burst time for process " << i << ": ";
        cin >> temp[1]; 
        cin >> temp[2]; 
        temp[0] = 0;    
        proc.push(temp);
    }

    srtf_sim(proc);
    return 0;
}
