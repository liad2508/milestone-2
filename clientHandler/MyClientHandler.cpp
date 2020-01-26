//
// Created by idan on 14/01/2020.
//

#include "MyClientHandler.h"

MyClientHandler* MyClientHandler::setNameOfFile(string *nameOfFile) {
    if(this->f.is_open()) {
        this->f.close();
    }
    this->f = ofstream(*nameOfFile);
    this->nameOfFile = new string(*nameOfFile);
}

bool MyClientHandler::handleClient(ostringstream *InputStream, ostringstream
*OutputStream) {
    hash<string> str_hash;
    if (InputStream->str() != "end\n") {
        this->f << InputStream->str();
        this->data << InputStream->str();
        return false;
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
                *OutputStream << "No Route" << endl;
            }
            return true;
        } catch (const char* e) {
            Route *r = NULL;
            this->f << InputStream->str() << "\n";
            this->f.close();
            stringstream matrix;
            Graph *graph = new Graph();
            graph->InitializeGraph(*this->nameOfFile);
            this->f = ofstream(this->nameOfFile->c_str());
            this->sol->setNum(0);
            try {
                r = this->sol->solve(graph);
                // Insert the result
                InputStream->str("");
                *OutputStream << r->toString() << endl;

            } catch (const char *e) {
                r = new Route();
                *OutputStream << "No Route" << endl;
            }
            this->cacheManager->insert(in.str(), r);
            return true;
        }
    }
}

MyClientHandler* MyClientHandler::clone() {
    MyClientHandler* c = new MyClientHandler(this->sol->clone(),
            this->cacheManager);
    stringstream fname;
    c->nameOfFile = new string(*this->nameOfFile);
    this->num++;
    c->num = this->num;
    fname << *c->nameOfFile << "_";
    fname << this->num;
    c->setNameOfFile(new string(fname.str()));
    return c;
}