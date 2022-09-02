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
#include <string.h>

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
char* trnsDgt(char cc[]);

int main(int argc, char** argv) {
    const int SIZE = 17;
    int type;
    int valid = 0;
    char ccard[SIZE];
    srand(time(NULL));
    
    cout << "Select a credit card:\n1.Visa\n2.MasterCard\n3.Discover\n4.American Express\n5.Random\n";
    cin >> type;
    //Transposing 2 numbers
    for(int i=0;i<10000;i++){
        genCC(type, ccard);
        trnsDgt(ccard);
        valid += validCC(ccard, type);
    }
    cout << "Transposing 2 numbers:" << endl;
    cout << "Valid: " << valid << endl
            << "Invalid: " << 10000 - valid << endl << endl;
    valid = 0;
    
    for(int i=0;i<10000;i++){
        genCC(type, ccard);
        flipDgt(ccard);
        valid += validCC(ccard, type);
    }
    cout << "Flipping 2 numbers:" << endl;
    cout << "Valid: " << valid << endl 
            << "Invalid: " << 10000 - valid << endl << endl;
    
    return 0;
}

char* genCC(int crdType, char cc[]){
    int n;
    int type = crdType;
    while(type == all || type == 0){
        type = rand()%5;
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
    //cout << "\n" << "size: " << strlen(cc) << endl;
    return cc;
}

char rndDgit(){
    return rand()%10+48;
}

char* flipDgt(char cc[]){
    int dgt1 = rand()%16;
    int dgt2 = rand()%16;
    //ensure they are not the same digits.
    while(dgt1 == dgt2){
        dgt2 = rand()%16;
    }
    
    cc[dgt1] = rndDgit();
    cc[dgt2] = rndDgit();
    
    return cc;
}

int validCC(char cc[], int type){
    int n = strlen(cc);
    
    int num = 0;
    int fstDgt = 0;
    //int lstDgt = cc[n-2]-48;
    //int chksum = 0;
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

    //chksum = (9 * sum)%10;
    if(sum%10 == 0){
        return 1;
    } else {
        return 0;
    }
}

//Transpose 2 adjacent numbers.
char* trnsDgt(char cc[]){
    int a, b;
    a = rand()%16;
    b = a - 1;
    swap(cc[a], cc[b]);
    
    return cc;
}