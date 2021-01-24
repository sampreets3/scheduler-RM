#include "tasks.hpp"
#include <ctime>

std::vector<taskControlBlock> taskSet;

/* function createTask : creates a task by initialising
 * a taskControlBlock element with the given values and
 * pushing it to the vector of taskControlBlock elements.
 */
void createTask(std::string tName, int c, int p) {
  taskControlBlock temp;

  temp.taskID   = tName;
  temp.compTime = c;
  temp.period   = p;
  temp.remTime  = c;
  temp.utility  = (float)c/(float)p;
  temp.isReady  = 1;

  taskSet.push_back(temp);
}

/* function printTaskState : Small helper function to print the state of the task
 */
std::string printTaskState(taskControlBlock t) {
  if(t.isReady)
    return "READY";
  else
    return "WAITING";
}

/* function showTaskSet : Iterates through the set of
 * tasks and print them.
 */
void showTaskSet() {

  std::cout << "\t======== TASK STATS: ========\n" << std::endl;
  std::cout << "Task ID" << "     Computation Time" << "\tPeriod" << "\tUtility" << "\tState" << std::endl;
  for(auto elem: taskSet) {
    std::cout << "   " << elem.taskID << "\t\t" << elem.compTime << "\t\t" << elem.period << "\t" << elem.utility << "\t" << printTaskState(elem) << std::endl;
  }
  std::cout << "\t\t====== * ======" << std::endl;
}
