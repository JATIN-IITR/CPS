document.getElementById("algorithm").addEventListener("change", function() {
    const algorithm = document.getElementById("algorithm").value;
    const quantumDiv = document.getElementById("quantumDiv");
    if (algorithm === "rr") {
        quantumDiv.style.display = "block";
    } else {
        quantumDiv.style.display = "none";
    }
});

async function simulateScheduling() {
    const algorithm = document.getElementById("algorithm").value;
    const processesText = document.getElementById("processes").value.trim();
    const processes = processesText.split("\n").map(line => {
        const [pid, burstTime, priority] = line.split(",").map(Number);
        return { pid, burstTime, priority };
    });

    const requestBody = {
        algorithm: algorithm,
        processes: processes
    };

    if (algorithm === "rr") {
        const quantum = document.getElementById("quantum").value;
        requestBody.quantum = parseInt(quantum, 10);
    }

    try {
        const response = await fetch("http://localhost:18080/schedule", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(requestBody)
        });

        if (!response.ok) {
            throw new Error('Network response was not ok');
        }

        const result = await response.json();
        displayResults(result);
        displayStats(result);
        displayGanttChart(result);
    } catch (error) {
        console.error('There has been a problem with your fetch operation:', error);
    }
}

function displayResults(results) {
    const resultsDiv = document.getElementById("results");
    resultsDiv.innerHTML = "";

    if (!Array.isArray(results) || !results.length) {
        resultsDiv.innerHTML = "<p>No results to display.</p>";
        return;
    }

    const table = document.createElement("table");
    const headerRow = table.insertRow();
    const headers = ["PID", "Burst Time", "Priority", "Waiting Time", "Turnaround Time"];
    headers.forEach(headerText => {
        const headerCell = document.createElement("th");
        headerCell.textContent = headerText;
        headerRow.appendChild(headerCell);
    });

    results.forEach(process => {
        const row = table.insertRow();
        Object.values(process).forEach(text => {
            const cell = row.insertCell();
            cell.textContent = text;
        });
    });

    resultsDiv.appendChild(table);
}

function displayStats(results) {
    const statsDiv = document.getElementById("stats");
    statsDiv.innerHTML = "";

    if (!Array.isArray(results) || !results.length) {
        statsDiv.innerHTML = "<p>No stats to display.</p>";
        return;
    }

    const totalWaitingTime = results.reduce((sum, process) => sum + process.waitingTime, 0);
    const totalTurnaroundTime = results.reduce((sum, process) => sum + process.turnaroundTime, 0);
    const averageWaitingTime = totalWaitingTime / results.length;
    const averageTurnaroundTime = totalTurnaroundTime / results.length;
    const totalBurstTime = results.reduce((sum, process) => sum + process.burstTime, 0);
    const makespan = Math.max(...results.map(process => process.finishTime));
    const cpuUtilization = (totalBurstTime / makespan) * 100;
    const throughput = results.length / makespan;

    statsDiv.innerHTML = `
        <p><strong>Average Waiting Time:</strong> ${averageWaitingTime.toFixed(2)}</p>
        <p><strong>Average Turnaround Time:</strong> ${averageTurnaroundTime.toFixed(2)}</p>
        <p><strong>CPU Utilization:</strong> ${cpuUtilization.toFixed(2)}%</p>
        <p><strong>Throughput:</strong> ${throughput.toFixed(2)} processes/unit time</p>
    `;
}

function displayGanttChart(results) {
    const ganttChartDiv = document.getElementById("ganttChart");
    ganttChartDiv.innerHTML = "";

    if (!Array.isArray(results) || !results.length) {
        ganttChartDiv.innerHTML = "<p>No Gantt chart to display.</p>";
        return;
    }

    results.forEach(process => {
        const ganttBar = document.createElement("div");
        ganttBar.className = "gantt-bar";
        ganttBar.style.width = ${process.burstTime * 10}px; // Scale width for visibility
        ganttBar.textContent = P${process.pid} (${process.startTime}-${process.finishTime});
        ganttChartDiv.appendChild(ganttBar);
    });
}

document.getElementById("schedulingForm").addEventListener("submit", function(event) {
    event.preventDefault();
    simulateScheduling();
});