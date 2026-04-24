int CountDigit(int digit, int limit) {
  int count = 0;
  int factor = 1;
  int tail = 0;
  while (limit >= 10) {
    int d = limit % 10;
    limit /= 10;
    count += limit * factor;
    count += d > digit ? factor : d == digit ? tail : 0;
    tail += d * factor;
    factor *= 10;
  }
  return count + (limit > digit ? factor : limit == digit ? tail : 0);
}

class Solution {
public:
  int countDigitOne(int n) {
    return CountDigit(1, n + 1);
  }
};