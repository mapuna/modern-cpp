#include <functional>
#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> create(bool b) {
    if (b) {
        return "Godzilla";
    }
    return {};
}

auto create_auto(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

auto create_ref(bool b) {
    static std::string value = "Godzilla";
    return b ? std::optional<std::reference_wrapper<std::string>>{value}
             : std::nullopt;
}

int main() {
    std::cout << "create(false) returned " << create(false).value_or("empty")
              << '\n';
    if (auto str = create_auto(true)) {
        std::cout << "create_auto(true) returned " << *str << '\n';
    }
    if (auto str = create_ref(true)) {
        std::cout << "create_ref(true) returned " << str->get() << '\n';
        str->get() = "KingKong";
        std::cout << "modifying it changed it to " << str->get() << '\n';
    }
    return 0;
}
