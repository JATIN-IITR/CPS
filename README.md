# CPU Scheduler
This project is a web application CPU Scheduler designed for users to input processes and choose a scheduling algorithm to visualize the outcomes. Supported algorithms comprise FCFS, SJF, Priority Scheduling, and Round Robin.

# Features

-Algorithm Selection: Choose from FCFS, SJF, Priority Scheduling, or Round Robin.

-Process Input: Enter processes in pid, burst_time, priority format.

-Dynamic Results: View waiting time and turnaround time dynamically for each process

-Responsive Design: Ensures usability across various devices with a responsive layout.

# Dependencies
C++ Compiler

A Browser serving Frontend

Git



# Internal Working

1. **Clone the repository:**

   ```bash
   git clone https://github.com/JATIN-IITR/CPU-Scheduler.git

2.Setup backend:

-Ensure a C++ compiler is installed on your system.

Compile the backend files: 

```bash
https://github.com/JATIN-IITR/CPU-Scheduler/blob/main/main.cpp
https://github.com/JATIN-IITR/CPU-Scheduler/tree/main/Scheduling%20Algorithm%20variants
https://github.com/JATIN-IITR/CPU-Scheduler/blob/main/algo.cpp

```
3. Serve Frontend
   
   ```bash
   https://github.com/JATIN-IITR/CPU-Scheduler/blob/main/l.html
   ```

# Theory of Scheduling Algorithms

FCFS:
It is a non-preemptive scheduling algorithm where processes are executed in the order they arrive. Once a process starts executing, it continues until it is complete. If two processes have the same arrival time, the one that appears first in the input is executed first. Finish time is calculated during execution, and Turnaround Time and Wait Time are derived from it.
It is suitable for batch processing where all jobs are known in advance, and equal priority is given to all processes.

SJF:
It is a non-preemptive or preemptive scheduling algorithm where the process with the shortest execution time is selected for execution next.
It is suitable for environments where burst times are known in advance or can be estimated accurately, such as interactive systems or when processes arrive at random intervals.


Priority Scheduling:
It is a scheduling algorithm where each process is assigned a priority. The scheduler selects the process with the highest priority for execution.
It is used in real-time systems where certain processes require immediate attention or when there are specific service level agreements (SLAs) to be met.

Round Robin	:
It is a preemptive scheduling algorithm where each process is assigned a fixed time slice or quantum. The scheduler cycles through ready processes, allocating each one the CPU for the specified time.
It is commonly used in time-sharing systems, interactive systems, and environments where fairness and responsiveness are prioritized.


# Learning Takeaways

Throughout this project, several key insights and skills were acquired:

*Comprehensive Understanding of Scheduling Algorithms*: Developed a thorough grasp of different scheduling algorithms, including their strengths and weaknesses.

*Significance of Scheduling Terms and Selection Criteria*: Recognized the importance of scheduling terms and criteria in determining the most suitable scheduler for specific scenarios.

*Critical Role of Schedulers in Operating Systems*: Appreciated the pivotal role of schedulers in optimizing task execution and resource allocation within an operating system.

*Enhanced C++ Coding Proficiency*: Improved skills in writing structured and efficient C++ code tailored to implement specific algorithms effectively.

*Integration of Front-end and Back-end Systems*: Acquired knowledge in integrating front-end interfaces with back-end systems, facilitating the display of back-end data to users.

These insights and skills collectively contribute to a deeper understanding of system optimization through CPU scheduling algorithms and enhance proficiency in software development practices.

# References
Operating System Concepts by Abraham Silberschatz, Peter Baer Galvin, and Greg Gagne.

https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/

https://www.youtube.com/playlistlist=PLBlnK6fEyqRitWSE_AyyySWfhRgyA-rHk







