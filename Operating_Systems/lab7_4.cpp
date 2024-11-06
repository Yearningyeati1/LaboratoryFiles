#include <bits/stdc++.h>
using namespace std;

void rr_sim(queue<vector<int>> &proc, int q) {
    int global_time = 0;
    int wait_g = 0;
    int turn_g = 0;
    int num = proc.size();
    
    vector<int> remaining_burst(num);
    vector<int> wait(num, 0);
    vector<int> turn(num, 0);
    vector<int> arrival(num);  

   
    for (int i = 0; i < num; i++) {
        vector<int> cur = proc.front(); proc.pop();
        remaining_burst[i] = cur[2];  
        arrival[i] = cur[1];           
        proc.push(cur);            
    }

    
    while (true) {
        bool all_done = true;

        for (int i = 0; i < num; i++) {
            if (remaining_burst[i] > 0) {
                all_done = false; 
                if (remaining_burst[i] > q) {
                    global_time += q; 
                    remaining_burst[i] -= q; 
                    for(int j=0;j<num;j++){
                        if(j!=i && remaining_burst[j]!=0)wait[j]+=q;
                        if(remaining_burst[j]!=0)turn[j]+=q;
                    }
                } else {
                    // Process finishes
                    global_time += remaining_burst[i]; 
                    int burst = remaining_burst[i];

                    for(int j=0;j<num;j++){
                        if(j!=i && remaining_burst[j]!=0)wait[j]+=burst;
                        if(remaining_burst[j]!=0)turn[j]+=burst;
                    }

                    remaining_burst[i] = 0;

                    
                    int wait_time = wait[i];
                    int turn_time = turn[i];

                    wait_g += wait_time;
                    turn_g += turn_time;

                    
                    cout << "Process " << i << ": Arrival: " << arrival[i]
                         << ",Last Burst: " << burst << endl;
                    cout << "Wait time: " << wait_time 
                         << ", Turnaround time: " << turn_time << endl << endl;
                }
            }
        }

        if (all_done) break; 
    }

   
    cout << "Average waiting time: " << (float)wait_g / num << endl;
    cout << "Average turnaround time: " << (float)turn_g / num << endl;
}

int main() {
    queue<vector<int>> proc;
    int n, q;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> q;

    for (int i = 0; i < n; i++) {
        vector<int> temp(3);
        cout << "Enter {arrival, burst} for process " << i << ": ";
        cin >> temp[1]; 
        cin >> temp[2]; 
        temp[0] = 0; 
        proc.push(temp);
    }

    rr_sim(proc, q);
    return 0;
}
