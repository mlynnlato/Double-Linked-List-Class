#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

void test(){
    DoublyLinkedList<int>  dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList<int> dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    //used to test values after each iteration of the project
    
    //for(int i = 0; i < dllCopy.size(); i++){
        //cout<< "Bing" << endl;
     //   cout << dllCopy.at(i) << endl;
    //}
    
    cout<< "dll "; dll.printTheList();
    cout<< "dllCopy "; dllCopy.printTheList();
    
    dll = dllCopy;
    dll.pop();
    cout<< "dll "; dll.printTheList();
}

int main(){
    test();
    
    return 0;
}