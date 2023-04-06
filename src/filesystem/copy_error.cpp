#include <filesystem>
#include <iostream>
#include <system_error>

int main() {
  const std::filesystem::path from{"/root/abc"},
      to{"/root/def"}; // both do not exist
  try {
    std::filesystem::copy_file(from, to);
  } catch (std::filesystem::filesystem_error const &e) {
    std::cout << "what(): " << e.what() << '\n'
              << "path1(): " << e.path1() << '\n'
              << "path2(): " << e.path2() << '\n'
              << "code().value(): " << e.code().value() << '\n'
              << "code().message(): " << e.code().message() << '\n'
              << "code().category(): " << e.code().category().name() << '\n';
  }

  std::error_code ec;
  std::filesystem::copy_file(from, to, ec); // does not throw
  std::cout << "\nnon-throwing form of copy_file() sets the error_code: "
            << ec.message() << '\n';

  return 0;
}
