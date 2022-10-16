//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_STRATEGYFACTORY_H
#define PRISONERS_STRATEGYFACTORY_H

#include <vector>
#include "strategies/GameStrategy.h"
#include "strategies/AlwaysVoteCGameStrategy.h"
#include "GameMatrix.h"
#include <string>

class StrategyFactory {

public:
    StrategyFactory() = default;

    //Вариант 1
    static GameStrategy *createStrategy(StrategyName strategyName,
                                        const std::string &configPath,
                                        const GameMatrix &gameMatrix);

    //Вариант 2
    void addStrategy(GameStrategy *gameStrategy);

    GameStrategy *getStrategy(StrategyName strategyName);


    ~StrategyFactory();

private:
    std::vector<GameStrategy *> strategies;

};


#endif //PRISONERS_STRATEGYFACTORY_H
