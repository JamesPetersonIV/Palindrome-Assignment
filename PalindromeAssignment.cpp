#include<iostream>

#include<string.h>

#include<ctype.h>

using namespace std;

#define MAX 50 //define maximum length 50

class PPStack { //creating class stack

private:

char data[MAX],s[MAX]; //private members

int above,howLong,seq;

void pushData(char);//private method push to add the character in the stack

char popData(); //private method pop to add the character in the stack

public:

PPStack() 
{ //a default constructor

above=-1;

howLong=0;

seq=0;

}

void getString(); //get string method to take input string from user

void PalindromeChecker(); //method to check the string is palindrome or not

void ejectoStringo();   

void ReverseDisplay(); //method to display the string in reverse order

};

int main() //main function

{

PPStack obj; //creating the object of the stack class

obj.getString();//calling the get string method

obj.ejectoStringo();//calling the extract string method

obj.ReverseDisplay();//calling ReverseDisplay method

obj.PalindromeChecker();//calling the PalindromeChecker method

return 0;

}

void PPStack::getString()

{

cout<<"\n Enter a String: "; //taking the user input

cin.getline(s,MAX); //assign to the s variable of class stack

howLong=strlen(s);//finds the length of the s string and assigns to the length variable

}

void PPStack::ejectoStringo()

{

char temporary[MAX];

int i,j;

for(i=0; i<howLong; i++) //copying the all string to temporary string

{

temporary[i]=s[i];

}

j=0;

for(i=0; i<howLong; i++ )  

{

if(isalpha(temporary[i])) //checking the character is alphabet or not

{

s[j]=tolower(temporary[i]);//if alphabet then convert to uppercase and assign to the s

j++;

}

}

howLong=j; //update length with new s length

}

void PPStack::PalindromeChecker()

{

for(int i=0; i<howLong; i++)

pushData(s[i]);//push one by one character to stack pushData

for(int i=0; i<howLong; i++)

{

if(s[i]==popData())//here now checking each character of s to character popped from the stack

seq++; //if both are same then increment the count

}

if(seq==howLong) //if count and length both are same then its palindrome

{

cout<<"\n\nEntered string is a Palindrome. \n";

}

//if not then

else cout<<"\n\nEntered string is not a Palindrome. \n";

}

void PPStack::ReverseDisplay()//method to print the string in reverse order

{

cout<<"\n\nReverse String is:";

for(int i=howLong-1; i>=0; i--)

  

cout<<s[i];

}

void PPStack::pushData(char temporary) //push the data into the stack

{

if(above==MAX-1) //checking for the overflow condition

{

cout<<"\n Stack Overflow";

return;

}

above++;

data[above]=temporary;//adding the character to the stack

}

char PPStack::popData() //method to pop the last character from the stack

{

if(above==-1) //checking for under flow condition

{

cout<<"\n Stack Underflow";

char ch='\n';

return ch;

}

char temporary=data[above];//pop out the last character from the stack

above--;

return temporary; //return to popped character

}
