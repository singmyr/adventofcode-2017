#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>

int main() {
    std::ifstream file("2017/6/input.txt");

    int cycles = 0;
    if (file.is_open()) {
        std::string line;
        
        getline(file, line);
        std::vector<int> banks;
        std::istringstream line_stream(line);
        for (std::string bank; std::getline(line_stream, bank, '\t');) {
            banks.push_back(std::stoi(bank, nullptr, 0));
        }

        int max = 0;
        int maxPos = 0;

        std::string currentString;

        std::list<std::string> bankHistory;
        do {
            // Reset the max value.
            max = 0;
            maxPos = 0;
            // Find the biggest bank.
            for (unsigned int i = 0; i < banks.size(); ++i) {
                if (banks[i] > max) {
                    max = banks[i];
                    maxPos = i;
                }
            }

            // Set the highest bank to 0.
            banks[maxPos] = 0;

            for (unsigned int i = maxPos; max > 0; ) {
                ++i;
                if (i >= banks.size()) {
                    i = 0;
                }

                ++banks[i];
                --max;
            }

            // Add the bank state to the history.
            std::ostringstream sstream;
            for (unsigned int i = 0; i < banks.size(); ++i) {
                sstream << banks[i] << '-';
            }
            currentString = sstream.str();
            bankHistory.push_back(currentString);
            ++cycles;
        } while (std::find(bankHistory.begin(), bankHistory.end(), currentString) == std::prev(bankHistory.end()));
    }

    std::cout << cycles << std::endl;
    
    return 0;
}