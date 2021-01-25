#include <iostream>
#include "Player.h"
#include <Admin.h>
#include <Quiz.h>
#include <Statistics.h>
#include <bits/stdc++.h>
using namespace std;
extern vector<User*> users;
extern unsigned int ptr;
extern vector<Statistics> lastTwo;

void Player::mainMenu()
{
    cout << "\nWelcome " << firstName << " " << lastName << " (PLAYER), please choose from the following options:" << endl;
    cout << "       [1] Switch accounts" << endl;
    cout << "       [2] Update your name" << endl;
    cout << "       [3] Start a new quiz" << endl;
    cout << "       [4] Display your scores statistics" << endl;
    cout << "       [5] Display all your scores" << endl;
    cout << "       [6] Display details of your last 2 quizzes" << endl;
    cout << "       [7] Exit the program" << endl;
    cout << "My Choice: ";
}

// Start a new quiz Function

void Player::newQuiz()
{
    Quiz quiz;
}

// Display all scores statistics Function

void Player::display_allStatisics()
{
    if (users[ptr] -> numOfQuizzes < 1)
    {
        cout << "\nSorry, there are not enough quizzes to show its data !" << endl;
    }
    else
    {
        cout << "\nYour score statistics per quiz:" << endl;
        cout << "       - Number of Quizzes taken: " << users[ptr] -> numOfQuizzes << endl;
        cout << "       - Highest quiz score: " << users[ptr] -> highScore << endl;
        cout << "       - Lowest quiz score: " << users[ptr] -> lowScore << endl;
        cout << "       - Average quiz score: " << users[ptr] -> avgScore / users[ptr] -> numOfQuizzes << endl;
        cout << "Your score statistics per question type:" << endl;
        cout << "       - Number of MC questions: " << users[ptr] -> numOfQuizzes * 2 << endl;
        cout << "       - Number of Complete questions: " << users[ptr] -> numOfQuizzes << endl;
        cout << "       - Number of T/F Questions: " << users[ptr] -> numOfQuizzes * 3 << endl;
        cout << "       - Average grade for MC questions: " <<
             users[ptr] -> mcq_rightAnswers / users[ptr] -> numOfQuizzes << "/2" << endl;
        cout << "       - Average grade for Complete questions: " <<
             users[ptr] -> complete_rightAnswers / users[ptr] -> numOfQuizzes << "/1" << endl;
        cout << "       - Average grade for T/F questions: " <<
             users[ptr] -> tf_rightAnswers / users[ptr] -> numOfQuizzes << "/3" << endl;
    }
    cout << "\nPress [b] if you want to go back to the main menu or [e] to exit" << endl;
    cout << "\nMy choice: ";
}

// Display all scores Function
void Player::display_scores()
{
    if (users[ptr] -> numOfQuizzes < 1)
    {
        cout << "\nSorry, there are not enough quizzes to show its data !" << endl;
    }
    else
    {
        cout << "Number of Quizzes taken: " << users[ptr] -> numOfQuizzes << endl;
        cout << "--------------------------" << endl;
        for (unsigned int i = 0 ; i < quizScores.size() ; i++)
        {
            cout << "\nQuiz: " << i+1 << endl;
            cout << "--------" << endl;
            cout << "\nNumber of Right Answers: " << users[ptr] -> rightsPerQuiz[i] << endl;
            cout << "\nNumber of Wrong Answers: " << (6 -users[ptr] -> rightsPerQuiz[i]) << endl;
            cout << "\nTotal Score: " << quizScores[i] << endl;
        }
        cout << endl;
    }
    cout << "\nPress [b] if you want to go back to the main menu or [e] to exit" << endl;
    cout << "\nMy choice: ";
}

// Display last two quizzes statistics

void Player::display_lastTwo()
{
    if (users[ptr] -> numOfQuizzes < 2)
        cout << "\nSorry, there are not enough quizzes to show its data !" << endl;
    else
    {
        int quizzesNum = users[ptr] -> numOfQuizzes;
        char str;
        for (int vec = 0 ; vec < 2 ; vec++)
        {
            cout << "Quiz: " << (vec + quizzesNum - 1) << endl;
            cout << "--------" << endl;
            // MCQ LOOP
            for (int i = 0 ; i < 2 ; i++)
            {
                cout << "\n[" << i+1 << "]" << lastTwo[(6*vec)+i].question << endl;
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
                    cout << "[" << str << "]" << lastTwo[(6*vec)+i].mcq[x] << "        ";
                }
                cout << "\n       Player Answer: "<< lastTwo[(6*vec)+i].playerAnswer
                     << "       " << lastTwo[(6*vec)+i].rightORwrong;
                cout << "\n       Right Answer: " << lastTwo[(6*vec)+i].rightAnswer << endl;
            }
            cout << "\nYour Score for MCQ questions: " << lastTwo[(6*vec)+1].mcqScore << "/4" << endl;
            cout << "\n---------------------------------------------------" << endl;
            // TRUE OR FALSE LOOP
            for (int i = 2 ; i < 5 ; i++)
            {
                cout << "\n[" << i+1 << "]" << lastTwo[(6*vec)+i].question << endl;
                cout << "\n       Player Answer: "<< lastTwo[(6*vec)+i].playerAnswer
                     << "       " << lastTwo[(6*vec)+i].rightORwrong;
                cout << "\n       Right Answer: " << lastTwo[(6*vec)+i].rightAnswer << endl;
            }
            cout << "\nYour Score for TF questions: " << lastTwo[(6*vec)+4].tfScore << "/3" << endl;
            cout << "\n---------------------------------------------------" << endl;
            // COMPLETE
            cout << "\n[6]" << lastTwo[(6*vec)+5].question << endl;
            cout << "\n       Player Answer: "<< lastTwo[(6*vec)+5].playerAnswer
                 << "       " << lastTwo[(6*vec)+5].rightORwrong;
            cout << "\n       Right Answer: " << lastTwo[(6*vec)+5].rightAnswer << endl;
            cout << "\nYour Score for COMPLETE questions: " << lastTwo[(6*vec)+5].completeScore << "/3" << endl;
            cout << "\n---------------------------------------------------" << endl;
            cout << "\nTotal Score for quiz " << (vec + quizzesNum - 1) <<": " << lastTwo[(6*vec)+5].totalScore << "/10" << endl;
            cout << "\n--------------------------" << endl;
        }
    }
    cout << "\nPress [b] if you want to go back to the main menu or [e] to exit" << endl;
    cout << "\nMy choice: ";
}

Player::Player()
{
    firstName = "player";
    lastName = "player";
    userName = "player";
    password = "player";
    role = "Player";
}

Player::Player(std::string userName, std::string password, std::string firstName, std::string lastName)
{
    this -> userName = userName;
    this -> password = password;
    this -> firstName = firstName;
    this -> lastName = lastName;
    role = "Player";
    mcq_rightAnswers = 0.0;
    tf_rightAnswers = 0.0;
    complete_rightAnswers = 0.0;
    numOfQuizzes = 0;
    avgScore = 0;
    lowScore = 1000;
    highScore = 0;
}

Player::~Player()
{
    //dtor
}
