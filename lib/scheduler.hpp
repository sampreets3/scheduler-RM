#ifndef SCHEDULER
#define SCHEDULER

#include "misc.hpp"
#include "matplotlibcpp.h"
#include <algorithm>
#include <cmath>

bool necTest = false, sufTest = false, isSched = false;
float totalUtil = 0.00, feasible = 0.0;
int idleTime = 0;

/* function testSchedulability : Runs important schedulability
 * tests on the given set of task
 */
bool testSchedulability() {

  std::cout << "\n\n" << "-------- SCHEDULABILITY ANALYSIS ------- " << std::endl;

  for(auto elem: taskSet)
    totalUtil += elem.utility;            // Iterate through the task set and compute the total utilisation

  feasible = taskSet.size() * (std::pow(2, 1/(double)taskSet.size()) - 1);
  std::cout << "[INFO] Number of tasks            : " << taskSet.size() << std::endl;
  std::cout << "[INFO] Hyperperiod is             : " << computeHyperPeriod(taskSet) << " time units" << std::endl;
  std::cout << "[INFO] Tota Processor Utilisation : " << totalUtil << std::endl;
  std::cout << "[INFO] Feasibility Metric is      : " << feasible << std::endl;
  std::cout << "[INFO] Running Sufficient Test    : ";
  if(totalUtil < feasible) {              // Sufficient schedulability test
    std::cout << "PASSED" << std::endl;
    sufTest = true;
  }
  else {
    std::cout << "FAILED" << std::endl;
    sufTest = false;
  }

  std::cout << "[INFO] Running Necessary Test     : ";
  if(totalUtil < 1.0) {                   // Necessary schedulability test
    std::cout << "PASSED" << std::endl;
    necTest = true;
  }
  else {
    std::cout << "FAILED" << std::endl;
    necTest = false;
  }

  std::cout << "-------------------------------------" << std::endl;

  if(necTest & sufTest)
    isSched = true;                     // Returns true if both tests pass

  return isSched;
}

/* function scheduleRM : Implements the Fixed Priority Rate Monotonic
 * scheduling algorithm on the task set
 */
std::vector<std::string> scheduleRM(){

  std::vector<std::string> sched;
  int hp = computeHyperPeriod(taskSet);
  int n = taskSet.size();
  sort(taskSet.begin(), taskSet.end(), comparePeriod);      // Sort the task set in ascending order of period

  if(testSchedulability()){                                 // If the task list is schedulable, then go on
    for(int i=0 ; i< hp ; i++){
      if(i>=taskSet[0].period)
        for(int j=0 ; j<n ; j++){
          if(!(i%taskSet[j].period))                       // If the task is restarted
              taskSet[j].isReady=1;                        // Set the state to ready
        }
        for(int j=0 ; j<n ; j++){
          if(taskSet[j].isReady && (taskSet[j].remTime)){  //If task is ready and has remaining execution time
              if(!(--(taskSet[j].remTime))){               //If task has executed fully
                  taskSet[j].isReady=0;                    //Set task status to waiting
                  taskSet[j].remTime=taskSet[j].compTime;  //Reset the remaining execution time of the task
              }
              sched.push_back(" " + taskSet[j].taskID + " ");
              break;
          }
          if(j == n-1) {
            sched.push_back("IDLE");
            idleTime++;
          }
        }
    }
  }
  return sched;
}

void printSchedule(std::vector<std::string> s) {

  std::cout << "\n\tSchedule:\t\t" << std::endl;
  std::cout << "Task\t|   ";

  for(auto elem: s)
    std::cout << elem << "   ";

  std::cout << "\n\nTime\t|   ";
  for(int t = 0; t < computeHyperPeriod(taskSet); t++) {
    std::cout << t << "    ";
  }
  std::cout << "\n------------------------------" <<std::endl;
  std::cout << "[INFO] Maximum Processor Idle     : " << idleTime << " time units" <<std::endl;
  std::cout << std::endl;
}

#endif
