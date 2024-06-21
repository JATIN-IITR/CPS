#include <iostream>
#include <vector>
#include <queue>

struct Process {
    int pid;            
    int burst_time;     
    int remaining_time; 
    int waiting_time;   
    int turnaround_time;
};

void calculateRoundRobin(std::vector<Process>& processes, int quantum) {
    std::queue<Process*> processQueue;
    for (auto& process : processes) {
        process.remaining_time = process.burst_time;
        processQueue.push(&process);
    }

    int current_time = 0;
    while (!processQueue.empty()) {
        Process* current_process = processQueue.front();
        processQueue.pop();

        if (current_process->remaining_time > quantum) {
            current_process->remaining_time -= quantum;
            current_time += quantum;
            processQueue.push(current_process);
        } else {
            current_time += current_process->remaining_time;
            current_process->waiting_time = current_time - current_process->burst_time;
            current_process->turnaround_time = current_time;
            current_process->remaining_time = 0;
        }
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
    int n, quantum;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter burst time for process " << i + 1 << ": ";
        std::cin >> processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    std::cout << "Enter quantum time: ";
    std::cin >> quantum;

    calculateRoundRobin(processes, quantum);
    printResults(processes);

    return 0;
}
