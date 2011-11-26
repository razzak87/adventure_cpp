#include <iostream>
#include "Parser.h"
#include "Player.h"
#include "Element.h"
#include "Node.h"
#include <cstdlib>
#include <cctype>

using namespace std;


int main() {
    cout << "Application starting " << endl;

    Parser game("advent.dat");

    Player player("Rajib Ahmed", 0 , 1);

    map<string, int>::iterator it;

    string words[3];

    bool show_item= true;


    for(;;){//game loop
        cout << game.locations[player.get_current_location()]->get_clue() << endl;
        player.set_location(game.locations[player.get_current_location()]);



        /*
         * check for items in current player location
         */
        int numer_of_items = player.get_location()->items.size();
        int items_carried = player.carrying.size();
        if(numer_of_items > 0){
            for (int i = 0; i < numer_of_items; i++) {
                for(int j=0; j< items_carried ; j++){
                  if(player.carrying[j]->id == player.get_location()->items[i]->id){
                    show_item=false;
                    break;
                  }
                }
                if(show_item){
                  cout << "=> " << player.get_location()->items[i]->messages[0] << endl;
                }
                show_item = true;
            }
        }

        /*
         * User input handling & formatting
         */
        cout << ">";
        getline(cin,player.verb);
        player.format_answer();


        game.start_idx=0;
        for(int i=0; i<3 ;i++){
            words[i] = game.tokenizer(player.verb," ");
        }

        !words[0].empty() ? player.verb = words[0] : "";
        !words[1].empty() ? player.noun = words[1] : "";

        /*
         * player wants to take Elements
         */
        if(!player.verb.empty() && !player.noun.empty()){
            cout << player.noun << endl;
            it = game.vocabulary.find(player.verb);
            if(it!=game.vocabulary.end()){
                if(game.is_action(player.verb) && game.is_object(player.noun)){
                  //cout << "action verb and object sequence" << endl;
                  int element_id = game.vocabulary.find(player.noun)->second;
                  player.carry_item(element_id);
                }
            }

        /*
         * player want to only move
         */
        }else if(!player.verb.empty() && player.noun.empty()){
          cout << "test" << endl;
            it = game.vocabulary.find(player.verb);
            if(it!=game.vocabulary.end()){
              if(game.is_motion(player.verb)){
                 player.moves = game.vocabulary.find(player.verb)->second;
                 player.go_to_next_location();
              }
            }else{
                cout << "dont understand that" << endl;
            }
        }
        //loop :) continues
    }

    return EXIT_SUCCESS;
}
