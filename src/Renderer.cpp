#include "Renderer.h"

#include <SDL_error.h>
#include <SDL_rect.h>

#include "Point.h"
#include "Rect.h"
#include "SdlError.h"
#include "Texture.h"
#include "Window.h"

namespace RescueHim {
    namespace Sdl {
        Renderer::Renderer(Window const& window)
            : renderer{nullptr, SDL_DestroyRenderer}
        {
            renderer.reset(SDL_CreateRenderer(window.window.get(), -1, 0));

            if (renderer == nullptr) {
                throw SdlError{SDL_GetError()};
            }
        }

        Renderer::Renderer(Renderer&& other)
            : renderer{nullptr, SDL_DestroyRenderer}
        {
            swap(*this, other);
        }

        Renderer& Renderer::operator=(Renderer&& other) {
            swap(*this, other);
            return *this;
        }

        void Renderer::clear() {
            SDL_RenderClear(this->renderer.get());
        }

        void Renderer::present() {
            SDL_RenderPresent(this->renderer.get());
        }

        void Renderer::setDrawColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
            SDL_SetRenderDrawColor(this->renderer.get(), r, g, b, a);
        }

        void Renderer::copy(Texture const& texture, Geom::Rect const& src, Geom::Rect const& dest) {
            auto s = SDL_Rect(src);
            auto d = SDL_Rect(dest);

            auto result = SDL_RenderCopy(this->renderer.get(), texture.getSdlTexture(), &s, &d);

            if (result != 0) {
                throw SdlError{SDL_GetError()};
            }
        }

        void Renderer::drawLine(Geom::Point const& p1, Geom::Point const& p2) {
            auto result = SDL_RenderDrawLine(this->renderer.get(), p1.x, p1.y, p2.x, p2.y);

            if (result != 0) {
                throw SdlError{SDL_GetError()};
            }
        }

        SDL_Renderer* Renderer::getSdlRenderer() const {
            return this->renderer.get();
        }


        void swap(Renderer& a, Renderer& b) noexcept {
            std::swap(a.renderer, b.renderer);
        }
    }
}
