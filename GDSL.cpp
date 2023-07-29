#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
        if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{   
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of Singly Circular Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    do
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    } while (temp != first);
    
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;

}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount +1)
    {
       InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;
        NodeS<T> temp = first;
        for (int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if ((first == last))
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if ((first == last))
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        delete last->next;
        last->next = first;
        
    }
    iCount--;

}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount )
    {
       DeleteLast();
    }
    else
    {
        NodeS<T> temp = first;
        NodeS<T> tempX = NULL;
        for (int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements of Doubly Linear Linked list are : "<<"\n";

    NodeD<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    iCount++;
    
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    int icnt = 0;
    NodeD<T> temp = first;
    NodeD<T> newn = NULL;
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if ( iPos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
    
        for ( icnt = 1; icnt < iPos-1; icnt++)
        {
           temp = temp->next;
        }
        NodeD<T> * newn = new NodeS<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        (first) = (first)->next;
        delete((first)->prev);
        (first)->prev = NULL;
    
    }
    iCount--;

}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        NodeD<T> temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;

        
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    NodeD<T> temp = first;
    if (iPos == 1)
    {
        DeleteFirst(first);
    }
    else if ( iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        for ( int icnt = 1; icnt < iPos-1; icnt++)
        {
           temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next);                                       
        temp->next->prev = temp;                                
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements of Doubly Circular Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    do
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    } while (temp != first);
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if ((first == NULL) && (last ==NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if ((first == NULL) && (last ==NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
       last->next = newn;
       last = last->next;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;

        NodeD<T> temp = first;

        for (int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next= newn;
        newn->prev = temp;
        
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
       return;
    }
    else if ((first->next == NULL) && (last->next == NULL))
    {
        delete first;
        first= NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    iCount--;
    
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL))
    {
       return;
    }
    else if ((first->next == NULL) && (last->next == NULL))
    {
        delete first;
        first= NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> temp = first;
        while (temp->next->next != first)
        {
            temp = temp->next;
        }
        last = temp;
        delete first->prev;
        last->next = first;
        first->prev = last;
        
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount )
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> temp = first;
        NodeD<T>tempX = NULL;
        for (int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
    } 
}
///////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class node
{
    public:
        T data;
        node *next;

        node(T value)
        {
            data = value;
            next = NULL;
        }

};
template <class T>
class Stack
{
    private:
        T First;
        int iCount;

    public:
        Stack();
        void Push(int no);      // InsertLast
        int Pop();              // DleteLast
        void Display();
        int Count();
};

template <class T>
Stack <T> :: Stack()
{
    First = NULL;
    iCount = 0;
}
template <class T>
void Stack <T>::Push(int no)        // InsertLast
{
    T newn = new T(no);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        T temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 
template <class T>
int Stack <T>::Pop()        // DeleteLast
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First -> data;
        delete First;
        First = NULL;
    }
    else
    {
        T temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

    return Value;
}  

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are : \n";

    T temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Stack <T>::Count()
{
    return iCount;
}
///////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

template <class T>
class nodeQ
{
    public:
        T data;
        nodeQ *next;

        nodeQ(T value)
        {
            data = value;
            next = NULL;
        }

};
template <class T>
class Queue
{
    private:
        T First;
        int iCount;

    public:
        Queue();
        void Enqueue(int no);      // InsertLast
        int Dequeue();              // DleteFirst
        void Display();
        int Count();
};
template <class T>
Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;
}
template <class T>
void Queue <T>::Enqueue(int no)        // InsertLast
{
    T newn = new T(no);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        T temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 
template <class T>
int Queue <T>::Dequeue()        // DeleteFirst
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First -> data;
        delete First;
        First = NULL;
    }
    else
    {
        Value = First -> data;
        T temp = First;
        First = First -> next;
        delete temp;
    }

    iCount--;

    return Value;
}              
template <class T>
void Queue<T>::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    T temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}
template <class T>
int Queue<T>::Count()
{
    return iCount;
}
///////////////////////////////////////////////////////////////////////////////////////////
// Linear Search, BidirectionalSearch, BinarySearch
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BidirectinalSearch(T);
        bool BinarySearch(T);
};

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag  = false;

    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BidirectinalSearch(T No)
{
    bool flag  = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd = 0, iMid = 0;
    
    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if(Arr[iMid] == No)
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}
///////////////////////////////////////////////////////////////////////////////////////////
//  Sorting 1) BubbleSort
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class ArrayXX
{
    public:
        T *Arr;
        int iSize;

        ArrayXX(int);
        ~ArrayXX();
        void Accept();
        void Display();
        void BubbleSort();
};

