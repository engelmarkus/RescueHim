#include "Renderer.h"

#include "Window.h"
#include "SdlError.h"

namespace RescueHim {
    namespace Sdl {
        Renderer::Renderer(const Window& window)
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
        
        
        void swap(Renderer& a, Renderer& b) {
            std::swap(a.renderer, b.renderer);
        }
    }
}