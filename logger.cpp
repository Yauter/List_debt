#include "logger.h"
#include <ctime>

static std::string nowStr()
{
    std::time_t t = std::time(nullptr);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
    return buf;
}

Logger::Logger(const std::string& file)
{
    file_.open(file, std::ios::app);
    log("=== Session started ===");
}

Logger::~Logger()
{
    log("=== Session ended ===");
    file_.close();
}

void Logger::log(const std::string& msg)
{
    std::lock_guard<std::mutex> lock(mtx_);
    if (file_)
        file_ << "[" << nowStr() << "] " << msg << '\n';
}
