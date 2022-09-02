#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void mstrmnd(int codeLen, bool dupes);
void automnd();
int* genCode(int arr[], int codeLen, bool dupes, int range);
char* genCode(char arr[], int codeLen, bool dupes);
void clear();
bool chkDgts(int num, int codeLen);
int* cnv2Arr(int n, int arr[], int codeLen);
char* cnv2Arr(int n, char arr[], int codeLen);
string cmpArr(int arr1[], int arr2[], int codeLen);
bool cmpArr(string arr1, string arr2, char &rr, char &rw);
void prnHist(int gHist[], string rHist[]);
string AI(char rr,char rw);

int main(int argc, char** argv) {
    srand(time(NULL));
    int codeLen;
    int choice;
    bool dupes;
    bool autoplay;
    
    cout << "Automatically play the game using AI? \n1. No\n2. Yes" << endl;
    cin >> choice;
    switch(choice){
        default:
        case 1: autoplay = false;
        break;
        case 2: autoplay = true;
        clear();
        automnd();
        return 0;
        break;
    }
    clear();
    
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
    clear();
    
    mstrmnd(codeLen, dupes);
    
    return 0;
}

void mstrmnd(int codeLen, bool dupes) {
    int code[codeLen]; //Generated code
    int urCode[codeLen]; //User's input converted into array
    int history[10]; //History of user guesses
    string result[10]; //History of results from guesses

    genCode(code, codeLen, dupes, 8);

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

//Automatic mastermind function
void automnd(){
    int codeLen = 4;
    int urCode = -1;
    char code[codeLen];
    //char guessArr[codeLen];       [[TO BE REMOVED]]
    int response;
    
    cout << "Would you like to input the code yourself? (4 digits)\n1. No\n2. Yes\n";
    cin >> response;
    cout << endl;
    
    switch(response){
        default:
        case 1: genCode(code, codeLen, false);
        break;
        case 2:
            while(urCode > 9999 || urCode < 0){
                cout << "Input your code: ";
                cin >> urCode;
            }
            cnv2Arr(urCode, code, codeLen);
            break;
    }
    clear();
    
    string guess = "0000";
    //int result[2];                [[TO BE REMOVED]]
    char rr,rw;
    rr=rw=0;
    
    cout << "Code       Guess      Correct Close  Sum\n";
    
    do{
        guess = AI(rr, rw);
        //cnv2Arr(guess, guessArr, codeLen);
        //cmpArr(code, guess, rr, rw);
        
        //cout << left << setw(8);

    }while(cmpArr(code, guess, rr, rw));
    //Put the following below in the loop once ready.
    for (int i = 0; i < codeLen; i++) {
        cout << code[i];
    }
    cout << setw(8);
    for (int i = 0; i < codeLen; i++) {
        cout << guess[i];
    }
    cout << setw(8) << int(rr) << setw(8) << int(rw) <<
            setw(8) << rr + rw << endl;
}

int* genCode(int arr[], int codeLen, bool dupes, int range){    
    for(int i = 0; i < codeLen; i++){
        arr[i] = rand()%range;
        
        //Duplicate prevention
        if(dupes == false){
            for(int j = 0; j < i; j++){
                //cout << "i = " << i << "\nj = " << j << endl;
                if(arr[i] == arr[j]){
                    //cout << "arr[" << i << "] == arr[" << j << "] == " << arr[i] << endl;
                    arr[i] = rand()%range;
                    //cout << "* arr[" << i << "] == " << arr[i] << endl;
                    j = -1; //Set to -1 cause it increments to 0 right after
                }
            }
        }
    }
    
    return arr;
}

char* genCode(char arr[], int codeLen, bool dupes){    
    for(int i = 0; i < codeLen; i++){
        arr[i] = rand()%10+48;
        
        //Duplicate prevention
        if(dupes == false){
            for(int j = 0; j < i; j++){
                //cout << "i = " << i << "\nj = " << j << endl;
                if(arr[i] == arr[j]){
                    //cout << "arr[" << i << "] == arr[" << j << "] == " << arr[i] << endl;
                    arr[i] = rand()%10+48;
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

char* cnv2Arr(int n, char arr[], int codeLen){
    int num = n;
    int digit;
    for(int i=codeLen-1; i>=0; i--){
        digit = num%10;
        arr[i] = char(digit+48);
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
            //cout << "got one!\n";
            //cout << "arr1[" << i << "] == arr2[" << i << "] == " << arr1[i] << endl;
            correct++;
            continue;
        }
        for(int j=0; j<codeLen; j++){
            if(arr1[i] == arr2[j]){
                //cout << "gettin close..\n";
                //cout << "arr1[" << i << "] == arr2[" << j << "] == " << arr1[i] << endl;
                //cout << "checked[" <<  j << "] = " << checked[j] << endl;
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

bool cmpArr(string arr1, string arr2, char &rr, char &rw){
    int correct = 0;
    int close = 0;
    int codeLen = 4;
    bool checked[codeLen];
    
    //Initialize the boolean array to be false
    for(int i=0; i<codeLen; i++){
        checked[i] = false;
    }
    
    for(int i=0; i<codeLen; i++){
        if(arr1[i] == arr2[i]){
            //cout << "got one!\n";
            //cout << "arr1[" << i << "] == arr2[" << i << "] == " << arr1[i] << endl;
            correct++;
            continue;
        }
        for(int j=0; j<codeLen; j++){
            if(arr1[i] == arr2[j]){
                //cout << "gettin close..\n";
                //cout << "arr1[" << i << "] == arr2[" << j << "] == " << arr1[i] << endl;
                //cout << "checked[" <<  j << "] = " << checked[j] << endl;
                //Ensure the same number isn't flagged as close twice or more.
                if(checked[j] == false){
                    close++;
                    checked[j] = true;
                }
                break;
            }
        }
    }
    
    rr = correct;
    rw = close;
    //cout << result << endl;
    if(rr == 4) return false;
    return true;
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

string AI(char rr,char rw){
    //Define helper functions here
    void (*print)(string [],char [],char [],int,int)=
        [] (string g[],char r[],char w[],int nb,int ne){ 
            for(int i=nb;i<=ne;i++){
                cout<<g[i]<<" "
                    <<static_cast<int>(r[i])<<" "
                    <<static_cast<int>(w[i])<<endl;
            }
    };
    
    //Save the historical values of guesses and results
    static const int SIZE=10000;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    
    //Calculate the guess
    int n1000=(guess-guess%1000)/1000;
    int n100=(guess-guess%100)/100-10*n1000;
    int n10=(guess%100-guess%10)/10;
    int n1=guess%10;
    sGuess[0]=n1000+'0';
    sGuess[1]=n100+'0';
    sGuess[2]=n10+'0';
    sGuess[3]=n1+'0';
    aGuess[++guess]=sGuess;//Save the result
    
    //Return the result
    return sGuess;
}