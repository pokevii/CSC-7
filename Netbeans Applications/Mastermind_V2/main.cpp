#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int* genCode(int arr[]);
void clear();
bool chkDgts(int num);
int* cnv2Arr(int n, int arr[]);
void cmpArr(int arr1[], int arr2[]);

int main(int argc, char** argv) {
    srand(time(NULL));
    //Generate the code
    int code[4];
    int urCode[4];
    genCode(code);
    
    int guess;
    bool valid;
    
    //Do it 12 times, for 12 turns.
    for(int i=0; i<12; i++){
        valid = false;
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
        cmpArr(code, urCode);
        
        for (int i = 0; i < 4; i++) {
            cout << code[i];
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
    for(int i=3; i>=0; i--){
        digit = num%10;
        //arr[i] = digit;
        num /= 10;
        //cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    return arr;
}

void cmpArr(int arr1[], int arr2[]){
    int correct = 0;
    int close = 0;
    int total = 4;
    
    for(int i=0; i<4; i++){
        if(arr1[i] == arr2[i]){
            //cout << "Ya got one!\n";
            //cout << "arr1[" << i << "] == arr2[" << i << "] == " << arr1[i] << endl;
            correct++;
            continue;
        }
        //cout << "Going to check j now.\n";
        for(int j=0; j<4; j++){
            if(arr1[i] == arr2[j]){
                //cout << "You're gettin close..\n";
                close++;
            }
        }
    }
    
    while(correct--){
        cout << "[✓] ";
        total--;
    }
    while(close--){
        cout << "[~] ";
        total--;
    }
    while(total--){
        cout << "[ ] ";
    }
    
    cout << endl;
    
}