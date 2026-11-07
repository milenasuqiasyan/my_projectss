#include <iostream> 
using namespace std;

template <typename T>

class Vector {
    
    private:
     T*arr; 
     int sz; 
     int cap;


public: Vector() { 
    sz = 0;
     cap = 2; 
     arr = new T[cap]; 
    }

// Copy constructor
Vector(const Vector& other) {
    sz = other.sz;
    cap = other.cap;
    arr = new T[cap];

    for (int i = 0; i < sz; i++) {
        arr[i] = other.arr[i];
    }
}

// Destructor
~Vector() {
    delete[] arr;
}

// push_back
void push_back(T value) {
    
    if (sz == cap) {
        cap *= 2;
        T* temp = new T[cap];

        for (int i = 0; i < sz; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    arr[sz] = value;
    sz++;
}

// size
int size() const {
    return sz;
}

// capacity
int capacity() const {
    return cap;
}

// operator[]
T& operator[](int index) {
    return arr[index];
}

const T& operator[](int index) const {
    return arr[index];
}

// operator=
Vector& operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] arr;

    sz = other.sz;
    cap = other.cap;
    arr = new T[cap];

    for (int i = 0; i < sz; i++) {
        arr[i] = other.arr[i];
    }

    return *this;
}

// operator+
Vector operator+(const Vector& other) const {
    Vector result;

    for (int i = 0; i < sz; i++) {
        result.push_back(arr[i]);
    }

    for (int i = 0; i < other.sz; i++) {
        result.push_back(other.arr[i]);
    }

    return result;
}

// operator+=
Vector& operator+=(const Vector& other) {
    for (int i = 0; i < other.sz; i++) {
        push_back(other.arr[i]);
    }

    return *this;
}

// operator==
bool operator==(const Vector& other) const {
    if (sz != other.sz) {
        return false;
    }

    for (int i = 0; i < sz; i++) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }

    return true;
}

// operator!=
bool operator!=(const Vector& other) const {
    return !(*this == other);
}

};

int main() { 
    
    Vector<int> a; 
    
    a.push_back(10);
    a.push_back(20);


     Vector<int> b;

   b.push_back(30);
   b.push_back(40);

Vector<int> c = a + b;

cout << "a + b: ";
for (int i = 0; i < c.size(); i++) {
    cout << c[i] << " ";
}

cout << "\n";

a += b;

cout << "a += b: ";
for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
}

cout << "\n";

cout << "a[0] = " << a[0] << "\n";

Vector<int> d;
d = b;

cout << "a == b: " << (a == b) << "\n";
cout << "a != b: " << (a != b) << "\n";
cout << "d == b: " << (d == b) << "\n";

return 0;
}

