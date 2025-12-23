//Tr0vix AoC 2025 day 4

//lowkey this code is inefficient asf 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool check_for_roll(int x, int y, std::vector<std::vector<char>>& grid){


    if((x < 0 || x >= grid.size()) || (y < 0 || y >= grid.size())){                 //bounds check
        return false;
    }

    std::vector<char> line = grid[y];
    char cell = line[x];

    if(cell == '@'){
        return true;
    }
    else{
        return false;
    }

}

int rolls = 0;
int main (){
    
    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> last_grid;
    std::vector<std::vector<int>> marked_positions; 
    
   
    //----------------------------------------------------------
    while (std::getline(file, line)) {                                              //go thru input line by line 
        
        std::vector<char> line_vct_placeholder;
        
        for(int i = 0; i<line.length(); i++){                                       //makes it into one big vector 
            line_vct_placeholder.push_back(line[i]);
        }
        
        grid.push_back(line_vct_placeholder);
        
    
    }
    //------------------------------------------------------------- 

   
      
       
        for(int j = 0; j < grid.size(); j++){                                           
            std::vector<char>& row = grid[j];
        
            for(int i = 0; i < row.size(); i++){

                if(row[i] == '@'){
                
                
                    int sum = check_for_roll(i - 1, j - 1, grid) +          //top left 
                            check_for_roll(i, j - 1, grid) +              //top mid 
                            check_for_roll(i + 1, j - 1, grid) +          //top right 
                            check_for_roll(i - 1, j, grid) +              //mid left 
                            check_for_roll(i + 1, j, grid) +              //mid right 
                            check_for_roll(i - 1, j + 1, grid) +          //bottom left 
                            check_for_roll(i, j + 1, grid) +              //bottom mid
                            check_for_roll(i + 1, j + 1, grid);           //bottom right 

                    if(sum<4){
                        rolls = rolls + 1;
                        
                    }
            
                }
            }
        }

    //then we update grid
    
 

   

std::cout << rolls;


}
