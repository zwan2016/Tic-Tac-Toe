//
//  Player.cpp
//  TTTGame
//
//  Created by 子成 万 on 16/9/9.
//  Copyright © 2016年 Zicheng Wan. All rights reserved.
//

#include "Player.h"

Player::Player(){
    name = "";
    marker = "";
    playerNum = NULL;
}

Player::Player(string _name, string _marker, int _playerNum){
    name = _name;
    marker = _marker;
    playerNum = _playerNum;
}

string Player::getName(){
    return name;
}

string Player::getMarker(){
    return marker;
}

int Player::getPlayerNum(){
    return playerNum;
}

void Player::wins(){
    cout << name << " wins!" << endl;
}
