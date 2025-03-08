//logger class - exposed to the application
//category- this should be selected based on the run time
//Sink- based on parameter
//application - >logger class -> category (info, error, debug)-> sink(console, file or database)
#include "logger.cpp"
#include "common.hpp"
int main(){
    auto logger = LoggerManager::getInstance();

    logger->log(LogLevel::INFO, "This is an info message.");
    logger->log(LogLevel::DEBUG, "This is a debug message.");
    logger->log(LogLevel::ERROR, "This is an error message.");

    return 0;
}