#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int pid;           
    int burst_time;     
    int priority;      
    int waiting_time;   
    int turnaround_time;
};

bool comparePriority(Process a, Process b) {
    return a.priority < b.priority;
}

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
    std::cout << "PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : processes) {
        std::cout << process.pid << "\t" << process.burst_time << "\t\t" 
                  << process.priority << "\t\t" << process.waiting_time << "\t\t" 
                  << process.turnaround_time << "\n";
    }
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter burst time and priority for process " << i + 1 << ": ";
        std::cin >> processes[i].burst_time >> processes[i].priority;
        processes[i].pid = i + 1;
    }

    std::sort(processes.begin(), processes.end(), comparePriority);

    calculateWaitingTime(processes);
    calculateTurnaroundTime(processes);
    printResults(processes);

    return 0;
}
