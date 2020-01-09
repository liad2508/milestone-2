//
// Created by liad on 09/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(ostringstream* InputStream,
        ostringstream *OutputStream) {
    stringstream in;
    stringstream problem;
    problem << InputStream->str() << endl;
    in << sol->getSolutionType() << "_" << problem.str();
    cout << this->cacheManager->get(in.str()) << endl;
    string* s = this->cacheManager->get(in.str());
    cout << s << endl;
    if (s == nullptr) {
        *OutputStream << this->sol->solve(problem.str());
        string out = string(OutputStream->str());
        this->cacheManager->insert(in.str(), &out);
    } else {
        OutputStream->str(*s);
    }
}