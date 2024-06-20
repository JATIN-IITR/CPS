#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "algorithms.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace httplib;

std::vector<Process> parse_processes(const json& processes_json) {
    std::vector<Process> processes;
    for (const auto& item : processes_json) {
        processes.push_back(Process{item["pid"], item["burst_time"], item["priority"]});
    }
    return processes;
}

json to_json(const std::vector<Process>& processes) {
    json j = json::array();
    for (const auto& process : processes) {
        j.push_back({
            {"pid", process.pid},
            {"burst_time", process.burst_time},
            {"priority", process.priority},
            {"waiting_time", process.waiting_time},
            {"turnaround_time", process.turnaround_time},
            {"start_time", process.start_time},
            {"finish_time", process.finish_time}
        });
    }
    return j;
}

int main() {
    Server svr;

    svr.Post("/schedule", [](const Request& req, Response& res) {
        auto req_json = json::parse(req.body);
        auto algorithm = req_json["algorithm"].get<std::string>();
        auto processes = parse_processes(req_json["processes"]);
        int quantum = req_json.value("quantum", 1);

        std::vector<Process> result;

        if (algorithm == "fcfs") {
            result = fcfs(processes);
        } else if (algorithm == "sjf") {
            result = sjf(processes);
        } else if (algorithm == "priority") {
            result = priority_scheduling(processes);
        } else if (algorithm == "rr") {
            result = round_robin(processes, quantum);
        }

        res.set_content(to_json(result).dump(), "application/json");
    });

    svr.listen("0.0.0.0", 18080);
    return 0;
}
