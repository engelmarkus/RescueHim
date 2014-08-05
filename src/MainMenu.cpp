#include "MainMenu.h"

#include "Game.h"
#include "MainWindow.h"
#include "Renderer.h"

namespace RescueHim {
    using namespace Sdl;

    void MainMenu::update() {
    }

    void MainMenu::render() {
        Renderer& r = this->game.getMainWindow().getRenderer();
        
        r.setDrawColor(100, 100, 100, 255);
        r.clear();
        r.present();
    }
}
