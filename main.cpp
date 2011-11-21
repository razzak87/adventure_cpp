#include <iostream>
#include "Player.h"
#include <cstdlib>
using namespace std;


int main() {
    cout << "Application starting " << std::endl;
    Player rajib();
    cout << rajib->get_info() << endl;
    
    //cout << rajib.get_info();
    
//    for(int i=1; i < 141 ;i++)
//        cout << p.locations[i] << endl;
    
    return EXIT_SUCCESS;
}

