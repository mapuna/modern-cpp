#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2(5);

    std::transform(std::execution::par, v1.begin(), v1.end(), v2.begin(),
                   [](int x) { return x * x; });
    for (auto i : v2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
