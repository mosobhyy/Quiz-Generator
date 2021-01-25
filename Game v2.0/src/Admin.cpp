#include "Admin.h"
#include <iostream>
#include <Player.h>
#include <Question.h>
#include <MCQ.h>
#include <TF.h>
#include <Complete.h>
#include <bits/stdc++.h>
using namespace std;
extern vector<User*> users;
extern unsigned int ptr;
extern vector<MCQ> mcq_Questions;
extern vector<TF> tf_Questions;
extern vector<Complete> complete_Questions;
extern bool defaultAdmin;
extern bool defaultPlayer;
extern unsigned int viewAllUsers_Iterator;
extern unsigned int numOfQuestions;

void Admin::mainMenu()
{
    cout << "\nWelcome " << firstName << " " << lastName << " (ADMIN), please choose from the following options:" << endl;
    cout << "       [1] Switch accounts" << endl;
    cout << "       [2] Update your name" << endl;
    cout << "       [3] View all users" << endl;
    cout << "       [4] Add new user" << endl;
    cout << "       [5] View all questions" << endl;
    cout << "       [6] Add new question" << endl;
    cout << "       [7] Load questions from file" << endl;
    cout << "       [8] Exit the program" << endl;
    cout << endl << "My choice:";
}

// View all users Function

void Admin::viewAllUsers()
{
    cout << "First name\tLast name\tUsername\tRole\t" << endl;

    for (viewAllUsers_Iterator = 0 ; viewAllUsers_Iterator < users.size() ; viewAllUsers_Iterator++)
    {
        cout << users[viewAllUsers_Iterator] -> firstName << "\t\t" << users[viewAllUsers_Iterator] -> lastName << "\t\t" << users[viewAllUsers_Iterator] -> userName
             << "\t\t" << users[viewAllUsers_Iterator] -> role << endl;
    }

    cout << "Press [n] if you want to add a new user or [b] to go back to the main menu." << endl;
    cout << "\nMy choice: ";

}

// Add New User Function (Only for Admin Role)

void Admin::addNewUser()
{
    bool exist;
    string fn, ln, us, pass, role;
Re_Enter:
    exist = false;
    cout << "Please Enter Your First name: ";
    cin >> fn;
    cout << "Please Enter Your Last name: ";
    cin >> ln;
    cout << "Please Enter Your UserName: ";
    cin >> us;
    cout << "Please Enter Your Password: ";
    cin >> pass;
    cout << "Please Enter Your Role: ";
    cin >> role;
    while (role != "admin" && role != "player")
    {
        cout << "This role is not exist !" << endl;
        cout << "Please Enter Your Role: ";
        cin >> role;
    }
    if(role == "admin")
    {
        Admin obj(us, pass, fn, ln);

        // Check if this User Name EXIST before or not

        for (unsigned int i = 0 ; i < users.size() ; i ++)
        {
            exist = (obj == users[i]);
            if (exist == 1)
            {
                cout << endl << "This username is already exist !" << endl;
                goto Re_Enter;
            }
        }
        users.push_back(new Admin(us, pass, fn, ln));
    }
    else
    {
        Player obj(us, pass, fn, ln);

        // Check if this User Name EXIST before or not

        for (unsigned int i = 0 ; i < users.size() ; i ++)
        {
            exist = (obj == users[i]);
            if (exist == 1)
            {
                cout << endl << "This username is already exist !" << endl;
                goto Re_Enter;
            }
        }
        users.push_back(new Player(us, pass, fn, ln));
    }
    cout << "\nUser has been registered successfully\n" << endl;
    if (users.size() > 1 && defaultAdmin == true && users[users.size() - 1] -> role == "Admin")
    {
        users.erase(users.begin());
        ptr = users.size() - 1;
        defaultAdmin = false;
    }
    else if (users.size() > 1 && defaultPlayer == true && users[users.size() - 1] -> role == "Player")
    {
        users.erase(users.begin() + 1);
        ptr = users.size() - 1;
        defaultPlayer = false;
    }
}

// View All Questions Function

