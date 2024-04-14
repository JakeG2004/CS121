/*
showDB.cpp
A file to read in shows from large.dat and store them in a tree
Jake Gendreau
April 13, 2024
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

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Incorrect usage! Usage: ./a.out <path_to_datafile>. Exiting program..." << endl;
        exit(-1);
    }

    //read in the tree from the data file
    BSTree showTree = readFile(argv[1]);

    //cout << "All show titles in the tree:" << endl;
    //showTree.printShows(showTree.head);

    cout << "All actors in Parry Mason" << endl;
    showTree.printActorsInShow(showTree.head, "Perry Mason");

    //the issue here is that i only account for one space when adding the name, not multiple
    cout << "All actors in The Office" << endl;
    showTree.printActorsInShow(showTree.head, "The Office");

    cout << "All actors in The Prisoner" << endl;
    showTree.printActorsInShow(showTree.head, "The Prisoner");

    cout << "All actors in Gilligan's Island" << endl;
    showTree.printActorsInShow(showTree.head, "Gilligan's Island");

    cout << "All actors in Parry M*A*S*H" << endl;
    showTree.printActorsInShow(showTree.head, "M*A*S*H");

    cout << "All Shows with Raymond Burr" << endl;
    showTree.printShowsWithActor(showTree.head, "Raymond Burr");

    //TODO: Handle duplicate cases
    cout << "All Shows with Bill Mumy" << endl;
    showTree.printShowsWithActor(showTree.head, "Bill Mumy");

    //TODO: The name has whitespace at the end
    cout << "All Shows with Bob Newhart" << endl;
    showTree.printShowsWithActor(showTree.head, "Bob Newhart");

    cout << "All Shows with Jerry Seinfeld" << endl;
    showTree.printShowsWithActor(showTree.head, "Jerry Seinfeld");

    //TODO: Also doesn't appear when he should
    cout << "All Shows with Bob Denver" << endl;
    showTree.printShowsWithActor(showTree.head, "Bob Denver");

    showTree.deleteTree(showTree.head);
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

        // Skip empty lines
        while(curLine == "") 
        {
            if(!getline(infile, curLine)) {
                // Exit loop if end of file is reached
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
        if(!showTree.isInTree(showTree.head, newShow.name))
        {
            showTree.insertNode(showTree.head, newShow);
        }

        else
        {
            //delete any allocated memory from linked list in duplicate show
            NodePtr p = newShow.actorHead;
            NodePtr q = p;

            while(p != NULL)
            {
                p = p -> next;
                q -> next = NULL;
                delete q;
                q = p;
            }
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