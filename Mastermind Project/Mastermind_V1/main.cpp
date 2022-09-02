#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int* genCode(int arr[]);
void clear();
bool chkDgts(int num);
int* cnv2Arr(int n, int arr[]);

int main(int argc, char** argv) {
    srand(time(NULL));
    //Generate the code
    int code[4];
    int urCode[4];
    genCode(code);
    
    int guess;
    bool valid = false;
    while(!valid){
        cin >> guess;
        valid = chkDgts(guess);
        if (guess > 8888 || guess < 1111) {
            valid = false;
        }
        if(valid){
            cout << "Valid\n";
            cnv2Arr(guess, urCode);
        }
    }

    for(int i=0; i<4; i++){
        cout << code[i];
    }
    return 0;
}

int* genCode(int arr[]){
    for(int i = 0; i < 4; i++){
        arr[i] = rand()%8+1;
    }
    return arr;
}

void clear(){
    cout << "\033[2J\033[1;1H";
}

bool chkDgts(int num){
    int digit;
    while (num >= 10){
        digit = num%10;
        if (digit == 9 || digit == 0) {
            return false;
        }
        num /= 10;
    }
    
    return true;
}

int* cnv2Arr(int n, int arr[]){
    int num = n;
    int digit;
    for(int i=0; i<4; i++){
        digit = num%10;
        arr[i] = digit;
        num /= 10;
        //cout << arr[i];
    }
    
    return arr;
}