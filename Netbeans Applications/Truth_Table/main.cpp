/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on August 30, 2021, 10:40 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //assuming ^ means XOR
    cout<<"p q ~p ~q p&&q p||q p^q p^q^q p^q^p !(p&&q) !p||!q !(p||q) !p^!q"<<endl;
    cout<<"_|_|__|__|____|____|___|_____|_____|_______|______|_______|_____"<<endl;
    cout<<"T|T|F |F | T  | T  | F |  T  |  T  |   F   |  F   |   F   |  F  "<<endl;
    cout<<"T|F|F |T | F  | T  | T |  T  |  F  |   T   |  T   |   T   |  T  "<<endl;
    cout<<"F|T|T |F | F  | T  | T |  F  |  T  |   T   |  T   |   T   |  T  "<<endl;
    cout<<"F|F|T |T | F  | F  | F |  F  |  F  |   T   |  T   |   T   |  F  "<<endl;
    return 0;
}