void Admin::viewQuestions()
{
    numOfQuestions = mcq_Questions.size() + tf_Questions.size() + complete_Questions.size();
    cout << "Number of questions available: " << numOfQuestions << endl;
    cout << "---------------------------------" << endl;
    cout << "MCQ Questions list (Total: " << mcq_Questions.size() << " Questions)" << endl;
    cout << "---------------------------------------" << endl;
    mcqPrint();
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << "TF Questions list (Total: " << tf_Questions.size() << " Questions)" << endl;
    cout << "--------------------------------------" << endl;
    tfPrint();
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Complete Questions list (Total: " << complete_Questions.size() << " Questions)" << endl;
    cout << "--------------------------------------------" << endl;
    completePrint();
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Press [d] and the question ID if you want to delete a question (Example: d 2)" << endl;
    cout << "Press [b] if you want to go back to the main menu" << endl;
}

// Delete a question Function

void Admin::deleteQuestion(int id)
{
    bool found = false;     // To reduce consuming more loop without need
    while (found == false)
    {
        // search on ID in MCQ questions
        for (unsigned int i = 0 ; i < mcq_Questions.size() ; i++)
        {
            if (id == mcq_Questions[i].questionId)
            {
                mcq_Questions.erase(mcq_Questions.begin() + i);
                cout << "\nQuestion has been deleted Successfully !" << endl;
                found = true;
                break;
            }
        }
        if (found == true)
            break;
        // search on ID in TF questions
        for (unsigned int i = 0 ; i < tf_Questions.size() ; i++)
        {
            if (id == tf_Questions[i].questionId)
            {
                tf_Questions.erase(tf_Questions.begin() + i);
                cout << "\n\nQuestion has beed deleted Successfully !" << endl;
                found = true;
                break;
            }
        }
        if (found == true)
            break;
        // search on ID in Complete questions
        for (unsigned int i = 0 ; i < complete_Questions.size() ; i++)
        {
            if (id == complete_Questions[i].questionId)
            {
                complete_Questions.erase(complete_Questions.begin() + i);
                cout << "\nQuestion has beed deleted Successfully !" << endl;
                found = true;
                break;
            }
        }
        if (found == false)
            cout << "\nThis question not exist !" << endl;
    }
}

// Add Question Function

void Admin::addQuestion()
{
    char type;
reEnter_question:
    cout << "Enter Type  of question that you want to add [ 1-MCQ   2-TF    3-COMPLETE ]: ";
    cin >> type;
    cin.ignore();

    if (type == '1')
        addMcq();
    else if (type == '2')
        addTf();
    else if (type == '3')
        addComplete();
    else
    {
        cout << "This type of question is not exist\n";
        goto reEnter_question;
    }
}

// Add MCQ Questions Function (use in Add Question Function)

void Admin::addMcq()
{
    MCQ addedQuestion;
    // Get The question
reEnter_question:
    cout << "Enter your question: ";
    getline(cin, addedQuestion.question);
    // Check that question Not EXIST Before
    for (unsigned int i = 0 ; i < mcq_Questions.size() ; i++)
    {
        if (addedQuestion.question == mcq_Questions[i].question)
        {
            cout << endl << "This question is already exist ! (Duplicate question)" << endl;
            goto reEnter_question;
        }
    }
    // Get Answers of the question
    for (int i = 0 ; i < 4 ; i++)
    {
        if (i == 0)
            cout << "Choice " << i + 1 << "[The right answer]: ";
        else
reEnter_answer:
            cout << "Choice " << i + 1 << ": ";
        getline(cin, addedQuestion.answers[i]);
        // Check if answer already exist or no
        for (int x = i-1 ; x >= 0 ; x--)
        {
            if (addedQuestion.answers[i] == addedQuestion.answers[x])
            {
                cout << endl << "Duplicate answer" << endl;
                goto reEnter_answer;
            }
        }
    }
    mcq_Questions.push_back(addedQuestion);
}

// Add TF Questions Function (use in Add Question Function)

void Admin::addTf()
{
    TF addedQuestion;
    // Get The question
reEnter_question:
    cout << "Enter your question: ";
    getline(cin, addedQuestion.question);
    // Check that question Not EXIST Before
    for (unsigned int i = 0 ; i < tf_Questions.size() ; i++)
    {
        if (addedQuestion.question == tf_Questions[i].question)
        {
            cout << endl << "This question is already exist ! (Duplicate question)" << endl;
            goto reEnter_question;
        }
    }
reEnter_answer:
    cout << "Enter Answer of the question [True,False]: ";
    cin >> addedQuestion.answer;
    while (!(addedQuestion.answer == "true" || addedQuestion.answer == "false"))
    {
        cout << "\nInvalid Answer ! " << endl;
        goto reEnter_answer;
    }
    tf_Questions.push_back(addedQuestion);
}

// Add Complete Questions Function (use in Add Question Function)

