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

std::map<room*, std::pair<room*,int>> AStarRealDistance(std::vector<room>& rooms, room* finalRoom) {
  std::map<room*, std::pair<room*,int>> heuristic;
  std::queue<room*> queue;
  room* current;
  int actWeight;

  heuristic[finalRoom] = std::make_pair(nullptr, 0);

  queue.push(finalRoom);
  while(!queue.empty()) {
    current = queue.front();
    current->visited = true;

    for (auto& [neighbor, weight] : current->neighborns) {
      actWeight = weight + heuristic[current].second;
      auto it = heuristic.find(neighbor);
      if (it != heuristic.end()) { // ja existe na heuristica
        if (actWeight < (heuristic[current].second + weight)) {
          heuristic[neighbor] = std::make_pair(current, heuristic[current].second + weight);
          queue.push(neighbor);
        }
      } else { // eh novo na heuristica 
        heuristic[neighbor] = std::make_pair(current, actWeight);
      }
      if (false == neighbor->visited) {
        queue.push(neighbor);
      }
    }
    
    queue.pop();
  }

  return heuristic;
}

std::vector<char> AStar(std::vector<room>& rooms, char start, char final) {
  room* finalRoom = findRoomByName(rooms, final);
  std::map<room*, std::pair<room*, int>> realDistance = AStarRealDistance(rooms, finalRoom);

  return std::vector<char> ();
}

// A* -> retorna caminho
// std::vector<char> AStar(std::vector<room>& rooms, char start, char goal) {
//   resetVisited(rooms);
//   room* s = findRoomByName(rooms, start);
//   room* g = findRoomByName(rooms, goal);
//   if (s == NULL || g == NULL) return std::vector<char>();

//   std::map<room*, int> gScore;
//   for (std::size_t i = 0; i < rooms.size(); i++) {
//     gScore[&rooms[i]] = INT_MAX;
//   }
//   gScore[s] = 0;

//   struct CompareAStar {
//     std::map<room*, int>& gScore;
//     room* g;
//     std::vector<room>& rooms;
//     CompareAStar(std::map<room*, int>& gs, std::vector<room>& r, room* goalPtr) : gScore(gs), g(goalPtr), rooms(r) {}
//     bool operator()(room* a, room* b) {
//       int fa = gScore[a] + heuristic(rooms, a, g);
//       int fb = gScore[b] + heuristic(rooms, b, g);
//       return fa > fb;
//     }
//   };

//   std::priority_queue<room*, std::vector<room*>, CompareAStar> openSet(CompareAStar(gScore, rooms, g));
//   std::map<room*, room*> parent;
//   parent[s] = NULL;
//   openSet.push(s);

//   while (!openSet.empty()) {
//     room* current = openSet.top(); openSet.pop();
//     if (current == g) {
//       return buildPath(parent, g);
//     }
//     for (auto& [neighbor, weight] : current->neighborns) {
//       if (gScore[current] == INT_MAX) continue; // protecao
//       int tentative = gScore[current] + weight;
//       if (tentative < gScore[neighbor]) {
//         gScore[neighbor] = tentative;
//         parent[neighbor] = current;
//         openSet.push(neighbor);
//       }
//     }
//   }
//   return std::vector<char>();
// }

int main()
{
  char init;
  char final;
  std::vector<room> allRooms; 
  allRooms = createAllRooms("ABCDEFGHIJKLMNOPQRSTU", 22);

  // askAttributes(&init, &final); //DEV ONLY: AFTER DISCOMMENT   (preservado)
  askAttributes(&init, &final);     // usando a entrada do usuario

  // exemplo de uso: cada funcao retorna um vetor de chars com o caminho
  std::vector<char> pathBFS   = BFS(allRooms, init, final);
  std::vector<char> pathDFS   = DFS(allRooms, init, final);
  std::vector<char> pathGreed = Greedy(allRooms, init, final);
  // std::vector<char> pathAstar = AStar(allRooms, init, final);

  // impressao opcional (fora das funcoes de busca)
  std::cout << "\n--- Resultados ---\n";
  std::cout << "BFS: ";
  if (pathBFS.empty()) std::cout << "Nenhum caminho";
  else { for (std::size_t i = 0; i < pathBFS.size(); i++) std::cout << pathBFS[i] << " "; }
  std::cout << "\n";

  std::cout << "DFS: ";
  if (pathDFS.empty()) std::cout << "Nenhum caminho";
  else { for (std::size_t i = 0; i < pathDFS.size(); i++) std::cout << pathDFS[i] << " "; }
  std::cout << "\n";

  std::cout << "Greedy: ";
  if (pathGreed.empty()) std::cout << "Nenhum caminho";
  else { for (std::size_t i = 0; i < pathGreed.size(); i++) std::cout << pathGreed[i] << " "; }
  std::cout << "\n";

  // std::cout << "A*: ";
  // if (pathAstar.empty()) std::cout << "Nenhum caminho";
  // else { for (std::size_t i = 0; i < pathAstar.size(); i++) std::cout << pathAstar[i] << " "; }
  // std::cout << "\n";

  return 0;
}
