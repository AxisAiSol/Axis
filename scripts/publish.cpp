#include <iostream>
#include <cstdlib> // For system()
using namespace std;

int main() {
    cout << "Uploading distribution packages using Twine..." << endl;

    // Execute the Twine upload command
    int result = system("python3 -m twine upload dist/*");

    if (result == 0) {
        cout << "Upload completed successfully." << endl;
    } else {
        cerr << "Upload failed with error code: " << result << endl;
    }

    return 0;
}
