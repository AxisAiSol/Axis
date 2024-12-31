#include <iostream>
#include <cstdlib> // For system()
using namespace std;

int main() {
    cout << "Running formatting and linting on the project..." << endl;

    // Run isort equivalent (e.g., include file sorter)
    int isort_result = system("isort src tests");
    if (isort_result != 0) {
        cerr << "isort failed with error code: " << isort_result << endl;
        return isort_result;
    }

    // Run black equivalent (e.g., code formatter)
    int black_result = system("black src tests");
    if (black_result != 0) {
        cerr << "black failed with error code: " << black_result << endl;
        return black_result;
    }

    // Run flake8 equivalent (e.g., linting tool)
    int flake8_result = system("flake8 src tests");
    if (flake8_result != 0) {
        cerr << "flake8 failed with error code: " << flake8_result << endl;
        return flake8_result;
    }

    cout << "Formatting and linting completed successfully." << endl;
    return 0;
}
