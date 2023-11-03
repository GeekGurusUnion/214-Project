#include <stdexcept>
#include "sum.h"

int Sum(int a, int b) {

  // Validate preconditions

  // First precondition
  // a must be greater than zero
  if (a <= 0) {
      throw std::invalid_argument("a must be greater than zero"); 
  }

  // Second precondition
  // b must be equal to greater than zero
  if (b < 0) {
      throw std::invalid_argument("b must be equal to greater than zero"); 
  }

  // What did we do at the top?
  // 1. Early exit. What does that give us?
  // 2. What do we know at this line? What are we guaranteed here <--------
  // a > 0 and b >= 0

  return (a + b);
}
