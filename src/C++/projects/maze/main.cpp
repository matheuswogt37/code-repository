#include <iostream>
#include <cctype>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <utility>

// global var to manhattan heuristic
// like { 'name', {x, y}}
std::map<char, std::pair<int, int>> coords = {
    { 'A', { 2, 1} },
    { 'B', { 1, 4} },
    { 'C', { 3, 4} },
    { 'D', { 2, 7} },
    { 'E', { 2, 10} },
    { 'F', { 2, 13} },
    { 'G', { 5, 2} },
    { 'H', { 6, 5} },
    { 'I', { 5, 8} },
    { 'J', { 5, 12} },
    { 'K', { 7, 2} },
    { 'L', { 8, 8} },
    { 'M', { 8, 12} },
    { 'N', { 10, 2} },
    { 'O', { 10, 5} },
    { 'P', { 11, 10} },
    { 'Q', { 14, 2} },
    { 'R', { 14, 5} },
    { 'S', { 14, 7} },
    { 'T', { 14, 10} },
    { 'U', { 14, 13} }
};

// classes
class room {
  public:
    char name;
    std::map<room*, int> neighborns;
    bool visited;
    room(char name) {
      this->name = name;
      this->visited = false;
    }
    void addNeighborn(room *neighborn, int height) {
      this->neighborns[neighborn] = height;
    }
};

// functions to make room vector work's properly
room *findRoomByName(std::vector<room>& rooms, char name) {
  for (int i = 0; i < (int)rooms.size(); i++) {
    if (name == rooms[i].name) {
      return &rooms[i];
    }
  }
  return NULL;
}

void createAllNeighborns(std::vector<room> *rooms, char room1, std::vector<char> room2, std::vector<int> heights) {
  room *tempRoom;
  room *mainRoom = findRoomByName(*rooms, room1);
  // room1 to uppdercase
  room1 = std::toupper(room1);

  for (int i = 0; i < (int)room2.size(); i++) {
    // room2 to uppercase
    room2[i] =  std::toupper(room2[i]);
    tempRoom = findRoomByName(*rooms, room2[i]);
    if (NULL != tempRoom) {
      mainRoom->addNeighborn(tempRoom, heights[i]);
    }
  }
}

std::vector<room> createAllRooms(std::string allRooms, int allRoomsSize) {
  std::vector<room> rooms;

  for (int i = 0; i < allRoomsSize; i++) {
    rooms.push_back(room(allRooms[i]));
  }

  createAllNeighborns(&rooms, 'A', {'C'}, {5});
  createAllNeighborns(&rooms, 'B', {'C', 'D'}, {2, 4});
  createAllNeighborns(&rooms, 'C', {'A', 'B', 'G'}, {5, 2, 5});
  createAllNeighborns(&rooms, 'D', {'B', 'E'}, {4, 3});
  createAllNeighborns(&rooms, 'E', {'D', 'F'}, {3, 3});
  createAllNeighborns(&rooms, 'F', {'E', 'J'}, {3, 4});
  createAllNeighborns(&rooms, 'G', {'C', 'H', 'K'}, {5, 4, 2});
  createAllNeighborns(&rooms, 'H', {'G', 'I', 'K', 'L'}, {4, 4, 4, 4});
  createAllNeighborns(&rooms, 'I', {'H', 'J'}, {4, 4});
  createAllNeighborns(&rooms, 'J', {'F', 'I', 'M'}, {4, 4, 3});
  createAllNeighborns(&rooms, 'K', {'G', 'H', 'N'}, {2, 3, 3});
  createAllNeighborns(&rooms, 'L', {'H', 'M'}, {4, 4});
  createAllNeighborns(&rooms, 'M', {'J', 'L', 'P'}, {3, 4, 5});
  createAllNeighborns(&rooms, 'N', {'K', 'O', 'Q'}, {3, 3, 4});
  createAllNeighborns(&rooms, 'O', {'N', 'P'}, {3, 6});
  createAllNeighborns(&rooms, 'P', {'M', 'O', 'T'}, {5, 6, 3});
  createAllNeighborns(&rooms, 'Q', {'N', 'R'}, {4, 3});
  createAllNeighborns(&rooms, 'R', {'Q', 'S'}, {3, 2});
  createAllNeighborns(&rooms, 'S', {'R', 'T'}, {2, 3});
  createAllNeighborns(&rooms, 'T', {'P', 'S', 'U'}, {3, 3, 3});
  createAllNeighborns(&rooms, 'U', {'T'}, {3});
  
  return rooms;
}

