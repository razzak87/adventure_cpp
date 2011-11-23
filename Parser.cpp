/*
 * File:   Parser.cpp
 * Author: Rajib , Razzak
 *
 * Created on November 15, 2011, 7:20 AM
 */

#include "Parser.h"
#include <stdlib.h>
#include <fstream>



Parser::Parser(string fileName) {

    ifstream dataFile;
    string line;
    string data;
    start_idx = 0;


    for(int i=0 ; i < 141; i++) locations[i] = NULL; //Thanks Charlie

    int section = 0;

    dataFile.open(fileName.c_str());

    if(!dataFile.eof()){
        while(getline(dataFile,line)){
            data += line + END_LINE;

            int first_number = getFirstNumberOf(line);

            if(SEPARATOR == first_number){
               section++;
            }

            switch(section){
                case LONG_DESC_SECTION:
                    parse_locations(line, first_number);
                    break;
                case SHORT_DESC_SECTION:
                    break;
                case TRAVEL_TABLE:
                    parse_travel_table(line, first_number);
                    break;
                case VOCABULARY:
                    parse_vocabulary(line);
                    break;
                case ELEMENT_DESC:
                    break;
                case ELEMENT_LOCATION:
                    break;
                case ABBR_MSG:
                    break;
                case ACTIONS:
                    break;
                case LIQUID_ASSET:
                    break;
                case CLASS_MSG:
                    break;
                case HINTS:
                    break;
                case MAGIC_WORDS:
                    break;
            }//endSwitch
        }//endWhile
        dataFile.close();
    }

}

Parser::~Parser() {

}




int Parser::getFirstNumberOf(string &line){
    size_t tab_start = line.find_first_of("\t");
    return atoi (line.substr(0, tab_start).c_str());
}



void Parser::parse_locations(string &line, int first_number ){

    size_t tab_ends = line.find_first_of("\t") + 1; //END of that TAB CHAR

    string direction = line.substr( tab_ends);
    if(!direction.empty()){
        if(locations[first_number]==NULL){
            locations[first_number]= new Node(direction);
        }else{
            locations[first_number]->append(direction);
        }
    }
}


void Parser::parse_vocabulary(string &line){

    size_t tab = line.find_first_of("\t");
    int value  = atoi(line.substr(0,tab).c_str());
    string key = line.substr(tab+1);

    if(key!="4") //for removing the section number
        this->vocabulary[key]=value;
}


                        
/**
 * This method parses the most important table
 */
void Parser::parse_travel_table(string &line, int first_number){
    
    string temp[11];
    
    for(int i=0 ; i < 12 ; i++) temp[i] = tokenizer(line);
    
    start_idx=0;
    int sum = 0;
    for(int i=0;i< 12 ;i++){
       // for removing section number
       // and -1 separator
        
       if(!temp[i].empty() && !temp[1].empty()){ 
       //now table parsing beings
           
           
           
       }//ifEnds
    }//forEnds
    cout << sum << endl;
}




/*
 * This method parses a line and returns 
 * string tokens delimited by tab
 */
string Parser::tokenizer(string &line){
    //Thank H.S
    if(start_idx == string::npos) return "";
    end_idx = line.find_first_of("\t", start_idx);
    string tokn(line.substr(start_idx, end_idx- start_idx));
    start_idx = line.find_first_not_of("\t", end_idx);
    return tokn;
}




bool Parser::is_motion(string key){
    return this->vocabulary[key]/1000 == 0 ? true : false;
}

bool Parser::is_object(string key){
    return this->vocabulary[key]/1000 == 1 ? true : false;
}

bool Parser::is_action(string key){
    return this->vocabulary[key]/1000 == 2 ? true : false;
}


bool Parser::is_special(string key){
    return this->vocabulary[key]/1000 == 3? true : false;
}