#include "tasks.h"

int numTasks;

/* function init : Initialises a new taskControlBlock element with given input
 * parameters. This function is not directly called by the user, but instead the
 * user calls the createTask() function, which in turn calls this function
 */
struct taskControlBlock* init(char* tID, float c, float d) {

  //Allocate the amount of memory required by the taskControlBlock element
	struct taskControlBlock* newTask = (struct taskControlBlock*)malloc(sizeof(struct taskControlBlock));

  // Assign all the fields of the taskControlBlock with the given data
  newTask->taskID   = tID;
	newTask->compTime = c;
  newTask->deadline = d;
	newTask->utility  = c/d;
	newTask->state    = READY;
	newTask->tcbPrev  = NULL;
	newTask->tcbNext  = NULL;
	return newTask;
}

/* function sortTaskList : Sorts the task list
 * TODO : figure out order to sort it in
 */
void sortTaskList() {
  struct taskControlBlock *current = NULL, *index = NULL;
  double tempC, tempD;		// Maybe use another taskControlBlock struct here
  char* temptID;

  if(head == NULL) {  // Check if list is empty
    return;
  }

  else {
    for (current = head; current->tcbNext != NULL; current = current->tcbNext) {
      for (index = current->tcbNext; index != NULL; index = index->tcbNext) {
        if(current->deadline > index->deadline) {
          tempC   = current->compTime;
          tempD   = current->deadline;
          temptID = current->taskID;

          current->compTime = index->compTime;
          current->deadline = index->deadline;
          current->taskID   = index->taskID;

          index->compTime = tempC;
          index->deadline = tempD;
          index->taskID   = temptID;
        }
      }
    }
  }
}

void createTask(char* tID, float c, float d) {

	// Increment the number of tasks
	numTasks++;

	// Initialise a new taskControlBlock with the given values
	struct taskControlBlock* newTCB = init(tID, c, d);
	if(head == NULL) {
		head = newTCB;      // If list is empty, add the task at the top of the list
		return;
	}

	// Make the necessary connections for the Linked List
	head->tcbPrev = newTCB;
	newTCB->tcbNext = head;
	head = newTCB;

  // before sorting, check if schedulable or not
  sortTaskList();     // Sorts the task list
}

/* function assignPriority : Assigns fixed priorities to each task
 * based on their period and total number of tasks
 */
void assignPriority() {
	int n = numTasks;
	struct taskControlBlock* t;

	/* Since the tasks are already sorted in ascending order of period
	 * we can simply traverse through the list and assign descending
	 * priorities in descending order
	 */
	while (t != NULL) {
		t->priority = n--;
		t = t->tcbNext;
	}
}

void showTaskSet() {
	struct taskControlBlock* temp = head;
	printf("\n\n\t------ TASK STATS: ------ \n\n");
	while(temp != NULL) {
    printf("\tIdentifier        : %s  \n", temp->taskID);
    printf("\tPriority          : %.2f\n", temp->priority);

		if(temp->state == RUNNING) {
			printf("\tState             : RUNNING  \n");
		}
		else if(temp->state == READY) {
			printf("\tState             : READY  \n");
		}
		else {
			printf("\tState             : BLOCKED  \n");
		}

		printf("\tComputation Time  : %.2f\n", temp->compTime);
		printf("\tUtility	          : %.2f\n", temp->utility);
    printf("\tPeriod(=Deadline) : %.2f\n", temp->deadline);
    printf("\t------ * ------- \n");
		temp = temp->tcbNext;
	}

	printf("[INFO] Number of tasks : %d\n", numTasks);
}
