/*
Stack.cpp

CS121.Bolden......................GCC 11.4.0......................Jake Gendreau
Feb 27, 2024.....Pop!_OS 22.04 / Core i9-13900H.....gend0188@vandals.uidaho.edu

Use a stack to convert a given infix expression to a postfix expression
-------------------------------------------------------------------------------
*/


#include <iostream>
#include "stack.h"

using namespace std;

string getInfix();
string cleanExpression(string);

void initStack(Stack&);

bool isNum(char);

int isGreaterPrecedence(char, char);
void handleClosedParens(Stack&, string&);
void handleOperators(Stack&, char, string&);
void inToPost(string&);

int main(){

    string infix = getInfix();

    while(infix != "quit"){
        inToPost(infix);
        infix = getInfix();
    }

}

void inToPost(string &infix){
    char token;
    string postfix;

    //Step 0: init stack
    Stack stack = Stack();
    initStack(stack);

    //for every character in the infix string
    for(int i = 0; infix[i] != '\0'; i++){
        token = infix[i];

        if(token == '('){
            stack.push('(');
        }

        //if token is an operand, append it and move on
        else if(isNum(token)){
            postfix += token;
        }

        else if(token == ')' && stack.size() > 0){
            handleClosedParens(stack, postfix);
        }


        else{
            handleOperators(stack, token, postfix);
        }

    }

    stack.deleteList();

    cout << "Converted to Postfix: " << postfix << endl;
}

void handleOperators(Stack &stack, char token, string &postfix){
    char tmpChar;

    while(stack.size() > 0 && isGreaterPrecedence(stack.peek(), token)){
        tmpChar = stack.pop();
        if(tmpChar != '(')
            postfix += tmpChar;
    }
    stack.push(token);
}

void handleClosedParens(Stack &stack, string &postfix){
    char tmpChar = stack.pop();

    while(tmpChar != '('){
        postfix += tmpChar;
        if(stack.size() > 0){
            tmpChar = stack.pop();
        }
    }
}

int isGreaterPrecedence(char stackChar, char token){
    //MAKE PRETTIER
    int tokenVal = 0;
    int stackVal = 0;

    switch(stackChar){
        case ')':
            stackVal = -1;
            break;
        case '(':
            stackVal = 0;
            break;
        case '+':
            stackVal = 2;
            break;
        case '-':
            stackVal = 2;
            break;
        case '*':
            stackVal = 4;
            break;
        case '/':
            stackVal = 4;
            break;
    }

    switch(token){
        case ')':
            tokenVal = 0;
            break;
        case '(':
            tokenVal = 5;
            break;
        case '+':
            tokenVal = 1;
            break;
        case '-':
            tokenVal = 1;
            break;
        case '*':
            tokenVal = 3;
            break;
        case '/':
            tokenVal = 3;
            break;
    }

    return(stackVal >= tokenVal);
}

bool isNum(char token){
    //doesn't handle negative numbers at the moment
    if(token >= '0' && token <= '9')
        return true;
    return false;
}

void initStack(Stack &stack){
    stack.push('(');
}

string getInfix(){
    string tmpString;
    string buffer;

    //prompt the user and get the expression
    cout << "Enter your Infix expression or type \"quit\" to exit: ";
    getline(cin, tmpString);

    if(tmpString == "quit"){
        return(tmpString);
    }

    return(cleanExpression(tmpString));
}

//function is at 4 indents, either optimise or functionalise
string cleanExpression(string expression){
    string buffer;

    char validChars[] = "()0123456789*+-/";

    //check each character of the expression against the list of valid chars
    for(int i = 0; expression[i] != '\0'; i++){
        for(int j = 0; validChars[j] != '\0'; j++){

            //add to buffer if it is in valid chars
            if(expression[i] == validChars[j])
                buffer += expression[i];
        }
    }

    if(buffer.size() == 0){
        cout << "Invalid statement. Exiting program..." << endl;
        exit(-1);
    }

    //add ) to the end of the infix expression
    buffer += ')';

    return buffer;
}








