/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on September 7, 2021, 12:29 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Absorption Law: p&&(p||q) == p||(p&&q) == p\n"<<endl;
    cout << "p q p&&q p||q p&&(p||q) p||(p&&q)"<<endl;
    cout << "T|T| T  | T  |    T    |    T    "<<endl;
    cout << "T|F| F  | T  |    T    |    T    "<<endl;
    cout << "F|T| F  | T  |    F    |    F    "<<endl;
    cout << "F|F| F  | F  |    F    |    F    "<<endl;
    return 0;
}

