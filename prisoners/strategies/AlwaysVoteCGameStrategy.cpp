//
// Created by daniil on 15.10.22.
//

#include "AlwaysVoteCGameStrategy.h"

AlwaysVoteCGameStrategy::AlwaysVoteCGameStrategy(std::string configPath, GameMatrix gameMatrix) {
}

Choice AlwaysVoteCGameStrategy::vote() {
    return COOPERATE;
}

bool AlwaysVoteCGameStrategy::isApplicable(StrategyName name) {
    return name == ALWAYS_CHOICE_C;
}
