#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::for_each(std::execution::par_unseq, v.begin(), v.end(),
                [](int x) { std::cout << x << "^2 = " << x * x << ", "; });
  std::cout << std::endl;
  return 0;
}
