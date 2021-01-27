#ifndef TASKS
#define TASKS
#include <iostream>
#include <vector>

typedef struct {
  std::string taskID;         // Stores the task identifier
  int compTime;               // Stores the computation time for the task
  int period;                 // Stores the period(=deadline) of the task
  int remTime;                // Stores the remaining execution time of the task
  float utility;              // Stores the utility of the task
  int isReady;                // Stores the current state of the task
  int priority;               // Stores the priority of the task
} taskControlBlock;

extern std::vector<taskControlBlock> taskSet;

void createTask(std::string tName, int c, int p);
void showTaskSet();
std::string printTaskState(taskControlBlock t);

#endif
