#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

void mstrmnd(int codeLen, bool dupes);
int* genCode(int arr[], int codeLen, bool dupes);
void clear();
bool chkDgts(int num, int codeLen);
int* cnv2Arr(int n, int arr[], int codeLen);
string cmpArr(int arr1[], int arr2[], int codeLen);
void prnHist(int gHist[], string rHist[]);

int main(int argc, char** argv) {
    srand(time(NULL));
    int codeLen;
    int choice;
    bool dupes;
    cout << "Choose the length of the code.\n1. 4\n2. 6\n3. 8" << endl;
    cin >> choice;
    switch(choice){
        default:
        case 1: codeLen = 4;
        break;
        case 2: codeLen = 6;
        break;
        case 3: codeLen = 8;
        break;
    }
    clear();
    
    cout << "Allow duplicates?\n1. No\n2. Yes" << endl;
    cin >> choice;
    switch(choice){
        default:
        case 1: dupes = false;
        break;
        case 2: dupes = true;
        break;
    }
    
    mstrmnd(codeLen, dupes);
    
    return 0;
}

void mstrmnd(int codeLen, bool dupes) {
    int code[codeLen]; //Generated code
    int urCode[codeLen]; //User's input converted into array
    int history[10]; //History of user guesses
    string result[10]; //History of results from guesses
    genCode(code, codeLen, dupes);

    int guess;
    bool valid;

    //Initialize history array
    for (int i = 0; i < 10; i++) {
        history[i] = -1;
    }

    cout << "Welcome to Mastermind! Input any " << codeLen << "-digit number (digits can only be 1-8).\n";
    cout << "You have 10 turns to figure out the code with your own deductive reasoning.\n";
    if(dupes == true){
        cout << "(Psst... Duplicates are on for an extra challenge! Good luck-- you're gonna need it.)\n";
    }

    //Do it 10 times, for 10 turns.
    for (int i = 0; i < 10; i++) {
        valid = false;
        while (!valid) {
            //Get guess from user
            cin >> guess;
            clear();
            
            //Check digits to make sure the number is valid
            valid = chkDgts(guess, codeLen);
            
            //If valid, save the guess to the history array and convert the
            //guess to an array of integers to compare.
            if (valid) {
                history[i] = guess;
                cnv2Arr(guess, urCode, codeLen);
            }
        }
        //Save the result from cmpArr to the result history array.
        result[i] = cmpArr(code, urCode, codeLen);
        
        //Print out the results from the entire game.
        prnHist(history, result);
        
        //If the latest result was "YOU WIN", win the game and return.
        if (result[i] == "YOU WIN!") {
            cout << result[i] << endl;
            return;
        }
        
        //Debug for seeing the code on each turn
        //**UNCOMMENT TO SEE THE CODE** 
        for (int i = 0; i < codeLen; i++) {
            //cout << code[i];
        }
    }
    //If the 10 turns are up, you lose.
    cout << "You lost! The code was ";
    for (int i = 0; i < codeLen; i++) {
        cout << code[i];
    }
    return;
}
    
int* genCode(int arr[], int codeLen, bool dupes){    
    for(int i = 0; i < codeLen; i++){
        arr[i] = rand()%8+1;
        
        //Duplicate prevention
        if(dupes == false){
            for(int j = 0; j < i; j++){
                //cout << "i = " << i << "\nj = " << j << endl;
                if(arr[i] == arr[j]){
                    //cout << "arr[" << i << "] == arr[" << j << "] == " << arr[i] << endl;
                    arr[i] = rand()%8+1;
                    //cout << "* arr[" << i << "] == " << arr[i] << endl;
                    j = -1; //Set to -1 cause it increments to 0 right after
                }
            }
        }
    }
    
    return arr;
}

void clear(){
    cout << "\033[2J\033[1;1H";
}

bool chkDgts(int num, int codeLen){
    int digit;
    int count = 1;
    while (num >= 10){
        digit = num%10;
        if (digit == 9 || digit == 0) {
            cout << "Invalid number! (Only digits 1 through 8 are valid.)\n";
            return false;
        }
        num /= 10;
        count++;
        
    }
    if(count != codeLen){
        cout << "[[" << count << "]]\n";
        return false;
    }
    return true;
}

int* cnv2Arr(int n, int arr[], int codeLen){
    int num = n;
    int digit;
    for(int i=codeLen-1; i>=0; i--){
        digit = num%10;
        arr[i] = digit;
        num /= 10;
        //cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    return arr;
}

string cmpArr(int arr1[], int arr2[], int codeLen){
    int correct = 0;
    int close = 0;
    int total = codeLen;
    string result = "";
    bool checked[codeLen];
    
    //Initialize the boolean array to be false
    for(int i=0; i<codeLen; i++){
        checked[i] = false;
    }
    
    for(int i=0; i<codeLen; i++){
        if(arr1[i] == arr2[i]){
            correct++;
            continue;
        }
        for(int j=0; j<codeLen; j++){
            if(arr1[i] == arr2[j]){
                //Ensure the same number isn't flagged as close twice or more.
                if(checked[j] == false){
                    close++;
                    checked[j] = true;
                }
                break;
            }
        }
    }
    
    if(correct == codeLen){
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
    for(int i=0; i<10; i++){
        if(gHist[i] == -1){
            break;
        }
        cout << gHist[i] << " | " << rHist[i] << endl;
    }
}