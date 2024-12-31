#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <stdexcept>
using namespace std;

// Mock classes and methods for Axis SDK in C++
struct Build {
    string id;
    string status;
};

struct Execution {
    string id;
    string agent_executor_job_id;
};

class Agent {
public:
    string id;

    static Agent create(const string& name, const string& script, const string& cpp_version) {
        cout << "Creating agent: " << name << " with C++ version: " << cpp_version << endl;
        return Agent{"agent123"};
    }

    Execution execute() {
        cout << "Executing agent: " << id << endl;
        return Execution{"execution123", "executor123"};
    }

    static void delete_agent(const string& id) {
        cout << "Deleting agent: " << id << endl;
    }
};

class AgentBuilderJob {
public:
    static vector<Build> list(const string& agent_id) {
        cout << "Listing builds for agent: " << agent_id << endl;
        return {{"build123", "success"}};
    }
};

// Helper functions
void delete_all_agents() {
    cout << "Deleting all agents..." << endl;
    vector<Agent> agents = {Agent{"agent123"}, Agent{"agent456"}};
    for (const auto& agent : agents) {
        Agent::delete_agent(agent.id);
    }
}

map<string, string> prepare() {
    cout << "Preparing data for tests..." << endl;

    Agent agent = Agent::create("testagent", "cout << 'Hello World';", "C++17");

    auto builds = AgentBuilderJob::list(agent.id);
    string build_id;
    while (true) {
        this_thread::sleep_for(chrono::seconds(3));
        for (const auto& build : builds) {
            if (build.status == "success") {
                build_id = build.id;
                break;
            } else if (build.status == "failure") {
                throw runtime_error("Build failed.");
            }
        }
        if (!build_id.empty()) break;
    }

    Execution execution = agent.execute();

    return {
        {"agent_id", agent.id},
        {"agent_builder_job_id", "builder123"},
        {"build_id", build_id},
        {"agent_executor_job_id", execution.agent_executor_job_id},
        {"execution_id", execution.id},
    };
}

int main() {
    cout << "Starting test setup and teardown..." << endl;

    try {
        map<string, string> test_data = prepare();
        for (const auto& [key, value] : test_data) {
            cout << key << ": " << value << endl;
        }
        delete_all_agents();
    } catch (const exception& e) {
        cerr << "Error during preparation: " << e.what() << endl;
    }

    cout << "Test setup and teardown completed successfully." << endl;
    return 0;
}
