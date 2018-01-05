#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream file("2017/2/input.txt");

    long long sum = 0;
    if (file.is_open()) {
        std::string line;
        
        while (getline(file, line)) {
            int max = 0;
            int min = 0;
            std::vector<std::string> numbers;
            std::istringstream line_stream(line);
            for (std::string token; std::getline(line_stream, token, '\t');) {
                int val = std::stoi(token, nullptr, 0);
                if (val < min || min == 0) {
                    min = val;
                }

                if (val > max || max == 0) {
                    max = val;
                }
            }

            sum += max - min;
        }
    }

    std::cout << sum << std::endl;
    
    return 0;
}