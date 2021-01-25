cmake_minimum_required(VERSION 3.17)
project(Game_v2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Game_v2_0
        include/Admin.h
        include/Complete.h
        include/MCQ.h
        include/Player.h
        include/Question.h
        include/Quiz.h
        include/Statistics.h
        include/TF.h
        include/User.h
        src/Admin.cpp
        src/Complete.cpp
        src/MCQ.cpp
        src/Player.cpp
        src/Question.cpp
        src/Quiz.cpp
        src/Statistics.cpp
        src/TF.cpp
        src/User.cpp
        main.cpp)
