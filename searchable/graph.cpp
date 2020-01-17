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
        while(getline(mat_file, line) && curr_ver <= (num_of_lines - 1)) {
            matrix << line.substr(0, (line.size() - 2)) << ",";
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            vector<string*>* line_splitted = splitter->solve(&line);
            num_of_ver = line_splitted->size();
            int col = 0;
            create_neig->push_back(new vector<State<myPoint*>*>());

            while (col < num_of_ver) {
                double val = stod(*line_splitted->at(col));
                Vertex* ver;

                // If val equals -1 it is equivalent to infinity
                if (val == -1) {
                    ver = new Vertex(new myPoint(curr_ver, col), INFINITY);
                } else {
                    ver = new Vertex(new myPoint(curr_ver, col), val);
                }

                create_neig->at(curr_ver)->push_back(ver);
                this->vertexes->push_back(ver);
                col++;
            }
            curr_ver++;
        }

        // Get starting position
        vector<string*>* line_splitted = splitter->solve(&line);
        int n = stod(*(line_splitted->at(0)));
        int m = stod(*(line_splitted->at(1)));
        this->initialState = getVer(n, m);

        // Get ending position
        getline(mat_file, line);
        line_splitted = splitter->solve(&line);
        n = stod(*(line_splitted->at(0)));
        m = stod(*(line_splitted->at(1)));
        this->goalState = getVer(n, m);
        mat_file.close();
        InitializeNeighbors(create_neig);
    }
}

void Graph::InitializeNeighbors(vector<vector<State<myPoint *> *> *>
        *create_neig) {
    int col = create_neig->at(0)->size();
    int line = create_neig->size();
    int vers = 0;
    list<State<myPoint*>*>* neigs;
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < col; j++) {
            neigs = new list<State<myPoint*>*>();

            // Right
            if (j < (col - 1)){
                neigs->push_back(create_neig->at(i)->at(j + 1));
            }
            // Left
            if (j > 0) {
                neigs->push_back(create_neig->at(i)->at(j - 1));
            }

            // Down
            if (i < (line - 1)){
                neigs->push_back(create_neig->at(i + 1)->at(j));
            }
            // Up
            if (i > 0) {
                neigs->push_back(create_neig->at(i - 1)->at(j));
            }
            this->neighbors->insert({this->vertexes->at(vers), neigs});
            vers++;
        }
    }
}

void Graph::InitializeVisit() {
    auto end = this->getVertexes()->end();
    for(auto ver = this->getVertexes()->begin(); ver != end; ver++) {
        (*ver)->setVisit("Unvisited");
        (*ver)->setCostOfWay(INFINITY);
    }
}

State<myPoint *> * Graph::getVer(int n, int m) {
    myPoint* p = new myPoint(n, m);
    auto end = this->vertexes->end();
    for(auto start = this->vertexes->begin(); start != end; start++) {
        if(p->equals((*start)->getState())) {
            return *start;
        }
    }
}
