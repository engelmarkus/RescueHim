#include "Game.h"

#include <cstdlib>

#include <SDL.h>
#include <SDL_image.h>
#include <sigc++/sigc++.h>

#include "Sdl.h"
#include "SdlError.h"
#include "Logger.h"
#include "Image.h"
#include "MainWindow.h"
#include "Intro.h"

namespace RescueHim {
    using namespace Geom;
    using namespace Sdl;

    MainWindow& Game::getMainWindow() {
        return *mainWindow.get();
    }

    void Game::initialize() {
        try {
            SDL::instance().initialize(SDL_INIT_VIDEO);
        } catch (SdlError const& error) {
            AppLog<Severity::Error>::log("Error while initializing SDL: ", error.what());
            std::exit(1);
        }

        try {
            SDL_image::instance().initialize(IMG_INIT_PNG);
        } catch (SdlError const& error) {
            AppLog<Severity::Error>::log("Error while initializing SDL_image: ", error.what());
            std::exit(1);
        }

        mainWindow = std::static_pointer_cast<MainWindow>(SDL::instance().createWindow<MainWindow>());

        currentState = std::make_unique<Intro>(*this);

        updateConnection = SDL::instance().updateSignal().connect(sigc::mem_fun(*this, &Game::update));
        renderConnection = SDL::instance().renderSignal().connect(sigc::mem_fun(*this, &Game::render));

        SDL::instance().run();
    }

    void Game::update() {
        this->currentState->update();
    }

    void Game::render() {
        this->currentState->render();
    }
}
