#include <print>
#include <thread>
#include <vector>

#include <chrono>
using namespace std::chrono_literals;

constexpr size_t max_num_threads = 3;

auto hello(size_t thread_idx) -> void {
    std::println("Thread {} got created.", thread_idx);
    std::this_thread::sleep_for(1.0s * (thread_idx + 1));
    std::println("Thread {} Finished Sleeping", thread_idx);
}

int main() {
    std::vector<std::thread> threads;
    for (size_t i = 0; i < max_num_threads; ++i) {
        threads.emplace_back([i]() { hello(i); });
    }
    for (auto &thread : threads) {
        thread.join();
    }
}