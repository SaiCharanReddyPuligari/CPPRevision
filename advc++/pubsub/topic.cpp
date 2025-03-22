#include <iostream>
#include <string>
#include <vector>
#include "subs.cpp"
#include <algorithm>

class Topic{
      std::string name;
      std::string description;
      std::vector<Subscriber*> subscribers;
      bool active;

      public:
      Topic(std::string _name, std::string _des):name(_name), description(_des){
          
      }

      std::string getName(){
        return name;
      }

      std::string getDescription(){
        return description;
      }

      bool isActive(){
        return active;
      }
       std::vector<Subscriber*>& getSubscribers() { return subscribers; }
    void addSubscriber(Subscriber* subscriber){
      if (!subscriber) return;
    
      auto it = std::find(subscribers.begin(), subscribers.end(), subscriber);
      if (it == subscribers.end()) {
          subscribers.push_back(subscriber);
      }
    }
    void removeSubscriber(const std::string& subscriberId){
      auto it = std::find_if(subscribers.begin(), subscribers.end(),
      [subscriberId](Subscriber* sub) { return sub->getId() == subscriberId; });
  
  if (it != subscribers.end()) {
      subscribers.erase(it);
  }
    }
    void publishMessage(const Message& message){
      if (!active) return;
    
      for (auto subscriber : subscribers) {
          subscriber->receiveMessage(message);
      }
    }
    void setActive(bool status){
      active = status;
    }
    void displayInfo(){
      std::cout << "Topic: " << name << std::endl;
      std::cout << "Description: " << description << std::endl;
      std::cout << "Status: " << (active ? "Active" : "Inactive") << std::endl;
      std::cout << "Subscribers: " << subscribers.size() << std::endl;
    }
      
      


};
