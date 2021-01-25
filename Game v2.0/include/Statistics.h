#ifndef STATISTICS_H
#define STATISTICS_H
#include <bits/stdc++.h>

class Statistics
{
public:

    // Attributes
    std::string question, mcq[4], playerAnswer, rightORwrong, rightAnswer;
    int mcqScore, tfScore, completeScore, totalScore;
    Statistics();
    Statistics(std::string question,std::string mcq[],std::string playerAnswer,std::string rightORwrong,std::string rightAnswer
               , int mcqScore);
    Statistics(std::string question, std::string playerAnswer,std::string rightORwrong,std::string rightAnswer
               , int tfScore);
    Statistics(std::string question, std::string playerAnswer,std::string rightORwrong,std::string rightAnswer
               , int completeScore, int totalScore);
    ~Statistics();
};

#endif // STATISTICS_H
