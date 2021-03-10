//
// Created by david on 10/03/2021.
//

#ifndef HESTIA_BREAKOUT_BREAKOUT_SESSION_H
#define HESTIA_BREAKOUT_BREAKOUT_SESSION_H

class BreakoutSession : public HGE::GameEnvironment {

public:
    explicit BreakoutSession(HGE::Context* context) : HGE::GameEnvironment(context) { }

    ~BreakoutSession() override = default;

    void beginGame() override {

    }

    void gameLoop(const double &deltaTime) override {
        LOG_DEBUG(std::to_string(deltaTime))
    }

    void endGame() override {

    }
};

#endif //HESTIA_BREAKOUT_BREAKOUT_SESSION_H
