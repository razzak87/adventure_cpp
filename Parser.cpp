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

    //INITIALIZTIONS
    ifstream dataFile;
    string line;
    string data;
    start_idx = 0;
    element_counter=0;

    elements[17]=new Element(">$<");
    elements[18]=new Element(">$<");


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
                    parse_element_desc(line);
                    break;
                case ELEMENT_LOCATION:
                    parse_element_location(line);
                    break;
                case ABBR_MSG:
                    parse_abbr_msg(line);
                    break;
                case ACTIONS:
                    parse_actions(line);
                    break;
                case LIQUID_ASSET:
                    break;
                case CLASS_MSG:
                    parse_player_classification(line);
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
            locations[first_number]->id = first_number;
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


    if(!temp[1].empty()){
        //now table parsing beings
        int y = atoi(temp[1].c_str());

        //TODO change this to array no need for vector here
        locations[first_number]->directions[locations[first_number]->count]=y;


        for (int i = 2; i < 10; i++) {
            locations[first_number]->active_verbs[locations[first_number]->count][i-2]= atoi(temp[i].c_str());
        }

        locations[first_number]->count++;

    }//ifEnds
}

void Parser::parse_abbr_msg(string &line){
    string temp[2];
    for(int i=0 ; i < 2 ; i++) temp[i] = tokenizer(line);
    start_idx=0;
    int indx = atoi(temp[0].c_str());
    if(!temp[1].empty()){
        abbr_messages[indx] += temp[1];
    }
}



void Parser::parse_element_desc(string &line){
    //cout  << line << endl;
    string temp[2];
    for(int i=0 ; i < 2 ; i++) temp[i] = tokenizer(line);
    start_idx=0;

    int element_id = atoi(temp[0].c_str());
    if(!temp[1].empty()){
       //cout << temp[0] << "=>" << temp[1] << endl;
        if((element_id >0) && (element_id < 65)){
            elements[element_id]= new Element(temp[1]);
            element_counter=element_id;
            elements[element_id]->id = element_id;
        }else{
            //element_id is now 3DIGIT number
            //adds descriptions blocks with index
            elements[element_counter]->messages[element_id/100] = temp[1];
        }

    }
}



void Parser::parse_element_location(string& line){
    string temp[3];
    for(int i=0 ; i < 3 ; i++) temp[i] = tokenizer(line);
    start_idx=0;

    int count=0;

    if(!temp[1].empty()){
        int element_id = atoi(temp[0].c_str());
        int location_idx = atoi(temp[1].c_str());
        int secon_loc_idx = atoi(temp[2].c_str());

        if(element_id > 0 && element_id != 17 && element_id !=18) {
            //TOOK me 3hr solve this because there is no index 17 and 18 why ???
            if(location_idx>0){
                locations[location_idx]->items.push_back(elements[element_id]);
            }
            if(secon_loc_idx>0){
                locations[secon_loc_idx]->items.push_back(elements[element_id]);
            }

        }
        location_idx = 0;
        secon_loc_idx=0;
    }
}


void Parser::parse_actions(string& line){
    string temp[2];
    for(int i=0 ; i < 2 ; i++) temp[i] = tokenizer(line);
    start_idx=0;

   if(!temp[1].empty()){
        action_verbs[atoi(temp[0].c_str())] = atoi(temp[1].c_str());
   }
}



void Parser::parse_player_classification(string& line){
    string temp[2];
    for(int i=0 ; i < 2 ; i++) temp[i] = tokenizer(line);
    start_idx=0;

//    if(!temp[1].empty())
//        cout << temp[0] << "\t" << temp[1] << endl;
}

/*========================================
 * This method parses a line and returns
 * string tokens delimited by tab
 ========================================= */

string Parser::tokenizer(string &line, string delimiter){
    //Thanks H.S
    if(start_idx == string::npos) return "";
    end_idx = line.find_first_of(delimiter , start_idx);
    string tokn(line.substr(start_idx, end_idx- start_idx));
    start_idx = line.find_first_not_of(delimiter, end_idx);
    return tokn;
}








/*==============================================================================
 *      THIS SECTION HOLDS ALL POSSIBLE GAME LOGIC
 =============================================================================*/




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
