#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>

class User
{
public:

    // Attributes

    std::string userName, password, firstName, lastName, role;

    // Player Attributes only

    int numOfQuizzes;
    float highScore, lowScore, avgScore;
    float mcq_rightAnswers, tf_rightAnswers, complete_rightAnswers;
    std::vector<int> quizScores;
    std::vector<int> rightsPerQuiz;

    // Methods

    virtual void mainMenu()=0;
    void swicthAccount();
    void updateName();
    virtual void viewAllUsers();
    virtual void addNewUser();
    virtual void viewQuestions();
    virtual void deleteQuestion(int id);
    virtual void addQuestion();
    virtual void loadFile(std::string file);
    virtual void mcqPrint();
    virtual void tfPrint();
    virtual void completePrint();
    virtual void newQuiz();
    virtual void display_allStatisics();
    virtual void display_lastTwo();
    virtual void display_scores();

    // Constructors

    User();
    User(std::string userName, std::string password, std::string firstName, std::string lastName);

    // Destructor

    ~User();
};

#endif // USER_H
