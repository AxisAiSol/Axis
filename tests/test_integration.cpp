#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// Mock definitions for Axis SDK functionality
struct Job {
    string id;
};

struct Build {
    string id;
};

struct Execution {
    string id;
};

class Agent {
public:
    string id;

    static Agent create(const string& name, const string& script, const string& requirements, const string& env_vars, const string& cpp_version) {
        cout << "Creating agent: " << name << endl;
        return Agent{"agent123"};
    }

    static void delete_agent(const string& id) {
        cout << "Deleting agent: " << id << endl;
    }

    static vector<Agent> list() {
        return vector<Agent>{{"agent123"}, {"agent456"}};
    }

    static Agent retrieve(const string& id) {
        cout << "Retrieving agent: " << id << endl;
        return Agent{id};
    }

    Execution execute(bool wait = true) const {
        cout << "Executing agent: " << id << ", wait: " << (wait ? "true" : "false") << endl;
        return Execution{"execution123"};
    }
};

// Test cases
void test_agent_builder_job() {
    cout << "Testing agent builder job..." << endl;

    vector<Job> jobs = {{.id = "job123"}};
    assert(jobs.size() == 1);
    assert(jobs[0].id == "job123");

    Job job = {.id = "job123"};
    assert(job.id == "job123");
}

void test_build() {
    cout << "Testing build functionality..." << endl;

    vector<Build> builds = {{.id = "build123"}};
    assert(builds.size() == 1);
    assert(builds[0].id == "build123");

    Build build = {.id = "build123"};
    assert(build.id == "build123");
}

void test_execution() {
    cout << "Testing execution functionality..." << endl;

    vector<Execution> executions = {{.id = "execution123"}};
    assert(executions.size() == 1);
    assert(executions[0].id == "execution123");

    Execution execution = {.id = "execution123"};
    assert(execution.id == "execution123");
}

void test_agent() {
    cout << "Testing agent creation and management..." << endl;

    Agent agent = Agent::create("testagent2", "Handle payload", "requests", "FOO=BAR", "C++17");
    assert(Agent::list().size() == 2);
    assert(Agent::retrieve(agent.id).id == agent.id);

    Agent::delete_agent(agent.id);
    assert(Agent::list().size() == 1);
}

void test_execute_agent() {
    cout << "Testing agent execution..." << endl;

    Agent agent = Agent::retrieve("agent123");

    Execution execution = agent.execute();
    assert(execution.id == "execution123");

    Execution async_execution = agent.execute(false);
    assert(async_execution.id == "execution123");
}

int main() {
    test_agent_builder_job();
    test_build();
    test_execution();
    test_agent();
    test_execute_agent();

    cout << "All tests passed successfully!" << endl;
    return 0;
}
