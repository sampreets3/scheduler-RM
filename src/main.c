#include "tasks.h"
#include "scheduler.h"

int main(void) {

  head = NULL;

  // Create four tasks : remember (taskName, compTime, deadline)
  createTask("T1", 3.0, 20.0);
  createTask("T2", 2.0, 05.0);
  createTask("T3", 2.0, 10.0);

  // Assign priorities to each task
  assignPriority();


  //show the task set
  //showTaskSet();

  // Run the schedulability tests
  testSchedulability();


}
