#include "Intro.h"

#include <SDL_render.h>

#include "Logger.h"
#include "Image.h"
#include "Point.h"
#include "Game.h"
#include "Renderer.h"
#include "State.h"
#include "Texture.h"
#include "MainWindow.h"
#include "MainMenu.h"

namespace RescueHim {
    using namespace Geom;
    using namespace Sdl;

    Intro::Intro(Game& game)
        : State(game)
        , counter{0}
        , logoNormal{SDL_image::instance().load("../data/images/rescuehim0.png")}
        , logoGlow{SDL_image::instance().load("../data/images/rescuehim1.png")}
    {
        normalTexture.reset(new Texture(game.getMainWindow().getRenderer(), logoNormal));
        glowTexture.reset(new Texture(game.getMainWindow().getRenderer(), logoGlow));

        SDL_SetTextureAlphaMod(normalTexture->getSdlTexture(), 0);
        SDL_SetTextureAlphaMod(glowTexture->getSdlTexture(), 0);
    }

    void Intro::update() {
        // 6 sekunden warten...
        // das update-intervall ist etwa 1/60/4 also 1/240 s.
        // damit die animationen auch richtig werden, rechnen wir aber lieber mit 256...
        counter++;

        // in den ersten zwei Sekunden die normalTexture updaten...
        if (counter < 256 * 2) {
            SDL_SetTextureAlphaMod(normalTexture->getSdlTexture(), counter / 2 % 256);
        }

        // danach eine sekunde die glowTexture einfaden...
        if (counter >= 256 * 2 && counter < 256 * 3)
        {
            SDL_SetTextureAlphaMod(glowTexture->getSdlTexture(), counter % 256);
        }

        // und beide zusammen zwei sekunden ausfaden...
        if (counter >= 256 * 3 && counter < 256 * 5) {
            int cn = counter - 256 * 3;
            // cn liegt zwischen 0 und 511

            SDL_SetTextureAlphaMod(normalTexture->getSdlTexture(), (511 - cn) / 2);
            SDL_SetTextureAlphaMod(glowTexture->getSdlTexture(), (511 - cn) / 2);

            AppLog<Severity::Info>::log("%d -> %d", cn, ((511 - cn) / 2));
        }

        // zustand wechseln.
        if (counter > 256 * 6) {
            this->game.switchState<MainMenu>(this->game);
            return;
        }
    }

    void Intro::render() {
        auto& r = this->game.getMainWindow().getRenderer();

        r.setDrawColor(0, 0, 0, 255);
        r.clear();

        normalTexture->draw(Point{0, 0});
        glowTexture->draw(Point{0, 0});
        r.present();
    }
}
