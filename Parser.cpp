/*
 * File:   Parser.cpp
 * Author: Rajib , Razzak
 *
 * Created on November 15, 2011, 7:20 AM
 */

#include "Parser.h"
#include "cstdlib"


Parser::Parser(string fileName) {
    

    ifstream dataFile;
    string line;
    string data;

    
    int section = 1;
    
    
    
    dataFile.open(fileName.c_str());

    if(!dataFile.eof()){
        while(getline(dataFile,line)){
            data += line + END_LINE; 
            
            int first_number = getFirstNumberOf(line);
            
            if (SEPARATOR == first_number) section++;
            
            switch(section){
                case 1: 
                    parseLocations(line, first_number);
                    break;
            }
        }
        dataFile.close();
    }
    
    for(int i=0 ; i <= LOCATIONS ; i ++){
        cout << this->locations[i] << endl;
    }
    
}

Parser::~Parser() {

}




int Parser::getFirstNumberOf(string line){
    size_t tab_start = line.find_first_of("\t");
    return atoi (line.substr(0, tab_start).c_str());
}

void Parser::display(){
    cout << this->fileData;
}

void Parser::parseLocations(string line, int first_number ){
    
    size_t tab_ends = line.find_first_of("\t") + 1;
    string direction = line.substr( tab_ends);
    
    if(!direction.empty()){
        if(!this->locations[first_number].empty()){
            this->locations[first_number]+=direction;
        }else{
            this->locations[first_number]=direction;
        }
    }
    
}

void Parser::parseVerbs(){

}