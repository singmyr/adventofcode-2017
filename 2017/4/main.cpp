#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>

int main() {
    std::ifstream file("2017/4/input.txt");

    int validPassphrases = 0;
    if (file.is_open()) {
        std::string line;
        
        while (getline(file, line)) {
            std::list<std::string> words;
            std::istringstream line_stream(line);
            for (std::string word; std::getline(line_stream, word, ' ');){
                words.push_back(word);
            }

            int parsed = words.size();
            words.sort();
            words.unique();
            int unique = words.size();

            if (parsed == unique) {
                ++validPassphrases;
            }
        }
    }

    std::cout << validPassphrases << std::endl;
    
    return 0;
}