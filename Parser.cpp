/* 
 * File:   Parser.cpp
 * Author: rajib
 * 
 * Created on November 15, 2011, 7:20 AM
 */

#include "Parser.h"


Parser::Parser(char* fileName) {
    
    ifstream dataFile;
    string line;
    string data;
    
    dataFile.open(fileName);
    
    if(!dataFile.fail()){
        while(getline(dataFile,line)){
            cout << line << endl;
        }
    }
}



Parser::~Parser() {

}


Parser::getDataFileName(){
    return "";
}

