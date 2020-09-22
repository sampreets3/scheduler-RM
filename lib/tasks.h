#include <stdio.h>
#include <stdlib.h>

extern int hyperPeriod;              // Stores the hyperperiod for simulation
extern int numTasks;                    // Stores the number of tasks in the list

enum taskState{
  BLOCKED=0,
  RUNNING=1,
  READY=2
};

struct taskControlBlock {
  char* taskID;
  float compTime;                      // Stores the Computation Time of the task
  float deadline;                      // Stores the Period(= Deadline) of the task
  float priority;                      // Stores the priority of the task
  float utility;                       // Stores the utility of the task
  enum taskState state;                // Stores the current state of the task(useful in scheduling)
  struct taskControlBlock* tcbPrev;    // Points to the previous taskControlBlock element
  struct taskControlBlock* tcbNext;    // Points to the next taskControlBlock element
};

struct taskControlBlock* head;         // Pointer to the head(starting) node

struct taskControlBlock* init(char* tID, float c, float d);
void sortTaskList();
void createTask(char* tID, float c, float d);
void showTaskSet();
void assignPriority();
