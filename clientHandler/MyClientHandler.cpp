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
    if (InputStream->str() != "end") {
        this->f << InputStream->str() << "\n";
    } else {
        this->f << InputStream->str() << "\n";
        this->f.close();
        stringstream matrix;
        Graph* graph = new Graph();
        graph->InitializeGraph(*this->nameOfFile);

        this->num++;
        matrix << "Matrix_Funky_" << this->num;
        this->nameOfFile = new string(matrix.str());
        this->f = ofstream(this->nameOfFile->c_str());
        cout << *this->nameOfFile << endl;
        this->sol->setNum(0);
        try {
            Route* r = this->sol->solve(graph);
            InputStream->str("");
            cout << "Num of vers iterated: "<< this->sol->getNum() << endl;
            *OutputStream << r->toString() << endl;

        } catch (const char* e) {
            cout << "Num of vers iterated: "<< INFINITY << endl;
        }
    }

}