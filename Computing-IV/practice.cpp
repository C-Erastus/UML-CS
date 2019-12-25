#include <iostream> 
#include <memory> // contains Smart pointers.

int main(){

    shared_ptr<std::string> p1; 
    // shared_ptr that can point at a string

    shared_ptr<std::list<int>> p2; 
    // shared_ptr that can point at a list of ints

    // if p1 is not null, check whether it's the 
    // empty string

    if (p1 && p1->empty())
        *p1 = "hi" // if so, dereference p1 to 
                    // assign a new value to that 
                        // string

        // EXAMPLES OF MAKE_SHARED  

        // p3 is a shared_ptr that points to an int with value 42;
        shared_ptr<int>p3 = make_shared<int>(42);

        // p4 points to a string with value
        //9999999999
        shared_ptr<string> p4 = make_shared<string>(10, '9');

        // p5 points to tan int that is value
        // initialized to 0

        shared_ptr<int> p5 = make_share<int>();

        // p6 points to a dynamically allocated, empty vector<string>
        auto p6 = make_shared<vector<string>>();

    return 0; 
}

