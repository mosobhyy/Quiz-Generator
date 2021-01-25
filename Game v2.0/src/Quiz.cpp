#include <iostream>
#include "Quiz.h"
#include <Player.h>
#include <MCQ.h>
#include <TF.h>
#include <Complete.h>
#include <Statistics.h>
#include <bits/stdc++.h>
using namespace std;
extern vector<MCQ> mcq_Questions;
extern vector<TF> tf_Questions;
extern vector<Complete> complete_Questions;
extern vector<User*> users;
extern vector<Statistics> lastTwo;
extern unsigned int ptr;
extern int rightsPerQuiz;

void Quiz::generateQuiz()
{
    if(mcq_Questions.size() < 2 || tf_Questions.size() < 3 || complete_Questions.size() < 1)
    {
        cout << "\nSorry, there are not enough questions to start the quiz" << endl;
    }
    else
    {
        rightsPerQuiz = 0;
        if (lastTwo.size() == 12)
            lastTwo.erase(lastTwo.begin(), lastTwo.begin()+6);
        users[ptr] -> numOfQuizzes++;
        cout << "\nQuiz " << users[ptr] -> numOfQuizzes << ":" << endl;
        cout << "-------" << endl;
        generateMCQ();
        generateTF();
        generateComplete();
        users[ptr] -> quizScores.push_back(score);
        users[ptr] -> rightsPerQuiz.push_back(rightsPerQuiz);
        cout << endl << "Your score: " << score << "/10" << endl;
    }
}

// Generate MCQ questions Function

void Quiz::generateMCQ()
{
    string choice, rightAns, str;
    // Variables for stat constructor
    string question, mcq[4], playerAnswer, rightORwrong, rightAnswer;
    int mcqScore = 0;
    // *****************************
    int index, mcq_random_question[2], mcq_random_answers[8];
    srand(time(0));
    // Generate random Questions
    for (int i = 0 ; i < 2 ; i++)
    {
Question_generate:
        index = rand() % mcq_Questions.size();
        // Check if this index of question is unique in array or not to not repeat question
        if (i == 1)
        {
            if (index == mcq_random_question[0])
                goto Question_generate;
        }
        mcq_random_question[i] = index;
    }
    // Generate random Answers
    for (int i = 0 ; i < 2 ; i++)
    {
        for (int x = 0 ; x < 4 ; x++)
        {
Answer_generate:
            index = rand() % 4;
            // Check if this index of question is unique in array or not to not repeat question
            for (int z = ((4*i)+(x-1)) ; z >= 4*i ; z--)
            {
                if (index == mcq_random_answers[z])
                    goto Answer_generate;
            }
            mcq_random_answers[(4*i)+x] = index;
        }
    }
    // Print questions and answers
    for (int i = 0 ; i < 2 ; i++)
    {
        cout << "\n[" << i+1 << "]" << mcq_Questions[mcq_random_question[i]].question << endl;
        question = mcq_Questions[mcq_random_question[i]].question;
//        lastTwo_stat.push_back(mcq_Questions[mcq_random_question[i]].question);     // questions
        for (int x = 0 ; x < 4 ; x++)
        {
            if (x == 0)
            {
                cout << "       ";
                str = "a";
            }
            else if (x == 1)
                str = "b";
            else if (x == 2)
                str = "c";
            else if (x == 3)
                str = "d";
            cout << "[" << str << "]" << mcq_Questions[mcq_random_question[i]].answers[mcq_random_answers[(4*i)+x]] << "        ";
            mcq[x] = mcq_Questions[mcq_random_question[i]].answers[mcq_random_answers[(4*i)+x]];
            if (mcq_Questions[mcq_random_question[i]].answers[mcq_random_answers[(4*i)+x]] ==
                    mcq_Questions[mcq_random_question[i]].answers[0] )
                rightAns = str;
            rightAnswer = mcq_Questions[mcq_random_question[i]].answers[0];
//            lastTwo_stat.push_back(mcq_Questions[mcq_random_question[i]].answers[mcq_random_answers[(4*i)+x]]); // Answers
        }
        // Player Answer process (included calculate score)
re_choice:
        cout << "\nMy Choice: ";
        cin >> choice;
        while (!(choice == "a" || choice == "b" || choice == "c" || choice == "d"))
        {
            cout << "\nInvalid Choice !" << endl;
            goto re_choice;
        }
        if (choice == rightAns)
        {
            rightORwrong = "Right Answer";
            score += 2;
            mcqScore += 2;
            rightsPerQuiz++;
            users[ptr] -> mcq_rightAnswers++;
        }
        else
            rightORwrong = "Wrong Answer";
        if (choice == "a")
            playerAnswer = mcq[0];
        else if (choice == "b")
            playerAnswer = mcq[1];
        else if (choice == "c")
            playerAnswer = mcq[2];
        else if (choice == "d")
            playerAnswer = mcq[3];
        Statistics stat(question, mcq, playerAnswer, rightORwrong, rightAnswer, mcqScore);
        lastTwo.push_back(stat);
    }
}

