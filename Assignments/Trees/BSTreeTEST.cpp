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
    Show newShow = createNode("Matlock", "Mystery", "google.com", 1995, 2000, "Alice", "Bob");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("The Office", "Mystery", "google.com", 1995, 2000, "Derek", "Eric");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("The Office1", "Mystery", "google.com", 1995, 2000, "Farquad", "Gerald");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("0Matlock", "Mystery", "google.com", 1995, 2000, "Hunter", "Ingo");
    showTree.insertNode(showTree.head, newShow);

    newShow = createNode("Matlock0", "Mystery", "google.com", 1995, 2000, "Jake", "Keenan");
    showTree.insertNode(showTree.head, newShow);

    showTree.printShows(showTree.head);

    showTree.printActorsInShow(showTree.head, "Matlock");
    showTree.printShowsWithActor(showTree.head, "Alice");

    showTree.printShowsReleasedBetween(showTree.head, 1990, 2001);

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