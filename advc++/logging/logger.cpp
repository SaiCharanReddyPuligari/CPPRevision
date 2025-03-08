#include <mutex>
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include "abslogger.cpp"

class LoggerManager {
private:
    static std::shared_ptr<LoggerManager> instance;
    static std::mutex mutex;
    std::shared_ptr<Logger> loggerChain;

    // Private constructor to prevent instantiation
    LoggerManager() {
        // Initialize the chain of loggers
        auto consoleLogger = std::make_shared<ConsoleLogger>(LogLevel::INFO);
        auto fileLogger = std::make_shared<FileLogger>(LogLevel::DEBUG, "app.log");
        auto nullLogger = std::make_shared<NullLogger>(LogLevel::ERROR);

        consoleLogger->setNextLogger(fileLogger);
        fileLogger->setNextLogger(nullLogger);

        loggerChain = consoleLogger;
    }

public:
    // Delete copy constructor and assignment operator
    LoggerManager(const LoggerManager&) = delete;
    LoggerManager& operator=(const LoggerManager& inst) = delete;

    static std::shared_ptr<LoggerManager> getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = std::shared_ptr<LoggerManager>(new LoggerManager());
        }
        return instance;
    }

    void log(LogLevel level, const std::string& message) {
        loggerChain->logMessage(level, message);
    }
};

// Initialize static members
std::shared_ptr<LoggerManager> LoggerManager::instance = nullptr;
std::mutex LoggerManager::mutex;