// Generate TF questions Function

void Quiz::generateTF()
{
    // Variables for stat constructor
    string question, playerAnswer, rightORwrong, rightAnswer;
    int tfScore = 0;
    // *****************************
    string choice;
    int index, tf_random[3];
    srand(time(0));
    // Generate random questions
    for (int i = 0 ; i < 3 ; i++)
    {
Re_generate:
        index = rand() % tf_Questions.size();
        // Make Sure that the question not repeated
        for (int x=i-1; x>=0 ; x--)
        {
            if(index == tf_random[x])
                goto Re_generate;
        }
        tf_random[i] = index;
    }
    // Print questions and answers
    for (int i = 0 ; i < 3 ; i++)
    {
        cout << endl << "[" << i+3 << "]" << tf_Questions[tf_random[i]].question;
        question = tf_Questions[tf_random[i]].question;
        rightAnswer = tf_Questions[tf_random[i]].answer;
        cout << "       [ true     -     false ]" << endl;
re_choice:
        // Player Answer process (included calculate score)
        cout << "\nMy Choice: ";
        cin >> choice;
        while (!(choice == "true" || choice == "false"))
        {
            cout << "\nInvalid Choice !" << endl;
            goto re_choice;

        }
        playerAnswer = choice;
        if (choice == rightAnswer)
        {
            rightORwrong = "Right Answer";
            score++;
            tfScore++;
            users[ptr] -> tf_rightAnswers++;
            rightsPerQuiz++;
        }
        else
            rightORwrong = "Wrong Answer";
        Statistics stat(question, playerAnswer, rightORwrong, rightAnswer, tfScore);
        lastTwo.push_back(stat);
    }
    cout << endl;
}

// Generate COMPLETE Questions Function

void Quiz::generateComplete()
{
    // Variables for stat constructor
    string question, playerAnswer, rightORwrong, rightAnswer;
    int completeScore = 0, totalScore = 0;
    // *****************************
    int index;
    srand(time(0));
    index = rand() % complete_Questions.size();
    cout << "[6]" << complete_Questions[index].question << "         [ Complete ]" << endl;
    question = complete_Questions[index].question;
    rightAnswer = complete_Questions[index].answer;
    cout << "\nMy Choice: ";
    cin >> playerAnswer;
    if (playerAnswer == rightAnswer)
    {
        rightORwrong = "Right Answer";
        score += 3;
        completeScore += 3;
        users[ptr] -> complete_rightAnswers++;
        rightsPerQuiz++;
    }
    else
        rightORwrong = "Wrong Answer";
    totalScore = score;
    if (users[ptr] -> numOfQuizzes == 1)
        users[ptr] -> lowScore = score;
    users[ptr] -> avgScore += score;
    if (score > users[ptr] -> highScore)
        users[ptr] -> highScore = score;
    else if (score < users[ptr] -> lowScore)
        users[ptr] -> lowScore = score;
    Statistics stat(question, playerAnswer, rightORwrong, rightAnswer, completeScore, totalScore);
    lastTwo.push_back(stat);
}

Quiz::Quiz()
{
    score = 0;
    generateQuiz();
}

Quiz::~Quiz()
{
    //dtor
}
