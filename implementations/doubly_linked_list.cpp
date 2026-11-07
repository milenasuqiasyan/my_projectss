#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    
    Node (int val) : value (val), next (nullptr), prev (nullptr) {}
    
    Node* get_next () {
        return next;
    }
    
    Node* get_prev () {
        return prev;
    }
};

class List {
private:
    Node* head;
    Node* tail;
    
public: 
    //Constructor
    List () : head (nullptr), tail (nullptr) {}

    //Destructor
    ~List () {
        Node* current = head;

        while (current != nullptr) {
            Node* next = current -> next;
            delete current;
            current = next;
        }
    }

    //Begin
    Node* begin () {
        return head;
    }

    //End
    Node* end () {
        return tail;
    }

    //Insert Function
    void insert (Node* position, int val) {
        if (position == nullptr) { 
            push_back (val);
            return;
        }

        //Creating New Node
        Node* new_node = new Node (val);
        new_node -> next = position -> next;
        new_node -> prev = position;
        
        if (position -> next != nullptr) /* Position-ից հետո Node կա? */
            position -> next -> prev = new_node; 
        else 
            tail = new_node;
        
        position -> next = new_node;
    }

    //Deleting One Element From The List
    void erase (Node* list) {
        if (list == nullptr) 
            return;

        if (list == head) {
            
            pop_front ();
            return;
        }
        if (list == tail) {
            pop_back ();
            return;
        }

        list -> prev -> next = list -> next; /* 1<->2<->3 -> 1->3 */
        list -> next -> prev = list -> prev; /* 1<-3 */

        delete list;
    }

    //Adding Element As A Tail
    void push_back (int val) {
        Node* new_node = new Node (val);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail -> next = new_node;
            new_node -> prev = tail;
            tail = new_node;
        }
        /* No need to write new_node -> next = nullptr, because it already does our constructor */ 
    }

    //Adding Element As A Head
    void push_front (int val) {
        Node* new_node = new Node (val);
            
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node -> next = head;
            head -> prev = new_node;
            head = new_node;
        }
    }

    //Deleting Head
    void pop_front () {
        if (head == nullptr) 
            return;

        Node* temp = head; /* To not lose head's address */
        head = head -> next; /* Our 2nd element is now head */
        
        if (head != nullptr) /* It means that we have any elements left */
            head -> prev = nullptr;
        else /* All elements are deleted */
            tail = nullptr;
        
        delete temp;
    }

    //Deleting Tail Function
    void pop_back () {
        if (tail == nullptr) 
            return;
        Node* temp = tail;
        tail = tail -> prev;
            
        if (tail != nullptr) 
            tail -> next = nullptr;
        else 
            head = nullptr;
            
        delete temp;
    }

    //Print Forward Function
    void printForward () {
        Node* traverser = head;

        while (traverser != nullptr) {
            std::cout << traverser -> value << std::endl;
            traverser = traverser -> next;
        }
    }

    //Print Forward Function
    void printBackward () {
        Node* traverser = tail;

        while (traverser != nullptr) {
            std::cout << traverser -> value << std::endl;
            traverser = traverser -> prev;
        }
    }

    //Get Size Function
    int get_size () {
        int size = 0;
        Node *current = head;

        while (current != nullptr) {
            size ++;
            current = current -> next;
        }

        return size;
    }
};

int main () {
    List l;

    l.push_back (10);
    l.push_back (20);
    l.push_back (30);
    std::cout << "\nPrint forward: \n";
    l.printForward ();
    std::cout << "\nPrint backward: \n";
    l.printBackward ();  

    l.push_front (5);
    std::cout << "\nAdding element of the beginning: \n";
    l.printForward ();  

    Node* first = l.begin (); //after 5
    l.insert (first, 7);
    std::cout << "\nAdding element after position: \n";
    l.printForward ();

    std::cout << "\nDeleting last element using position \n";
    Node* last = l.end ();
    l.erase (last);
    l.printForward ();

    std::cout << "\nDeleting head and tail \n";
    l.pop_front (); 
    l.pop_back ();
    l.printForward ();

    std::cout << "\nList size: " << l.get_size () << std::endl;

    return 0;
}