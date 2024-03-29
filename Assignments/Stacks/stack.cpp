/*
*-------------------------------------------------------------------------------
*Stack.cpp
*
*CS121.Bolden......................GCC 11.4.0......................Jake Gendreau
*Feb 27, 2024.....Pop!_OS 22.04 / Core i9-13900H.....gend0188@vandals.uidaho.edu
*
*Use a stack to convert a given infix expression to a postfix expression
*-------------------------------------------------------------------------------
*/

//dependencies
#include <iostream>
#include "stackADT.h"

using namespace std;

//prototypes
string cleanExpression(string);

int getPrecedence(char);

void initStack(Stack&);
void handleClosedParens(Stack&, string&);
void handleOperators(Stack&, string, string&);
void inToPost(Stack&);

bool isNum(string);
bool isGreaterPrecedence(string, string);
bool isInString(char, string);
bool getInfix(Stack&);
bool isWellFormed(string);

int main()
{

    //prompt user
    Stack infix = Stack();
    
    //repeat until quit keyword is met
    while(getInfix(infix))
    {
        inToPost(infix);
    }

    cout << "Exiting Program..." << endl;

    infix.deleteStack();
}

string cleanExpression(string expression)
{
    //check for quit
    if(expression == "quit")
        return("quit");

    string buffer;

    //define valid characters
    string validChars = "()0123456789*+-/";

    //iterate through expression, comparing to validChars along the way
    for(int i = 0; expression[i] != '\0'; i++)
    {
        if(isInString(expression[i], validChars))
        {
            //add to buffer if validChar
            buffer += expression[i];
        }
    }

    //error checking
    if(buffer.size() == 0)
    {
        cout << "Invalid statement." << endl;
        return("quit");
    }

    return buffer;
}

int getPrecedence(string op)
{
    if(op.size() != 1){
        cout << "ERROR: Invalid size in getPrecedence" << endl;
        exit(-1);
    }
    //use PEMDAS to define priority
    if(op[0] == '/' || op[0] == '*')
        return 2;

    if(op[0] == '+' || op[0] == '-')
        return 1;

    return 0;
}

void initStack(Stack &stack)
{
    stack.pushFront("(");
}

void handleClosedParens(Stack &stack, string &postfix)
{
    string stackToken = stack.pop();

    //add everything in the stack on a closed parens
    while(stackToken != "(")
    {
        postfix += stackToken + " ";

        if(stack.size() > 0)
            stackToken = stack.pop();
    }
}

void handleOperators(Stack &stack, string token, string &postfix)
{
    string stackToken;

    //iterate through whole stack, organizing operators as it goes
    while(stack.size() > 0 && isGreaterPrecedence(stack.peek(), token))
    {
        stackToken = stack.pop();
        if(stackToken != "(")
            postfix += stackToken + " ";
    }

    stack.pushFront(token);
}

void inToPost(Stack &infix)
{
    //init stack
    Stack stack = Stack();
    initStack(stack);

    //init needed variables
    string token;
    string postfix;

    //for every character in the infix string
    while(infix.size() > 0)
    {
        token = infix.pop();

        //handle open parens
        if(token == "(")
            stack.pushFront("(");

        //if token is an number, append it and move on
        else if(isNum(token))
            postfix += token + " ";

        //handle closed parens
        else if(token == ")" && stack.size() > 0)
            handleClosedParens(stack, postfix);

        //handle operators
        else
            handleOperators(stack, token, postfix);

    }

    //free the stack
    stack.deleteStack();
    infix.deleteStack();

    //print the converted expression
    cout << "Converted to Postfix: " << postfix << endl;
}

bool isNum(string token)
{
    for(int i = 0; token[i] != '\0'; i++)
    {
        //true if token is a num, false otherwise
        if(token[i] < '0' || token[i] > '9')
            return false;
    }

    return true;
}

bool isGreaterPrecedence(string stackChar, string token)
{
    //grab precedence values
    int tokenVal = getPrecedence(token);
    int stackVal = getPrecedence(stackChar);

    //compare and return
    return(stackVal >= tokenVal);
}

bool isInString(char query, string string)
{
    //iterate through string, return true if query in string
    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == query)
            return true;
    }
    return false;
}

bool getInfix(Stack &stack)
{
    string tmpString;
    string buffer;
    int offset = true;

    //prompt the user and get the expression
    cout << "Enter your Infix expression or type \"quit\" to exit: ";

    //get the string
    getline(cin, tmpString);

    //clean it
    tmpString = cleanExpression(tmpString);

    //error checking
    if(tmpString == "quit"){
        return 0;
    }

    if(!isWellFormed(tmpString))
    {
        cout << "ERROR: String not well formed" << endl;
        return 0;
    }

    //create substrings and add them to the temp stack
    for(int i = 0; tmpString[i] != '\0'; i++)
    {
        buffer = "";

        //handle non-numbers
        if(!isNum(string(1, tmpString[i])))
        {
            buffer = tmpString[i];
        }

        //group numbers together
        while(isNum(string(1, tmpString[i])) && tmpString[i] != '\0')
        {
            buffer += tmpString[i];

            //iterate through rest of list
            i++;
            offset++;
        }

        //set i to where it should be
        if(offset > 0){
            offset = 0;
            i--;
        }

        //write it to the stack
        stack.pushBack(buffer);
    }

    stack.pushBack(")");

    return 1;
}

bool isWellFormed(string expression)
{
    int balanced = 0;

    for(int i = 0; expression[i] != '\0'; i++)
    {
        if(expression[i] == '(')
            balanced++;
        else if(expression[i] == ')')
            balanced--;
    }

    return(balanced == 0);
}