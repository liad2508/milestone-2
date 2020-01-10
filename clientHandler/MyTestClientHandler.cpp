//
// Created by liad on 09/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(ostringstream* InputStream,
        ostringstream *OutputStream) {
    stringstream in;
    stringstream problem;
    problem << InputStream->str();
    in << sol->getSolutionType() << "_" << problem.str();
    const char* s = this->cacheManager->get(in.str());
    if (s == NULL) {
        *OutputStream << this->sol->solve(problem.str());
        const char* out = OutputStream->str().c_str();
        this->cacheManager->insert(in.str(), out);
    } else {
        *OutputStream << s;
    }
}