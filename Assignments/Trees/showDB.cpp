/* showDB.cpp
 *
 * CS 121.Bolden...gcc 11.4.0...Jake Gendreau
 * 04/24/24 ...Core i9 13900H POP!_os 22.04 ...gend0188@vandals.uidaho.edu
 *
 * A program to store info about shows in a tree
 *---------------------------------------------------------
 */

#include <iostream>
#include <fstream>
#include "BSTree.cpp"

using namespace std;

BSTree readFile(string);

string getName(string);
string removeFollowingWhiteSpace(string);

int getStartDate(string);
int getEndDate(string);

void insertActor(NodePtr&, string);
void deleteActorList(NodePtr&);

void printActorsInShow(BSTree, string);
void printShowsWithActor(BSTree, string);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Usage: ./a.out <path_to_datafile>. Exiting program..." << endl;
        exit(-1);
    }

    //read in the tree from the data file
    BSTree showTree = readFile(argv[1]);

    cout << "All show titles in the tree:" << endl;
    showTree.printShows();

    //print actors in show
    printActorsInShow(showTree, "Perry Mason");
    printActorsInShow(showTree, "The Prisoner");
    printActorsInShow(showTree, "Gilligan's Island");
    printActorsInShow(showTree, "M*A*S*H");

    //print shows with actor
    printShowsWithActor(showTree, "Raymond Burr");
    printShowsWithActor(showTree, "Bill Mumy");
    printShowsWithActor(showTree, "Bob Newhart");
    printShowsWithActor(showTree, "Jerry Seinfeld");
    printShowsWithActor(showTree, "Bob Denver");

    showTree.deleteTree();
}

BSTree readFile(string filepath)
{
    BSTree showTree = BSTree();
    string curLine;

    //open file
    ifstream infile;
    infile.open(filepath);

    //ensure that file exists and is open
    if(!infile.is_open())
    {
        cout << "Error opening file at " << filepath << ". Exiting program..." << endl;
        exit(-1);
    }

    //While not at the end of the file
    while(getline(infile, curLine))
    {
        //make new show for each 
        Show newShow = Show();

        //skip empty lines
        while(curLine == "") 
        {
            if(!getline(infile, curLine)) {
                //exit loop if end of file is reached
                break;
            }
        }

        //check for end of file
        if(infile.eof()) 
        {
            break;
        }

        //get name and dates
        newShow.name = removeFollowingWhiteSpace(getName(curLine));
        newShow.startDate = getStartDate(curLine);
        newShow.endDate = getEndDate(curLine);

        //get genre
        getline(infile, curLine);
        newShow.genre = removeFollowingWhiteSpace(curLine);

        //get link
        getline(infile, curLine);
        newShow.link = removeFollowingWhiteSpace(curLine);

        //get actors / actresses
        while(curLine != "")
        {
            getline(infile, curLine);
            insertActor(newShow.actorHead, removeFollowingWhiteSpace(curLine));
        }

        //handle duplicates
        if(!showTree.isInTree(newShow.name))
        {
            showTree.insertNode(newShow);
        }

        else
        {
            deleteActorList(newShow.actorHead);
        }
    }

    return showTree;
}

string getName(string curLine)
{
    string name = "";

    //read through string, stopping at parenthesis
    //use curLine[i + 1] to account for the space between the title and dates
    for(int i = 0; curLine[i + 1] != '('; i++)
    {
        name += curLine[i];
    }

    return name;
}

string removeFollowingWhiteSpace(string curLine)
{
    string returnString = "";

    //get size of string
    int numChars = 0;
    for(int i = 0; curLine[i] != '\0'; i++)
    {
        numChars++;
    }

    //cout << "numChars in " << curLine << ": " << numChars << endl;

    //get whitespace
    int whiteSpace = 0;
    //check for tabs and spaces
    for(int i = numChars - 1; i >= 0 && (curLine[i] == ' ' || curLine[i] == '\t'); i--)
    {
        whiteSpace++;
    }

    for(int i = 0; i < numChars - whiteSpace; i++)
    {
        returnString += curLine[i];
    }

    return returnString;
}

int getStartDate(string curLine)
{
    string startDate = "";

    //navigate until first date is met, defined by open parens
    int i = 0;
    while(curLine[i - 1] != '(')
    {
        i++;
    }

    //add the following four digits to the return string
    for(int x = 0; x < 4; x++)
    {
        startDate += curLine[i + x];
    }

    //return the stoi conversion of startDate
    return stoi(startDate);
}

int getEndDate(string curLine)
{
    string endDate = "";

    //get size of string
    int numChars = 0;
    for(int i = 0; curLine[i] != ')'; i++)
    {
        numChars++;
    }

    //add the first four of the last 5 characters to the string
    for(int i = numChars - 4; i < numChars; i++)
    {
        endDate += curLine[i];
    }

    //return the stoi conversion of endDate
    return stoi(endDate);
}

void insertActor(NodePtr &head, string actorName)
{
    //handle empty name
    if(actorName == "")
        return;

    //insert new actor at the beginning
    NodePtr n = new node();

    n -> data = actorName;
    n -> next = head;

    head = n;
}

void deleteActorList(NodePtr &head)
{
    //delete linked list of actors
    NodePtr p = head;
    NodePtr q = p;

    while(p != NULL)
    {
        p = p -> next;
        q -> next = NULL;
        delete q;
        q = p;
    }
}

void printActorsInShow(BSTree showTree, string showName)
{
    cout << "All actors in " << showName << endl;
    showTree.printActorsInShow(showName);
}

void printShowsWithActor(BSTree showTree, string actorName)
{
    cout << "All Shows with " << actorName << endl;
    showTree.printShowsWithActor(actorName);
}