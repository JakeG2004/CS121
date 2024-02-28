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
#include "stack.h"

using namespace std;

//prototypes
string getInfix();
string cleanExpression(string);

int getPrecedence(char);

void initStack(Stack&);

void handleClosedParens(Stack&, string&);
void handleOperators(Stack&, char, string&);
void inToPost(string&);

bool isNum(char);
bool isGreaterPrecedence(char, char);
bool isInString(char, string);

int main()
{

    //prompt user
    string infix = getInfix();

    //repeat until quit keyword is met
    while(infix != "quit")
    {
        inToPost(infix);
        infix = getInfix();
    }

    cout << "Quitting Program..." << endl;

}

void inToPost(string &infix)
{
    //init stack
    Stack stack = Stack();
    initStack(stack);

    //init needed variables
    char token;
    string postfix;

    //for every character in the infix string
    for(int i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];

        //handle open parens
        if(token == '(')
            stack.push('(');

        //if token is an operand, append it and move on
        else if(isNum(token))
            postfix += token;

        //handle closed parens
        else if(token == ')' && stack.size() > 0)
            handleClosedParens(stack, postfix);

        //handle operators
        else
            handleOperators(stack, token, postfix);

    }

    //free the stack
    stack.deleteList();

    //print the converted expression
    cout << "Converted to Postfix: " << postfix << endl;
}

void handleOperators(Stack &stack, char token, string &postfix)
{
    char tmpChar;

    //iterate through whole stack, organizing operators as it goes
    while(stack.size() > 0 && isGreaterPrecedence(stack.peek(), token))
    {
        tmpChar = stack.pop();
        if(tmpChar != '(')
            postfix += tmpChar;
    }
    stack.push(token);
}

void handleClosedParens(Stack &stack, string &postfix)
{
    char tmpChar = stack.pop();

    //add everything in the stack on a closed parens
    while(tmpChar != '(')
    {
        postfix += tmpChar;
        if(stack.size() > 0)
            tmpChar = stack.pop();
    }
}

int getPrecedence(char op)
{
    //use PEMDAS to define priority
    if(op == '/' || op == '*')
        return 2;

    if(op == '+' || op == '-')
        return 1;

    return 0;
}

bool isGreaterPrecedence(char stackChar, char token)
{
    //grab precedence values
    int tokenVal = getPrecedence(token);
    int stackVal = getPrecedence(stackChar);

    //compare and return
    return(stackVal >= tokenVal);
}

bool isNum(char token)
{
    //true if token is a num, false otherwise
    if(token >= '0' && token <= '9')
        return true;
    return false;
}

void initStack(Stack &stack)
{
    stack.push('(');
}

string getInfix()
{
    string tmpString;
    string buffer;

    //prompt the user and get the expression
    cout << "Enter your Infix expression or type \"quit\" to exit: ";
    getline(cin, tmpString);

    //return if quit
    if(tmpString == "quit"){
        return(tmpString);
    }

    return(cleanExpression(tmpString));
}

string cleanExpression(string expression)
{
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

    //add a ')' to the end of the infix expression
    buffer += ')';

    return buffer;
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