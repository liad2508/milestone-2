cmake_minimum_required(VERSION 3.15)
project(MILESTONE_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MILESTONE_2 main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h)