#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>

class Logger {
private:
    std::ofstream   file_;
    std::mutex      mtx_;

public:
    explicit Logger(const std::string& file = "app.log");
    ~Logger();

    void log(const std::string& msg);
};

#endif 
