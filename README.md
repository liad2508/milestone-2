# milestone-2
## Searchable

Includes state - this is used for getting the state of vertex - **also implemented a class that inherits from state and called it vertex**.

Searchable - a class that we should create so that we will send a searchable to our solvers. For example, you can see that the implementation of DFS does as follows:

  1. Gets a **Graph** (searchable) and returns the best Route.
  2. It iterates on **Vertexes** (states) and uses the **Graph's** methods to search.
  

Also, I added a few changes to the server so that the parrallel server will work - **we can check this next week**.

Regarding the cache - I wasn't able to solve the issue. You can try yourself, I think the issue is because of how we save the data. I tried to create a class just like in **ex2** and it didn't work. Maybe try your code or something or we just can change the implementation.
