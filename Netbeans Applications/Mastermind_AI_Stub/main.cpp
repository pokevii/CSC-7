/*
    Dr. Mark E. Lehr
    CSC 7 Template for Mastermind AI
    May 11th, 2021
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=set();
    cout << code << " | " << endl;
    rr=rw=0;
    
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
       //cout << "The AI has guessed " << cGuess << ". || ";
    }while(eval(code,guess,rr,rw));
    //Check evaluation
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    guess=AI(rr,rw);
    /*cout<<code<<endl;
    for(int i=0;i<10000;i++){
        guess=AI(0,0);
        eval(code,guess,rr,rw);
        cout<<setw(5)<<code<<setw(5)<<guess
                <<setw(2)<<static_cast<int>(rr)
                <<setw(2)<<static_cast<int>(rw)<<endl;
    }*/
    
    //Exit the program
    return 0;
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
    
    auto swap = [](char &c1, char &c2)
    {
        char temp;
        temp = c1;
        c1 = c2;
        c2 = temp; 
    };
    
    //Save the historical values of guesses and results
    static const int SIZE=10000;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    
    //Variables added by me
    static int num = 0;                //number incremented until all numbers are found
    static int fgDigit[4];             //foreground digits
    static int found = 0;              //found digits
    static bool solveState = false;    //bool that tells AI to start solving
    static int x = 0;                  //variables for swapping
    static int y = 0;
    static int bGuess = 0;     //Best guess so far.

    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    
    //If all digits have been found & more correct digits are found than last 
    //guess, make the best guess the current guess.
    if(found == 4){
        if(rr > grr[bGuess]){
            cout << int(rr) << " (code: " << aGuess[guess] << ") > " << 
                    int(grr[guess-1]) << " (code: " << aGuess[guess-1] << ") | ";
            //cout << "The best guess is " << sGuess << ". | ";
            bGuess = guess;
        }
    }
    cout << " guess " << guess << " | " << aGuess[bGuess] << " | ";
    
    //If solve state is true, begin figuring out the code by swapping.
    if (solveState == true) {
        //Set the guess-to-be equal to the best previous guess immediately.
        sGuess = aGuess[bGuess];
        
        //If x is 2, set x and y back to 0.
        if(x == 2){ x = 0; y = 0; }
        
        //If the two digits to be swapped are equal, increase y.
        while(sGuess[x] == sGuess[y]){
            y++;
        }
        
        //If x is equal to y, increase y. They cannot be identical.
        if(x == y) y++;

        //If y is greater than 3 (the size of the guess string) increment x by 1
        //and set y to x + 1.
        if(y > 3){
            x++;
            y = x + 1;
        }
        
        cout << "x = " << x << " | y = " << y << " | ";
        swap(sGuess[x], sGuess[y]);
        y++;
    }
    
    //If a number has been found during the initial search, add it to fgDigits.
    if (grr[guess] + grw[guess] > 0 && found < 4) {
        int queue = grr[guess] + grw[guess];
        while (queue--){
            fgDigit[found] = num - 1;
            found++;
        }
        cout << "(There are " << int(rr) << " " << int(num - 1) << "s in the code.) | ";
    }
    
    /*If all numbers have been found cout them (comment this out)
    if(found == 4 && solveState == false){
        cout << "(All numbers have been found: ";
        for(int i=0; i<found; i++){
            cout << fgDigit[i];
        }
        cout << ") | ";
    }*/
    
    //Cycle through 0000 ... 9999 until all digits are found.
    if(found < 4){
        sGuess[0]=num+'0';
        sGuess[1]=num+'0';
        sGuess[2]=num+'0';
        sGuess[3]=num+'0';
    } 
    //Once all digits have been found, set the guess to these digits and enable solveState
    else if (found == 4 && solveState == false){
        sGuess[0]=fgDigit[0]+'0';
        sGuess[1]=fgDigit[1]+'0';
        sGuess[2]=fgDigit[2]+'0';
        sGuess[3]=fgDigit[3]+'0';
        bGuess = guess+1;    //make this the automatic best guess.
        solveState = true;
    }
    
    aGuess[++guess]=sGuess;//Save the result
    
    //Increment num until we've found all digits
    if(found < 4) num++;

    //Return the result
    return sGuess;
}

bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    cout << int(rr) << " " << int(rw) << endl;
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}


