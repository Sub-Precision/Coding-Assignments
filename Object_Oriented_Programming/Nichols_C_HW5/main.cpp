#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node
{
private:
    //Class variables
    string s;
    char ID;
    Node* North;
    Node* East;
    Node* South;
    Node* West;

public:
    //Constructors
    Node() { North = East = South = West = NULL; }
    Node(char newID) { North = East = South = West = NULL; ID = newID; }

    void setPath(Node* N, Node* E, Node* S, Node* W)
    {
        North = N;
        East = E;
        South = S;
        West = W;
    }

    //Getters
    char getID() { return ID; }
    Node* getNorth() { return North; }
    Node* getEast() { return East; }
    Node* getSouth() { return South; }
    Node* getWest() { return West; }
    Node* getNULL() { return NULL; }

    //Setters
    void setID(char I) { ID = I; }

    //Deconstructor
    ~Node()
    {
    }
};

int main()
{
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');
    Node* L = new Node('L');
    Node* current = A;
    char direction;

    A->setPath(NULL, B, E, NULL);
    B->setPath(NULL, NULL, F, A);
    C->setPath(NULL, NULL, G, NULL);
    D->setPath(NULL, NULL, H, NULL);
    E->setPath(A, NULL, I, NULL);
    F->setPath(B, G, NULL, NULL);
    G->setPath(C, H, NULL, F);
    H->setPath(D, NULL, L, G);
    I->setPath(E, J, NULL, NULL);
    J->setPath(NULL, K, NULL, I);
    K->setPath(NULL, NULL, NULL, J);
    L->setPath(H, NULL, NULL, NULL);

    while (current != L)
    {
        cout << "You are in room " << current->getID() << " of a maze of twisty passages, all alike." << " You can go: " << endl;
        if (current->getNorth() != NULL)
        {
            cout << "North (n) ";
        }
        if (current->getEast() != NULL)
        {
            cout << "East (e) ";
        }
        if (current->getSouth() != NULL)
        {
            cout << "South (s) ";
        }
        if (current->getWest() != NULL)
        {
            cout << "West (w) ";
        }
        cin >> direction;
        if ((direction == 'n') && (current->getNorth() == NULL))
        {
            cout << "ERROR! Please enter a valid direction from the options." << endl;
        }
        if ((direction == 'e') && (current->getEast() == NULL))
        {
            cout << "ERROR! Please enter a valid direction from the options." << endl;
        }
        if ((direction == 's') && (current->getSouth() == NULL))
        {
            cout << "ERROR! Please enter a valid direction from the options." << endl;
        }
        if ((direction == 'w') && (current->getWest() == NULL))
        {
            cout << "ERROR! Please enter a valid direction from the options." << endl;
        }
        if ((direction == 'n') && (current->getNorth() != NULL))
        {
            current = current->getNorth();
        }
        if ((direction == 'e') && (current->getEast() != NULL))
        {
            current = current->getEast();
        }
        if ((direction == 's') && (current->getSouth() != NULL))
        {
            current = current->getSouth();
        }
        if ((direction == 'w') && (current->getWest() != NULL))
        {
            current = current->getWest();
        }
    }
    cout << "You are in room L. You have arrived at the finish point. Good job!" << endl;
    return 0;
}