//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_ALWAYSVOTECGAMESTRATEGY_H
#define PRISONERS_ALWAYSVOTECGAMESTRATEGY_H

#include <string>
#include "GameStrategy.h"
#include "GameMatrix.h"

class AlwaysVoteCGameStrategy : public GameStrategy {

public:

    AlwaysVoteCGameStrategy(std::string configPath, GameMatrix gameMatrix);

    Choice vote() override;

    bool isApplicable(StrategyName name) override;

    ~AlwaysVoteCGameStrategy() override = default;

};


#endif //PRISONERS_ALWAYSVOTECGAMESTRATEGY_H
