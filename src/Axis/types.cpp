#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <map>
using namespace std;

// Define a recursive type for JSON-like structures
class JSON; // Forward declaration

using JSONValue = variant<map<string, JSON>, vector<JSON>, string, int, float, bool, nullptr_t>;

class JSON {
public:
    JSONValue value;

    JSON() : value(nullptr) {}
    JSON(const JSONValue& val) : value(val) {}
};

int main() {
    // Example usage of JSON-like structures
    JSON json_object = map<string, JSON>{
        {"key1", JSON("value1")},
        {"key2", JSON(123)},
        {"key3", JSON(vector<JSON>{JSON(1.23), JSON(true), JSON("nested")})}
    };

    cout << "JSON-like structure created successfully!" << endl;

    return 0;
}
