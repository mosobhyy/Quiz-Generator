#include <iostream>
#include <User.h>
#include <Admin.h>
#include <Player.h>
#include <MCQ.h>
#include <TF.h>
#include <Complete.h>
#include <Statistics.h>
#include <bits/stdc++.h>
using namespace std;
// Global Variables
vector<User*> users;
unsigned int ptr;
vector<MCQ> mcq_Questions;
vector<TF> tf_Questions;
vector<Complete> complete_Questions;
vector<Statistics> lastTwo;
bool defaultAdmin = true;    // To check if the default admin exist or not
bool defaultPlayer = true;    // To check if the default player exist or not
unsigned int viewAllUsers_Iterator; // For view all users Function
unsigned int numOfQuestions;    // Number of all questions  (MCQ + TF + COMPLETE)
int rightsPerQuiz;          // To Store every quiz score then add it to its vector

int main()
{
    cout << "*******************************************************************" << endl;
    cout << "Welcome to the Quiz game program V2.0!" << endl;
    cout << "*******************************************************************" << endl;
    int id;     // Parameter for Delete question Function
    char choice, option;
    string file;
    users.push_back(new Admin);
    users.push_back(new Player);
    users[ptr] -> swicthAccount();
start:
    cin >> choice;
    while ( !(choice>='1'&& choice <='8') )
    {
        cin.ignore(9999, '\n');
        cout << "invalid choice\n";
        cout << endl << "My Choice: ";
        goto start;
    }
    if (choice == '1')
    {
        users[ptr] -> swicthAccount();
        goto start;
    }
    else if (choice == '2')
    {
        users[ptr] -> updateName();
        users[ptr] -> mainMenu();
        goto start;
    }
    else if (choice == '3')
    {
        if (users[ptr] -> role == "Admin")
        {
            users[ptr] -> viewAllUsers();
            cin >> option;
            while (option != 'n' && option != 'b')
            {
                cin.ignore(9999, '\n');// in case of if the user wrote a word.
                cout << "invalid choice" << endl;
                cin >> option;
            }
            switch(option)
            {
            case 'n':
                users[ptr] -> addNewUser();
                users[ptr] -> swicthAccount();
                break;
            case 'b':
                users[ptr] -> mainMenu();
                break;
            }
        }
        else
        {
            users[ptr] -> newQuiz();
            users[ptr]  -> mainMenu();
        }
        goto start;
    }
    else if (choice == '4')
    {
        if (users[ptr] -> role == "Admin")
        {
            users[ptr] -> addNewUser();
            users[ptr] -> swicthAccount();
        }
        else
        {
            users[ptr] -> display_allStatisics();
            cin >> option;
            while (option != 'b' && option != 'e')
            {
                cin.ignore(9999, '\n');     // in case of if the user wrote a word.
                cout << "invalid choice" << endl;
                cin >> option;
            }
            switch(option)
            {
            case 'b':
                users[ptr] -> mainMenu();
                break;
            case 'e':
                cout << "\nThanks for using our application ^_^" << endl;
                return 0;
            }
        }
        goto start;
    }
    else if (choice == '5')
    {
        if (users[ptr] -> role == "Admin")
        {
reView:
            numOfQuestions = mcq_Questions.size() + tf_Questions.size() + complete_Questions.size();
            if (numOfQuestions == 0)
                cout << "\nUnfortunately, No Questions available to show !\n" << endl;
            else
            {
                users[ptr] -> viewQuestions();
                cout << "My Choice: ";
                cin >> option;
                while (option != 'd' && option != 'b')
                {
                    cin.ignore(9999, '\n');// in case of if the user wrote a word.
                    cout << "invalid choice" << endl;
                    cin >> option;
                }
                switch(option)
                {
                case 'd':
                    cout << "Enter ID of question that you want to delete: ";
                    cin >> id;
                    users[ptr] -> deleteQuestion(id);
                    goto reView;
                    break;
                }
            }
        }
        else
        {
            users[ptr] -> display_scores();
            cin >> option;
            while (option != 'b' && option != 'e')
            {
                cin.ignore(9999, '\n');     // in case of if the user wrote a word.
                cout << "invalid choice" << endl;
                cin >> option;
            }
            switch(option)
            {
            case 'e':
                cout << "\nThanks for using our application ^_^" << endl;
                return 0;
            }
        }
        users[ptr] -> mainMenu();
        goto start;
    }
    else if (choice == '6')
    {
        if (users[ptr] -> role == "Admin")
        {
            users[ptr] -> addQuestion();
            users[ptr] ->viewQuestions();
            cout << "My Choice: ";
            cin >> option;
            while (option != 'd' && option != 'b')
            {
                cin.ignore(9999, '\n');// in case of if the user wrote a word.
                cout << "invalid choice" << endl;
                cin >> option;
            }
            switch(option)
            {
            case 'd':
                cout << "Enter ID of question that you want to delete: ";
                cin >> id;
                users[ptr] -> deleteQuestion(id);
                goto reView;
                break;
            }
        }
        else
        {
            users[ptr] -> display_lastTwo();
            cin >> option;
            while (option != 'b' && option != 'e')
            {
                cin.ignore(9999, '\n');     // in case of if the user wrote a word.
                cout << "invalid choice" << endl;
                cin >> option;
            }
            switch(option)
            {
            case 'e':
                cout << "\nThanks for using our application ^_^" << endl;
                return 0;
            }
        }
        users[ptr] -> mainMenu();
        goto start;
    }
    else if (choice == '7')
    {
        if (users[ptr] -> role == "Admin")
        {
            cout << "Enter name of the file: ";
            cin >> file;
            users[ptr] -> loadFile(file);
            users[ptr] -> mainMenu();
        }
        else
        {
            cout << endl << "Thanks for using our application ^_^" << endl;
            return 0;
        }
        goto start;

    }
    else if (choice == '8')
    {
        if (users[ptr] -> role == "Admin")
            cout << "\nThanks for using our application ^_^" << endl;
        else
        {
            cout << "invalid choice" << endl;
            cout << "\nMy Choice: ";
            goto start;
        }
    }

    return 0;
}

// Operator Overloading to check the username EXIST before or NOT (Used in Add New User Function ---> Admin Class)

bool operator == (Admin const obj1, User const *obj2)
{
    bool result = false;
    if (obj1.userName == obj2 -> userName)
        result = true;
    return result;
}

bool operator == (Player const obj1, User const *obj2)
{
    bool result = false;
    if (obj1.userName == obj2-> userName)
        result = true;
    return result;
}
