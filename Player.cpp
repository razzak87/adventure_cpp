/* 
 * File:   Player.cpp
 * Author: Rajib, Razzak
 * 
 * Created on November 21, 2011, 1:57 AM
 */

#include "Player.h"
    
Player::Player(string name, int score, int location){
    this->name = name;
    this->score = score;
    this->current_location_idx = location;
}

Player::~Player(){}

string Player::get_input(){
    return answer;
}

void Player::set_current_location(int location){
    this->current_location_idx = location;
}

int Player::get_current_location(){

    return this->current_location_idx;
}

void Player::set_item(int item){
    current_item = item;
}

int Player::get_item(){
    return current_item;
}


void Player::set_score(int score){
    this->score  = score;
}




int Player::get_score(){
    return this->score;
}

string Player::get_info(){
    return name;
}

Node* Player::get_location(){
    return this->location;
}

void Player::set_location(Node* loc){
    this->location = loc;
}

/*
 *
 */
void Player::go_to_next_location(){
    
    location->directions;
    location->active_verbs;
    
    for(int i=0 ; i < 10; i++)
    {
        if(location->directions[i] > 0)
        { 
//          cout << location->directions[i]  << endl;
            for(int j=0 ; j < 10 ; j++)
            {
                if(location->active_verbs[i][j] > 0)
                {
                    if( location->active_verbs[i][j] == moves){
                    
                        set_current_location(location->directions[i]);
                    
                    }
                }
            }   
        }
    }
}


string Player::format_answer(){
    int length = answer.length();
    for (int i = 0; i != length ; i++) {
        answer[i] = toupper(answer[i]);
    }
    
    return answer;
}