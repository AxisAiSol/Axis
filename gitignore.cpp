#include <iostream>
using namespace std;

int main() {
    // Exclude compiled or optimized files
    cout << "Excluding compiled or optimized files:" << endl;
    cout << "__cache__/*" << endl;
    cout << "*.o" << endl;
    cout << "*.dll" << endl;

    // Exclude build and packaging files
    cout << "Excluding build and packaging files:" << endl;
    cout << "build/" << endl;
    cout << "dist/" << endl;
    cout << "*.manifest" << endl;
    cout << "*.spec" << endl;

    // Exclude log and temporary files
    cout << "Excluding log and temporary files:" << endl;
    cout << "*.log" << endl;
    cout << "*.tmp" << endl;

    // Exclude environment and dependency files
    cout << "Excluding environment and dependency files:" << endl;
    cout << "env/" << endl;
    cout << "venv/" << endl;
    cout << ".env" << endl;

    // Exclude IDE and tooling files
    cout << "Excluding IDE and tooling files:" << endl;
    cout << ".vscode/" << endl;
    cout << ".idea/" << endl;

    // Exclude test and coverage files
    cout << "Excluding test and coverage files:" << endl;
    cout << ".coverage" << endl;
    cout << "coverage.xml" << endl;
    cout << "tests/" << endl;

    // Exclude documentation build files
    cout << "Excluding documentation build files:" << endl;
    cout << "docs/_build/" << endl;

    return 0;
}
