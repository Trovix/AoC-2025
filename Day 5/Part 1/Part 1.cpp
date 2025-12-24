//Tr0vix AoC 2025 day 5 part 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main (){
    
    
    int total_valid_ids = 0;
    std::vector<long long> valid_ids;
    

    std::ifstream ID_file("Ids_to_check.txt");
    std::string id_string;
    while (std::getline(ID_file, id_string)) {
    
        long long id = 0;
        bool found = false;
        for(int i = 0; i < id_string.size(); i++){
            int digit = id_string[i] - '0';
            id = id*10 + digit;
        }

        std::ifstream range_file("fresh_ranges.txt");
        std::string range;

        while (std::getline(range_file, range) && found == false) {              //go thru ranges line by line 
            long long range_start = 0;
            long long range_end = 0;
            bool first = true;
            
            for(int i = 0; i < range.size(); i++){ //turn range start and end into two numbers 
            
                if(range[i] == '-'){
                    first = false;
                    continue;
                }
                int digit = range[i] - '0'; 

                if(first == true){
                    range_start = range_start*10 + digit; 
                }

                if(first == false){
                    range_end = range_end*10 + digit;
                }
            }


            if(id >= range_start && id <= range_end){
                found = true;
            }

        }
    if(found == true){
        total_valid_ids++;
    }
    }   
std::cout << total_valid_ids; 
}