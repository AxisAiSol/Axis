#include <iostream>
#include <cstdlib> // For system()
using namespace std;

int main() {
    cout << "Running type checking on the project..." << endl;

    // Execute the type checker command
    int result = system("mypy src tests");

    if (result == 0) {
        cout << "Type checking completed successfully." << endl;
    } else {
        cerr << "Type checking failed with error code: " << result << endl;
    }

    return 0;
}
