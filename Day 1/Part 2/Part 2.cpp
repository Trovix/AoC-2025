//Tr0vix AoC 2025 day 1 part 2

#include <iostream>
#include <fstream>
#include <string>

int position = 50;                                  //original position 
int password = 0; 

int main (){
    
    std::ifstream file("input.txt");
    std::string line;
    
    while (std::getline(file, line)) {              //go thru input line by line 
        char letter = line[0];                          //select first character (represents direction) 
        int number = std::stoi(line.substr(1));         //remaining characters are the number of rotations 
        
        while (letter == 'R' && number > 0){
        position++;
        number--;
        if (position == 100){
            position = 0;
            password++;
        }
        } 
        

        while(letter == 'L' && number > 0){
        position--;
        number--;
        if (position == 0){
            password++;
        }
        if (position == -1){
            position = 99;
        }
        }
    
    }

    
    
    std::cout << password;                          //print output 
    return(0);

}