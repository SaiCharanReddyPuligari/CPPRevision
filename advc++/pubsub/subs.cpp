#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include <iostream>
#include <string>
#include <vector>
#include "message.cpp"

class Subscriber{
    std::string id;
    std::string name;
    std::vector<Message> messageQueue;
    bool active;

    public:
    Subscriber(const std::string _id, const std::string _name):id(_id), name(_name), active(true){
            
    }

    std::string getId(){
        return id;
    }

    std::string getName(){
        return name;
    }
    
    bool isActive(){
        return active;
    }

    std::vector<Message>& getMessageQueue(){
          return messageQueue;
    }

    void receiveMessage(const Message& message){
         if(active){
            messageQueue.push_back(message);
         }
    }
    void displayMessages(){
        std::cout<< "Messages"<<std::endl;
        if(messageQueue.empty()){
            std::cout<<"No Messages"<<std::endl;
        }

        for(const auto& message : messageQueue){
            message.display();
            std::cout<<"-------"<<std::endl;
        }
    }
    void clearMessages(){
        messageQueue.clear();
    }
    void setActive(bool status){
           active = status;
    }
    void displayInfo() {
        std::cout << "Subscriber: " << name << " (ID: " << id << ")" << std::endl;
        std::cout << "Status: " << (active ? "Active" : "Inactive") << std::endl;
        std::cout << "Pending Messages: " << messageQueue.size() << std::endl;
    }

};
#endif