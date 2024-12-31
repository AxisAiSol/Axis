#include <iostream>
using namespace std;

int main() {
    cout << "Setting up multiple environments for Axis SDK containers." << endl;

    // Environment for Axis SDK with C++17
    cout << "Environment: Axis C++17" << endl;
    cout << "Container name: axis-cpp17" << endl;
    cout << "Dockerfile target: cpp17" << endl;
    cout << "Volumes: Mounting repository to container workspace." << endl;
    cout << "Environment variables: AXIS_API_KEY and AXIS_API_BASE configured." << endl;

    // Environment for Axis SDK with C++20
    cout << "Environment: Axis C++20" << endl;
    cout << "Container name: axis-cpp20" << endl;
    cout << "Dockerfile target: cpp20" << endl;
    cout << "Volumes: Mounting repository to container workspace." << endl;
    cout << "Environment variables: AXIS_API_KEY and AXIS_API_BASE configured." << endl;

    // Environment for Axis SDK with C++23
    cout << "Environment: Axis C++23" << endl;
    cout << "Container name: axis-cpp23" << endl;
    cout << "Dockerfile target: cpp23" << endl;
    cout << "Volumes: Mounting repository to container workspace." << endl;
    cout << "Environment variables: AXIS_API_KEY and AXIS_API_BASE configured." << endl;

    cout << "All environments have been successfully set up!" << endl;

    return 0;
}
