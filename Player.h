/* 
 * File:   Player.h
 * Author: rajib , razzak
 *
 * Created on November 21, 2011, 1:57 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include <iostream>
using namespace std;

class Player {
    
public:
    int max_items;
    string answer;
private:
    string name;
    int score;
    int current_location;
    Node* state;
    int current_item;
    int moves;
    
public:
    Player(string name,int score, int location);
    
    ~Player();
    
    void set_current_location(int location);
    int  get_current_location();
    
    int  get_score();
    void set_score(int score);
    
    Node* get_location();
    void set_location(Node* loc);
    
    void set_item(int item);
    int get_item();
    string get_input();
    
    void go_to_next_location(
    
    
    );
    
    string get_info();

private:
    
};
        
#endif	/* PLAYER_H */

