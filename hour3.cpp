#include <iostream>
#include <string>

int doubleadding(const std::string USER); 
/*
Double every second digit from right to left 
(if doubled num is 2 digits split the number)
add all single digits from step before
*/

int oddadding(const std::string USER);
//Add all off the odd numbered digits (staring from 1) from right to left

void sumofsum(int DOUBLENUM, int ODDNUM);
/*
Sum results from other 2 functions
If sum is divisible by 10, card number is valid
*/


int main(){
    std::string USER;
    
    std::cout << "---------------------------------------------------" << '\n';
    std::cout << "Welcome to the bank please enter your card number: " << '\n';

    std::cin >> USER;
    
    int DOUBLENUM = doubleadding(USER);
    
    int ODDNUM = oddadding(USER);

    sumofsum(DOUBLENUM, ODDNUM);

    return 0;
}

int doubleadding(const std::string USER){
    int DOUBLENUM = 0;
    
    for (int i = USER.size()-2; i >= 0; i = i - 2){
        

        if(((USER[i] - '0') * 2) >= 10){
            DOUBLENUM = (((USER[i] - '0') * 2)/10 % 10) + (((USER[i] - '0') * 2) % 10) + DOUBLENUM;
            
        }
        else{
            DOUBLENUM = ((USER[i] - '0') * 2) + DOUBLENUM;
        }
        
    }
    
    return DOUBLENUM;
    
}

int oddadding(const std::string USER){
    int ODDNUM = 0;
    
    for (int i = USER.size()-1; i >= 0; i = i - 2){
        
        ODDNUM = ((USER[i] - '0')) + ODDNUM;
        
        
    }
    
    return ODDNUM;

}

void sumofsum(int DOUBLENUM, int ODDNUM){

    int checker = DOUBLENUM + ODDNUM;

    if(checker % 10 == 0){
        std::cout << "This card is valid" << '\n';
        std::cout << "---------------------------------------------------" << '\n';
    }
    else{
        std::cout << "This card is not valid!" << '\n';
        std::cout << "---------------------------------------------------" << '\n';
    }

}


