//Tr0vix AoC 2025 day 5 part 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>





int main (){
    long long total_valid_ids = 0;

    std::vector<std::vector<long long>> all_ranges;


    std::ifstream range_file("fresh_ranges.txt");
    std::string range;
    
    while (std::getline(range_file, range)) {              //go thru ranges line by line 
        
        
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

        std::vector<long long> range = {range_start, range_end};
        
        all_ranges.push_back(range); //add the range to the vector that stores all the ranges

    }

    std::sort(all_ranges.begin(), all_ranges.end()); //sort the vector by starting points
    
    std::vector<std::vector<long long>> merged; //define a new vector that will hold the merged ranges 

    long long current_start = all_ranges[0][0];
    long long current_end   = all_ranges[0][1]; //starting point 

    for (size_t i = 1; i < all_ranges.size(); i++) {

        long long next_start = all_ranges[i][0];
        long long next_end   = all_ranges[i][1];

        if (next_start <= current_end) {
            // Overlap so merge
            current_end = std::max(current_end, next_end);
        } else {
            // gap so push new element 
            merged.push_back({current_start, current_end});
            current_start = next_start;
            current_end   = next_end;
        }
    }

    //last element 
    merged.push_back({current_start, current_end});


    for(size_t i = 0; i < merged.size(); i++){//count 
        std::vector<long long> r = merged[i];
        long long s = r[0];
        long long e = r[1];
        total_valid_ids = total_valid_ids + (e-s + 1); //inclusive (ts bug took me ages to find)
    }
    
    std::cout << total_valid_ids;    

}








