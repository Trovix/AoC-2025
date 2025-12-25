// Tr0vix AoC 2025 day 6 Part 2  — rewritten for the 100000th time

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main (){

    std::string line_0;
    std::string line_1;
    std::string line_2;
    std::string line_3;
    std::string instructions;

    std::vector<std::vector<int>> problem_set;
    long long answer = 0;

    std::ifstream file("input.txt");
    std::string line;
    int i = 0;
    while (std::getline(file, line)) {
        switch(i){
            case 0:{
                line_0 = line;
                break;
            }

            case 1:{
                line_1 = line;
                break;
            }

            case 2:{
                line_2 = line;
                break;
            }

            case 3:{
                line_3 = line;
                break;
            }

            case 4:{
                instructions = line;
                break;
            }
        }
        i++;
    }

    //now all the lines are stored in strings (all 3790 chars long), we now go through, forming our problem set. These problem sets are gonna be in the form {op, num0, num1, num2, num3}.  op = 0 ==> +, op = ==> * 
    std::cout << "Line Lengths: " << line_0.length() << ' ' << line_1.length() << ' ' << line_2.length() << ' ' << line_3.length() << ' ' << instructions.length() <<'\n';
    
    int num0 = 0;
    int num1 = 0; 
    int num2= 0;
    int num3 = 0;
    int op;
    bool num1_flag = false;
    bool num2_flag = false;
    bool num3_flag = false;
    std::vector<int> problem;
     
    
    for(size_t i = 0; i < line_0.length(); i++){
  
    std::vector<int> problem;
        //if all ' ' push problem to problem set, set all flags to false then continue
        if(line_0[i] == ' ' && line_1[i] == ' ' && line_2[i] == ' ' && line_3[i] == ' ' && instructions[i] == ' '){
        
        problem = {op, num0, num1, num2, num3};
        problem_set.push_back(problem);
        
        std::cout << num0 << ' ' << num1 << ' ' << num2 << ' ' << num3 << '\n';

        num1_flag = false;
        num2_flag = false;
        num3_flag = false;
        num0 = 0;
        num1 = 0;
        num2 = 0;
        num3 = 0;
        op = 0;
        continue;
        }
    //check if theres an operator, if so set operator to operator then get num0 push to num 0 and continue
        if(instructions[i] == '+' || instructions[i] == '*'){
            if(instructions[i] == '+'){
                op = 0;
            }
            if(instructions[i] == '*'){
                op = 1;
            }
            
            std::string s;
            
            if(line_0[i] != ' '){
                s+= line_0[i];
            }

            if(line_1[i] != ' '){
                s+= line_1[i];
            }

            if(line_2[i] != ' '){
                s+= line_2[i];
            }

            if(line_3[i] != ' '){
                s+= line_3[i];
            }

            num0 = std::stoi(s);
            continue;
        }
         //if num1 flag is false, get string and push to num 1
        if(num1_flag == false){
            std::string s;
            
            if(line_0[i] != ' '){
                s+= line_0[i];
            }

            if(line_1[i] != ' '){
                s+= line_1[i];
            }

            if(line_2[i] != ' '){
                s+= line_2[i];
            }

            if(line_3[i] != ' '){
                s+= line_3[i];
            }

            num1 = std::stoi(s);
            num1_flag = true;
            continue;
        }
        //if num2 flag is false, get string and push to num 2
        if(num2_flag == false){
            std::string s;
            
            if(line_0[i] != ' '){
                s+= line_0[i];
            }

            if(line_1[i] != ' '){
                s+= line_1[i];
            }

            if(line_2[i] != ' '){
                s+= line_2[i];
            }

            if(line_3[i] != ' '){
                s+= line_3[i];
            }

            num2 = std::stoi(s);
            num2_flag = true;
            continue;

        }
        
        //write to num3, push to num3
        if(num3_flag == false){
            std::string s;
            if(line_0[i] != ' '){
                    s+= line_0[i];
                }

                if(line_1[i] != ' '){
                    s+= line_1[i];
                }

                if(line_2[i] != ' '){
                    s+= line_2[i];
                }

                if(line_3[i] != ' '){
                    s+= line_3[i];
                }

                num3 = std::stoi(s);
                num3_flag = true;
                continue;

            }

    }

    problem = {op, num0, num1, num2, num3}; //push last problem 
    problem_set.push_back(problem);

    std::cout << num0 << ' ' << num1 << ' ' << num2 << ' ' << num3 << '\n';


    //we now have a vector of vectors called problem set which has all our problems. 

    for(size_t i= 0; i < problem_set.size(); i++){
        long long solution;
        problem = problem_set[i];
        if(problem[0] == 0){ //case addition 
            solution = 0LL + problem[1] + problem [2] + problem[3] + problem[4];
            answer = answer + solution;
        }
        if(problem[0] == 1){ //case multiplication 
            
           

            if(problem[1] == 0){
                problem[1] = 1;
            }
            if(problem[2] == 0){
                problem[2] = 1;
            }
            if(problem[3] == 0){
                problem[3] = 1;
            }
            if(problem[4] == 0){
                problem[4] = 1;
            }

            solution = 1LL * problem[1] * problem [2] * problem[3] * problem[4];
            answer = answer + solution;
        }
        std::cout << solution << '\n';
    }

    std::cout << answer;

    

}
