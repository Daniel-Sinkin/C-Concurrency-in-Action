#include <print>
#include <thread>

auto hello() -> void {
    std::println("Hello, World!");
}

auto main() -> int {
    std::thread t(hello);
    t.join();
}