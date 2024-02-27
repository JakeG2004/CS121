#include <iostream>
#include "stack.h"

using namespace std;

string getInfix();
string cleanExpression(string);

string toPostfix(string, Stack&);

void initStack(Stack&);

bool isNum(char);
bool greaterPresidence(char, char);

void processOperators(char, Stack&, string&);
void processClosedParens(string&, Stack&);

int main(){
    Stack stack = Stack();

    //1) push '(' onto the stack
    initStack(stack);

    //2) add a ')' to the end of the infix expression
    string infix = getInfix();
    cout << toPostfix(infix, stack) << endl;
}

string toPostfix(string infix, Stack &stack){
    string postfix;
    char tmpChar = '\0';
    char token;
    int index = 0;

    //3) while the stack is not empty
    while(stack.size() > 0){
        //4) get (read) the next token from the infix expression
        token = infix[index];
        //5) if the token is a '('
        if(token == '('){
            cout << "Adding (" << endl;
            //6) push token onto the stack
            stack.push(token);
        }
        //7) else if the token is a number
        else if(isNum(token)){
            cout << "adding number" << endl;
            //8) add the number to the end of the postfix expression
            postfix += token;
        }
        //9) else if the token is a ')'
        else if(token == ')'){
            processClosedParens(postfix, stack);
        }
        //14) else (the token must be an operator)
        else{
            processOperators(token, stack, postfix);
        }

        index++;
    }

    return postfix;
}

void processClosedParens(string &postfix, Stack &stack){
    char tmpChar;
    cout << "handling )" << endl;
    //10) pop the element c from the stack
    tmpChar = stack.pop();
    //11) while c is not a '('
    while(tmpChar != '(' && stack.size() > 0){
        //12) place c at the end of the postfix expression
        postfix += tmpChar;
        //13) pop another element c from the stack
        tmpChar = stack.pop();
    }
}

void processOperators(char token, Stack &stack, string &postfix){
    char tmpChar;
    cout << "handling operators" << endl;
    //15) while the top of the stack is an operator with precendence greater than or equal to the token
    while(greaterPresidence(stack.peek(), token) && stack.size() > 0){
        cout << greaterPresidence(stack.peek(), token) << endl;
        //16) pop the element c from the stack
        tmpChar = stack.pop();
        //17) place c at thet end of the postfix expression

        postfix += tmpChar;

        cout << stack.size() << endl;
    }
    cout << "almose" << endl;
    //18) push the token onto the stack
    stack.push(token);
    cout << "done" << endl;
}

bool greaterPresidence(char char1, char char2){
    int op1Priority = 0;
    int op2Priority = 0;

    //using PEMDAS for order of operations

    if(char1 == '*' || char1 == '/'){
        op1Priority = 1;
    }

    if(char2 == '*' || char2 == '/'){
        op2Priority = 1;
    }

    return(op1Priority >= op2Priority);
}

bool isNum(char tmpChar){
    if(tmpChar >= 48 && tmpChar <= 57)
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
    cout << "Enter your Infix expression: ";
    getline(cin, tmpString);

    return(cleanExpression(tmpString));
}

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








