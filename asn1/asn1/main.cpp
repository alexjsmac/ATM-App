#include <iostream> 
#include <string>
#include "account.h"
#include "user.h"

using namespace std;

int main(){
    //create manager object
    Manager man(123456, "Manager");
    
    //create maintenance object
    Maintenance main(234567, "Maintenance");
    
start:
    cout<<"\nHello, please enter login ID\n\n";
    int loginID;
    cin>>loginID;
    
    if(loginID==man.getID()){
        while(1){
            int choice;
            
            system("clear");
            cout<<"\nWhat would you like to do?\n";
            cout<<"1)   Open a user account\n";
            cout<<"2)   Close a user account\n";
            cout<<"3)   View details of a customer account\n";
            cout<<"4)   View details of all customers\n";
            cout<<"5)   Logout\n";
            cout<<"6)   Exit\n";
            cin>>choice;
            
            switch(choice){
                case 1:{
                    cout<<"Please create a new ID number:";
                    int userID;
                    cin>>userID;
                    cout<<"Enter the user's name:";
                    string userName;
                    cin>>userName;
                    man.createUser(userID, userName);
                    break;
                }
                case 2:{
                    cout<<"Please enter user's ID number:";
                    int userID;
                    cin>>userID;
                    man.deleteUser(userID);
                    break;
                }
                case 3:{
                    cout<<"Please enter a user ID number:";
                    int userID;
                    cin>>userID;
                    cout<<man.dispAccount(userID)<<endl;
                    break;
                }
                case 4 :{
                    break;
                }
                case 5:{
                    goto start;
                }
                case 6:{
                    goto end;
                }
                default:{
                    cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
                }
            }
        }
    }
    
    else if(man.custExists(loginID)){
        Customer userAccount = man.findCust(loginID);
        ChequingAccount checkAccount = userAccount.getChequing();
        SavingsAccount saveAccount = userAccount.getSavings();
            while(1){
            cust:
                cout<<"\nWhat would you like to do?\n";
                cout<<"1)   Deposit\n";
                cout<<"2)   Withdraw\n";
                cout<<"3)   Transfer\n";
                cout<<"4)   Display Balance\n";
                cout<<"5)   Open an account\n";
                cout<<"6)   Close an account\n";
                cout<<"7)   Logout\n";
                cout<<"8)   Exit\n";
                int choice;
                cin>>choice;
                switch(choice)
                {
                    case 1:{
                    deposit:
                        cout<<"To which account?\n";
                        cout<<"1) Checking Account\n";
                        cout<<"2) Savings Account\n";
                        cout<<"3) Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"How much would you like to deposit?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = checkAccount.getBalance() + amount;
                                checkAccount.setBalance(newBalance);
                                cout<<"New balance is: $"<<newBalance<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"How much would you like to deposit?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = saveAccount.getBalance() + amount;
                                saveAccount.setBalance(newBalance);
                                cout<<"New balance is: $"<<newBalance<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto deposit;
                            }
                        }
                        break;
                    }
                    case 2:{
                    withdraw:
                        cout<<"From which account?\n";
                        cout<<"1) Checking Account\n";
                        cout<<"2) Savings Account\n";
                        cout<<"3) Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"How much would you like to withdraw?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = checkAccount.getBalance() - amount;
                                if (newBalance < 0) {
                                    cout<<"WARNING: Insufficient funds, withdrawal not possible\n";
                                }
                                else if (newBalance < 1000){
                                    cout<<"WARNING: Balance will drop below $1000 and each following transaction will incur a  $2 fee.\n Do you wish to continue?\n 1) Yes\n";
                                    int decision;
                                    cin>>decision;
                                    if (decision == 1){
                                        checkAccount.setBalance(newBalance - 2);
                                    }
                                }
                                else
                                    checkAccount.setBalance(newBalance);
                                cout<<"Chequing account balance is/remains: $"<<checkAccount.getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"How much would you like to withdraw?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = saveAccount.getBalance() - amount;
                                saveAccount.setBalance(newBalance);
                                cout<<"New balance is: $"<<newBalance<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto withdraw;
                            }
                        }
                        break;
                    }
                    case 3:{
                    transfer:
                        cout<<"Which transfer would you like to do?\n";
                        cout<<"1) Checking Account to Savings Account\n";
                        cout<<"2) Savings Account to Chequing Assount\n";
                        cout<<"3) Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"How much would you like to transfer?\n";
                                int amount;
                                cin>>amount;
                                double newBalance1 = saveAccount.getBalance() + amount;
                                double newBalance2 = checkAccount.getBalance() - amount;
                                saveAccount.setBalance(newBalance1);
                                checkAccount.setBalance(newBalance2);
                                cout<<"Savings account is/remains: $"<<newBalance1<<endl;
                                cout<<"Chequing account is/remains: $"<<newBalance2<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"How much would you like to transfer?\n";
                                int amount;
                                cin>>amount;
                                double newBalance1 = checkAccount.getBalance() + amount;
                                double newBalance2 = saveAccount.getBalance() - amount;
                                checkAccount.setBalance(newBalance1);
                                saveAccount.setBalance(newBalance2);
                                cout<<"Chequing account is/remains: $"<<newBalance1<<endl;
                                cout<<"Savings account is/remains: $"<<newBalance2<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto transfer;
                            }
                        }
                        break;
                    }
                    case 4:{
                    display:
                        cout<<"Which account?\n";
                        cout<<"1) Checking Account\n";
                        cout<<"2) Savings Account\n";
                        cout<<"3) Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"Current balance is: $"<<checkAccount.getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"Current balance is: $"<<saveAccount.getBalance()<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto display;
                            }
                        }
                        break;
                    }
                    case 5:{
                        break;
                    }
                    case 6:{
                        break;
                    }
                    case 7:{
                        goto start;
                    }
                    case 8:{
                        goto end;
                    }
                    default:{
                        cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
                    }
                }
            }
        }
    else{
        cout<<"Invalid ID, try again"<<endl;
        goto start;
    }
    
    end:
        return 0;
};