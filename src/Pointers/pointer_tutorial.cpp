#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>

// Using namespace for cleaner code in tutorial
using namespace std;

// =============================================================================
// PART 1: BASIC POINTER AND REFERENCE FUNDAMENTALS
// =============================================================================

void demonstrateBasics() {
    cout << "\n=== PART 1: BASIC POINTER AND REFERENCE FUNDAMENTALS ===" << endl;
    
    // Regular variable - lives at a specific memory address
    int number = 42;
    cout << "Value of number: " << number << endl;
    cout << "Address of number: " << &number << endl;
    
    // Pointer declaration and initialization
    int* ptr = &number;  // ptr now holds the address of number
    cout << "\nPointer ptr points to address: " << ptr << endl;
    cout << "Value at that address (*ptr): " << *ptr << endl;
    cout << "Address of pointer itself (&ptr): " << &ptr << endl;
    
    // Modifying through pointer
    *ptr = 100;  // Changes the value at the address ptr points to
    cout << "\nAfter *ptr = 100:" << endl;
    cout << "number is now: " << number << endl;  // number changed!
    
    // Reference - an alias for an existing variable
    int& ref = number;  // ref is now another name for number
    cout << "\nReference ref refers to: " << ref << endl;
    ref = 200;  // This changes number
    cout << "After ref = 200, number is: " << number << endl;
    
    // Key difference: pointers can be reassigned, references cannot
    int another = 999;
    ptr = &another;  // ptr now points to another
    cout << "\nAfter ptr = &another:" << endl;
    cout << "*ptr is now: " << *ptr << endl;
    cout << "But number is still: " << number << endl;
    
    ref = another;  // This would just assign 999 to number, NOT make ref refer to another!
    cout << "\nref:" << ref <<endl;
    cout << "\nnumber:" << number <<endl;
}

// =============================================================================
// PART 2: NULLPTR AND POINTER VALIDATION
// =============================================================================

void demonstrateNullPointers() {
    cout << "\n=== PART 2: NULLPTR AND POINTER VALIDATION ===" << endl;
    
    int* ptr1 = nullptr;  // Modern C++ way
    int* ptr2 = NULL;     // C-style (avoid in modern C++)
    int* ptr3 = 0;        // Also works but not recommended
    
    // Always check before dereferencing
    if (ptr1 == nullptr) {
        cout << "ptr1 is null - safe to know before using!" << endl;
    }
    
    // More idiomatic check
    if (!ptr1) {
        cout << "ptr1 is null (using boolean conversion)" << endl;
    }
    
    int value = 42;
    ptr1 = &value;
    
    if (ptr1) {  // Now ptr1 is valid
        cout << "ptr1 is valid and points to: " << *ptr1 << endl;
    }
    
    // Dangerous! Never dereference null pointer
    int* bad_ptr = nullptr;
    // cout << *bad_ptr;  // CRASH! Segmentation fault
}

// =============================================================================
// PART 3: CONST CORRECTNESS WITH POINTERS AND REFERENCES
// =============================================================================

void demonstrateConst() {
    cout << "\n=== PART 3: CONST CORRECTNESS ===" << endl;
    
    int value = 42;
    const int const_value = 100;
    
    // Pointer to const - can't modify value through pointer
    const int* ptr_to_const = &value;
    cout << "ptr_to_const points to: " << *ptr_to_const << endl;
    // *ptr_to_const = 50;  // ERROR! Can't modify through this pointer
    ptr_to_const = &const_value;  // But can point to different address
    
    // Const pointer - can't change where it points
    int* const const_ptr = &value;
    *const_ptr = 50;  // Can modify the value
    cout << "Modified through const_ptr: " << value << endl;
    // const_ptr = &const_value;  // ERROR! Can't change the pointer itself
    
    // Const pointer to const - completely read-only
    const int* const const_ptr_to_const = &value;
    // *const_ptr_to_const = 60;  // ERROR! Can't modify value
    // const_ptr_to_const = &const_value;  // ERROR! Can't change pointer
    
    // Const reference - common for function parameters
    const int& const_ref = value;
    cout << "const_ref refers to: " << const_ref << endl;
    // const_ref = 70;  // ERROR! Can't modify through const reference
}

