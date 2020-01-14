//
// Created by idan on 10/01/2020.
//

#include "graph.h"

void Graph::InitializeGraph(string matrix_file) {
    string line;
    ifstream mat_file(matrix_file.c_str());
    int num_of_ver = (int)INFINITY;
    int curr_ver = 0, num_of_lines = 0;
    vector<vector<State<myPoint*>*>*>* create_neig = new
            vector<vector<State<myPoint*>*>*>;

    // How we should split the lines
    vector<string>* dels = new vector<string>();
    dels->push_back(" ");
    dels->push_back(",");
    dels->push_back("\n");
    dels->push_back("\r");
    LineSplitter* splitter = new LineSplitter("Line_Splitter", dels);

    if(mat_file.is_open()) {
        while(getline(mat_file, line)) {
            num_of_lines++;
        }
        num_of_lines -= 3;
        mat_file.close();
    }

    mat_file = ifstream(matrix_file.c_str());
    if(mat_file.is_open()) {
        // Initialize the vertexes in from file
        while(getline(mat_file, line) && curr_ver <= num_of_lines) {
            matrix << line.substr(0, (line.size() - 2)) << ",";
            vector<string*>* line_splitted = splitter->solve(&line);
            int num_of_vers = line_splitted->size();
            int row = 0;
            create_neig->push_back(new vector<State<myPoint*>*>());
            while (row < num_of_vers) {
                Vertex* ver = new Vertex(new myPoint(curr_ver, row), stod
                (*line_splitted->at(row)));
                create_neig->at(curr_ver)->push_back(ver);
                this->vertexes->push_back(ver);
                row++;
            }
            curr_ver++;
        }

        // Get starting position
        getline(mat_file, line);
        vector<string*>* line_splitted = splitter->solve(&line);
        int loc = stod(*(line_splitted->at(0)));
        this->initialState = this->vertexes->at(loc);

        // Get ending position
        getline(mat_file, line);
        line_splitted = splitter->solve(&line);
        loc = stod(*(line_splitted->at(0)));
        this->goalState = this->vertexes->at(loc);

        InitializeNeighbors(create_neig);
    }
}

void Graph::InitializeNeighbors(vector<vector<State<myPoint *> *> *>
        *create_neig) {
    int row = create_neig->at(0)->size();
    int line = create_neig->size();
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < row; j++) {
            list<State<myPoint*>*>* neigs = new list<State<myPoint*>*>();

            // Right
            if (j < (row - 1)){
                neigs->push_back(create_neig->at(i)->at(j + 1));
            }
            // Left
            if (j > 0) {
                neigs->push_back(create_neig->at(i)->at(j - 1));
            }

            // Down
            if (i < (line - 1)){
                neigs->push_back(create_neig->at(i)->at(i + 1));
            }
            // Up
            if (i > 0) {
                neigs->push_back(create_neig->at(i)->at(i - 1));
            }
        }
    }
}

void Graph::InitializeVisit() {
    auto end = this->getVertexes()->end();
    for(auto ver = this->getVertexes()->begin(); ver != end; ver++) {
        (*ver)->setVisit("Unvisited");
    }
}
