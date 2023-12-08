int ways_to_top(int n) {

  return n == 0  ? 1
         : n < 0 ? 0
                 : ways_to_top(n - 1) + ways_to_top(n - 2) + ways_to_top(n - 3);
}
