#include "tasks.hpp"
#include "misc.hpp"
#include "scheduler.hpp"

int main(void){

  // Create three tasks
  createTask("T1", 3, 20);
  createTask("T2", 2, 5);
  createTask("T3", 2, 10);

  // Show the set of tasks
  showTaskSet();

  // Run the scheduler
  printSchedule(scheduleRM());
  return 0;
}
