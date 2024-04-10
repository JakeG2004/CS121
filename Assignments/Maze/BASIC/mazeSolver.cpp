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

//prototypes
void solveMaze(cell, char**, int, Queue&);
void printMaze(char**, int);
void addUnvisited(cell, char**, int, Queue&);

bool checkGoal(cell, char**, int);

int getDimension(string);

char** getMaze(string, int);
cell findStart(char**, int);

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
    char** maze = getMaze(fileName, dimension);

    //make the agent
    cell agent = findStart(maze, dimension);

    //make the queue
    Queue queue = Queue();

    //solve and print the maze
    solveMaze(agent, maze, dimension, queue);
    printMaze(maze, dimension);
}

void solveMaze(cell agent, char** maze, int dimension, Queue &queue)
{
    //check for goal cell
    if(checkGoal(agent, maze, dimension))
    {
        cout << "Found solution" << endl;
        return;
    }

    //add all unvisited neighbors
    addUnvisited(agent, maze, dimension, queue);

    //remove next element and make it current cell
    cell newAgent = queue.dequeue();
    solveMaze(newAgent, maze, dimension, queue);
}

void printMaze(char** maze, int dimension)
{
    //print the maze
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void addUnvisited(cell agent, char** maze, int dimension, Queue &queue)
{
    int x = agent.x;
    int y = agent.y;

    //check south
    if(y + 1 < dimension && maze[y + 1][x] == '.' && maze[y + 1][x] == '.')
    {
        maze[y + 1][x] = 'v';
        queue.enqueue(y + 1, x);
    }

    //check east
    if(x + 1 < dimension && maze[y][x + 1] == '.' && maze[y][x + 1] == '.')
    {
        maze[y][x + 1] = '>';
        queue.enqueue(y, x + 1);
    }

    //check north
    if(y - 1 >= 0 && maze[y - 1][x] == '.' && maze[y - 1][x] == '.')
    {
        maze[y - 1][x] = '^';
        queue.enqueue(y - 1, x);
    }

    //check west
    if(x - 1 >= 0 && maze[y][x - 1] == '.' && maze[y][x - 1] == '.')
    {
        maze[y][x - 1] = '<';
        queue.enqueue(y, x - 1);
    }
}

bool checkGoal(cell agent, char** maze, int dimension)
{
    int x = agent.x;
    int y = agent.y;

    //check north
    if(y - 1 >= 0 && maze[y - 1][x] == 'G')
        return true;
    
    //check south
    if(y + 1 < dimension && maze[y + 1][x] == 'G')
        return true;

    //check west
    if(x - 1 >= 0 && maze[y][x - 1] == 'G')
        return true;

    //check east
    if(x + 1 < dimension && maze[y][x + 1] == 'G')
        return true;
    
    return false;
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

char** getMaze(string fileName, int dimension)
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

    //start 2D array
    char** maze = new char*[dimension];

    //read in the map
    for(int i = 0; i < dimension; i++)
    {
        //define row of 2D array
        maze[i] = new char[dimension];
        //get current line
        getline(file, line);
        for(int j = 0; j < dimension; j++)
        {
            //write the chars of the current line into the array
            maze[i][j] = line[j];
        }
    }

    //close the file
    file.close();

    return maze;
}

cell findStart(char** maze, int dimension)
{
    //go through whole maze, finding start cell
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            if(maze[i][j] == 'S')
            {
                cell c = cell();

                c.x = j;
                c.y = i;

                return c;
            }
        }
    }

    cout << "ERROR: COULDN'T FIND START" << endl;
    exit(-1);
}