// COMSC 210 | LAB 18 | Abhishek Nanduri 

#include<iostream>
#include<string>
using namespace std; 

struct Node
{
    double data; 
    string review; 
    Node  * next; 
};

Node * addToHead(Node *); 
Node * addToTail(Node *); 

int main() {

    Node * head = nullptr; 

    int answer;
    cout<<"Which linked list method should we use? (1 or 2)?"<<endl; 
    cout<<"[1] New nodes are added at the head of the linked list"<<endl; 
    cout<<"[2] New nodes are added at the tail of the linked list"<<endl;
    cin>>answer; 

    if (answer == 1)
    {
        head = addToHead(head); 
    }    
    else if(answer == 2)
    {
        head = addToTail(head); 
    }
    else 
    {
        cout<<"Invalid Input."<<endl; 
    }

    int count = 1;
    Node * current = head; 
    if(!head)
    {
        cout<<"empty list"<<endl; 
    }
    while(current != nullptr)
    {
        cout<<"Review #"<<count++<<": "<<current->data<<": "<<current->review<<endl;
        current = current->next; 
    }

    return 0; 
}

Node * addToHead ( Node * head)
{
    Node * newNode = new Node; 
    double value; 
    string rev; 
    cout<<"Enter review rating (0 - 5): "; 
    cin>>value; 
    cin.ignore(); 
    cout<<"Enter a review: "; 
    getline(cin, rev); 

    if(!head) 
    {
        head = newNode; 
        newNode->next = nullptr; 
        newNode->data = value; 
        newNode->review = rev; 
    }
    else 
    {
        newNode->next=head; 
        newNode->data = value; 
        newNode->review = rev;
        head = newNode; 
    }

   // char choice;
        
   // cout<<"Enter another review? (y/n) "; 
   
  /*  while(cin>>choice) 
    {

    if(choice = 'y') 
        {
             head = addToHead(head);         
        } 
    else if(choice = 'n')
        break; 
    } */
        return head;  
} 

Node * addToTail(Node * head) 
{
    Node * newNode = new Node; 
    double value; 
    string rev; 
    cout<<"Enter review rating (0 - 5): "; 
    cin>>value; 
    cin.ignore(); 
    cout<<"Enter a review: "; 
    getline(cin, rev); 

    if(!head) 
    {
        head = newNode; 
        newNode->next = nullptr; 
        newNode->data = value; 
        newNode->review = rev; 
    }

    else
    {
        Node * current = head; 
        while(current->next != nullptr)
            {
                current = current->next; 
            }
        current->next = newNode; 
        newNode->next = nullptr;    
    }

    return head; 

}