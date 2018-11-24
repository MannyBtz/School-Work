#include <iostream>
#include <cassert>
using namespace std;

class HanoiStack{
    private:
        struct HanoiNode{
            int value;
            HanoiNode *next;
            HanoiNode(int inValue){
                value = inValue;
                next = NULL;
            }
        };
        HanoiNode *_top;
        int numNodes;

    public:
        HanoiStack(){
            numNodes = 0;
        }

        //Returns the value of the top node in the stack
        int top(){
            int outValue = 0;
            if(isEmpty())
                cout << "Top(): The Stack Is Empty\n";
            else
                outValue = _top->value;
            return outValue;
        }

        /*  Adds a new node to the stack, incrememnts the total number
            of nodes and points _top to the new node.
        */
        void push(int nodeValue){
            HanoiNode *hNode = new HanoiNode(nodeValue);
            if(isEmpty() == false)
                hNode->next = _top;
            _top = hNode;            
            numNodes++;
        }

        /*  Returns the value of the top node in the stack and moves
            the _top pointer to the next node in the stack if the is one.
        */
        int pop(){
            int popValue = 0;
            if(isEmpty())
                cout << "Pop(): Stack is empty";
            else{
                popValue = _top->value;
                _top = _top->next;
                numNodes--;
            }
            return popValue;
        }

        //Returns a value of whether the stack is empty or not.
        bool isEmpty(){
            bool empty;
            if(!numNodes)
                empty = true;
            else
                empty = false;
            return(empty);
        }

        //Prints the stack to the console.
        void printStack(){
            if(isEmpty())
                cout << "0\n" << endl;
            else{
                HanoiNode *current = _top;
                while(current != NULL){
                    cout << current->value << endl;
                    current = current->next;
                }
                cout<<endl;
            }
        }
};

void moveBrick(HanoiStack *stack1, HanoiStack *stack2){
    if(stack1->isEmpty())
        stack1->push(stack2->pop());
    else if(stack2->isEmpty())
        stack2->push(stack1->pop());
    else if(stack1->top() > stack2->top())
        stack1->push(stack2->pop());
    else if(stack1->top() < stack2->top())
        stack2->push(stack1->pop());
}

void printOutput(HanoiStack *pole1, HanoiStack *pole2, HanoiStack *pole3){
    pole1->printStack();
    pole2->printStack();
    pole3->printStack();
    cout << "/****************************/ \n" << endl;
}

int main(){
    HanoiStack pole1 = HanoiStack(), pole2 = HanoiStack(), pole3 = HanoiStack();
    HanoiStack *_pole1 = &pole1, *_pole2 = &pole2, *_pole3 = &pole3;
    int numDisks, movesLeft = 1, notEvenDisks, totalMoves;
    cout << "How many disks? > ";
    cin >> numDisks;

    for(int i = numDisks; i > 0; i--){
         pole1.push(i);
    }

    for(int i = 0; i < numDisks; i++){
        movesLeft = 2 * movesLeft;
    }movesLeft--;

    printOutput(_pole1, _pole2, _pole3);

    totalMoves = 0;
    notEvenDisks = numDisks % 2;
    while(movesLeft){
        switch(movesLeft%3){
            case 0:
                if(notEvenDisks)
                    moveBrick(_pole1, _pole2);
                else
                    moveBrick(_pole1, _pole2);
                break;
            case 1:
                if(notEvenDisks)
                    moveBrick(_pole1, _pole3);
                else
                    moveBrick(_pole2, _pole3);
                break;
            case 2:
                if(notEvenDisks)
                    moveBrick(_pole2, _pole3);
                else
                    moveBrick(_pole1, _pole3);
                break;
        } 
        movesLeft--;
        printOutput(_pole1, _pole2, _pole3);
        totalMoves++;
    }
    cout << totalMoves << " move(s)\n" << endl;
    return 0;
}