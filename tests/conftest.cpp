#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
using namespace std;

int main() {
    // Setting up the Axis SDK environment for C++ tests
    cout << "Configuring Axis SDK environment for tests..." << endl;

    // Define environment variables
    const char* api_base = getenv("AXIS_API_BASE");
    const char* api_key = getenv("AXIS_API_KEY");

    // Check if environment variables are set
    if (!api_base || !api_key) {
        cerr << "Error: Required environment variables AXIS_API_BASE or AXIS_API_KEY are not set." << endl;
        return EXIT_FAILURE;
    }

    // Set environment variables in the test configuration
    cout << "API Base: " << api_base << endl;
    cout << "API Key: " << api_key << endl;

    // Mock path setup for dependency resolution
    string current_dir = filesystem::current_path();
    string src_path = current_dir + "/../src";
    cout << "Adding source path for dependency resolution: " << src_path << endl;

    cout << "Axis SDK environment configuration completed successfully." << endl;
    return 0;
}
