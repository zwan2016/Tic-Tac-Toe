//
//  GameBoard.cpp
//  TTTGame
//
//  Created by 子成 万 on 16/9/11.
//  Copyright © 2016年 Zicheng Wan. All rights reserved.
//

#include "GameBoard.h"
#include <sstream>

GameBoard::GameBoard(){
    for(int i = 0; i < 9; i++){
        grid.push_back("-");
    }
}

string GameBoard::display(const vector<string> &grid, string name){
    stringstream output;
    output << endl;
    output << "  " << "0" << " " << "1" << " " << "2" << endl;
    for(int i = 0; i < 9; i++){
        if(i == 0 || i == 3 || i == 6){
            output << i/3 << " " << grid[i] << " ";
        }
        else if(i == 2){
            if(name == name1){
                output << grid[i] << "   *" << name1 << " ---- X" << endl;
            }
            else{
                output << grid[i] << "    " << name1 << " ---- X" << endl;
            }
        }
        else if(i == 5){
            if(name == name2){
                output << grid[i] << "   *" << name2 << " ---- O" << endl;
            }
            else{
                output << grid[i] << "    " << name2 << " ---- O" << endl;
            }
        }
        else if(i == 8){
            output << grid[i] << endl;
        }
        else{
            output << grid[i] << " ";
        }
    }
    return output.str();
}

void GameBoard::setName1(string name){
    name1 = name;
}

void GameBoard::setName2(string name){
    name2 = name;
}

string GameBoard::getName1(){
    return name1;
}

string GameBoard::getName2(){
    return name2;
}

void GameBoard::resetGrid(){
    for(int i = 0; i < 9; i++){
        grid.push_back("-");
    }
}

vector<string> GameBoard::getGrid(){
    return grid;
}

void GameBoard::setGrid(int index, string value){
    grid[index] = value;
}


