/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on September 22, 2021, 5:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

enum CrdCard {
    visa = 1, //Visa
    master, //MasterCard
    dscvr, //Discover
    amex, //American Express
    all //Any of the 4 specified
};

//Function Prototypes
char* genCC(int crdType, char cc[]);
char* crtCard(int length, char cc[]);
char rndDgit();
char* flipDgt(char cc[]);
int validCC(char cc[], int type);

int main(int argc, char** argv) {
    const int SIZE = 17;
    int type;
    int valid = 0;
    char ccard[SIZE];
    srand(time(NULL));
    
    cout << "Select a credit card:\n1.Visa\n2.MasterCard\n3.Discover\n4.American Express\n5.Random\n";
    cin >> type;
   
    for(int i=0;i<10000;i++){
        genCC(type, ccard);
        flipDgt(ccard);
        valid += validCC(ccard, type);
    }
    cout << "Valid: " << valid << endl << "Invalid: " << 10000 - valid << endl;
    return 0;
}

char* genCC(int crdType, char cc[]){
    int n;
    int type = crdType;
    while(type == all || type == 0){
        type = rand()%4;
    }
    if(type != amex) n = 16;
    else n = 15;
    
    for (int i = 0; i < n; i++) {
        //cout << i;
        cc[i] = rndDgit();
    }
    for (int i = n; i <= n + 1; i++) {
        cc[i] = '\0';
    }
    
    switch(type){
        case visa:
            cc[0] = 4+48;
            break;
        case master:
            cc[0] = 5+48;
            cc[1] = (rand()%6)+48; 
            break;
        case dscvr:
            cc[0] = 6+48;
            cc[1] = 0+48;
            cc[2] = 1+48;
            cc[3] = 1+48;
            break;
        case amex:
            cc[0] = 3+48;
            cc[1] = 4+48;
            break;
        default:
            break;
    }
    for (int i = 0; i < n; i++) {
        //cout << cc[i];
    }
    //cout << "\n";
    return cc;
}

char rndDgit(){
    return rand()%10+48;
}

char* flipDgt(char cc[]){
    int dgt2Flp = rand()%16;
    /*while(dgt2Flp==0){        Got rid of this code so it flips digits
        dgt2Flp = rand()%16;    completely randomly.
    }
    cout << "Normal: ";*/
    for(int i=0;i<17;i++){
        //cout << cc[i];
    }
    //cout << "\n";
    
    cc[dgt2Flp] = rand()%10+48;
    
    //cout << "Flipped: ";
    for(int i=0;i<17;i++){

    }
    //cout << "\n";
    return cc;
}

int validCC(char cc[], int type){
    int n;
    
    if(type != amex) int n = 17;
    else n = 16;
    
    int num = 0;
    int fstDgt = 0;
    int lstDgt = cc[n-2]-48;
    int chksum = 0;
    int sum = 0;
    
    for(int i = 1; i < n-1; i++){
        num = cc[i-1] - 48;
        if(i % 2 == 0){
            //cout << "*";
            num *= 2;
        }
        
        //Divide num by 10 to get first digit, mod 10 to get second digit, add
        //together to get the proper number.
        if(num >= 10){
            fstDgt = num / 10;
            num %= 10;
            num += fstDgt;
        } else {
            num %= 10;
        }
        
        sum += num;
        cc[i-1] = num + 48;
    }
    //sum += lstDgt;
    //cout << "sum:" << sum << endl;
    chksum = (9 * sum)%10;
    //cout << "chksum = " << chksum << endl;
    //cout << "lstDgt = " << lstDgt << endl;
    if(lstDgt == chksum){
        return 1;
    } else {
        return 0;
    }
}

