#ifndef H_LinkedStackType
#define H_LinkedStackType

#include <iostream>
#include<cassert>

using namespace std;

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType
{
public:
    const linkedStackType<Type>& operator=
                (const linkedStackType<Type> &);
    bool operator==(const linkedStackType<Type>& );

    void initializeStack();
    bool isFullStack() const;
    bool isEmptyStack() const;
    void push( const Type& );
    void pop();
    Type top() const;
    linkedStackType();
    linkedStackType( const linkedStackType<Type> &);
    ~linkedStackType();

private:
    nodeType<Type> *stackTop;

    void copyStack (const linkedStackType<Type>&);
};

template <class Type>
void linkedStackType<Type>::initializeStack()
{

    nodeType<Type> *temp;

    while (stackTop != NULL)
        {
            temp = stackTop;
            stackTop = stackTop->link;

            delete temp;
        }
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return (stackTop == NULL);
}

template <class Type>
void linkedStackType<Type>::push (const Type& newItem)
{

    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = stackTop;
    stackTop = newNode;
}

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;

    if (stackTop != NULL)
    {

        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    else
        cout << "\n\tCan not remove from an empty stack.";
}

template <class Type>
Type linkedStackType<Type>::top() const
{
    assert (stackTop != NULL );

    return stackTop->info;
}

template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = NULL;
}

template <class Type>
linkedStackType<Type>::linkedStackType
                (const linkedStackType<Type> &otherStack)
{

    stackTop = NULL;
    copyStack( otherStack );

}

template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}

template<class Type>
const linkedStackType<Type>&
linkedStackType<Type>::operator=
                (const linkedStackType<Type>& otherStack)
{

    if (this != &otherStack)
        copyStack (otherStack);

    return *this;
}

template <class Type>
void linkedStackType<Type>::copyStack
                (const linkedStackType<Type>& otherStack)
{

    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL)
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;

    else
    {
        current = otherStack.stackTop;

        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = NULL;

        last = stackTop;
        current = current->link;

        while (current != NULL)
        {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
bool linkedStackType<Type>::operator==
        (const linkedStackType<Type> &otherStack)
{
    if ((this->stackTop == NULL) &&
                (otherStack.stackTop == NULL))
        return true;

    nodeType<Type> *temp1, *temp2;

    temp1 = this->stackTop;
    temp2 = otherStack.stackTop;

    while ( ( temp1 != NULL ) && ( temp2 != NULL) )
    {
        if ( temp1->info != temp2 -> info)
            return false;
        else
        {
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
    }

    if ( ( temp1 != NULL ) || ( temp2 != NULL ))
        return false;

    return true;
}

#endif // H_LinkedStackType

int main()
{
    cout << "\n\n\t Program to overload equality operator"
         << "in a stack.";

    linkedStackType<int> stack1;
    linkedStackType<int> stack2;

    cout << "\n\n\t Inserting elements 5, 10, 15 ..."
         << "to both the stacks.";


    for ( int i=5; i < 50; i+=5)
        stack1.push( i );

    stack2 = stack1;

    if (stack1 == stack2)
        cout << "\n\n\tThe two stacks are Equal";
    else
        cout << "\n\n\tThe two stacks are Unequal";

    cout << "\n\tInserting an element into first stack.";

    stack1.push( 90 );

    if ( stack1 == stack2 )
        cout << "\n\n\t The two stacks are Equal";
    else
        cout << "\n\n\t The two stacks are Unequal";

    cout << "\n\tThe elements in the first stack are: \n\t";

    while ( !stack1.isEmptyStack() )
    {
        cout << stack1.top() << " ";
        stack1.pop();
    }

    cout << " \n\t The elements in the second stack are: \n\t";
    while ( !stack2.isEmptyStack() )
    {
        cout << stack2.top() << " ";
        stack2.pop();
    }

    cout << "\n\n\t";
    system("pause");
    return 0;
}


