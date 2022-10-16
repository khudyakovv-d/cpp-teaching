//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_GAMESTRATEGY_H
#define PRISONERS_GAMESTRATEGY_H

#include "Choice.h"

enum StrategyName {
    ALWAYS_CHOICE_C
};

class GameStrategy {
public:

    virtual Choice vote() = 0;

    virtual void update(Choice playerA, Choice playerB) {
    }

    virtual bool isApplicable(StrategyName name) = 0;

    virtual ~GameStrategy() = default;

};


#endif //PRISONERS_GAMESTRATEGY_H
