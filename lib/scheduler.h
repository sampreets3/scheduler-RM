#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <math.h>
#include <stdbool.h>

bool isSchedulable = false, necTest = false, sufTest = false;                       // Boolean flags to check various tests
int hyperPeriod;
double feasible, totalUtil;
int periodList[10];                                          // Maximum number of schedulable tasks for now is 10
int numTasks;

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  else {
    return gcd(b, a%b);
  }
}

int lcm(int arr[], int n) {
  int ans = arr[0];

  for (int i = 1; i < n; i++ ) {
    ans = (arr[i] * ans) / (gcd(arr[i], ans));
  }
  return ans;
}

void testSchedulability(){
  struct taskControlBlock *t = head;
  int pos;                                                      // Just to increment the array index

  printf("Task ID       Period(=Deadline)      Computation Time       Utility          Priority\n");

  while(t != NULL) {
    periodList[pos] = t->deadline;                           // populate the array of task periods
    totalUtil += t->utility;                                  // Compute the total processor utility
    printf("    %s            %.2f                   %.2f               %.2f               %.2f\n", t->taskID, t->deadline, t->compTime, t->utility, t->priority);
    t = t->tcbNext;
    pos++;
  }

  printf("    ----- * ----- * ----- * ----- * ----- * ----- ----- * ----- * ----- * ----- * ----- \n");
  hyperPeriod = lcm(periodList, numTasks);
  feasible = numTasks * (pow(2, (1/(double)numTasks)) - 1);
  printf("[INFO] Number of tasks                        : %d\n", numTasks);
  printf("[INFO] Hyperperiod is                         : %d\n", hyperPeriod);
  printf("[INFO] Total processor utilisation            : %.2f\n", totalUtil);
  printf("[INFO] Feasibility metric is                  : %.2f\n", feasible);
  printf("[INFO] Running Necessary Schedulability Test  : ");

  if(totalUtil < 1) {
    printf("PASSED.\n");
    necTest = true;
  }
  else {
    printf("FAILED.\n");
    necTest = false;
  }

  printf("[INFO] Running Sufficient Schedulability Test : ");

  if(necTest && (totalUtil < feasible)) {
    printf("PASSED.\n");
    sufTest = true;
  }
  else {
    printf("FAILED.\n");
    sufTest = false;
  }

  if(sufTest & necTest) {
    isSchedulable = true;
    printf("[INFO] Necessary and Sufficient Tests passed  : Task set is schedulable.\n");
  }
  else {
    printf("[INFO] Necessary or Sufficient Tests failed   : Task set is not schedulable.\n");
  }
}

#endif
