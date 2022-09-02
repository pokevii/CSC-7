/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on September 4, 2021, 9:30 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //assuming ^ in this case means XOR
    cout<<"p q p&&q p||q p^q (p&&q)||~(p||q) ~p^q"<<endl;
    cout<<"_|_|____|____|___|_______________|____"<<endl;
    cout<<"T|T| T  | T  | F |       T       |  T "<<endl;
    cout<<"T|F| F  | T  | T |       F       |  F "<<endl;
    cout<<"F|T| F  | T  | T |       F       |  F "<<endl;
    cout<<"F|F| F  | F  | F |       T       |  T "<<endl;
    cout<<endl;
    
    cout<<"p q p||q ~p&&q (p||q)&&~(p&&q) p^q"<<endl;
    cout<<"_|_|____|_____|_______________|___"<<endl;
    cout<<"T|T| T  |  F  |       F       | F "<<endl;
    cout<<"T|F| T  |  T  |       T       | T "<<endl;
    cout<<"F|T| T  |  T  |       T       | T "<<endl;
    cout<<"F|F| F  |  T  |       F       | F "<<endl;
    return 0;
}

