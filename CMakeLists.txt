cmake_minimum_required(VERSION 3.15)
project(MILESTONE_2)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(MILESTONE_2 "main.cpp" "server/Server.cpp" "server/Server.h" "server/MySerialServer.cpp"
        "server/MySerialServer.h" "clientHandler/ClientHandler.cpp" "clientHandler/ClientHandler.h" "clientHandler/MyTestClientHandler.cpp"
        "clientHandler/MyTestClientHandler.h" "solver/Solver.cpp" "solver/Solver.h" "cache/CacheManager.cpp"
        "cache/CacheManager.h" "cache/FileCacheManager.cpp" "cache/FileCacheManager.h"
        "server/MyParallelServer.cpp" "server/MyParallelServer.h"
        solver/StringReverser.cpp solver/StringReverser.h server/Main.cpp
        server/Main.h searchable/State.cpp searchable/State.h solver/DFS.cpp solver/DFS.h searchable/graph.cpp searchable/graph.h  searchable/Searchable.cpp searchable/Searchable.h searchable/Route.cpp searchable/Route.h searchable/Vertex.cpp searchable/Vertex.h solver/A_Star.cpp solver/A_Star.h solver/LineSplitter.cpp solver/LineSplitter.h solver/MatrixToString.cpp solver/MatrixToString.h)
target_link_libraries(${PROJECT_NAME} pthread)
