#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    const fs::path sandbox("sandbox");
    fs::create_directories(sandbox / "dir1" / "dir2");
    std::ofstream(sandbox / "file1.txt");
    std::ofstream(sandbox / "file2.txt");

    std::cout << "directory_iterator:\n";

    for (auto const &diren : fs::directory_iterator{sandbox}) {
        std::cout << diren.path() << '\n';
    }

    std::cout << "\ndirectory_iterator as a range:\n";
    std::ranges::for_each(
        fs::directory_iterator{sandbox},
        [](const auto &diren) { std::cout << diren << '\n'; });

    std::cout << "\nrecursive directory_iterator:\n";
    for (auto const &diren : fs::recursive_directory_iterator{sandbox}) {
        std::cout << diren << '\n';
    }

    fs::remove_all(sandbox);
    return 0;
}
