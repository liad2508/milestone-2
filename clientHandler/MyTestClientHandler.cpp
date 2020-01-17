//
// Created by liad on 09/01/2020.
//
#include <fstream>
#include <sstream>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(ostringstream* InputStream,
        ostringstream *OutputStream) {
    stringstream in;
    stringstream problem;
    problem << InputStream->str();
    in << sol->getSolutionType() << "_" << problem.str();
    try {
        string s = this->cacheManager->get(in.str());
        *OutputStream << s;
    } catch (const char* e){
        *OutputStream << this->sol->solve(problem.str());
        string out = string(OutputStream->str().c_str());
        this->cacheManager->insert(in.str(), out);
    }
}