#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
using namespace std;

// Base class for API errors
class APIError : public runtime_error {
private:
    string message;
    string code;
    map<string, string> extra;

public:
    APIError(const string& msg, const string& err_code, const map<string, string>& additional_info)
        : runtime_error(msg), message(msg), code(err_code), extra(additional_info) {}

    string to_json() const {
        string json_rep = "{ \"message\": \"" + message + "\", \"code\": \"" + code + "\", \"extra\": {";
        for (const auto& pair : extra) {
            json_rep += "\"" + pair.first + "\": \"" + pair.second + "\", ";
        }
        if (!extra.empty()) {
            json_rep.pop_back(); // Remove trailing space
            json_rep.pop_back(); // Remove trailing comma
        }
        json_rep += "} }";
        return json_rep;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Derived classes for specific API errors
class Unauthenticated : public APIError {
public:
    Unauthenticated(const string& msg, const map<string, string>& additional_info)
        : APIError(msg, "401", additional_info) {}
};

class NotFound : public APIError {
public:
    NotFound(const string& msg, const map<string, string>& additional_info)
        : APIError(msg, "404", additional_info) {}
};

class BadRequest : public APIError {
public:
    BadRequest(const string& msg, const map<string, string>& additional_info)
        : APIError(msg, "400", additional_info) {}
};

int main() {
    try {
        // Simulate an error
        throw BadRequest("Invalid request data", {{"field", "username"}, {"error", "missing"}});
    } catch (const APIError& e) {
        cerr << "API Error: " << e.what() << endl;
        cerr << "Details: " << e.to_json() << endl;
    }

    cout << "Program completed." << endl;
    return 0;
}
