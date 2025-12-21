// Tr0vix AoC 2025 day 2 part 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

long long invalid_total = 0;

int main() {
    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream commaStream(line);
        std::string commaPart;

        while (std::getline(commaStream, commaPart, ',')) {

            std::stringstream dashStream(commaPart);
            std::string leftStr, rightStr;

            std::getline(dashStream, leftStr, '-');
            std::getline(dashStream, rightStr, '-');

            long long left  = std::stoll(leftStr);
            long long right = std::stoll(rightStr);

            while (left <= right) {
                std::string id = std::to_string(left);
                std::size_t len = id.size();

                for (int n = len; n >= 2; n--) {
                    if (len % n != 0) continue;

                    std::size_t chunk = len / n;
                    bool valid = true;

                    for (int i = 1; i < n; i++) {
                        if (id.substr(0, chunk) !=
                            id.substr(i * chunk, chunk)) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        invalid_total += left;
                        break; 
                    }
                }

                left++;
            }
        }
    }

    std::cout << invalid_total;
    return 0;
}
