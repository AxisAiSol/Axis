#include <iostream>
#include <string>
using namespace std;

int main() {
    // Multi-environment setup for C++ projects
    cout << "Setting up multiple build environments for C++ projects:" << endl;

    // Environment: C++17
    cout << "Environment: C++17" << endl;
    cout << "Installing dependencies: build-essential, curl, libpq-dev, libssl-dev" << endl;
    cout << "Setting up user with ID: 1000 and group ID: 1000" << endl;
    cout << "Working directory: /repository" << endl;
    cout << "Environment variable PATH set to: /repository/src:$PATH" << endl;
    cout << "Entry point: Idle state to keep container running." << endl;

    // Environment: C++20
    cout << "Environment: C++20" << endl;
    cout << "Installing dependencies: build-essential, curl, libpq-dev, libssl-dev" << endl;
    cout << "Setting up user with ID: 1000 and group ID: 1000" << endl;
    cout << "Working directory: /repository" << endl;
    cout << "Environment variable PATH set to: /repository/src:$PATH" << endl;
    cout << "Entry point: Idle state to keep container running." << endl;

    // Environment: C++23
    cout << "Environment: C++23" << endl;
    cout << "Installing dependencies: build-essential, curl, libpq-dev, libssl-dev" << endl;
    cout << "Setting up user with ID: 1000 and group ID: 1000" << endl;
    cout << "Working directory: /repository" << endl;
    cout << "Environment variable PATH set to: /repository/src:$PATH" << endl;
    cout << "Entry point: Idle state to keep container running." << endl;

    cout << "All environments successfully configured." << endl;

    return 0;
}
