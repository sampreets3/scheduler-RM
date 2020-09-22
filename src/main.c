#include "tasks.h"

int main(void) {

  // Create four tasks : remember (taskName, compTime, deadline)
  createTask("T1", 2.0, 10.0);
  createTask("T1", 5.0, 20.0);
  createTask("T1", 3.0, 5.0);

  assignPriority();
  //show the task set
  showTaskSet();
}
