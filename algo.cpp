#include "algorithms.h"
#include <algorithm>
#include <queue>

std::vector<Process> fcfs(std::vector<Process> processes) {
    int current_time = 0;
    for (auto& process : processes) {
        process.start_time = current_time;
        process.waiting_time = current_time;
        current_time += process.burst_time;
        process.finish_time = current_time;
        process.turnaround_time = process.finish_time;
    }
    return processes;
}

std::vector<Process> sjf(std::vector<Process> processes) {
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.burst_time < b.burst_time;
    });
    return fcfs(processes);
}

std::vector<Process> priority_scheduling(std::vector<Process> processes) {
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.priority < b.priority;
    });
    return fcfs(processes);
}

std::vector<Process> round_robin(std::vector<Process> processes, int quantum) {
    std::queue<Process> q;
    std::vector<Process> result;
    int current_time = 0;

    for (auto& process : processes) {
        q.push(process);
    }

    while (!q.empty()) {
        auto process = q.front();
        q.pop();

        process.start_time = current_time;
        if (process.burst_time > quantum) {
            process.burst_time -= quantum;
            current_time += quantum;
            q.push(process);
        } else {
            current_time += process.burst_time;
            process.finish_time = current_time;
            process.turnaround_time = current_time;
            process.waiting_time = current_time - process.burst_time;
            result.push_back(process);
        }
    }
    return result;
}