// =============================================================================
// PART 4: ARRAYS AND POINTER ARITHMETIC
// =============================================================================

void demonstrateArraysAndArithmetic() {
    cout << "\n=== PART 4: ARRAYS AND POINTER ARITHMETIC ===" << endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Array name decays to pointer to first element
    int* ptr = arr;  // Same as: int* ptr = &arr[0];
    
    cout << "First element using array: " << arr[0] << endl;
    cout << "First element using pointer: " << *ptr << endl;
    cout << "First element using *(arr + 0): " << *(arr + 0) << endl;
    
    // Pointer arithmetic
    cout << "\nPointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "ptr + " << i << " points to: " << *(ptr + i) << endl;
    }
    
    // Incrementing pointer
    cout << "\nIncrementing pointer:" << endl;
    ptr++;  // Move to next element
    cout << "After ptr++, *ptr = " << *ptr << endl;
    
    // Array indexing with pointers
    ptr = arr;  // Reset to beginning
    cout << "\nArray indexing works with pointers:" << endl;
    cout << "ptr[2] = " << ptr[2] << endl;  // Same as *(ptr + 2)
    
    // Pointer difference
    int* ptr_start = &arr[0];
    int* ptr_end = &arr[4];
    cout << "\nPointer difference:" << endl;
    cout << "Elements between start and end: " << (ptr_end - ptr_start) << endl;
    
    // Iterating with pointers
    cout << "\nIterating with pointer until end:" << endl;
    for (int* p = arr; p <= &arr[4]; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

// =============================================================================
// PART 5: PASSING POINTERS AND REFERENCES TO FUNCTIONS
// =============================================================================

// Pass by value - gets a copy
void passByValue(int val) {
    val = 999;  // Only changes local copy
    cout << "Inside passByValue: " << val << endl;
}

// Pass by pointer - can modify original, can be null
void passByPointer(int* ptr) {
    if (ptr) {  // Always check!
        *ptr = 999;
        cout << "Inside passByPointer: " << *ptr << endl;
    }
}

// Pass by reference - can modify original, cannot be null
void passByReference(int& ref) {
    ref = 999;
    cout << "Inside passByReference: " << ref << endl;
}

// Pass by const reference - efficient for large objects, read-only
void passByConstReference(const int& ref) {
    // ref = 999;  // ERROR! Cannot modify
    cout << "Inside passByConstReference: " << ref << endl;
}

// Return by reference - allows chaining and modification
int& returnByReference(int& ref) {
    return ref;
}

// Dangerous! Never return reference to local variable
// int& badReturn() {
//     int local = 42;
//     return local;  // DANGER! local dies when function ends
// }

void demonstrateFunctionParameters() {
    cout << "\n=== PART 5: FUNCTION PARAMETERS ===" << endl;
    
    int number = 42;
    
    cout << "Original value: " << number << endl;
    
    passByValue(number);
    cout << "After passByValue: " << number << endl;  // Unchanged
    
    passByPointer(&number);
    cout << "After passByPointer: " << number << endl;  // Changed!
    
    number = 42;  // Reset
    passByReference(number);
    cout << "After passByReference: " << number << endl;  // Changed!
    
    passByConstReference(number);
    
    // Chaining with reference return
    int value = 100;
    returnByReference(value) = 200;  // This works!
    cout << "After returnByReference() = 200: " << value << endl;
}

// =============================================================================
// PART 6: DYNAMIC MEMORY MANAGEMENT
// =============================================================================

void demonstrateDynamicMemory() {
    cout << "\n=== PART 6: DYNAMIC MEMORY MANAGEMENT ===" << endl;
    
    // Single object allocation
    int* single = new int(42);
    cout << "Dynamically allocated int: " << *single << endl;
    
    // Array allocation
    int size = 5;
    int* array = new int[size];
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        array[i] = i * 10;
    }
    
    cout << "Dynamic array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    // CRITICAL: Always delete what you new!
    delete single;      // Delete single object
    delete[] array;     // Delete array (note the [])
    
    // After delete, pointer becomes dangling - points to freed memory
    // *single = 100;  // UNDEFINED BEHAVIOR! Don't use after delete
    single = nullptr;   // Good practice: set to nullptr after delete
    
    // Memory leak example (commented out to prevent actual leak)
    // int* leak = new int(42);
    // leak = new int(100);  // Lost the first allocation - memory leak!
}

