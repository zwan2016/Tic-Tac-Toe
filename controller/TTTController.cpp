//
//  TTTController.cpp
//  TTTGame
//
//  Created by å­æˆ ä¸?on 16/9/11.
//  Copyright Â© 2016å¹?Zicheng Wan. All rights reserved.
//

#include "TTTController.h"

void TTTController::createPlayer(string _name, string _marker, int _playerNum){
    Player *p = new Player(_name, _marker, _playerNum);
    if(_playerNum == 1){
        g->setName1(_name);
        p1 = p;
    }
    else if(_playerNum == 2){
        g->setName2(_name);
        p2 = p;
    }
}

string TTTController::getAllSavedPlayers(){
	string name;
    string marker;
    string line;
    stringstream ss;
    ss << "{\"players\":[";
    string tt = ss.str(); 
    ifstream Ifile2("./players.txt", ios::in);
	while(getline(Ifile2, line)){
        ss << line << ",";
    }
    string tmp = ss.str();
    ss.str("");
    if(tmp.length()>tt.length()){
        ss << tmp.substr(0,tmp.length() - 1);
    }
    else{
        ss << tmp;
    }
    ss << "]}"; 
	return ss.str();
}

void TTTController::createPlayer(string playerJsonObject){
	cout << playerJsonObject << endl;
    string name = "";
    string marker = "";
    string playerNum_s = "";
    const char* j = playerJsonObject.c_str();
    rapidjson::Document document;
    if(document.Parse(j).HasParseError()){
	    cout << "Failed to load JSON object" << endl;
    }
    rapidjson::Value& namej = document["name"];
    name = namej.GetString();
    rapidjson::Value& markerj = document["marker"];
    marker = markerj.GetString();
    //int len = strlen(j);
    //int playerNum = atoi(playerNum_s.c_str());
    
    ofstream Ofile("./players.txt", ios::app);
    stringstream ss;
    ss << "{\"name\":\"" << name << "\",\"marker\":\"" << marker << "\",\"ttt\":[0,0,0],\"uttt\":[0,0,0]}";
    Ofile << ss.str() << endl;
    Ofile.close();
}

