/*
mazeSolver.cpp
A program to solve mazes using an A* implementation
Jake Gendreau
April 1, 2024
*/

//boilerplate
#include <iostream>
#include <fstream>
#include "queueADT.cpp"

using namespace std;

//cell struct for storing maze
struct cell
{
    char type;
    bool visited = false;
    int x;
    int y;
    int cost;
};

//prototypes
int getDimension(string);
cell** getMaze(string, int);
void printMaze(cell**, int);
cell findStart(cell**, int);

/*
start - S
goal - G
wall - #
blank - .
*/

int main(int argc, char* argv[])
{
    //check proper usage
    if(argc != 2)
    {
        cout << "USAGE: ./a.out <map.txt>. Exiting program..." << endl;
        exit(-1); 
    }

    string fileName = argv[1];

    //init array
    int dimension = getDimension(fileName);
    cell** maze = getMaze(fileName, dimension);

    printMaze(maze, dimension);

    cell agent = findStart(maze, dimension);

    Queue queue = Queue();
}

int getDimension(string fileName)
{
    //open file
    string word;
    fstream file;

    file.open(fileName);

    //check that file is valid and open
    if(!file.is_open())
    {
        cout << "ERROR OPENING FILE: " << fileName << ". Exiting program..." << endl;
        exit(-1);
    }

    //extract just the first word
    file >> word;

    //close the file
    file.close();

    //return the dimension
    return stoi(word);
}

cell** getMaze(string fileName, int dimension)
{
    //open file
    string line;
    fstream file;

    file.open(fileName);

    //check that file is valid and open
    if(!file.is_open())
    {
        cout << "ERROR OPENING FILE: " << fileName << ". Exiting program..." << endl;
        exit(-1);
    }

    //adjust file pointer to be start of the maze
    getline(file, line);

    cell** maze = new cell*[dimension];

    //read in the map
    for(int i = 0; i < dimension; i++)
    {
        maze[i] = new cell[dimension];
        //get this line
        getline(file, line);
        for(int j = 0; j < dimension; j++)
        {
            //write the chars of the current line into the array
            maze[i][j].type = line[j];
            maze[i][j].x = j;
            maze[i][j].y = i;
        }
    }

    //close the file
    file.close();

    return maze;
}

void printMaze(cell** maze, int dimension)
{
    //print the maze
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            cout << maze[i][j].type;
        }
        cout << endl;
    }
}

cell findStart(cell** maze, int dimension)
{
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            if(maze[i][j].type == 'S')
            {
                return maze[i][j];
            }
        }
    }

    cout << "ERROR: COULDN'T FIND START" << endl;
    exit(-1);
}


