// functions 
void drawMaze() {
    // std::cout << "─ │ ┌ ┐ └ ┘ ├ ┤ ┬ ┴ ┼" << "\n\n";
    std::cout << "\n";
    std::cout << "┌───┬─┬─┬───┬───┐" << "\n";
    std::cout << "│AAA│G│K│NNN│QQQ│" << "\n";
    std::cout << "├─┬ ┤G K NNN QQQ│" << "\n";
    std::cout << "│B│C G│K│NNN│QQQ│" << "\n";
    std::cout << "│B C├ ┴ ┼─ ─┼─ ─┤" << "\n";
    std::cout << "│B│C│HHH│OOO│RRR│" << "\n";
    std::cout << "├ ┴─┼ ┬ ┴─┬ ┼─ ─┤" << "\n";
    std::cout << "│DDD│I│LLL│P│SSS│" << "\n";
    std::cout << "├─ ─┤I│LLL│P├─ ─┤" << "\n";
    std::cout << "│EEE│I│LLL│P│TTT│" << "\n";
    std::cout << "│EEE├ ┼─ ─┤P TTT│" << "\n";
    std::cout << "│EEE│J│MMM│P│TTT│" << "\n";
    std::cout << "├─ ─┤J MMM P├─ ─┤" << "\n";
    std::cout << "│FFF J│MMM│P│UUU│" << "\n";
    std::cout << "└───┴─┴───┴─┴───┘" << "\n";
}

void askAttributes(char* init, char* final) {
  char tmpInit;
  char tmpFinal;
  char validatedInputs[22] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
  bool valid;
 
  drawMaze();
  
  std::cout << "Select what is the initial point: ";
  std::cin >> tmpInit;
  tmpInit = std::toupper(tmpInit);
  // validate tmpInit
  valid = false;
  for (int i = 0; i < 22; i++) {
    if (tmpInit == validatedInputs[i]) {
      valid = true;
      break;
    }
  }
  if (!valid) {
    std::cout << "ERROR\tOPTION NOT AVAILABLE!!!\n";
    return;
  }
  
  std::cout << "\nSelect what is the final point: ";
  std::cin >> tmpFinal;
  tmpFinal = std::toupper(tmpFinal);
  // validate tmpFinal
  valid = false;
  for (int i = 0; i < 22; i++) {
    if (tmpFinal == validatedInputs[i]) {
      valid = true;
      break;
    }
  }
  if (!valid) {
    std::cout << "ERROR\tOPTION NOT AVAILABLE!!!\n";
    return;
  }
  
  *init = tmpInit;
  *final = tmpFinal;
}

void resetVisited(std::vector<room>& rooms) {
  for (std::size_t i = 0; i < rooms.size(); i++) {
    rooms[i].visited = false;
  }
}

std::vector<char> buildPath(std::map<room*, room*> parent, room* finalRoom) {
  std::vector<char> path;
  for (room* current = finalRoom; current != NULL; current = parent[current]) {
    path.push_back(current->name);
  }
  std::reverse(path.begin(), path.end());
  return path;
}

std::vector<char> buildPathManhattan(std::map<room*, std::pair<room*, int>>& heuristic, room* startRoom) {
  std::vector<char> path;

  room* current = startRoom;
  while (current != nullptr) {
    path.push_back(current->name);
    current = heuristic[current].first;
  }

  return path;
}

