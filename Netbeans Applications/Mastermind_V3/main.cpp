#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int* genCode(int arr[]);
void clear();
bool chkDgts(int num);
int* cnv2Arr(int n, int arr[]);
string cmpArr(int arr1[], int arr2[]);
void prnHist(int gHist[], string rHist[]);

int main(int argc, char** argv) {
    srand(time(NULL));

    int code[4];        //Generated code
    int urCode[4];      //User's input converted into array
    int history[12];    //History of user guesses
    string result[12];     //History of results from guesses
    genCode(code);
    
    int guess;
    bool valid;
    
    //Initialize history array
    for(int i=0; i<12; i++){
        history[i] = -1;
    }
    
    //Do it 10 times, for 10 turns.
    for(int i=0; i<10; i++){
        valid = false;
        while(!valid){
            cin >> guess;
            clear();
            valid = chkDgts(guess);
            if (guess > 8888 || guess < 1111) {
                valid = false;
            }
            if(valid){
                //cout << "Valid\n";
                history[i] = guess;
                cnv2Arr(guess, urCode);
            }
        }
        result[i] = cmpArr(code, urCode);
        prnHist(history, result);
        if(result[i] == "YOU WIN!"){
            cout << result[i] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            cout << code[i];
        }
    }
    cout << "You lost! The code was ";
    for (int i = 0; i < 4; i++) {
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
        arr[i] = digit;
        num /= 10;
        //cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    return arr;
}

string cmpArr(int arr1[], int arr2[]){
    int correct = 0;
    int close = 0;
    int total = 4;
    string result = "";
    int checked[4];
    
    for(int i=0; i<4; i++){
        checked[i] = -1;
    }
    
    for(int i=0; i<4; i++){
        if(arr1[i] == arr2[i]){
            //cout << "got one!\n";
            //cout << "arr1[" << i << "] == arr2[" << i << "] == " << arr1[i] << endl;
            correct++;
            continue;
        }
        for(int j=0; j<4; j++){
            if(arr1[i] == arr2[j]){
                cout << "gettin close..\n";
                cout << "arr1[" << i << "] == arr2[" << j << "] == " << arr1[i] << endl;
                close++;
                break;
            }
        }
    }
    
    if(correct == 4){
        result = "YOU WIN!";
        return result;
    }

    while (correct--) {
        result += "[!]";
        total--;
    }
    while (close--) {
        result += "[~]";
        total--;
    }
    while (total--) {
        result += "[ ]";
    }
    
    //cout << result << endl;
    return result;
}

void prnHist(int gHist[], string rHist[]){
    //guess history & result history
    for(int i=0; i<12; i++){
        if(gHist[i] == -1){
            break;
        }
        cout << gHist[i] << " | " << rHist[i] << endl;
    }
}