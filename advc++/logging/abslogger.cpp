#include <memory>
#include <string>
#include <iostream>
using namespace std;
#include "common.hpp"
#include <fstream>

class Logger {
protected:
    LogLevel logLevel;
    std::shared_ptr<Logger> nextLogger;

public:
    explicit Logger(LogLevel level) : logLevel(level), nextLogger(nullptr) {}

    void setNextLogger(std::shared_ptr<Logger> next) {
        nextLogger = next;
    }

    void logMessage(LogLevel level, const std::string& message) {
        if (this->logLevel == level) {
            write(message);
        }
        if (nextLogger != nullptr) {
            nextLogger->logMessage(level, message);
        }
    }

    virtual ~Logger() = default;

protected:
    virtual void write(const std::string& message) = 0;
};

class ConsoleLogger : public Logger{
    protected:
    void write(const string& message) override{
        cout<<message<<endl;
    }

    public:
    ConsoleLogger(LogLevel level) : Logger(level){}
};

class FileLogger : public Logger{
    private:
        ofstream logFile;

        public:
        FileLogger(LogLevel level, const string& filename):Logger(level), logFile(filename, ios::app){
            if(!logFile.is_open()){
                throw runtime_error("Unable to open file"+ filename);
            }
        }

    protected:
     void write(const string& msg){
        logFile <<"File Logger" <<msg<<endl;
     }
    
};

class NullLogger : public Logger {
    public:
        explicit NullLogger(LogLevel level) : Logger(level) {}
    
    protected:
        void write(const std::string& message) override {
            // No operation
        }
    };
