#ifndef MISC
#define MISC

#include "tasks.hpp"

/* function comparePeriod : takes in two taskControlBlock
 * elements, and returns true if the first element has a
 * smaller task period than the second element.
 */
bool comparePeriod(taskControlBlock x, taskControlBlock y) {
  if(x.period < y.period)
    return true;
  else
    return false;
}

/* function gcd : Computes the Greatest Common Denominator
 * between two given numbers using recursion
 */
int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  else {
    return gcd(b, a%b);
  }
}

/* function computeHyperPeriod : computes the hyperperiod
 * of a given vector of taskControlBlock elements.
 */
int computeHyperPeriod(std::vector <taskControlBlock> vec) {
  int n = vec.size();               // Calculate the size of the vector

  int ans = vec.begin()->period;   // Choose the first element as the default answer

  for (auto elem : vec) {
    ans = (int)(elem.period * ans) / (gcd(elem.period, ans));
  }
  return ans;
}

#endif
