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
    try {
        Solution<const char*> s = this->cacheManager->get(in.str());
        const char* t = s.getSolution();
        cout << t << endl;
        *OutputStream << t;
    } catch (const char* e){
        *OutputStream << this->sol->solve(problem.str());
        Solution<const char*> out = Solution<const char*>(OutputStream->str()
                                                                  .c_str());
        this->cacheManager->insert(in.str(), (out));
    }
}