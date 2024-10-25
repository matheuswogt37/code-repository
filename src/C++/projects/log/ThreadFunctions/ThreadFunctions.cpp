#include "ThreadFunctions.hpp"

void *foo(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    /*
        regex
        ip -> [\"]+[ ]+200+[ ]
        hour -> /[0-9]+:[0-2][0-9]
        status -> [\"]+[ ]+2+[0-9]+

     */
    //* to calc the hour access my idea is get the first and the last hour, in the middle add the access and in the final make the calcs one unique time, make this in the main i think

    std::string str;

    std::regex rStatus("[\"]+[ ]+200+[ ]");
    std::smatch sm;

    str = data->getStr();
    while (std::regex_search(str, sm, rStatus)) {
        if ("\" 200 " == sm.str(0)) {
            data->addStatus200();
        }
        str = sm.suffix();
    }

    str = data->getStr();
    std::regex rData("/[0-9]+:[0-2][0-9]");
    while (std::regex_search(str, sm, rData)) {
        data->addSumHour(atoi(sm.str(0).substr(sm.length() - 2).c_str()));
        str = sm.suffix();
    }
    
    std::cout << data->getId() << " finish!\n";
    pthread_exit(NULL);
}

void *finish() {
    pthread_exit(NULL);
}
