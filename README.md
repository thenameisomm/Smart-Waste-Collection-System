# Smart Waste Collection Management System

### 🧩 Description
A simple DSA mini-project built in **C++** to optimize garbage collection in urban areas.
The system uses **Structures**, **Arrays**, and **Graphs** (with Dijkstra’s Algorithm) to assign the nearest garbage truck to each full bin.

---

### ⚙️ Features
- Takes city map as an adjacency matrix.
- Finds the nearest truck using Dijkstra’s algorithm.
- Automatically assigns trucks to full bins (≥80%).
- Displays shortest route distances.

---

### 🧠 Data Structures Used
1. **Structures** – For representing `Bin` and `Truck`.
2. **Arrays** – For storing bins, trucks, and city map.
3. **Graph (2D Array)** – To represent city locations and roads.

---

### 🧑‍💻 How to Run
1. Compile the code using any C++ compiler:
   ```bash
   g++ smart_waste_collection.cpp -o smart_waste
   ./smart_waste
