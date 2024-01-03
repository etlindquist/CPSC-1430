/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM HERE TO LINE 61***********/
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node * next;
};

//create a list from given array
Node * createDigitListFromArray(int arr[], int size){
    Node * head = nullptr;
    Node * tail = nullptr;
    for (int i = 0; i < size; i++){
        Node * newNode = new Node{arr[i], nullptr};
        if (!head){
            head = newNode;
        }else{
            tail->next = newNode;
        }
        
        tail = newNode;
    }
    
    return head;
}

void printList(Node * head){
    Node * curr = head;
    cout << "head->";
    while (curr){
        cout << curr->val<<"->";
        curr = curr->next;
    }
    cout << "null" << endl;
}

// create a new digit list using two given list
Node * createSumDigitListFromDigitLists(Node * l1Head, Node * l2Head);

int main() {
    int size = 100;
    int arr1 [size] = {0, 6, 9, 7, 1, 0, 7, 2, 0, 1, 2, 4, 8, 8, 9, 9, 0, 7, 5, 4, 8, 7, 9, 3, 0, 9, 6, 9, 4, 5, 0, 5, 0, 5, 9, 3, 9, 2, 0, 3, 0, 9, 7, 9, 7, 8, 0, 9, 0, 9, 4, 0, 6, 6, 3, 6, 0, 2, 6, 8, 4, 4, 7, 3, 9, 9, 2, 9, 7, 6, 6, 9, 8, 6, 8, 3, 1, 7, 0, 9, 6, 5, 2, 8, 6, 4, 2, 0, 3, 4, 6, 6, 0, 9, 8, 2, 2, 3, 9, 4};
    int arr2 [size] = {7, 0, 4, 9, 3, 4, 3, 6, 0, 6, 1, 9, 4, 7, 4, 4, 0, 5, 6, 3, 6, 7, 4, 9, 4, 9, 8, 5, 5, 9, 4, 9, 0, 7, 1, 9, 5, 4, 0, 6, 8, 1, 2, 7, 6, 0, 5, 4, 8, 7, 3, 0, 5, 6, 0, 0, 6, 0, 5, 2, 7, 4, 3, 9, 3, 6, 4, 1, 4, 0, 7, 8, 4, 2, 9, 1, 1, 2, 7, 7, 5, 4, 0, 3, 9, 3, 3, 5, 1, 6, 0, 7, 4, 7, 8, 7, 7, 6, 0, 5};
    
    Node * l1Head = createDigitListFromArray(arr1, size); 
    cout << "The first list is:" << endl;
    printList(l1Head);
    
    Node * l2Head = createDigitListFromArray(arr2, size);
    cout << endl << "The second list is:" << endl;
    printList(l2Head);
    
    Node * sumListHead = createSumDigitListFromDigitLists(l1Head, l2Head);
    cout << endl << "The sum list is:" << endl;
    // when submitting your answer, copy the WHOLE string (including "head->" and "->null")
    printList(sumListHead);
    
    return 0;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM Line 1 TO HERE ***********/



/********* YOUR CODE GOES BELOW **********/
// when submitting your code, only submit this function - no need to submit the above L1-L67
Node * createSumDigitListFromDigitLists(Node * l1, Node * l2){
    Node *head = new Node;
    Node *ptr = head;
    //handling first value
    int value = l1->val + l2->val;
    ptr->val = value%10;    //the number should be one digit long
    int add = value/10;     //the amound to be carried over to the next number
    l1 = l1->next;
    l2 = l2->next;
    //traverising the remainder of the number
    while(l1/*could also use l2 here*/){
        ptr->next = new Node;
        ptr = ptr->next;
        value = l1->val + l2->val + add;
        ptr->val = value%10;
        add = value/10;
        l1 = l1->next;
        l2 = l2->next;
    }
    //in case the new number should be one digit longer than the other two 
    //eg. 4->2->9 + 3->1->4 = 7->3->3->1 not 7->3->3
    if(add == 1){
        ptr->next = new Node;
        ptr->next->val = 1;
        ptr->next->next = nullptr;
    }
    return head;
}