template <class T>
ArrayXX<T>:: ArrayXX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayXX<T> :: ~ArrayXX()
{
    delete []Arr;
}

template <class T>
void ArrayXX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayXX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void ArrayXX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
// BubbleSortEfficient
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Arrayy
{
    public:
        T *Arr;
        int iSize;

        Arrayy(int);
        ~Arrayy();
        void Accept();
        void Display();
        void BubbleSortEfficient();
};

template <class T>
Arrayy<T>:: Arrayy(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
Arrayy<T> :: ~Arrayy()
{
    delete []Arr;
}

template <class T>
void Arrayy<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void Arrayy<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void Arrayy<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
// SelectionSort
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class ArrayYY
{
    public:
        T *Arr;
        int iSize;

        ArrayYY(int);
        ~ArrayYY();
        void Accept();
        void Display();
        void SelectionSort();
};

template <class T>
ArrayYY<T>:: ArrayYY(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayYY<T> :: ~ArrayYY()
{
    delete []Arr;
}

template <class T>
void ArrayYY<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayYY<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void ArrayYY <T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//InsertionSort
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class ArrayXY
{
    public:
        T *Arr;
        int iSize;

        ArrayXY(int);
        ~ArrayXY();
        void Accept();
        void Display();
        void InsertionSort();
};

template <class T>
ArrayXY<T>:: ArrayXY(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayXY<T> :: ~ArrayXY()
{
    delete []Arr;
}

template <class T>
void ArrayXY<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayXY<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void ArrayXY <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//InsertionSort
///////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    TreeNode<T>* root;

    void InsertHelper(TreeNode<T>*& node, const T& value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
        } else if (value < node->data) {
            InsertHelper(node->left, value);
        } else if (value > node->data) {
            InsertHelper(node->right, value);
        }
    }

    bool SearchHelper(TreeNode<T>* node, const T& value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return SearchHelper(node->left, value);
        } else {
            return SearchHelper(node->right, value);
        }
    }

    void PreorderHelper(TreeNode<T>* node) const {
        if (node != nullptr) {
            std::cout << node->data << "\t";
            PreorderHelper(node->left);
            PreorderHelper(node->right);
        }
    }

    void PostorderHelper(TreeNode<T>* node) const {
        if (node != nullptr) {
            PostorderHelper(node->left);
            PostorderHelper(node->right);
            std::cout << node->data << "\t";
        }
    }

    void InorderHelper(TreeNode<T>* node) const {
        if (node != nullptr) {
            InorderHelper(node->left);
            std::cout << node->data << "\t";
            InorderHelper(node->right);
        }
    }

    int CountNodesHelper(TreeNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + CountNodesHelper(node->left) + CountNodesHelper(node->right);
    }

    int CountLeafNodesHelper(TreeNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        } else if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return CountLeafNodesHelper(node->left) + CountLeafNodesHelper(node->right);
    }

    int CountParentNodesHelper(TreeNode<T>* node) const {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return 0;
        }
        return 1 + CountParentNodesHelper(node->left) + CountParentNodesHelper(node->right);
    }

public:
    BST() : root(nullptr) {}

    void Insert(const T& value) {
        InsertHelper(root, value);
    }

    bool Search(const T& value) const {
        return SearchHelper(root, value);
    }

    void Preorder() const {
        PreorderHelper(root);
    }

    void Postorder() const {
        PostorderHelper(root);
    }

    void Inorder() const {
        InorderHelper(root);
    }

    int CountNodes() const {
        return CountNodesHelper(root);
    }

    int CountLeafNodes() const {
        return CountLeafNodesHelper(root);
    }

    int CountParentNodes() const {
        return CountParentNodesHelper(root);
    }
};


///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLL <int>obj1;
    SinglyCL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCL <int>obj4;
    

    
    return 0;
}

