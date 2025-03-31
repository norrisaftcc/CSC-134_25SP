#include <iostream>
#include <thread>
#include <chrono>

void slow_print(const std::string& msg) {
    for (char c : msg) {
        std::cout << c;
        std::cout.flush(); // Ensure the character is printed immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay of 100 milliseconds
    }
    std::cout << std::endl;
}

int main() {
    std::string message = "Hello, world!";
    slow_print(message);
    message = "Time to isekai!";
    slow_print(message);
    return 0;
}