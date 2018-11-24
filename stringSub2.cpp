/**
 * Title: Machine Problem #1
 * Author: Emmanuel Thernize
 * Date: 10/17/18
 * CS451 Fa18
 */

#include <iostream>
using namespace std;

#define STRMAX 80

int main(){
    char num1[STRMAX], num2[STRMAX], answer[STRMAX];
    char *num1_ptr, *num2_ptr, *answer_ptr;
    int length1 = 0, length2 = 0, proper = 0;

    answer_ptr = answer + STRMAX;
    *answer_ptr-- = 0;

    while(!proper){

        //Input first number
        cout << "Please enter the first number : ";
        num1_ptr = num1;
        while((*num1_ptr++ = cin.get()) != '\n')
            length1++;
        *--num1_ptr = 0;
        num1_ptr--;

        //Input second number
        cout << "Please enter the second number : ";
        num2_ptr = num2;
        while((*num2_ptr++ = cin.get()) != '\n')
            length2++;
        *--num2_ptr = 0;
        num2_ptr--;

        //Checking Number Authenticity
        num1_ptr = num1;
        num2_ptr = num2;
        if(length1 > length2)
            proper++;
        else if(length1 == length2){
            if(*num1_ptr <= *num2_ptr){
                while(*num1_ptr && !proper)
                    if(*num1_ptr++ < *num2_ptr++)
                        *num1_ptr = 0;  
                    else if(!*num1_ptr)
                            proper++;    
            }else
                proper++;
        }
        if(!proper)
            cout << "\n\tMake Sure that your first number is greater than your second number!\n\n";   
    }

    //Pritint Equation
    num1_ptr = num1;
    while(*num1_ptr)
        cout << *num1_ptr++;
    cout << " - ";

    num2_ptr = num2;
    while(*num2_ptr)
        cout << *num2_ptr++;
    cout << " = ";

    num1_ptr--;
    num2_ptr--;

    //Doing Subtraction
    while(!(num1_ptr < num1)){
        if(num2_ptr < num2){
            if(*num1_ptr < '0'){
                *num1_ptr-- = '9';
                (*num1_ptr++)--;
            }
            *answer_ptr-- = *num1_ptr--;
        }else if(*num1_ptr >= *num2_ptr)
            *answer_ptr-- = (*num1_ptr--) - (*num2_ptr--) + '0';
        else{
            *answer_ptr-- = 10 + (*num1_ptr--) - (*num2_ptr--) + '0';
            (*num1_ptr)--;
        }
    }

    //Print Answer
    answer_ptr++;
    while(*answer_ptr == '0')
            answer_ptr++;
    if(!*answer_ptr)
        answer_ptr--;
    cout << answer_ptr << endl;

    return 0;
}