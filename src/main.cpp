#include <iostream>
#include <engine.h>
#include <graphics/opengl_module.h>

#include "breakout_session.h"

int main() {
    auto engine = std::make_unique<HGE::Engine>();

    engine->useGraphicsModule<HGE::OpenglModule>();

    engine->getGraphicsModule()->setGameTitle("Hestia Breakout v1.0");

    engine->loadGameEnvironment<BreakoutSession>();
    return 0;
}
