#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

std::string outputString; // Buffer to store simulation results

// FCFS Scheduling
void fcfs(std::vector<Process>& processes) {
    int currentTime = 0;
    for (auto& process : processes) {
        process.waitingTime = std::max(0, currentTime - process.arrivalTime);
        process.turnaroundTime = process.waitingTime + process.burstTime;
        currentTime = std::max(currentTime, process.arrivalTime) + process.burstTime;
    }
}

// Round Robin Scheduling
void roundRobin(std::vector<Process>& processes, int quantum) {
    int currentTime = 0;
    std::queue<Process*> readyQueue;
    for (auto& process : processes) {
        readyQueue.push(&process);
    }

    while (!readyQueue.empty()) {
        Process* process = readyQueue.front();
        readyQueue.pop();

        if (process->burstTime > quantum) {
            currentTime += quantum;
            process->burstTime -= quantum;
            readyQueue.push(process);
        } else {
            currentTime += process->burstTime;
            process->waitingTime = currentTime - process->arrivalTime - process->burstTime;
            process->turnaroundTime = currentTime - process->arrivalTime;
            process->burstTime = 0;
        }
    }
}

// SJF Scheduling
void sjf(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });
    fcfs(processes);
}

// Main entry point
extern "C" {
    void simulateFCFS() {
        std::ostringstream buffer;
        
        std::vector<Process> processes = {
            {1, 0, 5, 0, 0},
            {2, 1, 3, 0, 0},
            {3, 2, 8, 0, 0},
            {4, 3, 6, 0, 0}
        };
        fcfs(processes);
        for (const auto& process : processes) {
            buffer << "Process " << process.id << ": Waiting Time = " << process.waitingTime
                  << ", Turnaround Time = " << process.turnaroundTime << "\n";
        }
        
        outputString = buffer.str();
    }

    void simulateRoundRobin(int quantum) {
        std::ostringstream buffer;
        
        std::vector<Process> processes = {
            {1, 0, 5, 0, 0},
            {2, 1, 3, 0, 0},
            {3, 2, 8, 0, 0},
            {4, 3, 6, 0, 0}
        };
        roundRobin(processes, quantum);
        for (const auto& process : processes) {
            buffer << "Process " << process.id << ": Waiting Time = " << process.waitingTime
                  << ", Turnaround Time = " << process.turnaroundTime << "\n";
        }
        
        outputString = buffer.str();
    }

    void simulateSJF() {
        std::ostringstream buffer;
        
        std::vector<Process> processes = {
            {1, 0, 5, 0, 0},
            {2, 1, 3, 0, 0},
            {3, 2, 8, 0, 0},
            {4, 3, 6, 0, 0}
        };
        sjf(processes);
        for (const auto& process : processes) {
            buffer << "Process " << process.id << ": Waiting Time = " << process.waitingTime
                  << ", Turnaround Time = " << process.turnaroundTime << "\n";
        }
        
        outputString = buffer.str();
    }

    // Function to get the output
    const char* getOutput() {
        return outputString.c_str();
    }
}
