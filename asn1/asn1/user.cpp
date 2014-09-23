#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "user.h"

using namespace std;

User::User(int userID, string userName){ //Constructor
    this->userID = userID;
    this->userName = userName;
}

int User::getID(){
    return userID;
}

string User::getUserName(){
    return userName;
}

int User::getUserType(){
    return userType;
}


Customer::Customer(int custID, string custName){
    userID = custID;
    userName = custName;
    userType = 0;
}

ChequingAccount Customer::getChequing(){
    return checkingsAcc;
}

SavingsAccount Customer::getSavings(){
    return savingsAcc;
}

Manager::Manager(int manID, string manName){
    userID = manID;
    userName = manName;
    userType = 1;
    //customers.reserve(1);
    cout<<customers.size()<<endl;
}

int Manager::getType(){
    return 1;
}

void Manager::createUser(int uID, string userName){
        Customer newCust(uID, userName);
        //cout<<"User created: "<<newCust.getUserName()<<" "<<newCust.getID();
        customers.push_back(newCust);
        cout<<"Customer account opened successfully!"<<endl;
        //cout<<customers.size()<<endl;
}

void Manager::deleteUser(int custID){
    vector<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it){
        if (customers.size() > 0){
            if (it->getID() == custID){
                customers.erase(it);
                cout<<"Customer with ID number \""<<custID<<"\" deleted successfully!\n";
            }
        }
        else break;
    }
}

Customer Manager::findCust(int loginID){
    vector<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it){
        if (it->getID() == loginID){
            return *it;
        }
    }
    return *it;
}

bool Manager::custExists(int loginID){
    bool found = false;
    for (int i=0; i<customers.size(); i++){
        if (customers[i].getID() == loginID){
            found = true;
        }
    }
    return found;
}

void Manager::dispAccount(int uID){
    Customer foundCust = findCust(uID);
    cout<<"\nUsername: " << foundCust.getUserName() << "\nID Number: " << foundCust.getID() << "\nChequing Account Balance: $" << foundCust.getChequing().getBalance() << "\nSavings Account Balance: $" << foundCust.getSavings().getBalance() << endl;
}

void Manager::dispAllAccounts(){
    vector<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it){
        dispAccount(it->getID());
    }
}

vector<Customer> Manager::custList(){
    return customers;
}

Maintenance::Maintenance(int mainID, string mainName){
    userID = mainID;
    userName = mainName;
    userType = 2;
}
