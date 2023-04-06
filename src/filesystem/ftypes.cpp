#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

namespace fs = std::filesystem;

void status(const fs::path &p, fs::file_status s) {
    std::cout << p;
    switch (s.type()) {
    case fs::file_type::none:
        std::cout << " has `not-evaluated-yet` type";
        break;
    case fs::file_type::not_found:
        std::cout << " does not exist";
        break;
    case fs::file_type::regular:
        std::cout << " is a regular file";
        break;
    case fs::file_type::directory:
        std::cout << " is a directory";
        break;
    case fs::file_type::symlink:
        std::cout << " is a symlink";
        break;
    case fs::file_type::block:
        std::cout << " is a block device";
        break;
    case fs::file_type::character:
        std::cout << " is a char device";
        break;
    case fs::file_type::fifo:
        std::cout << " is a named IPC pipe";
        break;
    case fs::file_type::socket:
        std::cout << " is a named IPC socket";
        break;
    case fs::file_type::unknown:
        std::cout << " has unknown type";
        break;
    default:
        std::cout << " has `implementation-defined` type";
        break;
    }
    std::cout << '\n';
}

int main() {
    fs::create_directory("sandbox");
    std::ofstream("sandbox/file");
    fs::create_directory("sandbox/dir");
    mkfifo("sandbox/pipe", 0644);
    sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    std::strcpy(addr.sun_path, "sandbox/sock");
    int fd = socket(PF_UNIX, SOCK_STREAM, 0);
    bind(fd, reinterpret_cast<sockaddr *>(&addr), sizeof addr);
    fs::create_symlink("file", "sandbox/symlink");

    for (auto it = fs::directory_iterator("sandbox");
         it != fs::directory_iterator(); ++it) {
        status(*it, it->symlink_status());
    }
    status("/dev/null", fs::status("/dev/null"));
    status("/dev/sda", fs::status("/dev/sda"));
    status("sandbox/no", fs::status("sandbox/no"));

    close(fd);
    fs::remove_all("sandbox");

    return 0;
}
