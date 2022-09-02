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
#include <time.h>
#include <vector>
#include "GeneralHashFunctions.h"

using namespace std;
void clear();
/*
 * 
 */
int main(int argc, char** argv) {
    int SIZE = 14;
    int strLen = 6;
    bool arr[SIZE] = {false};
    char str[strLen];
    vector<string> strHist;
    char response = 'y';

    srand(time(NULL));

    while (response != 'N' || response != 'n') {
        clear();
        cout << "Generated string: ";
        for (int i = 0; i < strLen; i++) {
            str[i] = (rand() % 91) + 33; //ascii code 33 to 124 and everything in between
            cout << str[i];
        }
        cout << endl;

        arr[RSHash(str) % (SIZE + 1)] = true;
        cout << "RS Hash   =  " << RSHash(str) % (SIZE + 1) << endl;
        arr[JSHash(str) % (SIZE + 1)] = true;
        cout << "JS Hash   =  " << JSHash(str) % (SIZE + 1) << endl;
        arr[PJWHash(str) % (SIZE + 1)] = true;
        cout << "PJW Hash  =  " << PJWHash(str) % (SIZE + 1) << endl;
        arr[ELFHash(str) % (SIZE + 1)] = true;
        cout << "ELF Hash  =  " << ELFHash(str) % (SIZE + 1) << endl;
        arr[BKDRHash(str) % (SIZE + 1)] = true;
        cout << "BKDR Hash =  " << BKDRHash(str) % (SIZE + 1) << endl;
        arr[DJBHash(str) % (SIZE + 1)] = true;
        cout << "DJB Hash  =  " << DJBHash(str) % (SIZE + 1) << endl;
        arr[DEKHash(str) % (SIZE + 1)] = true;
        cout << "DEK Hash  =  " << DEKHash(str) % (SIZE + 1) << endl;
        arr[BPHash(str) % (SIZE + 1)] = true;
        cout << "BP Hash   =  " << BPHash(str) % (SIZE + 1) << endl;
        arr[FNVHash(str) % (SIZE + 1)] = true;
        cout << "FNV Hash  =  " << FNVHash(str) % (SIZE + 1) << endl;

        for (int i = 0; i < SIZE + 1; i++) {
            if (arr[i] == true) {
                cout << "[X]";
            } else cout << "[ ]";
        }
        cout << endl << endl;
        
        strHist.push_back(str);
        for(int i=0; i<strHist.size(); i++){
            if(i==0) cout << "{";
            cout << strHist[i];
            if(i==strHist.size()-1) cout << "}";
            else cout << ", ";
        }
        cout << endl;
        cout << "Continue the program? (Y/N): ";
        cin >> response;
    }

    return 0;
}

void clear(){
    cout << "\033[2J\033[1;1H";
}
