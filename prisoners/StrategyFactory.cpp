//
// Created by daniil on 15.10.22.
//

#include <stdexcept>
#include "StrategyFactory.h"

GameStrategy *StrategyFactory::createStrategy(StrategyName strategyName,
                                              const std::string &configPath,
                                              const GameMatrix &gameMatrix) {
    switch (strategyName) {
        case ALWAYS_CHOICE_C:
            return new AlwaysVoteCGameStrategy(configPath, gameMatrix);
    }
    throw std::exception();
}

void StrategyFactory::addStrategy(GameStrategy *gameStrategy) {
    strategies.push_back(gameStrategy);
}

GameStrategy *StrategyFactory::getStrategy(StrategyName strategyName) {
    for (const auto &strategy: strategies) {
        if (strategy->isApplicable(strategyName)) {
            return strategy;
        }
    }
    throw std::exception();
}

StrategyFactory::~StrategyFactory() {
    for (const auto &strategy: strategies) {
        delete strategy;
    }
    strategies.clear();
}