#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream file("2017/5/input.txt");

    long long steps = 0;

    if (file.is_open()) {
        std::vector<int> numbers;
        std::string line;
        
        while (getline(file, line)) {
            int val = std::stoi(line, nullptr, 0);
            numbers.push_back(val);
        }

        int pos = 0;

        do {
            ++numbers[pos];
            pos += numbers[pos] - 1;
            ++steps;
        } while (pos >= 0 && pos < numbers.size());
    }

    std::cout << steps << std::endl;
    
    return 0;
}