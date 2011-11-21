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
    this->current_location = location;
}

Player::~Player(){}


void Player::set_current_location(int location){
    this->current_location = location;
}

int Player::get_current_location(){

    return this->current_location;
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