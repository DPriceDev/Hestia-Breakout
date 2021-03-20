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
        LOG_DEBUG("Game session", "begin game")
    }

    void gameLoop(const double & /*deltaTime*/) override {

    }

    void endGame() override {
        LOG_DEBUG("Game session", "end game")
    }
};

#endif //HESTIA_BREAKOUT_BREAKOUT_SESSION_H
