#include <iostream>

#include "StrategyFactory.h"
#include "strategies/AlwaysVoteCGameStrategy.h"

int main() {
    StrategyFactory strategyFactory;
    auto *strategy = new AlwaysVoteCGameStrategy("path", GameMatrix());
    strategyFactory.addStrategy(strategy);

    GameStrategy *gameStrategy = strategyFactory.getStrategy(ALWAYS_CHOICE_C);

    std::cout << gameStrategy->vote();

    return 0;
}
