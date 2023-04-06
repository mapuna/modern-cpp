#include <cstdint>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void print_info(const auto &dirs, int width = 15) {
    (std::cout << std::left).imbue(std::locale("en_US.UTF-8"));
    for (const auto s : {"Dir", "Capacity", "Free", "Available"}) {
        std::cout << "| " << std::setw(width) << s << ' ';
    }
    std::cout << '\n';
    std::error_code ec;

    for (const auto &dir : dirs) {
        const std::filesystem::space_info si = std::filesystem::space(dir, ec);
        std::cout << "| " << std::setw(width) << dir << ' ' << "│ "
                  << std::setw(width) << static_cast<std::intmax_t>(si.capacity)
                  << ' ' << "│ " << std::setw(width)
                  << static_cast<std::intmax_t>(si.free) << ' ' << "│ "
                  << std::setw(width)
                  << static_cast<std::intmax_t>(si.available) << '\n';
    }
}

int main() {
    const auto dirs = {"/dev/null", "/tmp", "/home", "/"};
    print_info(dirs);
}
