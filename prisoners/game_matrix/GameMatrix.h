//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_GAME_SCORE_H
#define PRISONERS_GAME_SCORE_H

#include <vector>
#include "Choice.h"

class GameScore {

public:

    void setScoreA(int score) {
        scoreA = score;
    }

    void setScoreB(int score) {
        scoreB = score;
    }

    void setScoreC(int score) {
        scoreC = score;
    }

    int getScoreA() const {
        return scoreA;
    }

    int getScoreB() const {
        return scoreB;
    }

    int getScoreC() const {
        return scoreC;
    }

private:
    int scoreA;
    int scoreB;
    int scoreC;

};

class GameMatrix {
public:
    GameScore getScore(Choice a, Choice b, Choice c);

    ~GameMatrix();

};

#endif //PRISONERS_GAME_SCORE_H