void Admin::addComplete()
{
    Complete addedQuestion;
    // Get The question
reEnter_question:
    cout << "Enter your question: ";
    getline(cin, addedQuestion.question);
    // Check that question Not EXIST Before
    for (unsigned int i = 0 ; i < complete_Questions.size() ; i++)
    {
        if (addedQuestion.question == complete_Questions[i].question)
        {
            cout << endl << "This question is already exist ! (Duplicate question)" << endl;
            goto reEnter_question;
        }
    }
    cout << "Enter Answer of the question: ";
    cin >> addedQuestion.answer;
    complete_Questions.push_back(addedQuestion);
}

// Load questions from File Function

void Admin::loadFile(std::string file)
{
    ifstream inputFile;
    inputFile.open(file.c_str());  // .c_str function to turn string into c-string.
    if(inputFile.fail())        //Check if the file exist or not
    {
        cout << endl <<"The file does not exist" << endl;
    }
    else
    {
        string type;
        while(!inputFile.eof())     // Read to the end of file
        {
            again:
            getline(inputFile, type);
            if (type == "MCQ")
            {
                MCQ loadedQuestion;     //a temporary variable to take the question
                getline(inputFile, loadedQuestion.question);
                for (unsigned int i = 0 ; i < mcq_Questions.size() ; i++)
                {
                    if (loadedQuestion.question == mcq_Questions[i].question)
                        goto again;
                }
                for (int i = 0 ; i < 4 ; i++)
                {
                    getline(inputFile, loadedQuestion.answers[i]);
                }
                mcq_Questions.push_back(loadedQuestion);
            }
            else if(type == "TF")
            {
                TF loadedQuestion;     //a temporary variable to take the question
                getline(inputFile, loadedQuestion.question);
                for (unsigned int i = 0 ; i < tf_Questions.size() ; i++)
                {
                    if (loadedQuestion.question == tf_Questions[i].question)
                        goto again;
                }
                getline(inputFile, loadedQuestion.answer);
                tf_Questions.push_back(loadedQuestion);
            }
            else if(type == "COMPLETE")
            {
                Complete loadedQuestion;     //a temporary variable to take the question
                getline(inputFile, loadedQuestion.question);
                for (unsigned int i = 0 ; i < complete_Questions.size() ; i++)
                {
                    if (loadedQuestion.question == complete_Questions[i].question)
                        goto again;
                }
                getline(inputFile, loadedQuestion.answer);
                complete_Questions.push_back(loadedQuestion);
            }
        }
        cout << endl << "File has been loaded successfully" << endl;
    }
    inputFile.close();
}

// MCQ Questions print Function

void Admin::mcqPrint()
{
    char str;
    for (unsigned int i = 0 ; i < mcq_Questions.size() ; i++)
    {
        cout << "[" << i+1 << "](ID: " << mcq_Questions[i].questionId << ") " << mcq_Questions[i].question << endl;
        for (int x = 0 ; x < 4 ; x++)
        {
            if (x == 0)
            {
                cout << "       ";
                str = 'a';
            }
            else if (x == 1)
                str = 'b';
            else if (x == 2)
                str = 'c';
            else if (x == 3)
                str = 'd';
            cout << "[" << str << "]" << mcq_Questions[i].answers[x] << "        ";
        }
        cout << endl;
    }
}

// True False Questions print Function

void Admin::tfPrint()
{
    for (unsigned int i = 0 ; i < tf_Questions.size() ; i++)
    {
        cout << "[" << i+1 << "](ID: " << tf_Questions[i].questionId << ") " << tf_Questions[i].question;
        cout << " (Answer: " << tf_Questions[i].answer  << ")"<< endl;
    }
}

// Complete Questions print Function

void Admin::completePrint()
{
    for (unsigned int i = 0 ; i < complete_Questions.size() ; i++)
    {
        cout << "[" << i+1 << "](ID: " << complete_Questions[i].questionId << ") " << complete_Questions[i].question;
        cout << "(Answer: " << complete_Questions[i].answer << ")" << endl;
    }
}

Admin::Admin()
{
    firstName = "admin";
    lastName = "admin";
    userName = "admin";
    password = "admin";
    role = "Admin";
}

Admin::Admin(std::string userName, std::string password, std::string firstName, std::string lastName)
{
    this -> userName = userName;
    this -> password = password;
    this -> firstName = firstName;
    this -> lastName = lastName;
    role = "Admin";
}

Admin::~Admin()
{
    //dtor
}
