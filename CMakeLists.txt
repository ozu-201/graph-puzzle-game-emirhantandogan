cmake_minimum_required(VERSION 3.25)
project(graph_puzzle_game_emirhantandogan)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(graph_puzzle_game_emirhantandogan
        main.cpp
        main.h List/Graph/Graph.cpp General/AbstractGraph.cpp General/Path.cpp List/Graph/EdgeList.cpp List/Node.cpp List/Queue.cpp Array/Heap/Heap.cpp Array/Heap/HeapNode.cpp Array/Heap/MinHeap.cpp Array/DisjointSet.cpp Array/Set.cpp List/Graph/Edge.cpp List/NodeString.cpp)
