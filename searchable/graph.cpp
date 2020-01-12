//
// Created by idan on 10/01/2020.
//

#include "graph.h"

void Graph::InitializeGraph(string matrix_file) {
    string line;
    ifstream mat_file(matrix_file.c_str());
    bool check_num_vertexes = true;
    int num_of_ver = INFINITY;
    int curr_ver = 0;

    // How we should split the lines
    vector<string>* dels = new vector<string>();
    dels->push_back(" ");
    dels->push_back(",");
    dels->push_back("\n");
    dels->push_back("\r");
    LineSplitter* splitter = new LineSplitter("Line_Splitter", dels);

    if(mat_file.is_open()) {
        while(getline(mat_file, line) && curr_ver < num_of_ver) {
            matrix << line.substr(0, (line.size() - 2));
            vector<string*>* line_splitted = splitter->solve(&line);

            // Initialize the vertexes in from file
            if (check_num_vertexes) {
                num_of_ver = InitializeVertexes(line_splitted);
                check_num_vertexes = false;
            }

            // Initialize Edges and weights
            list<State<string*>*>* edge = new list<State<string*>*>;
            map<State<string*>*, double>* edge_weig =
                    new map<State<string*>*, double>;
            int iter_line = 0;

            // Getting the edges for all weights that doesn't equal zero.
            while(iter_line < num_of_ver) {
                double weight = std::stod(*line_splitted->at(iter_line));
                if (weight != 0) {
                    edge->push_back(this->vertexes->at(iter_line));
                    edge_weig->insert({this->vertexes->at(iter_line), weight});
                }
            }

            // Insert to the appropriate fields.
            this->edges->insert({this->vertexes->at(curr_ver), edge});
            this->weights->insert({this->vertexes->at(curr_ver), edge_weig});
            curr_ver++;
        }

        // Get starting position
        getline(mat_file, line);
        vector<string*>* line_splitted = splitter->solve(&line);
        int loc = stod(*(line_splitted->at(0));
        this->initialState = this->vertexes->at(loc);

        // Get ending position
        getline(mat_file, line);
        line_splitted = splitter->solve(&line);
        loc = stod(*(line_splitted->at(0));
        this->goalState = this->vertexes->at(loc);
    }
}

int Graph::InitializeVertexes(vector<string*> *vers) {
    int num_of_vers = vers->size();
    while (num_of_vers > 0) {
        Vertex* ver = new Vertex(new string("vertex"), 0);
        this->vertexes->push_back(ver);
    }
    return num_of_vers;
}