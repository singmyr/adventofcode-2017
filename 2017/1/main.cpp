#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("2017/1/input.txt");

    long long sum = 0;
    if (file.is_open()) {
        char first;

        // Retrieve the first char for the circuluar property of the problem.
        file.get(first);
        
        char prev = first;
        char c;
        while (file.get(c)) {
            if (c == prev) {
                sum += c - '0';
            }

            prev = c;
        }

        // Match the last digit with the first.
        if (c == first) {
            sum += c - '0';
        }
    }

    std::cout << sum << std::endl;
    
    return 0;
}