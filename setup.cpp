#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// Function to extract version information from a file
string get_version(const string& package) {
    string path = "src/" + package + "/__init__.cpp"; // Path to the version file
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << path << endl;
        exit(EXIT_FAILURE);
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    size_t start = content.find("__version__ = \"") + 14;
    size_t end = content.find("\"", start);
    if (start == string::npos || end == string::npos) {
        cerr << "Error: Version information not found in the file." << endl;
        exit(EXIT_FAILURE);
    }
    return content.substr(start, end - start);
}

// Main function to set up the SDK
int main() {
    string name = "axisai";
    string description = "Deploy serverless AI agents in the cloud. "
                         "Orchestrate collaboration between agents via the Axis C++ SDK.";
    string version = get_version("axisai");
    vector<string> packages = {"src"};
    string package_dir = "src";
    bool include_package_data = true;
    bool zip_safe = false;
    string license = "MIT";
    vector<string> install_requires = {"HTTP Client Library", "WebSocket Library"};
    vector<string> supported_standards = {"C++17", "C++20"};

    cout << "SDK Setup:\n";
    cout << "Name: " << name << "\n";
    cout << "Description: " << description << "\n";
    cout << "Version: " << version << "\n";
    cout << "Packages Directory: " << package_dir << "\n";
    cout << "Include Package Data: " << (include_package_data ? "Yes" : "No") << "\n";
    cout << "License: " << license << "\n";
    cout << "Dependencies: ";
    for (const auto& req : install_requires) {
        cout << req << " ";
    }
    cout << "\nSupported Standards: ";
    for (const auto& standard : supported_standards) {
        cout << standard << " ";
    }
    cout << endl;

    return 0;
}
