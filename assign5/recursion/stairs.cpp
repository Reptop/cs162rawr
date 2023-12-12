/*********************************************************************
** Program Filename: stairs.cpp
** Author: Raed Kabir
** Date: 12/10/23
** Description: computes total number of ways to traverse staircase of size N
** Input: N/A
** Output: An integer denoting total number of ways to traverse staircase
*********************************************************************/

int ways_to_top(int n) {

  // I put this in one line because im silly
  return n == 0  ? 1
         : n < 0 ? 0
                 : ways_to_top(n - 1) + ways_to_top(n - 2) + ways_to_top(n - 3);
}
