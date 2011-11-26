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

    for(int i=0 ; i < 10; i++){
        if(location->directions[i] > 0){
            for(int j=0 ; j < 10 ; j++){
                if(location->active_verbs[i][j] > 0){
                    if( location->active_verbs[i][j]== moves){
                        if(check_location(i)){
                            set_current_location(location->directions[i]);
                        }
                    }
                }
            }
        }
    }
}



bool Player::check_location(int indx){

        int x, y , n , m ;

        bool status = false;

        y = this->location->directions[indx];

        m = y / 1000;
        n = y % 1000;

        cout << y << "\t n:" << n << "\t m:" << m << endl;
        if(n <= 300){
            if (m==0) {//unconditional jump
                status = true;
            }
            else if((m>0) and (m<100)){// m% probability
               cout << "Probability " << m <<endl;
            }
            else if((m>100) and (m<=200)){// must be carrying an Element=M-100
                int item_id= m-100;
                int item_size = this->carrying.size();
                if(item_size > 0){
                  for(int i=0; i < item_size ; i++){
                    if(this->carrying[i]->id == item_id ){
                        status = true; // make the jump
                    }
                  }
                }
            }
            else if((m>200) and (m <= 300)){// must carry element and same room=M-200
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

        }
        else if( (n > 300) && (n <=500) ) {
            //use n-300 to go to special code;
            status =false;
        }else{
            // n-500 to print section 6 and stay in same location

            status= false;
        }


        return status;
}

int Player::prop_vlaue(int m){
    return m % 100 ;
}


void Player::carry_item(int item_id){

    int item_size = this->location->items.size();
    item_id = item_id % 1000;
    for(int i=0 ; i < item_size; i++){
        if(this->location->items[i]->id == item_id){
            cout << "added " << endl;
            this->carrying.push_back(this->location->items[i]);
            break;
        }
    }
    cout << this->carrying[0]->description;
}

string Player::format_answer(){
    int length = verb.length();
    for (int i = 0; i != length ; i++) {
        verb[i] = toupper(verb[i]);
    }
    return verb;
}
