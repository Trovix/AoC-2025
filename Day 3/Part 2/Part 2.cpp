// Tr0vix AoC 2025 day 3 part 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

long long total_joltage = 0;


std::vector<int> find_value(int start_pos, int finish_pos, std::string bank){
    int scan = 9;                                                              
    bool done = false;
    int high = 0;
    int high_pos = 0;
    while(done == false){     
        for(int pos = start_pos; pos <= finish_pos; pos++){
            char c = bank[pos];
            int i = c - '0';
            if (i == scan){
                high = i;
                high_pos = pos; 
                done = true;
                break;
            }
        }
        scan--;
    }
    return {high, high_pos};
} 

int main () {
    std::ifstream file("input.txt");
    std::string bank;

    while (std::getline(file, bank)) {                                              //loop thru all battery banks
    int joltage_position = -1;
    int joltage = 0;
    long long bank_joltage = 0;
        for(int i = 0; i < 12; i++){
            std::vector<int> v = find_value(joltage_position + 1, bank.length() - 12 + i, bank);
            joltage = v[0];
            joltage_position = v[1];
            bank_joltage = bank_joltage * 10 + joltage;
        }
        
        total_joltage = total_joltage + bank_joltage;
    }

    std::cout << total_joltage;
     
    return 0;
}

