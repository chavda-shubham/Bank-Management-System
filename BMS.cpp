#include<iostream>

#include<string>

#include<vector>


using namespace std;


class open_account{
public:
  string name;
  string email;
  

private:

  string address;
  string phone;
  string gov_id;
  int account_no;
  double balance;

public:


  void deposite_amount(double amount){
    
    balance = balance + amount;
  }
  double get_deposite(){
    return balance;
  }

  void withdraw_amount(double amount){
    
    balance = balance - amount;
  }
  double get_withdraw(){
    return balance;
  }

  void check_balance(){
    cout<<"Your balance is: "<<balance<<endl;
  }




  void set_account_no(){
    account_no = rand()%1000000+ 100000;
  }
  int get_account_no(){
    return account_no;
  }
  // int existing_account_no;
  

  void get_details(){
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your email: ";
    cin>>email;
    cout<<"Enter your address: ";
    cin>>address;
    cout<<"Enter your phone: ";
    cin>>phone;
    cout<<"Enter your gov_id: ";
    cin>>gov_id;
  }

  void getinfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Phone: "<<phone<<endl;
    cout<<"Gov_id: "<<gov_id<<endl;
  }
};



int main(){
  srand(time(0));
  int choice;
  double amount;
  int account_no;

  vector<open_account> new_account;
  

  cout<<"WELCOME TO KINGFISHER BANK"<<endl;
  cout<<"THE KING OF GOOD TIMES"<<endl;
  do{
    cout<<"Please select an option"<<endl;
    cout<<"1. Open account"<<endl;
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Check Account"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    
    if(choice==1){
      new_account.push_back(open_account());
      new_account.back().get_details();
      new_account.back().getinfo();
      cout<<"To open an account, a minimum deposite of 500RS is required. Kindly deposite the amount to create your account"<<endl;
      cout<<"Enter an amount to deposite: ";
      cin>>amount;
      new_account.back().deposite_amount(amount);
      
      
     if(amount<500){
        cout<<"Insufficient amount"<<endl;
      }
       
      else{
        cout<<"Account created successfully"<<endl;
        cout<<"Your account number is: ";
        new_account.back().set_account_no();
        cout<<new_account.back().get_account_no();
        cout<<endl;
        }
    }
      
    else if (choice==2){
      cout<<"Enter your account number: ";
      cin>>account_no;
      bool found = false;
      for(int i=0; i<new_account.size(); i++){
        if(account_no==new_account[i].get_account_no()){
          cout<<"Account matched"<<endl;
          new_account[i].getinfo();
          cout<<"Enter an amount to deposite: ";
          cin>>amount;
          new_account[i].deposite_amount(amount);
          cout<<new_account[i].get_deposite()<<endl;
          cout<<"Account deposited successfully"<<endl;
          new_account[i].check_balance();
          found = true;
          break;
          
        }

      }
      if(!found){
        cout<<"Account not found"<<endl;
      }
        
      
      
    }
      
      
      
    else if(choice==3){
      cout<<"Enter your account number: ";
      cin>>account_no;
      bool found = false;
      for(int i=0; i<new_account.size(); i++){
        if(account_no==new_account[i].get_account_no()){
          cout<<"Account matched"<<endl;
          new_account[i].getinfo();
          cout<<"Enter an amount to withdraw: ";
          cin>>amount;
          if(amount>new_account[i].get_deposite()){
            cout<<"Insufficient balance"<<endl;
          }
          else{
          new_account[i].withdraw_amount(amount);
          cout<<new_account[i].get_withdraw()<<endl;
          cout<<"Account withdrawed successfully"<<endl;
          new_account[i].check_balance();
          found = true;
          break;
          }
        }
          
      }
      if(!found){
        cout<<"Account not found"<<endl;
      }
    }

      
    else if(choice==4){
      cout<<"Enter your account number: ";
      cin>>account_no;
      bool found = false;
      for(int i=0; i<new_account.size(); i++){
        if(account_no==new_account[i].get_account_no()){
          cout<<"Account matched"<<endl;
          new_account[i].getinfo();
          new_account[i].check_balance();
          found = true;
          break;
          }
          
        
        }
        if(!found){
          cout<<"Account not found"<<endl;
        }
      }

    else if(choice==5){
      cout<<"Thank you for using our bank"<<endl;
    }


    else{
      cout<<"Invalid choice"<<endl;
    }
    
  }while(choice!=5);

  
}
