//
//  GameBoard.hpp
//  TTTGame
//
//  Created by 子成 万 on 16/9/11.
//  Copyright © 2016年 Zicheng Wan. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class GameBoard{
private:
    vector<string> grid;
    string name1 = "";
    string name2 = "";
public:
    GameBoard();
    void setName1(string name);
    void setName2(string name);
    string getName1();
    string getName2();
    string display(vector<string> const &grid, string name);
    void resetGrid();
    vector<string> getGrid();
    void setGrid(int index, string value);
    
};

#endif /* GameBoard_hpp */
