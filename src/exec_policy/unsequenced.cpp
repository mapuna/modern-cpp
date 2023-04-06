#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::for_each(std::execution::unseq, v.begin(), v.end(),
                [](int x) { std::cout << x << "^3 = " << x * x * x << ", "; });
  std::cout << std::endl;
  return 0;
}