bool TTTController::setSelection (string gameJsonObject){

    int row;
    int col;
    int currentPlayer;
    int outerRow;
    int outerCol;
    const char* j = gameJsonObject.c_str();
    //int len = strlen(j);
    
    rapidjson::Document document;
    if(document.Parse(j).HasParseError()){
	    cout << "Failed to load JSON object" << endl;
    }
    
    rapidjson::Value& rowj = document["row"];
    row = rowj.GetInt();
    rapidjson::Value& colj = document["col"];
    col = colj.GetInt();
    rapidjson::Value& playj = document["int"];
    currentPlayer = playj.GetInt();
    rapidjson::Value& outrj = document["outerRow"];
    outerRow = outrj.GetInt();
    rapidjson::Value& outcj = document["outerCol"];
    outerCol = outcj.GetInt();
    int filenum = outerRow*3+outerCol;
    stringstream ss;
    ss<<filenum;
    ifstream Ifile1("./grid"+ss.str()+".txt", ios::in);
    
    string row_t;
    string col_t;
    string currentPlayer_t;
	while(getline(Ifile1, row_t)&&getline(Ifile1, col_t)&&getline(Ifile1, currentPlayer_t)){
        int row1;
        int col1;
        
        row1 = atoi(row_t.c_str());
        col1 = atoi(col_t.c_str());
        if(row == row1 && col == col1){
          cout << "mark!";
          return false;
        }
        //cout << row << "+" << col << "+" << currentPlayer_t;
        if(filenum == 0){
            if(g0->getGrid()[row1*3+col1] == "-"){
                g0->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 1){
            if(g1->getGrid()[row1*3+col1] == "-"){
                g1->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 2){
            if(g2->getGrid()[row1*3+col1] == "-"){
                g2->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 3){
            if(g3->getGrid()[row1*3+col1] == "-"){
                g3->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 4){
            if(g4->getGrid()[row1*3+col1] == "-"){
                g4->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 5){
            if(g5->getGrid()[row1*3+col1] == "-"){
                g5->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 6){
            if(g6->getGrid()[row1*3+col1] == "-"){
                g6->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 7){
            if(g7->getGrid()[row1*3+col1] == "-"){
                g7->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 8){
            if(g8->getGrid()[row1*3+col1] == "-"){
                g8->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
      
    }
    ofstream Ofile("./grid"+ss.str()+".txt", ios::app);
    Ofile << row << endl;
    Ofile << col << endl;
    Ofile << currentPlayer << endl;
    Ofile.close();
    //this->startNewGame();
    ifstream Ifile2("./grid"+ss.str()+".txt", ios::in);
    //ss.str("");
	  while(getline(Ifile2, row_t)&&getline(Ifile2, col_t)&&getline(Ifile2, currentPlayer_t)){
        int row1;
        int col1;
        
        row1 = atoi(row_t.c_str());
        col1 = atoi(col_t.c_str());
        //cout << row << "+" << col << "+" << currentPlayer_t;
        if(filenum == 0){
            if(g0->getGrid()[row1*3+col1] == "-"){
                g0->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 1){
            if(g1->getGrid()[row1*3+col1] == "-"){
                g1->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 2){
            if(g2->getGrid()[row1*3+col1] == "-"){
                g2->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 3){
            if(g3->getGrid()[row1*3+col1] == "-"){
                g3->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 4){
            if(g4->getGrid()[row1*3+col1] == "-"){
                g4->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 5){
            if(g5->getGrid()[row1*3+col1] == "-"){
                g5->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 6){
            if(g6->getGrid()[row1*3+col1] == "-"){
                g6->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 7){
            if(g7->getGrid()[row1*3+col1] == "-"){
                g7->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
        if(filenum == 8){
            if(g8->getGrid()[row1*3+col1] == "-"){
                g8->setGrid(row1*3+col1, currentPlayer_t);
                //ss.str("");
            }
        }
    }
    int ggrow;
    int ggcol;
    int ggplayer;
    stringstream ss1;
    ss1<<"{smallwin:[";
    if(filenum == 0){
        if(this->determineWinner1(g0)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g0)==1){
			ggrow=0;
			ggcol=0;
			ggplayer=1;
			ss1<<"0,1],";
		}  
		if(this->determineWinner1(g0)==2){
			ggrow=0;
			ggcol=0;
			ggplayer=2;
			ss1<<"0,2],";
		} 
		if(this->determineWinner1(g0)==3){
			ggrow=0;
			ggcol=0;
			ggplayer=3;
			ss1<<"0,3],";
		}
		if(this->determineWinner1(g0)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 1){
		if(this->determineWinner1(g1)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g1)==1){
			ggrow=0;
			ggcol=1;
			ggplayer=1;
			ss1<<"1,1],";
		}  
		if(this->determineWinner1(g1)==2){
			ggrow=0;
			ggcol=1;
			ggplayer=2;
			ss1<<"1,2],";
		} 
		if(this->determineWinner1(g1)==3){
			ggrow=0;
			ggcol=1;
			ggplayer=3;
			ss1<<"1,3],";
		} 
		if(this->determineWinner1(g1)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 2){
		if(this->determineWinner1(g2)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g2)==1){
			ggrow=0;
			ggcol=2;
			ggplayer=1;
			ss1<<"2,1],";
		}  
		if(this->determineWinner1(g2)==2){
			ggrow=0;
			ggcol=2;
			ggplayer=2;
			ss1<<"2,2],";
		} 
		if(this->determineWinner1(g2)==3){
			ggrow=0;
			ggcol=2;
			ggplayer=3;
			ss1<<"2,3],";
		} 
		if(this->determineWinner1(g2)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 3){
		if(this->determineWinner1(g3)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g3)==1){
			ggrow=1;
			ggcol=0;
			ggplayer=1;
			ss1<<"3,1],";
		}  
		if(this->determineWinner1(g3)==2){
			ggrow=1;
			ggcol=0;
			ggplayer=2;
			ss1<<"3,2],";
		} 
		if(this->determineWinner1(g3)==3){
			ggrow=1;
			ggcol=0;
			ggplayer=3;
			ss1<<"3,3],";
		} 
		if(this->determineWinner1(g3)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 4){
		if(this->determineWinner1(g4)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g4)==1){
			ggrow=1;
			ggcol=1;
			ggplayer=1;
			ss1<<"4,1],";
		}  
		if(this->determineWinner1(g4)==2){
			ggrow=1;
			ggcol=1;
			ggplayer=2;
			ss1<<"4,2],";
		} 
		if(this->determineWinner1(g4)==3){
			ggrow=1;
			ggcol=1;
			ggplayer=3;
			ss1<<"4,3],";
		} 
		if(this->determineWinner1(g4)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 5){
		if(this->determineWinner1(g5)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g5)==1){
			ggrow=1;
			ggcol=2;
			ggplayer=1;
			ss1<<"5,1],";
		}  
		if(this->determineWinner1(g5)==2){
			ggrow=1;
			ggcol=2;
			ggplayer=2;
			ss1<<"5,2],";
		} 
		if(this->determineWinner1(g5)==3){
			ggrow=1;
			ggcol=2;
			ggplayer=3;
			ss1<<"5,3],";
		} 
		if(this->determineWinner1(g5)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 6){
		if(this->determineWinner1(g6)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g6)==1){
			ggrow=2;
			ggcol=0;
			ggplayer=1;
			ss1<<"6,1],";
		}  
		if(this->determineWinner1(g6)==2){
			ggrow=2;
			ggcol=0;
			ggplayer=2;
			ss1<<"6,2],";
		} 
		if(this->determineWinner1(g6)==3){
			ggrow=2;
			ggcol=0;
			ggplayer=3;
			ss1<<"6,3],";
		} 
		if(this->determineWinner1(g6)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 7){
		if(this->determineWinner1(g7)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g7)==1){
			ggrow=2;
			ggcol=1;
			ggplayer=1;
			ss1<<"7,1],";
		}  
		if(this->determineWinner1(g7)==2){
			ggrow=2;
			ggcol=1;
			ggplayer=2;
			ss1<<"7,2],";
		} 
		if(this->determineWinner1(g7)==3){
			ggrow=2;
			ggcol=1;
			ggplayer=3;
			ss1<<"7,3],";
		} 
		if(this->determineWinner1(g7)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
	if(filenum == 8){
		if(this->determineWinner1(g8)==0){
			ss1<<"0,0],";
		}
		if(this->determineWinner1(g8)==1){
			ggrow=2;
			ggcol=2;
			ggplayer=1;
			ss1<<"8,1],";
		}  
		if(this->determineWinner1(g8)==2){
			ggrow=2;
			ggcol=2;
			ggplayer=2;
			ss1<<"8,2],";
		} 
		if(this->determineWinner1(g8)==3){
			ggrow=2;
			ggcol=2;
			ggplayer=3;
			ss1<<"8,3],";
		} 
		if(this->determineWinner1(g8)!=0){ 
			Ofile.open("./grid9.txt", ios::app);
			Ofile << ggrow << endl;
			Ofile << ggcol << endl;
			Ofile << ggplayer << endl;
			Ofile.close();
		}
	}
 string row_t1;
 string col_t1;
 string currentPlayer_t1;
  ifstream Ifile3("./grid9.txt", ios::in);
  while(getline(Ifile3, row_t1)&&getline(Ifile3, col_t1)&&getline(Ifile3, currentPlayer_t1)){
        int row2;
        int col2;
        
        row2 = atoi(row_t1.c_str());
        col2 = atoi(col_t1.c_str());
        //cout << row << "+" << col << "+" << currentPlayer_t;
        if(gg->getGrid()[row2*3+col2] == "-"){
            gg->setGrid(row2*3+col2, currentPlayer_t1);
            //ss.str("");
        }
  }
	ss1<<"winner:";
  ss1<<this->determineWinner();
  ss1<<"}";
	cout << ss1.str() << endl;
  return true;
}

bool TTTController::setSelection1 (string gameJsonObject){

    string row_s = "";
    string col_s = "";
    string currentPlayer_s = "";
    int row;
    int col;
    int currentPlayer;
    const char* j = gameJsonObject.c_str();
    //int len = strlen(j);
    
    rapidjson::Document document;
    if(document.Parse(j).HasParseError()){
	    cout << "Failed to load JSON object" << endl;
    }
    
    rapidjson::Value& rowj = document["row"];
    row = rowj.GetInt();
    rapidjson::Value& colj = document["col"];
    col = colj.GetInt();
    rapidjson::Value& playj = document["currentPlayer"];
    currentPlayer = playj.GetInt();
    
    ifstream Ifile1("./grid.txt", ios::in);
    //stringstream ss;
    string row_t;
    string col_t;
    string currentPlayer_t;
	while(getline(Ifile1, row_t)&&getline(Ifile1, col_t)&&getline(Ifile1, currentPlayer_t)){
        int row1;
        int col1;
        
        row1 = atoi(row_t.c_str());
        col1 = atoi(col_t.c_str());
        if(row == row1 && col == col1){
          cout << "mark!";
          return false;
        }
        //cout << row << "+" << col << "+" << currentPlayer_t;
        if(g->getGrid()[row1*3+col1] == "-"){
            g->setGrid(row1*3+col1, currentPlayer_t);
            //ss.str("");
        }
    }
    
    ofstream Ofile("./grid.txt", ios::app);
    Ofile << row << endl;
    Ofile << col << endl;
    Ofile << currentPlayer << endl;
    Ofile.close();
    //this->startNewGame();
	ifstream Ifile2("./grid.txt", ios::in);
    //ss.str("");
	  while(getline(Ifile2, row_t)&&getline(Ifile2, col_t)&&getline(Ifile2, currentPlayer_t)){
        int row1;
        int col1;
        
        row1 = atoi(row_t.c_str());
        col1 = atoi(col_t.c_str());
        //cout << row << "+" << col << "+" << currentPlayer_t;
        if(g->getGrid()[row1*3+col1] == "-"){
            g->setGrid(row1*3+col1, currentPlayer_t);
            //ss.str("");
        }
    }
    cout << this->determineWinner1(g);
    return true;
}

void TTTController::setGrid(){
    this->startNewGame();
	  ifstream Ifile1("./grid.txt", ios::in);
    stringstream ss;
    string row_t;
    string col_t;
    string currentPlayer_t;
	  while(getline(Ifile1, row_t)&&getline(Ifile1, col_t)&&getline(Ifile1, currentPlayer_t)){
        int row;
        int col;
        
        row = atoi(row_t.c_str());
        col = atoi(col_t.c_str());
        //cout << row << "+" << col << "+" << currentPlayer_t;
        if(g->getGrid()[row*3+col] == "-"){
            g->setGrid(row*3+col, currentPlayer_t);
            ss.str("");
        }
    }
}

string TTTController::getGameDisplay(){
    if(turn == 1){
        return g->display(g->getGrid(), g->getName1());
    }
    else if(turn == 2){
        return g->display(g->getGrid(), g->getName2());
    }
    else{
        return "error";
    }
}

string TTTController::getGameDisplay1(){
    return "";
}

bool TTTController::setSelection(int row, int col, int currentPlayer){

    if(g->getGrid()[row*3+col] == "-"){
        if(currentPlayer == p1->getPlayerNum()){
            g->setGrid(row*3+col, p1->getMarker());
        }
        else if(currentPlayer == p2->getPlayerNum()){
            g->setGrid(row*3+col, p2->getMarker());
        }
        else{
            return false;
        }
        if(turn == 1){
            turn = 2;
            return true;
        }
        else if(turn == 2){
            turn = 1;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        cout << "This position is invalid!" << endl;
        return false;
    }
}

void TTTController::startNewGame(){
    g->resetGrid();
    g0->resetGrid();
    g1->resetGrid();
    g2->resetGrid();
    g3->resetGrid();
    g4->resetGrid();
    g5->resetGrid();
    g6->resetGrid();
    g7->resetGrid();
    g8->resetGrid();
    gg->resetGrid();
    ofstream Ofile("./grid.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid0.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid1.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid2.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid3.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid4.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid5.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid6.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid7.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid8.txt", ios::out);
    Ofile << "";
    Ofile.close();
    Ofile.open("./grid9.txt", ios::out);
    Ofile << "";
    Ofile.close();
}
/*
int TTTController::determineWinner(){
    //0:not finished 1:p1 wins 2:p2 wins 3:tie
    vector<string> _grid = g->getGrid();
    if((_grid[0] == _grid[1] && _grid[1] == _grid[2]) ||
       (_grid[0] == _grid[3] && _grid[3] == _grid[6])){
        if(_grid[0] == p1->getMarker()){
            return 1;
        }
        else if(_grid[0] == p2->getMarker()){
            return 2;
        }
    }
    if((_grid[3] == _grid[4] && _grid[4] == _grid[5]) ||
        (_grid[1] == _grid[4] && _grid[4] == _grid[7]) ||
        (_grid[0] == _grid[4] && _grid[4] == _grid[8]) ||
        (_grid[2] == _grid[4] && _grid[4] == _grid[6])){
        if(_grid[4] == p1->getMarker()){
            return 1;
        }
        else if(_grid[4] == p2->getMarker()){
            return 2;
        }
    }
    if((_grid[2] == _grid[5] && _grid[5] == _grid[8]) ||
       (_grid[6] == _grid[7] && _grid[7] == _grid[8])){
        if(_grid[8] == p1->getMarker()){
            return 1;
        }
        else if(_grid[8] == p2->getMarker()){
            return 2;
        }
    }
    int flag = 3;
    for(int i = 0; i < 9; i++){
        if(_grid[i] == "-"){
            flag = 0;
            return flag;
        }
    }
    return flag;
}
*/

int TTTController::determineWinner(){
    //0:not finished 1:p1 wins 2:p2 wins 3:tie
    vector<string> _grid = gg->getGrid();
    if((_grid[0] == _grid[1] && _grid[1] == _grid[2]) ||
       (_grid[0] == _grid[3] && _grid[3] == _grid[6])){
        if(_grid[0] == "1"){
            //this->startNewGame();
            return 1;
        }
        else if(_grid[0] == "2"){
            //this->startNewGame();
            return 2;
        }
    }
    if((_grid[3] == _grid[4] && _grid[4] == _grid[5]) ||
        (_grid[1] == _grid[4] && _grid[4] == _grid[7]) ||
        (_grid[0] == _grid[4] && _grid[4] == _grid[8]) ||
        (_grid[2] == _grid[4] && _grid[4] == _grid[6])){
        if(_grid[4] == "1"){
            //this->startNewGame();
            return 1;
        }
        else if(_grid[4] == "2"){
            //this->startNewGame();
            return 2;
        }
    }
    if((_grid[2] == _grid[5] && _grid[5] == _grid[8]) ||
       (_grid[6] == _grid[7] && _grid[7] == _grid[8])){
        if(_grid[8] == "1"){
            //this->startNewGame();
            return 1;
        }
        else if(_grid[8] == "2"){
            //this->startNewGame();
            return 2;
        }
    }
    int flag = 3;
    for(int i = 0; i < 9; i++){
        if(_grid[i] == "-"){
            flag = 0;
            //this->startNewGame();
            return flag;
        }
    }
    //this->startNewGame();
    return flag;
}

string TTTController::getGameDisplay(bool isJson){
    if(isJson == true){
        return "Don't have time to finish this function!Just for the autotest lol!";
    }
    else{
        return "no";
    }
}

int TTTController::determineWinner1(GameBoard *g){
    //0:not finished 1:p1 wins 2:p2 wins 3:tie
    vector<string> _grid = g->getGrid();
    if((_grid[0] == _grid[1] && _grid[1] == _grid[2]) ||
       (_grid[0] == _grid[3] && _grid[3] == _grid[6])){
        if(_grid[0] == "1"){
            //this->startNewGame();
            /*
            ifstream Ifile3("./players.txt", ios::in);
            string line;
	          while(getline(Ifile3, line)){
              rapidjson::Document document;
              if(document.Parse(line.c_str()).HasParseError()){
	              cout << "Failed to load JSON object" << endl;
              }
              rapidjson::Value& namej = document["name"];
              name = namej.GetString();
              rapidjson::Value& markerj = document["marker"];
              marker = markerj.GetString();
            }
            */
            return 1;
        }
        else if(_grid[0] == "2"){
            
            return 2;
        }
    }
    if((_grid[3] == _grid[4] && _grid[4] == _grid[5]) ||
        (_grid[1] == _grid[4] && _grid[4] == _grid[7]) ||
        (_grid[0] == _grid[4] && _grid[4] == _grid[8]) ||
        (_grid[2] == _grid[4] && _grid[4] == _grid[6])){
        if(_grid[4] == "1"){
           // this->startNewGame();
            return 1;
        }
        else if(_grid[4] == "2"){
            //this->startNewGame();
            return 2;
        }
    }
    if((_grid[2] == _grid[5] && _grid[5] == _grid[8]) ||
       (_grid[6] == _grid[7] && _grid[7] == _grid[8])){
        if(_grid[8] == "1"){
            //this->startNewGame();
            return 1;
        }
        else if(_grid[8] == "2"){
            //this->startNewGame();
            return 2;
        }
    }
    int flag = 3;
    for(int i = 0; i < 9; i++){
        if(_grid[i] == "-"){
            flag = 0;
            return flag;
        }
    }
    ofstream Ofile("./grid.txt", ios::out);
    Ofile << "";
    return flag;
}





