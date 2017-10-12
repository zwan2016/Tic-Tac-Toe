//
//  TTTController.hpp
//  TTTGame
//
//  Created by Â≠êÊàê ‰∏?on 16/9/11.
//  Copyright ¬© 2016Âπ?Zicheng Wan. All rights reserved.
//

#ifndef TTTController_hpp
#define TTTController_hpp

#include <stdio.h>
#include <string>
#include "../view/GameBoard.h"
#include "../model/Player.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
using namespace std;

class TTTController{
private:
    GameBoard *g = new GameBoard();
    GameBoard *g0 = new GameBoard();
    GameBoard *g1 = new GameBoard();
    GameBoard *g2 = new GameBoard();
    GameBoard *g3 = new GameBoard();
    GameBoard *g4 = new GameBoard();
    GameBoard *g5 = new GameBoard();
    GameBoard *g6 = new GameBoard();
    GameBoard *g7 = new GameBoard();
    GameBoard *g8 = new GameBoard();
    GameBoard *gg = new GameBoard();
    Player *p1 = new Player();
    Player *p2 = new Player();
    int turn = 1;
public:
    void createPlayer(string _name, string _marker, int _playerNum);
    void createPlayer(string playerJsonObject);
    void startNewGame();
    bool setSelection(int row, int col, int currentPlayer);
    bool setSelection1 (string gameJsonObject);
    bool setSelection (string gameJsonObject);
    int determineWinner1(GameBoard *g);
    int determineWinner();
    string getGameDisplay();
    string getGameDisplay1();
    string getAllSavedPlayers();
    void setGrid();
    string getGameDisplay(bool isJson);
};

#endif /* TTTController_hpp */
