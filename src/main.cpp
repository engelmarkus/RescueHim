#include <iostream>

#include <SDL.h>
#include "Logger.h"
#include "Sdl.h"
#include "SdlError.h"

using namespace RescueHim;
using namespace RescueHim::Sdl;

int main(int argc, char* argv[]) {
    try {
        SDL::instance().initialize(SDL_INIT_VIDEO);
    } catch (const SdlError& error) {
        std::cerr << "Error while initializing SDL: " << error.what() << std::endl;
        AppLog<Severity::Error>::log("Error while initializing SDL: ", error.what());
        return 1;
    }

	return 0;
}

