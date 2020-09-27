#ifndef TASKS
#define TASKS
#include <iostream>
#include <vector>

typedef struct {
  std::string taskID;
  int compTime;
  int period;
  int remTime;
  float utility;
  int isReady;
} taskControlBlock;

extern std::vector<taskControlBlock> taskSet;

void createTask(std::string tName, int c, int p);
void showTaskSet();
std::string printTaskState(taskControlBlock t);

#endif
