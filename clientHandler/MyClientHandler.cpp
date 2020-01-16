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
    cout << InputStream->str() << endl;
    if (InputStream->str() != "end") {
        this->f << InputStream->str() << "\n";
    } else {
        this->f << InputStream->str() << "\n";
        this->f.close();
        Graph* graph = new Graph();
        graph->InitializeGraph(*this->nameOfFile);
        *OutputStream << this->sol->solve(graph);
    }

}