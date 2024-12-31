#include <iostream>
#include <cstdlib> // For system()
using namespace std;

int main() {
    cout << "Building project using setup script..." << endl;

    // Execute the build command
    int result = system("python3 setup.py bdist_wheel");

    if (result == 0) {
        cout << "Build completed successfully." << endl;
    } else {
        cerr << "Build failed with error code: " << result << endl;
    }

    return 0;
}
