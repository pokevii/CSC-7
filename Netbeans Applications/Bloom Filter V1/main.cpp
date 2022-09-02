/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on November 6, 2021, 12:50 AM
 */

#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int SIZE = 14;
    bool arr[SIZE] = {false};
    string str;
    
    cout << "Type in a string: ";
    cin >> str;
    
    arr[RSHash(str)%(SIZE+1)] = true;
    cout << "RSHash = " << RSHash(str)%15 << endl;
    arr[JSHash(str)%(SIZE+1)] = true;
    cout << "JSHash = " << JSHash(str)%15 << endl;

    for(int i=0; i<SIZE+1; i++){
        if(arr[i] == true){
            cout << "[X]";
        }
        else cout << "[ ]";
    }
    
    return 0;
}

