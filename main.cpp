#include <iostream>
#include "Parser.h"
#include "Player.h"
#include "Node.h"
#include <cstdlib>

using namespace std;


int main() {
    cout << "Application starting " << endl;
    Parser p("advent.dat");

    Player player("Rajib Ahmed", 0 , 1);
//    
//    for(;;){//game loop
//        cout << p.locations[player.get_current_location()]->get_clue() << endl;
//        //getline(cin, player.answer);
//        cout << p.locations[player.get_current_location()]->directions[1] << endl;
//        if(!player.answer.empty());
//          player.go_to_next_location();
//        break;
//    }
    

    
    return EXIT_SUCCESS;
}

