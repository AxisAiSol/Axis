#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <optional>
using namespace std;

// Mock Client class for making HTTP requests
class Client {
public:
    static string request_action(const string& method, const string& endpoint, const map<string, string>& params = {}) {
        cout << "Making " << method << " request to: " << endpoint << endl;
        // Simulated JSON response as string
        return "{\"id\": \"job123\", \"agent_id\": \"agent123\", \"created\": \"2023-12-30\", \"next\": null, \"previous\": null, \"total_count\": 1, \"current_page\": 1, \"results\": [{\"id\": \"job123\", \"agent_id\": \"agent123\", \"created\": \"2023-12-30\"}]}";
    }
};

// PagePaginatedResource class
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

// AgentBuilderJob class
class AgentBuilderJob {
public:
    string id;
    string agent_id;
    string created;

    // Constructor
    AgentBuilderJob(const string& job_id, const string& agent, const string& create_date)
        : id(job_id), agent_id(agent), created(create_date) {}

    static string api_source() {
        return "agent-builder-jobs";
    }

    static PagePaginatedResource<AgentBuilderJob> list(optional<string> agent_id = nullopt, int page = 1, int page_size = 10) {
        cout << "Listing AgentBuilderJobs with pagination: page " << page << ", page_size " << page_size << endl;

        map<string, string> params = {{"page", to_string(page)}, {"page_size", to_string(page_size)}};
        if (agent_id) {
            params["agent_id"] = *agent_id;
        }

        string response = Client::request_action("GET", api_source() + "/", params);

        // Simulating response parsing and creating PagePaginatedResource
        vector<AgentBuilderJob> results = {AgentBuilderJob("job123", "agent123", "2023-12-30")};
        return PagePaginatedResource<AgentBuilderJob>(nullopt, nullopt, 1, 1, results);
    }

    static AgentBuilderJob retrieve(const string& id) {
        cout << "Retrieving AgentBuilderJob with ID: " << id << endl;

        string response = Client::request_action("GET", api_source() + "/" + id + "/");

        // Simulating response parsing
        return AgentBuilderJob("job123", "agent123", "2023-12-30");
    }
};

int main() {
    // Example usage
    cout << "Listing AgentBuilderJobs:" << endl;
    auto jobs = AgentBuilderJob::list();
    for (const auto& job : jobs.results) {
        cout << "Job ID: " << job.id << ", Agent ID: " << job.agent_id << ", Created: " << job.created << endl;
    }

    cout << "Retrieving a specific AgentBuilderJob:" << endl;
    AgentBuilderJob job = AgentBuilderJob::retrieve("job123");
    cout << "Retrieved Job ID: " << job.id << ", Agent ID: " << job.agent_id << ", Created: " << job.created << endl;

    return 0;
}
