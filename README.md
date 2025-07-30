# CPU Scheduling Algorithm Simulator

A web-based simulator for visualizing common CPU scheduling algorithms using C++ and WebAssembly.

![CPU Scheduling Simulator](https://i.imgur.com/YHqYRMZ.png)

## 🚀 Features

- Simulate and visualize three popular CPU scheduling algorithms:
  - **First Come, First Served (FCFS)**: Non-preemptive scheduling in arrival order
  - **Round Robin (RR)**: Preemptive scheduling with configurable time quantum
  - **Shortest Job First (SJF)**: Non-preemptive scheduling prioritizing shortest burst time

- Interactive visualization with:
  - Gantt chart representation of process execution
  - Waiting time and turnaround time calculations
  - Performance metrics comparison

## 💻 Technologies Used

- **C++**: Core scheduling algorithm implementation
- **WebAssembly**: Compiling C++ to run in the browser
- **JavaScript**: UI interaction and visualization
- **HTML/CSS**: User interface

## 🔧 How It Works

The application uses C++ to implement the scheduling algorithms, which is then compiled to WebAssembly using Emscripten. This allows for efficient execution directly in the browser while leveraging the performance benefits of C++.

## 🏗️ Project Structure

```
cpu-scheduler/
├── public/              # Static files served to the browser
│   ├── index.html       # Main HTML file
│   ├── scheduler.js     # Generated JS glue code
│   └── scheduler.wasm   # WebAssembly binary
├── src/                 # Source code
│   └── scheduler.cpp    # C++ implementation of scheduling algorithms
├── vercel.json          # Vercel deployment configuration
└── README.md            # Project documentation
```

## 🚀 Getting Started

### Prerequisites

- Emscripten (for compilation)
- A modern web browser
- Basic web server (Python's http.server, Node's http-server, etc.)

### Running Locally

1. Clone the repository:
   ```bash
   git clone https://github.com/rkb3004/cpu-scheduler.git
   cd cpu-scheduler
   ```

2. Compile the C++ code to WebAssembly:
   ```bash
   emcc src/scheduler.cpp -o public/scheduler.js \
     -s EXPORTED_FUNCTIONS="['_simulateFCFS', '_simulateRoundRobin', '_simulateSJF', '_getOutput']" \
     -s EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap']" \
     -s ENVIRONMENT='web'
   ```

3. Serve the public directory:
   ```bash
   cd public
   python3 -m http.server
   ```

4. Open your browser and navigate to `http://localhost:8000`

## 📊 Using the Simulator

1. Choose a scheduling algorithm by clicking one of the buttons
2. For Round Robin, you can adjust the time quantum
3. View the results in the text output or switch to the visualization tab
4. Compare metrics like average waiting time and average turnaround time

## 🌐 Live Demo

Check out the live demo at: [https://cpu-scheduler-hdos.vercel.app/](https://cpu-scheduler-hdos.vercel.app/)

## 📝 Implementation Details

### FCFS (First Come, First Served)
- Processes are executed in the order they arrive
- Simple implementation but can lead to the convoy effect

### Round Robin
- Each process gets a fixed time slice (quantum)
- Preemptive - long processes are interrupted
- Good for time-sharing systems

### SJF (Shortest Job First)
- Executes the process with the shortest burst time first
- Optimal for minimizing average waiting time
- Requires knowledge of burst time in advance

## 🤝 Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to improve the simulator.

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.