// =============================================================================
// PART 7: SMART POINTERS (MODERN C++ APPROACH)
// =============================================================================

class Resource {
    string name;
public:
    Resource(string n) : name(n) {
        cout << "Resource " << name << " created" << endl;
    }
    ~Resource() {
        cout << "Resource " << name << " destroyed" << endl;
    }
    void use() { cout << "Using " << name << endl; }
};

void demonstrateSmartPointers() {
    cout << "\n=== PART 7: SMART POINTERS ===" << endl;
    
    // unique_ptr - exclusive ownership
    {
        cout << "\nUnique pointer:" << endl;
        unique_ptr<Resource> uptr = make_unique<Resource>("UniqueResource");
        uptr->use();
        
        // unique_ptr<Resource> uptr2 = uptr;  // ERROR! Cannot copy
        unique_ptr<Resource> uptr2 = move(uptr);  // But can move
        
        if (!uptr) {
            cout << "uptr is now null after move" << endl;
        }
        if (uptr2) {
            cout << "uptr2 now owns the resource" << endl;
            uptr2->use();
        }
    }  // uptr2 goes out of scope, automatically deletes Resource
    
    // shared_ptr - shared ownership with reference counting
    {
        cout << "\nShared pointer:" << endl;
        shared_ptr<Resource> sptr1 = make_shared<Resource>("SharedResource");
        cout << "Reference count: " << sptr1.use_count() << endl;
        
        {
            shared_ptr<Resource> sptr2 = sptr1;  // Share ownership
            cout << "Reference count: " << sptr1.use_count() << endl;
            sptr2->use();
        }  // sptr2 destroyed, but Resource still alive
        
        cout << "Reference count: " << sptr1.use_count() << endl;
        sptr1->use();  // Still valid!
    }  // Last shared_ptr destroyed, Resource deleted
    
    // weak_ptr - observe without owning
    cout << "\nWeak pointer:" << endl;
    weak_ptr<Resource> wptr;
    {
        shared_ptr<Resource> sptr = make_shared<Resource>("WeakObserved");
        wptr = sptr;  // Observe but don't own
        
        if (auto locked = wptr.lock()) {  // Convert to shared_ptr to use
            locked->use();
        }
    }  // sptr destroyed, Resource deleted
    
    if (wptr.expired()) {
        cout << "Weak pointer now expired" << endl;
    }
}

// =============================================================================
// PART 8: POINTER TO POINTER (MULTIPLE INDIRECTION)
// =============================================================================

void modifyPointer(int** ptr_to_ptr) {
    static int new_value = 999;  // Static so it persists after function
    *ptr_to_ptr = &new_value;    // Change what the original pointer points to
}

