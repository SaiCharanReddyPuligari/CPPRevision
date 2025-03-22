#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <ctime>
#include <iostream>

class Message{
    std::string msg;
    std::string topic;
    std:: time_t time;

    public:
    Message(const std::string topic, const std::string message): topic(topic), msg(message){

    }

    std::string getTopic(){
        return topic;
    }

    std::string getMes(){
        return msg;
    }

    std::time_t getTime(){
        return time;
    }

    void display() const{
        std::cout << "Topic: " << topic << std::endl;
        std::cout << "Content: " << msg << std::endl;
        std::cout << "Timestamp" <<std::ctime(&time)<<std::endl;
    }

};
#endif