//Tr0vix AoC 2025 day 7 Part 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main (){
    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::string> page;
    int source;
    int splitcount = 0;

    while(std::getline(file, line)) {              //go thru input line by line, save all lines as strings to a vector called page.
        page.push_back(line);
    }

    std::cout << "Page is " << page.size() << " lines long." << '\n';

    for(size_t i = 0; i < page[0].length(); i++){ //go thru line 0, find tachyon source
        if(page[0][i] == 'S'){
            source = i;
        }
    }

    
    std::cout << "Source located at index: " << source << '\n'; 

    //write source output to line 1.

    page[1][source] = '|';

    //now we cycle through remaining line 2 to page.size(), go thru line by line looking for ^, if ^ is found && page[i-1][j] = '|' then rewrite cell j-1 and j+1 to '|' increment splitcount; 

    for(size_t i = 2; i < page.size(); i++){
        for(size_t j = 0; j < page[i].length(); j++){
            if(page[i][j] == '.' && page[i-1][j] == '|'){
                page[i][j] = '|';
            }
            
            if(page[i][j] == '^' && page[i-1][j] == '|'){
                splitcount++;
                if(page[i][j-1] == '.'){
                    page[i][j-1] = '|';
                }
                if(page[i][j+1] == '.'){
                    page[i][j+1] = '|';
                }
            
            }
        }
    }
    std::cout << "Splitcount = " << splitcount;

}


