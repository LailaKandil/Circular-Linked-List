#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    int size;

public:
    CircularLinkedList() {
        head = nullptr;
        size = 0;
    }

    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            newNode->next = head;
            Node<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            cout<<"invalid index"<<endl;
            return;
        }
        if (index == 0) {
            insertAtHead(element);
            return;
        }
        if (index == size) {
            insertAtEnd(element);
            return;
        }
        Node<T>* newNode = new Node<T>(element);
        Node<T>* currentNode = head;
        for (int i = 0; i < index-1; i++) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        size++;
    }

    void removeAtHead() {
        if (head == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            Node<T>* temp = head;
            head = head->next;
            lastNode->next = head;
            delete temp;
        }
        size--;
    }

    void removeAtEnd() {
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* lastNode = head;
            Node<T>* secondLastNode = nullptr;
            while (lastNode->next != head) {
                secondLastNode = lastNode;
                lastNode = lastNode->next;
            }
            secondLastNode->next = head;
            delete lastNode;
        }
        size--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index"<<endl;
            return;
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        if (index == size-1) {
            removeAtEnd();
            return;
        }
        Node<T>* currentNode = head;
        Node<T>* prevNode = nullptr;
        for (int i = 0; i < index; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = currentNode->next;
        delete currentNode;
        size--;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index"<<endl;
            return T();
        }
        Node<T>* currentNode = head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index"<<endl;
            return;
        }
        Node<T>* currentNode = head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        currentNode->data = newElement;
    }

    bool isExist(T element) {
        if (head == nullptr) {
            return false;
        }
        Node<T>* currentNode = head;
        while (true) {
            if (currentNode->data == element) {
                return true;
            }
            currentNode = currentNode->next;
            if (currentNode == head) {
                break;
            }
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index"<<endl;
            return false;
        }
        else if(retrieveAt(index) == element)
            return true;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            cout << "Invalid indices"<<endl;
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        Node<T>* firstNode = head;
        for (int i = 0; i < firstItemIdx; i++) {
            firstNode = firstNode->next;
        }
        Node<T>* secondNode = head;
        for (int i = 0; i < secondItemIdx; i++) {
            secondNode = secondNode->next;
        }
        Node<T>* temp = firstNode->next;
        firstNode->next = secondNode->next;
        secondNode->next = temp;
        temp = firstNode->next->next;
        firstNode->next->next = secondNode->next->next;
        secondNode->next->next = temp;
    }

    bool isEmpty() {
        if(head == nullptr)
            return true;
        else
            return false;
    }

    int circularLinkedListSize() {
        return size;
    }

    void clear() {
        while (head != nullptr) {
            removeAtEnd();
        }
    }

    void print() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        Node<T>* currentNode = head;
        while (true) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
            if (currentNode == head) {
                break;
            }
        }
        cout<<endl;
    }
};
int main(){
//    CircularLinkedList<int> list1;
//    list1.insertAtHead(1);
//    list1.insertAtEnd(2);
//    list1.insertAtEnd(3);
//    list1.insertAtHead(7);
//    list1.insertAt(4, 2);
//    list1.print(); // Output: 1 4 2 3
//    list1.removeAtHead();//removes 7
//    list1.removeAtEnd();//removes 3
//    list1.removeAt(1);//removes 4
//    list1.print();
//    list1.replaceAt(5, 0);
//    cout<< list1.retrieveAt(0) <<endl; // Output: 5
//    cout << list1.isExist(2) <<endl; // Output: 1 (true)
//    cout << list1.isItemAtEqual(4, 0) <<endl; // Output: 1 (true)
//    list1.swap(0, 1);
//    list1.print(); // Output: 4
//    cout << list1.isEmpty() << endl; // Output: 0 (false)
//    cout<< list1.circularLinkedListSize() << endl; // Output: 2
//    list1.clear();
//    list1.print(); // Output: List is empty
    CircularLinkedList<string> list1;
    list1.insertAtHead("1");
    list1.insertAtEnd("2");
    list1.insertAtEnd("3");
    list1.insertAtHead("7");
    list1.insertAt("4", 2);
    list1.print(); // Output: 1 4 2 3
    list1.removeAtHead();//removes 7
    list1.removeAtEnd();//removes 3
    list1.removeAt(1);//removes 4
    list1.print();
//    list1.replaceAt("5", 0);
//    cout<< list1.retrieveAt(0) <<endl; // Output: 5
//    cout << list1.isExist("2") <<endl; // Output: 1 (true)
    cout << list1.isItemAtEqual("4", 0) <<endl; // Output: 1 (true)
//    list1.swap(0, 1);
//    list1.print(); // Output: 4
//    cout << list1.isEmpty() << endl; // Output: 0 (false)
//    cout<< list1.circularLinkedListSize() << endl; // Output: 2
//    list1.clear();
//    list1.print(); // Output: List is empty
}
