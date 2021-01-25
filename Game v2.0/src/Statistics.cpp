#include "Statistics.h"
#include <bits/stdc++.h>

Statistics::Statistics()
{
    mcqScore = 0;
    tfScore = 0;
    completeScore = 0;
    totalScore = 0;
}

// Constructor for MCQ

Statistics::Statistics(std::string question,std::string mcq[],std::string playerAnswer,std::string rightORwrong,std::string rightAnswer
                       , int mcqScore)
{
    this -> question = question;
    for (int i = 0 ; i < 4 ; i++)
        this -> mcq[i] = mcq[i];
    this -> playerAnswer = playerAnswer;
    this -> rightORwrong = rightORwrong;
    this -> rightAnswer = rightAnswer;
    this -> mcqScore = mcqScore;
}

// Constructor for TRUE OR FALSE

Statistics::Statistics(std::string question, std::string playerAnswer,std::string rightORwrong,std::string rightAnswer
                       , int tfScore)
{
    this -> question = question;
    this -> playerAnswer = playerAnswer;
    this -> rightORwrong = rightORwrong;
    this -> rightAnswer = rightAnswer;
    this -> tfScore = tfScore;
}

// Constructor for COMPLETE

Statistics::Statistics(std::string question, std::string playerAnswer,std::string rightORwrong,std::string rightAnswer
                       , int completeScore, int totalScore)
{
    this -> question = question;
    this -> playerAnswer = playerAnswer;
    this -> rightORwrong = rightORwrong;
    this -> rightAnswer = rightAnswer;
    this -> completeScore = completeScore;
    this -> totalScore = totalScore;
}

Statistics::~Statistics()
{
    //dtor
}
