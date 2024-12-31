#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
using namespace std;

// Mock error classes
class BadRequest : public runtime_error {
public:
    explicit BadRequest(const string& msg) : runtime_error("BadRequest: " + msg) {}
};

class Unauthenticated : public runtime_error {
public:
    explicit Unauthenticated(const string& msg) : runtime_error("Unauthenticated: " + msg) {}
};

class NotFound : public runtime_error {
public:
    explicit NotFound(const string& msg) : runtime_error("NotFound: " + msg) {}
};

// Client class for handling HTTP and WebSocket requests
class Client {
private:
    static string api_key;
    static string api_base;

    static map<string, string> get_http_headers() {
        return {{"Authorization", "Bearer " + api_key}};
    }

    static void validate_response(int status_code, const string& response_body) {
        if (status_code == 400) {
            throw BadRequest(response_body);
        } else if (status_code == 401) {
            throw Unauthenticated(response_body);
        } else if (status_code == 404) {
            throw NotFound(response_body);
        }
    }

public:
    static string request_action(const string& method, const string& action_path, const map<string, string>& params = {}, const string& data = "") {
        string url = "https://" + api_base + "/v1/" + action_path;
        cout << "Making " << method << " request to " << url << endl;
        // Simulate HTTP request
        int status_code = 200; // Mock response code
        string response_body = "Response from server"; // Mock response
        validate_response(status_code, response_body);
        return response_body;
    }

    static string request_url(const string& method, const string& url, const string& data = "") {
        cout << "Making " << method << " request to " << url << endl;
        // Simulate HTTP request
        int status_code = 200; // Mock response code
        string response_body = "Response from server"; // Mock response
        validate_response(status_code, response_body);
        return response_body;
    }

    static string listen_to_execution(const string& address) {
        string url = "wss://" + api_base + "/ws/v1/execution/" + address + "/";
        cout << "Connecting to WebSocket at " << url << endl;
        // Simulate WebSocket connection
        string received_message = "Execution result"; // Mock message
        return received_message;
    }
};

// Static member initialization
string Client::api_key = "your_api_key";
string Client::api_base = "api.axis.ai";

int main() {
    try {
        // Example usage
        Client::request_action("GET", "example/path");
        string response = Client::request_url("POST", "https://api.axis.ai/v1/example", "{\"key\": \"value\"}");
        cout << "Response: " << response << endl;

        string message = Client::listen_to_execution("execution_address");
        cout << "WebSocket Message: " << message << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