// BFS -> retorna caminho
std::vector<char> BFS(std::vector<room>& rooms, char init, char final) {
  resetVisited(rooms);
  room* initRoom = findRoomByName(rooms, init);
  room* finalRoom = findRoomByName(rooms, final);
  room* current;

  std::queue<room*> fifo;
  std::map<room*, room*> parent;
  fifo.push(initRoom);
  parent[initRoom] = NULL;
  initRoom->visited = true;

  while(!fifo.empty()) {
    current = fifo.front(); 
    fifo.pop();
    if (current == finalRoom) { // its the final room
      return buildPath(parent, finalRoom);
    }
    for (auto& [neighbor, weight] : current->neighborns) {
      if (!neighbor->visited) {
        neighbor->visited = true;
        parent[neighbor] = current;
        fifo.push(neighbor);
      }
    }
  }

  return std::vector<char>();
}

// DFS -> retorna caminho
bool DFSrecursive(room* current, room* final, std::map<room*, room*>& parent) {
  current->visited = true;

  if (current == final) {
    return true;
  }
  for (auto& [neighbor, weight] : current->neighborns) {
    if (!neighbor->visited) {
      parent[neighbor] = current;
      if (DFSrecursive(neighbor, final, parent)) {
        return true;
      }
    }
  }
  return false;
}

std::vector<char> DFS(std::vector<room>& rooms, char start, char final) {
  resetVisited(rooms);
  room* startRoom = findRoomByName(rooms, start);
  room* finalRoom = findRoomByName(rooms, final);

  std::map<room*, room*> parent;
  parent[startRoom] = NULL;
  
  if (DFSrecursive(startRoom, finalRoom, parent)) {
    return buildPath(parent, finalRoom);
  }
  return std::vector<char>();
}

int manhattanHeuristic(char start, char final) {
  std::pair<int, int> startCoords = coords[start];
  std::pair<int, int> finalCoords = coords[final];;
  
  return (std::abs((startCoords.first - finalCoords.first)) + std::abs((startCoords.second - finalCoords.second)));
}

// Busca Gulosa -> retorna caminho
std::vector<char> Greedy(std::vector<room>& rooms, char start, char final) {
  room* finalRoom = findRoomByName(rooms, final);
  room* startRoom = findRoomByName(rooms, start);
  std::map<room*, std::pair<room*, int>> bestPaths;
  std::queue<room*> queue;
  room* current;
  std::pair<room*, int> currentBestWay;
  bool hasCurrentBestWay;

  queue.push(startRoom);
  current = queue.front();
  while(current != finalRoom) {
    queue.pop();
    hasCurrentBestWay = false;
    for (auto& [neighbor, weight] : current->neighborns) {
      if (!hasCurrentBestWay || manhattanHeuristic(neighbor->name, finalRoom->name) < currentBestWay.second) {
        currentBestWay = std::make_pair(neighbor, manhattanHeuristic(neighbor->name, finalRoom->name));
        hasCurrentBestWay = true;
      }
    }
    queue.push(currentBestWay.first);
    
    bestPaths[current] = std::make_pair(currentBestWay.first, currentBestWay.second);
    current = queue.front();
  }

  return buildPathManhattan(bestPaths, startRoom);
}

std::map<room*, int> AStarRealDistance(std::vector<room>& rooms, room* finalRoom) {
  std::map<room*, int> distance;
  std::queue<room*> queue;
  room* current;
  int actWeight;

  distance[finalRoom] = 0;
  queue.push(finalRoom);
  while(!queue.empty()) {
    current = queue.front();
    current->visited = true;
    
    for(auto& [neighbor, weight] : current->neighborns) {
      actWeight = weight + distance[current];
      auto it = distance.find(neighbor);
      if (it != distance.end()) { // alredy exist
        if (actWeight < distance[current]) {
          distance[neighbor] = distance[current] + weight;
          queue.push(neighbor);
        }
      } else { // it's new
        distance[neighbor] = actWeight;
      }
      if (false == neighbor->visited) {
        queue.push(neighbor);
      }
    }

    queue.pop();
  }

  return distance;
}

