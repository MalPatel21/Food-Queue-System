#include <iostream>
#include <queue>
#include <limits>



struct Node{
    std::string custName;
    int tixNum;
    
};

class ticket{
private:
    Node* tix;
    std::queue<Node*> ticketQueue;

public:
/*
ticket(std::string name, int number){
   tix=new Node;
   tix->custName=name;
   tix->tixNum=number;
} to be removed after */ 

void addCustomer(const std::string &customerName,  int orderNumber){
    Node* customerTicket= new Node;
    customerTicket->custName=customerName;
    customerTicket->tixNum=orderNumber;
    ticketQueue.push(customerTicket);
    std::cout<<"Customer: "<<customerName<<" with Ticket Number: "<<orderNumber<<" was added"<<std::endl;

}

void serveCustomer(){
    if (ticketQueue.empty()) {
    std::cout << "No customers to serve." << std::endl;
    return;
    }

    std::cout<<"Serving customer: "<<ticketQueue.front()->custName<<" with Ticket Number: "<<ticketQueue.front()->tixNum<<std::endl;
    delete ticketQueue.front();
    ticketQueue.pop();
    std::cout<<"[last customer was removed from queue]"<<std::endl;
}

void displayQueue(){
    std::queue<Node*> tempQueue;
    tempQueue=ticketQueue;
    while(!tempQueue.empty()){
        std::cout<<"Customer: "<<tempQueue.front()->custName<<" Ticket Number: "<<tempQueue.front()->tixNum<<std::endl;
        tempQueue.pop();
    }
}

void ticketMenu() {
    int choice;

    while (true) {
        std::cout << "Ticket Counter System Menu" << std::endl;
        std::cout << "1. Add a customer\n";
        std::cout << "2. Display queue\n";
        std::cout << "3. Serve Customer\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int orderNum;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
            std::cout << "Enter customer name: ";
            std::getline(std::cin, name);  // Use std::getline for full name input

            std::cout << "Enter ticket number: ";
            while (!(std::cin >> orderNum)) {  
                std::cin.clear();              
                std::cin.ignore(10000, '\n');  
                std::cout << "Invalid ticket number. Please enter a valid number: ";
            }

            addCustomer(name, orderNum);
        } else if (choice == 2) {
            displayQueue();
        } else if (choice == 3) {
            serveCustomer();
        } else if (choice == 4) {
            std::cout << "Exiting program!" << std::endl;
            break;
        } else {
            std::cout << "Invalid response. Please try again!" << std::endl;
        }
    }
}


};

int main(){

ticket tix1;

tix1.ticketMenu();

}