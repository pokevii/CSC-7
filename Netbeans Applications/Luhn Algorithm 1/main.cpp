/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 1st, 2021, 8:35 AM
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
void prpLuhn(char[],int); //Prepares the Luhn Sequence
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
void output(char[],int);  //Output the sequence as integers
//Function you are to create
void Luhn(char[],int);    //Calculate and append the Luhn Digit

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set the Credit Card size
    const int SIZE=17;
    char ccard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    output(crdCard,SIZE-2);
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    Luhn(crdCard,SIZE);
    cout<<"Random number with Luhn Encoding + check digit\n"<<crdCard<<endl;
    
    //Exit Stage Right
    return 0;
}

void Luhn(char ccc[],int n){
    int num = 0;
    int fstDgt = 0;
    int sum = 0;
    
    for(int i = 1; i < n-1; i++){
        num = ccc[i-1] - 48;
        if(i % 2 == 0){
            cout << "*";
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
        
        cout << i << ": " << num;
        sum += num;
        cout << " == " << sum << endl;
        //ccc[i-1] = num + 48;
    }
    cout << "sum: " << (sum*9) % 10 << " being placed in ccc[" << n-2 << "]" << endl;
    ccc[n-2] = (sum*9 % 10) + 48;
}

void output(char cc[],int n){
    cout<<"The char array output as each integer digit"<<endl;
    for(int i=0;i<n;i++){
        cout<<cnvrt(cc[i]);
    }
    cout<<endl;
}

char  cnvrt(int digit){
    if(digit<0||digit>9){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+48;
}

int  cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}