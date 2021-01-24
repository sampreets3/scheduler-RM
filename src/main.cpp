#include "tasks.hpp"
#include "misc.hpp"
#include "scheduler.hpp"

int main(void){

  // Create three tasks
  createTask("T1", 2, 8);
  createTask("T2", 4, 16);
  createTask("T3", 1, 4);

  // Show the set of tasks
  showTaskSet();

  // Run the scheduler
  //std::vector <std::string> s = scheduleRM();
  printSchedule(scheduleRM());
  return 0;
}
