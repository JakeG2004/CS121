/*
BSTreeTest.cpp
Test if the .h and .cpp files work
Jake Gendreau
April 12, 2024
*/

#include <iostream>
#include "BSTree.cpp"

Show createNode(string newName, string newGenre, string newLink, int start, int end, string actor1, string actor2);

int main()
{
    BSTree showTree = BSTree();
    Show newShow = createNode("Matlock", "Mystery", "google.com", 1980, 1989, "Alice", "Bob");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("The Office", "Mystery", "google.com", 2001, 2002, "Derek", "Eric");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("The Office1", "Mystery", "google.com", 1995, 2000, "Farquad", "Gerald");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("0Matlock", "Mystery", "google.com", 1995, 2000, "Hunter", "Ingo");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("Matlock0", "Mystery", "google.com", 1995, 2000, "Jake", "Keenan");
    showTree.insertNode(showTree.head, newShow);

    cout << "Printing all shows" << endl;
    showTree.printShows(showTree.head);

    cout << "Printing all actors in Matlock" << endl;
    showTree.printActorsInShow(showTree.head, "Matlock");

    cout << "Printing all shows with Alice" << endl;
    showTree.printShowsWithActor(showTree.head, "Alice");

    cout << "Printing all shows released between 1990 and 2000" << endl;
    showTree.printShowsReleasedBetween(showTree.head, 1990, 2000);

    showTree.deleteTree(showTree.head);
}

Show createNode(string newName, string newGenre, string newLink, int start, int end, string actor1, string actor2)
{
    Show show = Show();

    show.name = newName;
    show.genre = newGenre;
    show.link = newLink;

    show.startDate = start;
    show.endDate = end;

    show.actorHead = new node();
    show.actorHead -> data = actor1;
    show.actorHead -> next = new node();

    show.actorHead -> next -> data = actor2;
    show.actorHead -> next -> next = NULL;


    return show;
}