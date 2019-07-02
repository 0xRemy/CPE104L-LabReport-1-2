#include <iostream>

using namespace std;

template <typename Type>
struct doubleNode{
    Type info;
    doubleNode *frontEnd;
    doubleNode *backEnd;
};

template <typename Type>
class doblyLinkedList{
public:
    //creates the linkedlist.
    void initialize(int n){
        doubleNode<Type> *temp;
        doubleNode<Type> *newNode;
        temp = 0;
        newNode = 0;
        head = 0;

        for(int i=0;i<n;i++){
            newNode = new doubleNode<Type>;
            newNode->frontEnd = 0;
            newNode->backEnd = 0;

            cout << "Enter the value to enter: ";
            cin >> newNode->info;

            if(head == 0){
                head = newNode;
                temp = newNode;
            }else if(head != 0){
                temp->frontEnd = newNode;
                newNode->backEnd = temp;
                temp = newNode;
            }else{
                cout << "Error" << endl;
            }
        }
        printAll();
    }

    //prints all the node.
    void printAll(){
        doubleNode<Type> *temp;
        temp = head;

        while(temp != 0){
            cout << "backEnd: " << temp->backEnd << "\t\t"
                 << "info: " << temp->info << "\t\t"
                 << "frontEnd: " << temp->frontEnd << "\t\t" << endl;
            temp = temp->frontEnd;
        }
        cout << endl << endl;
    }

    //delete a node that the user wanted.
    void deleteNode(Type n){
        doubleNode<Type> *temp;
        bool check = false;
        temp = head;

        while(temp != 0 && !check){
            if(temp->info == n && temp == head){
                head = temp->frontEnd;
                head->backEnd = 0;
                temp->frontEnd = 0;
                check = true;

                delete temp;
            }else if(temp->info == n && temp->frontEnd != 0){
                temp->backEnd->frontEnd = temp->frontEnd;
                temp->frontEnd->backEnd = temp->backEnd;
                temp->frontEnd = 0;
                temp->backEnd = 0;
                check = true;

                delete temp;
            }else if(temp->info == n && temp->frontEnd == 0){
                temp->backEnd->frontEnd = 0;
                temp->backEnd = 0;
                check = true;

                delete temp;
            }
            temp = temp->frontEnd;
        }

        if(temp == 0){
            cout << "The info you enter is not in the list." << endl;
        }else{
            printAll();
        }
    }

private:
    doubleNode<int> *head;
};

int main(){
    doblyLinkedList<int> dll;
    int n =0;

    cout << "Enter the number of stuff you want to enter: ";
    cin >> n;

    dll.initialize(n);
    cout << "Enter number to delete: ";
    cin >> n;
    dll.deleteNode(n);

    return 0;
}
