//
//  main.cpp
//  TTTGame
//
//  Created by å­æˆ ä¸?on 16/9/9.
//  Copyright Â© 2016å¹?Zicheng Wan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "controller/TTTController.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;

int main(){
  cout<<"Content-Type:text/html\n\n";  
  stringstream post;
  post<<cin.rdbuf();
  string command = post.str();
  string method = "";
  string input = "";
  const char* j = command.c_str();
 
  rapidjson::Document document;
  if(document.Parse(j).HasParseError()){
	  cout << "Failed to load JSON object" << endl;
  }
  rapidjson::Value& methodj = document["controllerMethod"];
  method = methodj.GetString();
  rapidjson::Value& inputj = document["input"];
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  inputj.Accept(writer);
  input = buffer.GetString();
  /*
  while(1){
    if(*j == ':'){
      j++;
      while(*j != ','){
        stringstream stream;
        stream << *j++;
        method.append(stream.str());
      }
      break;
    }
    j++;
  }
  while(1){
    if(*j == ':'){
      j++;
      while(*j != '}'){
        stringstream stream;
        stream << *j++;
        input.append(stream.str());
      }
      break;
    }
    j++;
  }
  */
  TTTController controller;
  if(method == "getAllSavedPlayers"){
	  cout << controller.getAllSavedPlayers();
  }
  if(method == "createPlayer"){
    controller.createPlayer(input);
  }
  if(method == "setSelection1"){
    controller.setSelection1(input);
  }
  if(method == "setSelection"){
    controller.setSelection(input);
  }
  if(method == "restart"){
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
	//cout << controller.getGameDisplay() << endl;
	return 0;
}
