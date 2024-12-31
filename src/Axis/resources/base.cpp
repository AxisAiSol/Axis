#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Resource {
public:
    // Pure virtual function to represent the abstract method
    virtual string api_source() const = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Resource() {}
};

int main() {
    // Example: Abstract class can't be instantiated directly
    // Uncommenting the following line will cause a compilation error
    // Resource resource;

    cout << "Abstract Resource class implemented successfully!" << endl;

    return 0;
}
