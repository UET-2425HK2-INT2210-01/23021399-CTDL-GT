1. Given a list A of n integer numbers, your task is to write a program to count the number of pairs (i,j) that A[i]=A[j].  

Input: − The first line contains an integer number n 	 

 − The second line contains n integer numbers separated by spaces. 	 

 Output: Write to the screen an integer number (i.e., the number of pairs (i,j) that A[i]=A[j]) 

 

#include <iostream> 

using namespace std; 

  

int demCap(int arr[], int n) { 

    int dem = 0; 

    for (int i = 0; i < n; i++) { 

        for (int j = i + 1; j < n; j++) { 

            if (arr[i] == arr[j]) { 

                dem++; 

            } 

        } 

    } 

    return dem; 

} 

  

int main() { 

    int n; 

    cin >> n; 

    int arr[n]; 

     

    for (int i = 0; i < n; i++) { 

        cin >> arr[i]; 

    } 

     

    cout << demCap(arr, n) << endl; 

    return 0; 

} 

 

2. The linked list structure has two following operations: 

 − insert (p, x): insert an integer number x at position p, elements from p are moved backward one position.	  

− delete (p): delete element at position p, elements after p are moved forward one position.	 Start from an empty list, your task is to implement a linked list, perform operations read from the keyboard.  

Input: − The first line contains an integer number n which is the number of operations.	 − The next n lines contain the operation description. One operation is in one line in either format:	 ● insert p x	 ● delete p	 where p is the position and x is the number. 

 Output: Write the resulting linked list to the screen in one line. Numbers are separated by spaces. 

 

#include using namespace std; 

struct Node { int data; Node* next; Node(int val) : data(val), next(nullptr) {} }; 

class LinkedList { Node* head; public: LinkedList() : head(nullptr) {} 

void insert(int pos, int val) { 
    Node** cur = &head; 
    while (pos-- && *cur) cur = &((*cur)->next); 
    Node* newNode = new Node(val); 
    newNode->next = *cur; 
    *cur = newNode; 
} 
 
void remove(int pos) { 
    Node** cur = &head; 
    while (pos-- && *cur) cur = &((*cur)->next); 
    if (*cur) { 
        Node* temp = *cur; 
        *cur = (*cur)->next; 
        delete temp; 
    } 
} 
 
void print() { 
    for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " "; 
    cout << endl; 
} 
  

};  

 

int main() { 

    int n; 

    cin >> n; 

    LinkedList list; 

    while (n--) { 

        string op; 

        int p, x; 

        cin >> op >> p; 

        if (op == "insert") { 

            cin >> x; 

            list.insert(p, x); 

        } else list.remove(p); 

    } 

    list.print(); 

    return 0; 

} 

 

3. Given a list of integer numbers, your task is to read these numbers into a doubly linked list, and implement function count_triplets() to count all positions p such that the sum of elements at positions p-1, p, and p+1 is zero. 

 Input: − The first line contains an integer number n which is the number of numbers.	 − The second line contains n integer numbers to read into count_triplets function	 

 Output: Write to the screen an integer number that is the result of function count_triplets(). 

 

#include  

using namespace std; 

struct Node { int data; Node* prev; Node* next; Node(int val) : data(val), prev(nullptr), next(nullptr) {} }; 

int count_triplets(Node* head) { if (!head || !head->next || !head->next->next) return 0;  

int count = 0; 
Node* current = head->next;  
 
while (current->next) { 
    if (current->prev->data + current->data + current->next->data == 0) { 
        count++; 
    } 
    current = current->next; 
} 
return count; 
  

} 

Node* create_doubly_linked_list(int arr[], int n) { if (n == 0) return nullptr; 

Node* head = new Node(arr[0]); 
Node* current = head; 
 
for (int i = 1; i < n; i++) { 
    Node* newNode = new Node(arr[i]); 
    current->next = newNode; 
    newNode->prev = current; 
    current = newNode; 
} 
return head; 
  

} 

int main() { int n; cin >> n; int arr[n]; 

for (int i = 0; i < n; i++) { 
    cin >> arr[i]; 
} 
 
Node* head = create_doubly_linked_list(arr, n); 
cout << count_triplets(head) << endl; 
 
return 0; 
  

} 

4. The Queue structure has two following operations:  

− enqueue (x): insert integer number x at the tail the queue.	 

 − dequeue (): remove the element at the head of the queue.	  

Start from an empty queue, your task is to implement a queue, perform operations from the keyboard and write the resulting queue to the screen. 

 Input: − The first line contains an integer number n which is the number of operations	 

 − The next n lines contain the operation description. One operation is in one line in either format:	 ● enqueue x	 ● dequeue	 where x is the number to enqueue  

Output: Write the resulting queue to the screen. Numbers are separated by spaces. 

 

#include <iostream> 

using namespace std; 

  

struct Node { 

    int data; 

    Node* next; 

    Node(int val) : data(val), next(nullptr) {} 

}; 

  

class Queue { 

private: 

    Node* front; 

    Node* rear; 

public: 

    Queue() : front(nullptr), rear(nullptr) {} 

     

    void enqueue(int x) { 

        Node* newNode = new Node(x); 

        if (!rear) { 

            front = rear = newNode; 

        } else { 

            rear->next = newNode; 

            rear = newNode; 

        } 

    } 

     

    void dequeue() { 

        if (front) { 

            Node* temp = front; 

            front = front->next; 

            if (!front) rear = nullptr; 

            delete temp; 

        } 

    } 

     

    void printQueue() { 

        Node* temp = front; 

        while (temp) { 

            cout << temp->data << " "; 

            temp = temp->next; 

        } 

    } 

}; 

  

int main() { 

    int n; 

    cin >> n; 

    Queue q; 

    string operation; 

     

    for (int i = 0; i < n; ++i) { 

        cin >> operation; 

        if (operation == "enqueue") { 

            int x; 

            cin >> x; 

            q.enqueue(x); 

        } else if (operation == "dequeue") { 

            q.dequeue(); 

        } 

    } 

     

    q.printQueue(); 

     

    return 0; 

} 

 

5. The Stack structure has two following operations:  

− push (x): insert integer number x to the top of the stack	 

 − pop (): remove the element at the top of the stack	  

Start from an empty stack, your task is to implement a stack, perform operations from the keyboard and write the resulting stack to the screen  

Input: − The first line contains an integer number n which is the number of operations	 

 − The next n lines contain the operation description. One operation is in one line in either format:	 ● push x	 ● pop	 where x is the number to push to the stack.  

Output: Write the resulting stack to the screen. Numbers are separated by spaces. 

 

#include <iostream> 

  

using namespace std; 

  

int main() { 

    int n; 

    cin >> n; 

    int stack[1000], top = -1; 

     

    for (int i = 0; i < n; i++) { 

        string operation; 

        cin >> operation; 

         

        if (operation == "push") { 

            int x; 

            cin >> x; 

            stack[++top] = x; 

        } else if (operation == "pop" && top >= 0) { 

            top--; 

        } 

    } 

     

    for (int i = 0; i <= top; i++) { 

        cout << stack[i] << " "; 

    } 

     

    return 0; 

} 

 

 