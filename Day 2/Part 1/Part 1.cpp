//Tr0vix AoC 2025 day 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

 long long invalid_total = 0;

int main (){
    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line)) {              //get data
        std::stringstream commaStream(line);
        std::string commaPart;

        while (std::getline(commaStream, commaPart, ',')) { //split by commas

            std::stringstream dashStream(commaPart);
            std::string leftStr;
            std::string rightStr;

            std::getline(dashStream, leftStr, '-'); //split by dash
            std::getline(dashStream, rightStr, '-');

            long long left  = std::stoll(leftStr); //convert both numbers to ints
            long long right = std::stoll(rightStr);
            
            while (left <= right){ //run through all ids
                std::string id = std::to_string(left); 
                if(id.size() % 2 == 0){
                    if((id.substr(0, id.size()/2)) == id.substr(id.size()/2)){ //split string "id" in half, check if halfs are equal
                        invalid_total = invalid_total + left; //if equal add the int to the total
                    }    
                }
                left++; //increment until all Ids have been checked 
            }
        }

    std::cout << invalid_total;
    
    }
return(0);
}