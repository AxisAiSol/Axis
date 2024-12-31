#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>
using namespace std;

// Mock Client class for making HTTP requests
class Client {
public:
    static string request_url(const string& method, const string& url) {
        cout << "Making " << method << " request to: " << url << endl;
        // Simulated JSON response
        return "{\"next\": \"next_url\", \"previous\": \"prev_url\", \"results\": [\"item1\", \"item2\"]}";
    }
};

// Generic CursorPaginatedResource class
template <typename T>
class CursorPaginatedResource {
private:
    optional<string> next_url;
    optional<string> previous_url;
    vector<T> results;

public:
    CursorPaginatedResource(optional<string> next, optional<string> previous, const vector<T>& res)
        : next_url(next), previous_url(previous), results(res) {}

    optional<CursorPaginatedResource<T>> next() {
        if (!next_url.has_value()) {
            return nullopt;
        }
        string response = Client::request_url("GET", next_url.value());
        // Simulate parsing response and creating new CursorPaginatedResource
        return CursorPaginatedResource<T>("next_url_parsed", "prev_url_parsed", {"item3", "item4"});
    }

    optional<CursorPaginatedResource<T>> previous() {
        if (!previous_url.has_value()) {
            return nullopt;
        }
        string response = Client::request_url("GET", previous_url.value());
        // Simulate parsing response and creating new CursorPaginatedResource
        return CursorPaginatedResource<T>("next_url_parsed", "prev_url_parsed", {"item1", "item2"});
    }

    void print_results() const {
        cout << "Results: ";
        for (const auto& result : results) {
            cout << result << " ";
        }
        cout << endl;
    }
};

// Generic PagePaginatedResource class
template <typename T>
class PagePaginatedResource {
private:
    optional<string> next_url;
    optional<string> previous_url;
    int total_count;
    int current_page;
    vector<T> results;

public:
    PagePaginatedResource(optional<string> next, optional<string> previous, int total, int page, const vector<T>& res)
        : next_url(next), previous_url(previous), total_count(total), current_page(page), results(res) {}

    optional<PagePaginatedResource<T>> next() {
        if (!next_url.has_value()) {
            return nullopt;
        }
        string response = Client::request_url("GET", next_url.value());
        // Simulate parsing response and creating new PagePaginatedResource
        return PagePaginatedResource<T>("next_url_parsed", "prev_url_parsed", 10, current_page + 1, {"item3", "item4"});
    }

    optional<PagePaginatedResource<T>> previous() {
        if (!previous_url.has_value()) {
            return nullopt;
        }
        string response = Client::request_url("GET", previous_url.value());
        // Simulate parsing response and creating new PagePaginatedResource
        return PagePaginatedResource<T>("next_url_parsed", "prev_url_parsed", 10, current_page - 1, {"item1", "item2"});
    }

    void print_results() const {
        cout << "Results: ";
        for (const auto& result : results) {
            cout << result << " ";
        }
        cout << endl;
    }
};

int main() {
    // Example usage of CursorPaginatedResource
    CursorPaginatedResource<string> cursor_resource("next_url", "prev_url", {"item1", "item2"});
    cursor_resource.print_results();

    if (auto next_page = cursor_resource.next()) {
        next_page->print_results();
    }

    // Example usage of PagePaginatedResource
    PagePaginatedResource<string> page_resource("next_url", "prev_url", 20, 1, {"item1", "item2"});
    page_resource.print_results();

    if (auto next_page = page_resource.next()) {
        next_page->print_results();
    }

    return 0;
}