// A* -> retorna caminho
std::vector<char> AStar(std::vector<room>& rooms, char start, char final) {
  resetVisited(rooms);
  room* finalRoom = findRoomByName(rooms, final);
  room* startRoom = findRoomByName(rooms, start);
  std::map<room*, int> realDistance = AStarRealDistance(rooms, finalRoom);
  resetVisited(rooms);
  std::queue<room*> queue;
  room* current;
  std::vector<char> path;
  int actWeight = 0;
  int tempWeight;
  std::pair<room*, int> actBestWay;
  bool hasActBestWay;

  queue.push(startRoom);

  while(!queue.empty()) {
    current = queue.front();
    path.push_back(current->name);
    if (current == finalRoom) { // it's the final room
      break;
    }

    current->visited = true;
    hasActBestWay = false;
    for (auto& [neighbor, weight] : current->neighborns) {
      if (!neighbor->visited) { // if not visited alredy
        tempWeight = manhattanHeuristic(neighbor->name, final) + realDistance[neighbor];
        if (hasActBestWay) {
          if (tempWeight < actBestWay.second) {
            actBestWay = std::make_pair(neighbor, tempWeight);
          }
        } else {
          actBestWay = std::make_pair(neighbor, tempWeight);
          hasActBestWay = true;
        }
      }
    }
    actWeight += actBestWay.second;
    queue.push(actBestWay.first);

    queue.pop();
  }

  return path;
} 

int measureCost(std::vector<room>& rooms, std::vector<char> path) {
  int cost = 0;
  room* current = findRoomByName(rooms, path.front());
  room* next;

  for (int i = 1; i < path.size(); i++) {
    next = findRoomByName(rooms, path[i]);
    cost += current->neighborns[next];
    current = next;
  }

  return cost;
}

// measure time to each algorytm
template <typename Func>
std::vector<char> measureTime(const std::string& name, Func f) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<char> result = f();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << name << " levou " << duration.count() << " ms\n";

    return result;
}

int main()
{
  char init;
  char final;
  std::vector<room> allRooms; 
  allRooms = createAllRooms("ABCDEFGHIJKLMNOPQRSTU", 22);

  askAttributes(&init, &final);
  
  std::cout << "\n";
  // BFS
  std::vector<char> pathBFS = measureTime("BFS", [&]() {
      return BFS(allRooms, init, final);
  });
  std::cout << "Caminho BFS: \t\t";
  for (char c : pathBFS) std::cout << c << " ";
  std::cout << "(" << measureCost(allRooms, pathBFS) << ")";
  std::cout << "\n\n";

  // DFS
  std::vector<char> pathDFS = measureTime("DFS", [&]() {
      return DFS(allRooms, init, final);
  });
  std::cout << "Caminho DFS: \t\t";
  for (char c : pathDFS) std::cout << c << " ";
  std::cout << "(" << measureCost(allRooms, pathDFS) << ")";
  std::cout << "\n\n";

  // Greedy
  std::vector<char> pathGreedy = measureTime("Greedy", [&]() {
      return Greedy(allRooms, init, final);
  });
  std::cout << "Caminho Greedy: \t";
  for (char c : pathGreedy) std::cout << c << " ";
  std::cout << "(" << measureCost(allRooms, pathGreedy) << ")";
  std::cout << "\n\n";

  // A*
  std::vector<char> pathAstar = measureTime("A*", [&]() {
      return AStar(allRooms, init, final);
  });
  std::cout << "Caminho A*: \t\t";
  for (char c : pathAstar) std::cout << c << " ";
  std::cout << "(" << measureCost(allRooms, pathAstar) << ")";
  std::cout << "\n\n";

  return 0;
}
