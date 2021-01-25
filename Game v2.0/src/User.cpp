#include "User.h"
#include <iostream>
#include <Admin.h>
#include <Player.h>
#include <bits/stdc++.h>
using namespace std;
extern vector<User*> users;
extern unsigned int ptr;

void User::swicthAccount()
{
    bool login = false;
    unsigned int object;
    string user_name, pass_word;
    while(login == false)
    {
        cout << "Please enter your username: ";
        cin >> user_name;
        cout << "Please enter your password: ";
        cin >> pass_word;

        for (object = 0 ; object < users.size() ; object++)
        {
            if (user_name == users[object] -> userName)
            {
                if(pass_word == users[object] -> password)
                {
                    ptr = object;
                    users[ptr] -> mainMenu();
                    login = true;
                    break;
                }
            }
        }
        if (login == false)
            cout << "\nWrong username or password !\n" << endl;
    }
}

void User::updateName()
{
    cout << endl << "Enter your new First name : ";
    cin >> firstName;
    cout << endl << "Enter your new Last name : ";
    cin >> lastName;
    cout << endl << "Your name Changed to " << firstName << " " << lastName << " Successfully." << endl;
}

User::User()
{

}

User::User(std::string userName, std::string password, std::string firstName, std::string lastName)
{

}

User::~User()
{
    //dtor
}

void User::viewAllUsers(){}
void User::addNewUser(){}
void User::viewQuestions(){}
void User::deleteQuestion(int id){}
void User::addQuestion(){}
void User::loadFile(std::string file){}
void User::mcqPrint(){}
void User::tfPrint(){}
void User::completePrint(){}
void User::newQuiz(){}
void User::display_allStatisics(){}
void User::display_lastTwo(){}
void User::display_scores(){}
