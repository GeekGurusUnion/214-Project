#ifndef SUM_H_
#define SUM_H_

/**
 * @brief Returns the sum of two integers
 * 
 * Name: Sum
 *
 * Preconditions:
 *  - a must be greater than zero
 *  - b must be equal to greater than zero
 *
 * Postconditions:
 *  - Returns the sum of the two parameters which will be greater than zero
 * 
 * Proof:
 * b >= 0 (Precondition 2)
 * b + a > 0 (Precondition 1)
 *
 * Exceptions:
 *  - Returns std::invalid_argument exception "a must be greater than zero" if a is less than or equal to zero
 *  - Returns std::invalid_argument exception "b must be equal to greater than zero" if b is less than zero
 *
 * @param a must be greater than zero
 * @param b must be equal to greater than zero
 * @return int The result of calculating the sum
 */
int Sum(int a, int b);

#endif  // SUM_H_
