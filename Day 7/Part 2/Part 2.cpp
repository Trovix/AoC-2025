//Tr0vix AoC 2025 day 7 Part 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main (){
    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::string> page;

    long long timelines = 0;

    int source;
    int splitcount = 0;

    while(std::getline(file, line)) {              //go thru input line by line, save all lines as strings to a vector called page.
        page.push_back(line);
    }

    std::cout << "Page is " << page.size() << " lines long." << '\n';

    std::vector<std::vector<long long>> grid(page.size(), std::vector<long long>(page[0].length())); 

    for(size_t i = 0; i < page[0].length(); i++){ //go thru line 0, find tachyon source
        if(page[0][i] == 'S'){
            source = i;
            grid[0][source] = 1;
        }
    }

    
    std::cout << "Source located at index: " << source << '\n'; 

    //write source output to line 1.

    page[1][source] = '|';
    grid[1][source] = 1;

    //now we cycle through remaining line 2 to page.size(), go thru line by line looking for ^, if ^ is found && page[i-1][j] = '|' then rewrite cell j-1 and j+1 to '|' increment splitcount; 

    for (size_t i = 2; i < page.size(); i++) {

    // clear timeline counts for this row
        for (size_t j = 0; j < grid[i].size(); j++) {
            grid[i][j] = 0;
        }

        for (size_t j = 0; j < page[i].length(); j++) {

            if (page[i-1][j] == '|') {

                // straight down
                if (page[i][j] == '.') {
                    page[i][j] = '|';
                }
                if (page[i][j] == '|') {
                    grid[i][j] += grid[i-1][j];
                }

            // split
                else if (page[i][j] == '^') {
                    splitcount++;

                // left
                    if (page[i][j-1] == '.') {
                        page[i][j-1] = '|';
                    }
                    grid[i][j-1] += grid[i-1][j];

                    // right
                    if (page[i][j+1] == '.') {
                        page[i][j+1] = '|';
                    }
                    grid[i][j+1] += grid[i-1][j];
                }
            }
        }
    }

    for(size_t i = 0; i < page.size(); i++){
        for(size_t j = 0; j < page[i].length(); j++){
            std::cout << page[i][j];
        }
        std::cout << '\n';
    }

    std::cout << '\n' << '\n';

    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[i].size(); j++){
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }


    std::cout << "Splitcount = " << splitcount <<'\n';

    for(size_t i = 0; i < grid[grid.size() -1].size(); i++){
        timelines = timelines + grid[grid.size() -1][i];
    }
    
    std::cout << "Timeline count = " << timelines;

}


