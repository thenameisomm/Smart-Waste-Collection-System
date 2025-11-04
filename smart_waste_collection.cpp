#include <iostream>
using namespace std;

const int MAX = 20;
const int INF = 9999; // Large value (used as infinity)

// Structure for bin
struct Bin {
    int id;
    int location;
    int fillLevel; // 0 to 100
};

// Structure for truck
struct Truck {
    int id;
    int location;
    bool available;
};

// Function to find vertex with minimum distance
int minDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra’s algorithm to find shortest path distance
int dijkstra(int graph[MAX][MAX], int src, int dest, int n) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break; // No valid vertex left
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist[dest];
}

int main() {
    int n, binCount, truckCount;
    int cityMap[MAX][MAX];

    cout << "==== SMART WASTE COLLECTION MANAGEMENT SYSTEM ====\n";

    cout << "\nEnter number of locations in city (max 20): ";
    cin >> n;

    cout << "\nEnter distance matrix (" << n << "x" << n << "):\n";
    cout << "(Enter 0 if there is no direct path between locations)\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cityMap[i][j];
        }
    }

    cout << "\nEnter number of garbage bins: ";
    cin >> binCount;

    Bin bins[MAX];
    for (int i = 0; i < binCount; i++) {
        cout << "\nEnter details for Bin " << i + 1 << ":\n";
        bins[i].id = i + 1;
        cout << "Enter location (0 to " << n - 1 << "): ";
        cin >> bins[i].location;
        cout << "Enter fill level (0 to 100): ";
        cin >> bins[i].fillLevel;
    }

    cout << "\nEnter number of garbage trucks: ";
    cin >> truckCount;

    Truck trucks[MAX];
    for (int i = 0; i < truckCount; i++) {
        trucks[i].id = i + 1;
        cout << "\nEnter location of Truck " << i + 1 << " (0 to " << n - 1 << "): ";
        cin >> trucks[i].location;
        trucks[i].available = true;
    }

    cout << "\n================= PROCESSING =================\n";

    for (int i = 0; i < binCount; i++) {
        if (bins[i].fillLevel >= 80) { // Full bin
            cout << "\nFull Bin Detected: Bin " << bins[i].id
                 << " (Location " << bins[i].location << ")";

            int nearestTruck = -1;
            int minDist = INF;

            // Find nearest available truck
            for (int j = 0; j < truckCount; j++) {
                if (trucks[j].available) {
                    int dist = dijkstra(cityMap, trucks[j].location, bins[i].location, n);
                    if (dist < minDist) {
                        minDist = dist;
                        nearestTruck = j;
                    }
                }
            }

            if (nearestTruck != -1) {
                cout << "\nNearest Truck: Truck " << trucks[nearestTruck].id
                     << " (Location " << trucks[nearestTruck].location << ")";
                cout << "\nShortest Distance: " << minDist << " km\n";
                trucks[nearestTruck].available = false; // Mark as busy
            } else {
                cout << "\nNo available truck found!\n";
            }
        }
    }

    cout << "\nAll full bins have been assigned for collection.\n";
    cout << "==================================================\n";
    return 0;
}