//Tr0vix AoC 2025 day 6

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main (){
    std::ifstream file("input.txt");
    std::string line;
    
    int i = 0;
    std::vector<int> line_0;
    std::vector<int> line_1;
    std::vector<int> line_2;
    std::vector<int> line_3;
    std::vector<char> instructions;

    long long final_answer = 0; 

    while (std::getline(file, line)) {              //go thru input line by line 
        switch(i){
            case 0:{
                int number = 0;
                bool num_flag = false;
                for(size_t j = 0; j < line.length(); j++){
                    if(line[j] == ' '){
                        if(num_flag == true){
                            line_0.push_back(number);
                        }
                        number = 0;
                        num_flag = false;
                        continue; 
                    }
                    number = number*10 + line[j] - '0'; 
                    num_flag = true;
                }
                
                if(num_flag == true){
                    line_0.push_back(number); //push last element
                }
                break;
            }
          case 1: {
                int number = 0;
                bool num_flag = false;
                for(size_t j = 0; j < line.length(); j++){
                    if(line[j] == ' '){
                        if(num_flag == true){
                            line_1.push_back(number);
                        }
                        number = 0;
                        num_flag = false;
                        continue; 
                    }
                    number = number*10 + line[j] - '0'; 
                    num_flag = true;
                }
                if(num_flag == true){
                    line_1.push_back(number);
                }
                break; 
            }
          case 2:{
                int number = 0;
                bool num_flag = false;
                for(size_t j = 0; j < line.length(); j++){
                    if(line[j] == ' '){
                        if(num_flag == true){
                            line_2.push_back(number);
                        }
                        number = 0;
                        num_flag = false;
                        continue; 
                    }
                    number = number*10 + line[j] - '0'; 
                    num_flag = true;
                }
                if(num_flag == true){
                    line_2.push_back(number); 
                }
                break; 
            }

        case 3:{
                int number = 0;
                bool num_flag = false;
                for(size_t j = 0; j < line.length(); j++){
                    if(line[j] == ' '){
                        if(num_flag == true){
                            line_3.push_back(number);
                        }
                        number = 0;
                        num_flag = false;
                        continue; 
                    }
                    number = number*10 + line[j] - '0'; 
                    num_flag = true;
                }
                if (num_flag == true){
                    line_3.push_back(number); 
                }
                break; 
            }
        case 4:{
                for(size_t j = 0; j < line.length(); j++){
                    if(line[j] == ' '){
                        continue; 
                    }
                    if(line[j] == '*'){
                        instructions.push_back(line[j]);
                    }
                    if(line[j] == '+'){
                        instructions.push_back(line[j]);
                    }  
                }
                break; 
            }
        }
        i++;
    }
    
    //we know all the line vectors are the same size now so we'll just go ahead and use line_0.size() for everything
    

    for(size_t i = 0; i < line_0.size(); i++){
        long long solution = 0;
        if(instructions[i] == '+'){
            solution = 0LL + line_0[i] + line_1[i] + line_2[i] + line_3[i];
        }
        if(instructions[i] == '*'){
            solution = 1LL * line_0[i] * line_1[i] * line_2[i] * line_3[i];
        }
        final_answer = final_answer + solution;
    }

    std::cout << final_answer;



   
}