void demonstratePointerToPointer() {
    cout << "\n=== PART 8: POINTER TO POINTER ===" << endl;
    
    int value = 42;
    int* ptr = &value;
    int** ptr_to_ptr = &ptr;
    
    cout << "value: " << value << endl;
    cout << "ptr points to: " << *ptr << endl;
    cout << "ptr_to_ptr points to ptr which points to: " << **ptr_to_ptr << endl;
    
    // Modify the pointer itself through pointer-to-pointer
    modifyPointer(&ptr);
    cout << "\nAfter modifyPointer(&ptr):" << endl;
    cout << "ptr now points to: " << *ptr << endl;
    
    // 2D dynamic array using pointer to pointer
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
    
    cout << "\n2D array using pointer to pointer:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Clean up 2D array
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// =============================================================================
// PART 9: FUNCTION POINTERS
// =============================================================================

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int subtract(int a, int b) { return a - b; }

void demonstrateFunctionPointers() {
    cout << "\n=== PART 9: FUNCTION POINTERS ===" << endl;
    
    // Declare and initialize function pointer
    int (*operation)(int, int) = add;
    
    cout << "5 + 3 = " << operation(5, 3) << endl;
    
    // Change what function it points to
    operation = multiply;
    cout << "5 * 3 = " << operation(5, 3) << endl;
    
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply};
    const char* names[] = {"add", "subtract", "multiply"};
    
    cout << "\nUsing array of function pointers:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << names[i] << "(10, 5) = " << operations[i](10, 5) << endl;
    }
    
    // Modern C++ alternative: std::function
    // #include <functional>
    // std::function<int(int, int)> modern_op = add;
    // cout << "\nUsing std::function: " << modern_op(7, 3) << endl;
}

// =============================================================================
// PART 10: CLASS MEMBERS AND THE 'this' POINTER
// =============================================================================

class Counter {
private:
    int* count;
    static int instance_count;  // Shared among all instances
    
public:
    // Constructor
    Counter(int initial = 0) {
        count = new int(initial);
        instance_count++;
        cout << "Counter #" << instance_count << " created with value " << *count << endl;
    }
    
    // Copy constructor - deep copy
    Counter(const Counter& other) {
        count = new int(*other.count);  // Allocate new memory
        instance_count++;
        cout << "Counter #" << instance_count << " copy-constructed with value " << *count << endl;
    }
    
    // Assignment operator
    Counter& operator=(const Counter& other) {
        if (this != &other) {  // Check for self-assignment using this pointer
            *count = *other.count;  // Copy value, not pointer
        }
        return *this;  // Return reference to this object
    }
    
    // Destructor
    ~Counter() {
        cout << "Counter with value " << *count << " destroyed" << endl;
        delete count;
        instance_count--;
    }
    
    // Member functions using this pointer
    Counter& increment() {
        (*count)++;
        return *this;  // Enable chaining
    }
    
    Counter& add(int value) {
        *count += value;
        return *this;  // Enable chaining
    }
    
    void print() const {
        cout << "Count: " << *count << " (at address " << count << ")" << endl;
    }
    
    // Compare using this pointer
    // bool equals(const Counter& other) const {
    //     return this->*count == *other.count;  // Explicit this usage
    // }
};

int Counter::instance_count = 0;  // Initialize static member

void demonstrateThisPointer() {
    cout << "\n=== PART 10: THE 'this' POINTER ===" << endl;
    
    Counter c1(10);
    Counter c2(20);
    Counter c3 = c1;  // Copy constructor
    
    c1.print();
    c2.print();
    c3.print();
    
    // Method chaining using this pointer
    cout << "\nMethod chaining:" << endl;
    c1.increment().add(5).increment().print();
    
    // Assignment operator
    c2 = c1;
    cout << "\nAfter c2 = c1:" << endl;
    c2.print();
}

// =============================================================================
// PART 11: COMMON PITFALLS AND BEST PRACTICES
// =============================================================================

