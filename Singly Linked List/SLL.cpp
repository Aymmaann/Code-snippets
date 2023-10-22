#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node *head, *tail;
    int length;

public:
    LinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList(){
        if(head==nullptr)
            cout <<"List is empty" << endl;
        else {
            Node *temp = head;
            cout << "Elements of Linked List: ";
            while(temp){
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    Node* get(int index){
        if(index>=length || index<0){
            cout << "Not a valid index" << endl;
            return nullptr;
        }
        Node* temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if (temp){
            temp->value = value;
            return true;
        }
        return false;
    }


    void prepend(int value){
        Node* newNode = new Node(value);
        if(length==0){
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    bool insert(int index, int value){
        if(index>length || index<0){
            cout << "Not a valid index" << endl;
            return false;
        }
        if(index==0){
            prepend(value);
            return true;
        }
        if(index==length){
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index-1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void append(int value){
        Node* newNode = new Node(value);
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteFirst(){
        if(length==0) return;
        Node* temp = head;
        if(length==1){
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void deleteNode(int index){
        if(index>=length || index<0) {
            cout << "Not a valid index" << endl;
            return;
        }
        if(index==0){
            deleteFirst();
            return;
        }
        if(index==length-1){
            deleteLast();
            return;
        }
        Node* prev = get(index-1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void deleteLast() {
        if (length == 0)
            return;
        Node *temp = head;
        if(length==1){
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* prev = head;
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            tail = prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void reverse(){
        if(length==0) return;

        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;
        for(int i=0; i<length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    Node* middleNode() {
        if (length == 0) return nullptr;
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << slow->value << endl;
        return slow;
    }

    void getHead(){
        cout << "Head value: " << head->value << endl;
    }
    void getTail(){
        cout << "Tail value: " << tail->value << endl;
    }
    void getLength(){
        cout << "Length of List: " << length << endl;
    }

    ~LinkedList(){
        Node* temp = head;
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};


int main() {
    // Write the operations to be performed here
}
