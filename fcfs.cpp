#include <iostream>
#include <vector>

struct Process {
    int pid;         
    int burst_time;  
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTime(std::vector<Process>& processes) {
    processes[0].waiting_time = 0; 

    
    for (size_t i = 1; i < processes.size(); ++i) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void calculateTurnaroundTime(std::vector<Process>& processes) {
    
    for (size_t i = 0; i < processes.size(); ++i) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void printResults(const std::vector<Process>& processes) {
    std::cout << "PID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : processes) {
        std::cout << process.pid << "\t" << process.burst_time << "\t\t" 
                  << process.waiting_time << "\t\t" << process.turnaround_time << "\n";
    }
}

int main() {
    std::vector<Process> processes ;
int n;
cout << "No. of operations" << endl;
cin >> n;
cout << "Enter the operation time " << endl;
for (int j=0; j<n; j++) {
int x;
cin >> x;
processes.push_back(X);
}
    calculateWaitingTime(processes);
    calculateTurnaroundTime(processes);
    printResults(processes);

    return 0;
}
