//
//  Player.hpp
//  TTTGame
//
//  Created by 子成 万 on 16/9/9.
//  Copyright © 2016年 Zicheng Wan. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp


#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Player{
private:
    string name;
    string marker;
    int playerNum;
public:
    Player();
    Player(string _name, string _marker, int playerNum);
    string getName();
    string getMarker();
    int getPlayerNum();
    void wins();
};

#endif /* Player_hpp */
