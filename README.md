[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)
[![Open Source Love svg3](https://badges.frapsoft.com/os/v3/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)

# scheduler-RM
Simulation of the behavior of a Preemptive Fixed Priority Rate Monotonic Scheduler in C++.


---

## Overview
This project focusses on building a preemptive fixed priority rate monotonic task scheduler in C++. Done as a part of the **Real-Time Scheduling** course at École Centrale de Nantes. The aim of this project is to create a simulation of a standard Rate Monotonic scheduler in order to gain a better understanding at building Hard Real-Time systems. The choice of scheduling algorithm was kept to be Rate Monotonic, since it is the easiest deterministic scheduler to implement. I have tried to design the software to be optimal to the best of my abilities, but if you can provide a more elegant solution, feel free to contribute to this project.

A simple outlook of the algorithm can be as follows:
> Each task has its own Task Control Block, containing necessary information about the task. The algorithm will assign priorities offline,
> and simulate for one hyperperiod. At each time interval of the simulation, the task with the highest priority will be executed, until there
> are no more tasks to be executed.

Also, before generating the schedule, it is imperative that we run schedulability tests on the task set to determine whether it is feasible or not. The software runs these schedulability tests on the task set and computes the schedule if and only if the task set is feasible.

---

## Usage
1. First, you have to clone the repo onto your local machine : `git clone https://github.com/sampreets3/scheduler-RM.git`
1. Then, navigate into the project directory by using : `cd scheduler-RM`
1. You have to create a *build* folder inside of the project directory : `mkdir build`
1. You can then build the executables using the GNU Make tool :  `make`

In case you need to delete all executables and start afresh, you can do so with the command : `make clean`

---

## Contribute

Feel free to request features, and make changes to the project! If you have an idea in mind, you can open an issue and create a pull request to make your changes. The general practice that I follow is **each feature gets its own branch**. It would be great if you could adhere to that.

---

## Contact
If you have any questions, feel free to contact me at `sampreets3@gmail.com`

---
