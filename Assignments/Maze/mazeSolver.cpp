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
void solveMaze(cell*, cell**, int, Queue&);
void printMaze(cell**, int);
void printSolvedMaze(cell**, int);
void addUnvisited(cell*, cell**, int, Queue&);

bool checkGoal(cell*, cell**, int);

int getDimension(string);

cell** getMaze(string, int);
cell* findStart(cell**, int);

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

    //print the maze
    //printMaze(maze, dimension);

    //make the agent
    cell* agent = findStart(maze, dimension);

    //make the queue
    Queue queue = Queue();

    //solve and print the maze
    solveMaze(agent, maze, dimension, queue);
    printSolvedMaze(maze, dimension);
}

void solveMaze(cell* agent, cell** maze, int dimension, Queue &queue)
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
    solveMaze(&newAgent, maze, dimension, queue);
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

void addUnvisited(cell agent, char** maze, int dimension, Queue &queue)
{
    //go through, printing goal, start, and visited paths
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            cout << maze[i][j].type;
        }
        cout << endl;
    }
}

void addUnvisited(cell* agent, cell** maze, int dimension, Queue &queue)
{
    int x = agent -> x;
    int y = agent -> y;

    //check south
    if(y + 1 < dimension && maze[y + 1][x].type == '.' && maze[y + 1][x].type == '.')
    {
        maze[y + 1][x].type = 'v';
        queue.enqueue(maze[y + 1][x]);
    }

    //check east
    if(x + 1 < dimension && maze[y][x + 1].type == '.' && maze[y][x + 1].type == '.')
    {
        maze[y][x + 1].type = '>';
        queue.enqueue(maze[y][x + 1]);
    }

    //check north
    if(y - 1 >= 0 && maze[y - 1][x].type == '.' && maze[y - 1][x].type == '.')
    {
        maze[y - 1][x].type = '^';
        queue.enqueue(maze[y - 1][x]);
    }

    //check west
    if(x - 1 >= 0 && maze[y][x - 1].type == '.' && maze[y][x - 1].type == '.')
    {
        maze[y][x - 1].type = '<';
        queue.enqueue(maze[y][x - 1]);
    }
}

bool checkGoal(cell* agent, cell** maze, int dimension)
{
    int x = agent -> x;
    int y = agent -> y;

    //check north
    if(y - 1 >= 0 && maze[y - 1][x].type == 'G')
        return true;
    
    //check south
    if(y + 1 < dimension && maze[y + 1][x].type == 'G')
        return true;

    //check west
    if(x - 1 >= 0 && maze[y][x - 1].type == 'G')
        return true;

    //check east
    if(x + 1 < dimension && maze[y][x + 1].type == 'G')
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

    //start 2D array
    cell** maze = new cell*[dimension];

    //read in the map
    for(int i = 0; i < dimension; i++)
    {
        //define row of 2D array
        maze[i] = new cell[dimension];
        //get current line
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

cell* findStart(cell** maze, int dimension)
{
    //go through whole maze, finding start cell
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            if(maze[i][j].type == 'S')
            {
                return &maze[i][j];
            }
        }
    }

    cout << "ERROR: COULDN'T FIND START" << endl;
    exit(-1);
}