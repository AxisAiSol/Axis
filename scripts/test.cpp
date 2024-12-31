#include <iostream>
#include <cstdlib> // For system()
using namespace std;

int main() {
    cout << "Running tests in Docker containers..." << endl;

    // Define Docker container names and commands
    string containers[] = {"axis-py38", "axis-py39", "axis-py310", "axis-py311", "axis-py312"};
    string command_template = "docker exec {container} pytest -s -x tests";

    // Execute the tests for each container
    for (const auto& container : containers) {
        string command = command_template;
        size_t pos = command.find("{container}");
        if (pos != string::npos) {
            command.replace(pos, 11, container);
        }

        cout << "Running tests in container: " << container << endl;
        int result = system(command.c_str());

        if (result != 0) {
            cerr << "Tests failed in container: " << container << " with error code: " << result << endl;
            return result;
        }
    }

    cout << "All tests completed successfully in all containers." << endl;
    return 0;
}
