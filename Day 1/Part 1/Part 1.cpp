//Tr0vix AoC 2025 day 1

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

    if (letter == 'R'){
        position = position + number;               
    } 
    
    if(letter == 'L'){
        position = position - number;       
    }
    
    position = position % 100;                      //wrap so remains between 0-99

    
    if(position == 0){
        password++;                                 //count number of zeros 
    }

    }
    
    std::cout << password;                          //print output 
    return(0);

}