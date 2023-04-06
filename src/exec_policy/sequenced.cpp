#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {5, 4, 3, 2, 1};
  std::sort(std::execution::seq, v.begin(), v.end());

  for (auto i : v) {
    std::cout << i << " ";
  }

  std::cout << std::endl;
  return 0;
}
