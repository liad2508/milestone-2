//
// Created by idan on 14/01/2020.
//

#include "MyClientHandler.h"

MyClientHandler* MyClientHandler::setNameOfFile(string *nameOfFile) {
    this->f = ofstream(*nameOfFile);
    MyClientHandler::nameOfFile = nameOfFile;
    return this;
}

void MyClientHandler::handleClient(ostringstream *InputStream, ostringstream *OutputStream) {
    hash<string> str_hash;
    if (InputStream->str() != "end") {
        this->f << InputStream->str() << "\n";
        this->data << InputStream->str();
    } else {
        stringstream in;
        stringstream problem;
        in << sol->getSolutionType() << "_" << str_hash(this->data.str());
        string file_name = in.str();
        try {
            // get result if exists
            Route* r = this->cacheManager->get(file_name)->createRoute();
            if (r != NULL) {
                *OutputStream << r->toString() << endl;
            } else {
                cout << "Num of vers iterated: " << INFINITY << endl;
                *OutputStream << "No Route" << endl;
            }
        } catch (const char* e) {
            Route *r = NULL;
            this->f << InputStream->str() << "\n";
            this->f.close();
            stringstream matrix;
            Graph *graph = new Graph();
            graph->InitializeGraph(*this->nameOfFile);

            matrix << "matrixes/Matrix_Funky";
            this->nameOfFile = new string(matrix.str());
            this->f = ofstream(this->nameOfFile->c_str());
            cout << *this->nameOfFile << endl;
            this->sol->setNum(0);
            try {
                r = this->sol->solve(graph);
                // Insert the result
                InputStream->str("");
                cout << "Num of vers iterated: " << this->sol->getNum() << endl;
                *OutputStream << r->toString() << endl;

            } catch (const char *e) {
                r = new Route();
                cout << "Num of vers iterated: " << INFINITY << endl;
                *OutputStream << "No Route" << endl;
            }
            this->cacheManager->insert(in.str(), r);
        }
    }

}