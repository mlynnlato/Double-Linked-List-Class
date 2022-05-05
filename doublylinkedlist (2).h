#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;
template<typename T>
struct node
{
    T data;
    node<T>* next = nullptr;
    node<T>* prev=nullptr;
};

template<typename T>
class DoublyLinkedList
{
    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& objToCopy);
    
    DoublyLinkedList& operator=(const DoublyLinkedList& objToCopy);
    void insert(int data, int pos);
    void printTheList();
    void pop();
    void push(T data);
    T& at(int index) const;
    int size() const;
    void remove(int indexToRemove);
    
    
    private:
    node<T>* head;
    int numElements;
    node<T>* tail;
    
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    numElements = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    std::cout << "Destructor Called!" << std::endl;
    while(numElements > 0)
        pop();
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& objToCopy)
{
    std::cout << "Copy Constructor Called!" << std::endl;
    
    head = nullptr;
    numElements = 0;
    for(int i = 0; i < objToCopy.size(); i++)
    {
        push(objToCopy.at(i));
    }
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& objToCopy)
{
    std::cout << "Copy Assignment Override Called!" << std::endl;
    
    while(numElements > 0)
        pop();
        
    for(int i = 0; i < objToCopy.size()+1; i++)
    {
        push(objToCopy.at(i));
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(int data, int pos){
    /*
    
    numElements++;
    node<T>* selectNode=head;
    node<T>* temp;
    node<T>* curNode=head;
    
    for(int i=0; i<pos; i++){
        selectNode=selectNode->next;
    }
    temp=selectNode;
    //while(temp->next != nullptr){
        cout<< "Testing: " << temp->data<< endl;
        
        temp->next->next=temp->next;
        temp->next=temp;
        cout<<"BUG"<<endl;
        if (pos==0){
        head->data = data;
    }
    
        temp=temp->next;
   // }
   */
  node<T>* curNode = new node<T>; 
  curNode->data = data;
  curNode->next = nullptr;
  curNode->prev = nullptr;
  pos+=1;
  if (pos == 1)
  {
    curNode->next = head;
    head->prev = curNode;
    head = curNode;
  } else {

    node<T>* temp = head;
    for(int i = 1; i < pos-1; i++) 
    {
      if(temp != nullptr)
      {
        temp = temp->next;
      }
    }
 
    if(temp != nullptr) {
      curNode->next = temp->next;
      curNode->prev = temp;
      temp->next = curNode;
      if(curNode->next != nullptr)
        curNode->next->prev = curNode;  
    }
  }

}

template<typename T>
void DoublyLinkedList<T>::printTheList(){
    node<T>* temp = head;
      if(temp != nullptr) 
      {
        cout<<"list: ";
        while(temp != nullptr) 
        {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      } else 
      {
        cout<<"Empty list" << endl;
      }
}

template<typename T>
void DoublyLinkedList<T>::push(T data){
    numElements++;
    
    if(head == nullptr)
    {
        head = new node<T>;
        head->data = data;
        return;
    }
    
    node<T>* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new node<T>;
    temp->next->data = data;
}

template<typename T>
void DoublyLinkedList<T>::pop()
{
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        numElements--;
        return;
    }
    
    node<T>* currentNode = head;
    while(currentNode->next->next != nullptr)
    {
        currentNode = currentNode->next;
    }
    
    delete currentNode->next;
    currentNode->next = nullptr;
    numElements--;
}

template<typename T>
T& DoublyLinkedList<T>::at(int index) const
{
    int currentIndex = 0;
    
    node<T>* currentNode = head;
    
    while(true){
        if(currentIndex == index)
        {
            return currentNode->data;
        }
        
        currentIndex++;
        currentNode = currentNode->next;
    }
}

template<typename T>
int DoublyLinkedList<T>::size() const
{
    /*
    int numElements = 0;
    
    if(head == nullptr){
        return numElements;
    }
    
    while(true){
        numElements++;
        if(head->next == nullptr){
            break;
        } else {
            head = head->next;
        }
    }
    
    return numElements;
    */
    return numElements;
}

template<typename T>
void DoublyLinkedList<T>::remove(int indexToRemove)
{
    if(indexToRemove == 0)
    {
        node<T>* temp = head;
        if(head->next == nullptr)
        {
            head = nullptr;
        } else 
        {
            head = head->next;
        }
        delete temp;
        numElements--;
        return;
    }
    
    node<T>* currentNode = head;
    int currentIndex = 0;
    
    while(true){
        if(currentIndex == (indexToRemove - 1))
        {
            break;
        }
        
        currentIndex++;
        currentNode = currentNode->next;
    }
    
    node<T>* temp = currentNode->next->next;
    delete currentNode->next;
    currentNode->next = temp;
    
    numElements--;
}

#endif