void demonstratePitfalls() {
    cout << "\n=== PART 11: COMMON PITFALLS ===" << endl;
    
    // 1. Dangling pointer
    int* dangling;
    {
        int temp = 42;
        dangling = &temp;
    }  // temp is destroyed here
    // cout << *dangling;  // UNDEFINED BEHAVIOR! temp no longer exists
    
    // 2. Memory leak (intentionally commented)
    // int* leak = new int(42);
    // leak = new int(100);  // Lost reference to first allocation
    
    // 3. Double delete
    int* ptr = new int(42);
    delete ptr;
    // delete ptr;  // UNDEFINED BEHAVIOR! Already deleted
    ptr = nullptr;  // Good practice
    delete ptr;  // Safe - delete nullptr is no-op
    
    // 4. Array/pointer confusion
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr_arr = arr;
    // delete[] ptr_arr;  // WRONG! arr is on stack, not heap
    
    // 5. Uninitialized pointer
    int* uninit;  // Contains garbage
    // *uninit = 42;  // UNDEFINED BEHAVIOR! Where does uninit point?
    
    cout << "Common pitfalls demonstrated (see code comments)" << endl;
}

// =============================================================================
// PRACTICAL EXAMPLE: A STRING CLASS USING POINTERS
// =============================================================================

class MyString {
private:
    char* data;
    size_t length;
    
public:
    // Constructor
    MyString(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        cout << "MyString created: \"" << data << "\"" << endl;
    }
    
    // Copy constructor (deep copy)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        cout << "MyString copy-constructed: \"" << data << "\"" << endl;
    }
    
    // Move constructor (C++11)
    MyString(MyString&& other) noexcept {
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
        cout << "MyString move-constructed: \"" << data << "\"" << endl;
    }
    
    // Destructor
    ~MyString() {
        if (data) {
            cout << "MyString destroyed: \"" << data << "\"" << endl;
            delete[] data;
        }
    }
    
    // Assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    
    // Subscript operator (return reference for modification)
    char& operator[](size_t index) {
        return data[index];
    }
    
    // Const version for const objects
    const char& operator[](size_t index) const {
        return data[index];
    }
    
    // Get C-string
    const char* c_str() const {
        return data;
    }
    
    // Get length
    size_t size() const {
        return length;
    }
};

void demonstratePracticalExample() {
    cout << "\n=== PRACTICAL EXAMPLE: CUSTOM STRING CLASS ===" << endl;
    
    MyString s1("Hello");
    MyString s2 = s1;  // Copy constructor
    MyString s3("World");
    
    s2[0] = 'J';  // Modify through reference
    cout << "s1: " << s1.c_str() << endl;
    cout << "s2: " << s2.c_str() << endl;
    
    MyString s4 = std::move(s3);  // Move constructor
    // s3 is now empty
}

// =============================================================================
// MAIN FUNCTION - RUN ALL DEMONSTRATIONS
// =============================================================================

int main() {
    cout << "=====================================================" << endl;
    cout << "    C++ POINTERS AND REFERENCES COMPLETE TUTORIAL   " << endl;
    cout << "=====================================================" << endl;
    cout << "\nStudy each section carefully. Uncomment dangerous" << endl;
    cout << "examples to see what happens (save your work first!)" << endl;
    
    // demonstrateBasics();
    // demonstrateNullPointers();
    // demonstrateConst();
    // demonstrateArraysAndArithmetic();
    demonstrateFunctionParameters();
    // demonstrateDynamicMemory();
    // demonstrateSmartPointers();
    // demonstratePointerToPointer();
    // demonstrateFunctionPointers();
    // demonstrateThisPointer();
    // demonstratePitfalls();
    // demonstratePracticalExample();
    
    // cout << "\n=====================================================" << endl;
    // cout << "                 TUTORIAL COMPLETE!                  " << endl;
    // cout << "=====================================================" << endl;
    // cout << "\nNext steps:" << endl;
    // cout << "1. Modify the examples and see what happens" << endl;
    // cout << "2. Uncomment the dangerous code (one at a time!)" << endl;
    // cout << "3. Add your own test cases to each section" << endl;
    // cout << "4. Use the debugger to step through pointer operations" << endl;
    
    return 0;
}