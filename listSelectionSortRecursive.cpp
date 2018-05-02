#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Structure LinkedList and your functions
struct Node {
    int e;
    Node* next;
};

struct LinkedList {
    Node* first;
};

LinkedList* listCreate(){
    LinkedList* l = new LinkedList;
    l->first = NULL;
    return l;
}

void listInsertLast(LinkedList* l, int e) {
    Node* node = new Node;
    node->e = e;
    node->next = l->first;
    l->first = node;
}

int listSize(LinkedList* l){
    int cout = 0;
    Node* node =  l->first;

    while(node!=NULL){
        cout++;
        node = node->next;
    }
    return cout;
}

void listPrint(LinkedList* l){
    Node* p = l->first;
    cout << "LinkedList [";
    while(p!=NULL){
        cout << p->e << " ";
        p = p->next;
    }
    cout << "]" << endl;
}

int getElementList(LinkedList* l, int position){
    Node* node =  l->first;
    int count = 0;
    while(node!=NULL){
        if(position == count){
            return node->e;
        }
        count++;
        node = node->next;
    }
}

void setElementList(LinkedList* l, int position, int value){
    Node* node =  l->first;
    int count = 0;
    while(node!=NULL){
        if(position == count){
            node->e = value;
        }
        count++;
        node = node->next;
    }
}
// Recursive Selection Sort
void selectionSort(LinkedList* list, int size, int a = 0)
{
    if(size - a == 1)
        return;
    else
    {
        int smallest = getElementList(list, a);
        int b = a; 
        for(int i = a; i < size; ++i) 
        {
            if(getElementList(list, i) < smallest)
            {
                smallest = getElementList(list, i); 
                b = i;
            }
        }

       
        int temp = getElementList(list, a);
        setElementList(list, a, getElementList(list, b) );
        setElementList(list, b, temp);
        selectionSort(list, size, a + 1); 
        
    }
}

void listSelectionSort(LinkedList* list){
     selectionSort(list,listSize(list) , 0);
}