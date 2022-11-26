#include <iostream>
#include <thread>
#include <vector>

void foo(std::vector<int> &nums, size_t i) {
    nums[i] += 1;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    const size_t THREAD_AMOUNT = std::thread::hardware_concurrency();
    std::thread executors[THREAD_AMOUNT];
    std::vector<int> nums(THREAD_AMOUNT);
    for (size_t j = 0; j < 5; j++) {
        size_t i = 0;
        for (auto & executor : executors) {
            if (!executor.joinable()) {
                executor = std::thread(foo, std::ref(nums), i);
            }
            i += 1;
        }

        for (auto & executor : executors) {
            executor.join();
        }

        for (const auto &num : nums) {
            std::cout << num << "  ";
        }
        std::cout << std::endl;
    }


    return 0;
}



