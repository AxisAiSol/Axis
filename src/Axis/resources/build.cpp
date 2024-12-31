#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <optional>
using namespace std;

// Mock Client class for HTTP requests
class Client {
public:
    static string request_action(const string& method, const string& endpoint, const map<string, string>& params = {}) {
        cout << "Making " << method << " request to: " << endpoint << endl;
        // Simulated response
        return "{\"id\": \"build123\", \"agent_builder_job_id\": \"job123\", \"status\": \"success\", \"logs\": [{\"log\": \"Build completed successfully\"}], \"created\": \"2023-12-30\", \"next\": null, \"previous\": null, \"results\": [{\"id\": \"build123\", \"agent_builder_job_id\": \"job123\", \"status\": \"success\", \"logs\": [{\"log\": \"Build completed successfully\"}], \"created\": \"2023-12-30\"}]}";
    }
};

// PagePaginatedResource class for paginated responses
template <typename T>
class PagePaginatedResource {
public:
    optional<string> next_url;
    optional<string> previous_url;
    int total_count;
    int current_page;
    vector<T> results;

    PagePaginatedResource(optional<string> next, optional<string> previous, int total, int page, const vector<T>& res)
        : next_url(next), previous_url(previous), total_count(total), current_page(page), results(res) {}
};

// Build class
class Build {
public:
    string id;
    string agent_builder_job_id;
    string status; // Literal ["success", "in_progress", "failure"]
    vector<map<string, string>> logs;
    string created;

    // Constructor
    Build(const string& build_id, const string& job_id, const string& build_status, const vector<map<string, string>>& build_logs, const string& creation_date)
        : id(build_id), agent_builder_job_id(job_id), status(build_status), logs(build_logs), created(creation_date) {}

    static string api_source() {
        return "builds";
    }

    static PagePaginatedResource<Build> list(optional<string> agent_builder_job_id = nullopt, int page = 1, int page_size = 10) {
        cout << "Listing builds with pagination: page " << page << ", page_size " << page_size << endl;

        map<string, string> params = {{"page", to_string(page)}, {"page_size", to_string(page_size)}};
        if (agent_builder_job_id) {
            params["agent_builder_job_id"] = *agent_builder_job_id;
        }

        string response = Client::request_action("GET", api_source() + "/", params);

        // Simulate response parsing
        vector<map<string, string>> logs = { {{"log", "Build completed successfully"}} };
        vector<Build> results = {Build("build123", "job123", "success", logs, "2023-12-30")};
        return PagePaginatedResource<Build>(nullopt, nullopt, 1, 1, results);
    }

    static Build retrieve(const string& id) {
        cout << "Retrieving build with ID: " << id << endl;

        string response = Client::request_action("GET", api_source() + "/" + id + "/");

        // Simulate response parsing
        vector<map<string, string>> logs = { {{"log", "Build completed successfully"}} };
        return Build("build123", "job123", "success", logs, "2023-12-30");
    }
};

int main() {
    // Example usage
    cout << "Listing builds:" << endl;
    auto builds = Build::list();
    for (const auto& build : builds.results) {
        cout << "Build ID: " << build.id << ", Job ID: " << build.agent_builder_job_id << ", Status: " << build.status << ", Created: " << build.created << endl;
    }

    cout << "Retrieving a specific build:" << endl;
    Build build = Build::retrieve("build123");
    cout << "Retrieved Build ID: " << build.id << ", Job ID: " << build.agent_builder_job_id << ", Status: " << build.status << ", Created: " << build.created << endl;

    return 0;
}
