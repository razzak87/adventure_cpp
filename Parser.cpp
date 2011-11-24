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
                    //parse_locations(line, first_number);
                    break;
                case SHORT_DESC_SECTION:
                    break;
                case TRAVEL_TABLE:
                    //parse_travel_table(line, first_number);
                    break;
                case VOCABULARY:
                    //parse_vocabulary(line);
                    break;
                case ELEMENT_DESC:
                    parse_element_desc(line);
                    break;
                case ELEMENT_LOCATION:
                    parse_element_location(line);
                    break;
                case ABBR_MSG:
                    break;
                case ACTIONS:
                    parser_actions(line);
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
    
    int x, y , n , m ;

    if(!temp[1].empty()){ 
    //now table parsing beings
        x = atoi(temp[0].c_str()) ;
        y = atoi(temp[1].c_str());
        
        m = y / 1000;
        n = y % 1000;
        
        if(n <= 300){
            
            
        }
        
        
        if (m==0) {             //unconditional jump
            cout << "Uncon "<< m << endl;
        } 
        else if((m>0) and (m<100)){     // m% probability
           cout << "Probability " << m <<endl;
        }
        else if((m>100) and (m<=200)){  // must be carrying an Element=M-100
            cout << "carry" << (m-100) <<endl;
        }
        else if((m>200) and (m <= 300)){    // must carry element and same room=M-200
            cout << "room" << (m- 200) << endl;
            
        }else if((m >300) && (m <=400) && (prop_vlaue(m) != 0)){
            cout << "Prop value not 0" <<endl; 
        
        }else if((m>400)  && (m <=500) && (prop_vlaue(m)!=1)){
            cout << "Prop value not 1" << endl;
        
        }else if((m> 500) && (m <=600) && (prop_vlaue(m)!=2)){
            cout << "Prop value not 2" << endl;
        
        }else{
            //default when no condition matches
            cout << "nothing matched" << endl;
        }
    }//ifEnds
 
}





void Parser::parse_element_desc(string &line){
    //cout  << line << endl;
    string temp[2];
    for(int i=0 ; i < 2 ; i++) temp[i] = tokenizer(line);
    start_idx=0;
            
    //if(!temp[1].empty()) 
        //cout << temp[0] << "=>" << temp[1] << endl;
}



void Parser::parse_element_location(string& line){
//    string temp[3];
//    for(int i=0 ; i < 3 ; i++) temp[i] = tokenizer(line);
//    start_idx=0;
//            
//    if(!temp[1].empty()) 
//        cout << temp[0] << "\t" << temp[1] << "\t"<< temp[2] << endl;
}


void Parser::parser_actions(string& line){
    string temp[2];
    for(int i=0 ; i < 2 ; i++) temp[i] = tokenizer(line);
    start_idx=0;
            
    if(!temp[1].empty()) 
        cout << temp[0] << "\t" << temp[1] << endl;
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








/*==============================================================================
 *      THIS SECTION HOLDS ALL POSSIBLE GAME LOGIC 
 =============================================================================*/


int Parser::prop_vlaue(int m){
    return m % 100 ;
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