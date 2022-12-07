#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){

    int o; //option chosen by user
    cout<<"\t\t\t__________________________________________________________________\n\n\n";
    cout<<"\t\t\t                    Welcome to the Login page                     \n\n";
    cout<<"\t\t\t                            MENU                                   \n\n\n";
    cout<<"                                                                        \n\n";
    cout<<"\t | Press 1 to LOGIN                       |"<<endl;
    cout<<"\t | Press 2 to REGISTER                    |"<<endl;
    cout<<"\t | Press 3 to if you forgot your PASSWORD |"<<endl;
    cout<<"\t | Press 4 to EXIT                        |"<<endl;
    cout<<"\n\t\t\t Please enter your choice  :  ";
    cin>>o;
    cout<<endl;

    switch(o)
    {
        case 1:
        login();
        break;

        case 2: 
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t\t\t Thankyou! \n\n";
        break;

        default:
        system("cls");
        cout<<"\t\t\t Please select from the options given above \n" <<endl;
        main();

    
    }
    return 0;
}



void login()
{
    int count;
    string userID , password, id , pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userID;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id == userID && pass == password){
            count =1;
            system("cls");
        }
    }
    input.close();

    if(count ==1)
    {
        cout<<userID<<"\n Your LOGIN is successfull \n Thanks for logging in! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password \n";
        main();
    }
}

void registration(){
    string ruserID , rpassword, rid , rpass;
    system("cls");
   
    cout<<"\t\t\t Enter a username : ";
    cin>>ruserID;
    cout<<"\t\t\t Enter a password : ";
    cin>>rpassword;

    ofstream f1("records.txt" , ios::app); //app mode , ios - input output stream - appends the new content in file
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\n\n Registration is successfull!  \n";
    main();

}


void forgot(){


    int choice;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    
    switch (choice)
    {
        case 1:
        {
            int count = 0; 
            string suserID , sID , spass;
            cout<<"\n\t\t Enter the username which you remembered : ";
            cin>>suserID;

            ifstream f2("records.txt");
            while(f2>>sID>>spass)
            {
                if(suserID == sID)
                {
                    count =1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is : "<<spass;
                main();

            }
            else{

                cout<<"\n\n Sorry, account not found .\n";
                main();
            }
        
            break;
        }

        case 2:
        {
            main();
        }

    
        default:
        cout<<"\t\t\t Wrong choice ! Please try again. "<<endl;
        forgot();

    
        
    }

}

