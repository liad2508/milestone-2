# milestone-2

## Introduction

In this milestone we have created a program based on some well known **"Design Patterns"** includeing bridge, state, etc.
The following diagram describes the flow of data through the different classes and objects to provide a solution for a graph search:

![Diagram](https://github.com/idan57/milestone-2/blob/master/diagrm.png)

We have implemented the following graph searching algorithms:
  * _**BFS**_ - searches the graph for some route by getting to a vertex, checking all his neighbors for the target and putting each one of them in a queue. (the route is found according to the distance and not the weight)
  * _**DFS**_ - serches the graph for some route by getting to a vertex and recursively iterating his neighbor's neighbor until the target is reached. (the route is found according to the distance and not the weight)
  * _**Best First Search**_ - just like BFS but in each iteration we check for a better route according to its weight.
  * _**AStar**_ - very similar to dijkstra, it iterates the vertexes and their neighbors. At each iteration the lowest route's weight is chosen and if a neighbor has a route with an higher weight it will be checked and updated according to the current route.
