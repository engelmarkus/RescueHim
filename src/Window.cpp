#include "Window.h"

#include <SDL_error.h>

#include "MakeUnique.h"
#include "Point.h"
#include "Renderer.h"
#include "SdlError.h"
#include "Size.h"

namespace RescueHim {
    namespace Sdl {
        Window::Window(const std::string& title, const Geom::Point& location, const Geom::Size& size)
            : window{nullptr, SDL_DestroyWindow}
            , renderer{nullptr}
        {
            window.reset(SDL_CreateWindow(title.c_str(), location.x, location.y, size.width, size.height, 0));
            
            if (window == nullptr) {
                throw SdlError{SDL_GetError()};
            }
            
            renderer = std::make_unique<Renderer>(*this);
        }
        
        Window::Window(Window&& other) noexcept
            : window{nullptr, SDL_DestroyWindow}
            , renderer{nullptr}
        {
            swap(*this, other);
        }
        
        Window& Window::operator=(Window&& other) {
            swap(*this, other);
            return *this;
        }
        
        Uint32 Window::getId() const {
            return SDL_GetWindowID(window.get());
        }

        std::string Window::getTitle() const {
            return SDL_GetWindowTitle(this->window.get());
        }
        
        void Window::setTitle(const std::string& title) {
            SDL_SetWindowTitle(this->window.get(), title.c_str());
        }
        
        Geom::Size Window::getSize() const {
            int w, h;
            
            SDL_GetWindowSize(this->window.get(), &w, &h);
            
            return Geom::Size { static_cast<unsigned int>(w), static_cast<unsigned int>(h) };
        }
        
        void Window::setSize(const Geom::Size& size) {
            SDL_SetWindowSize(this->window.get(), size.width, size.height);
        }
        
        Geom::Point Window::getPosition() const {
            Geom::Point position;
            
            SDL_GetWindowPosition(this->window.get(), &position.x, &position.y);
            
            return position;
        }
        
        void Window::setPosition(const Geom::Point& position) {
            SDL_SetWindowPosition(this->window.get(), position.x, position.y);
        }
        
        void Window::hide() {
            SDL_HideWindow(this->window.get());
        }
        
        void Window::maximize() {
            SDL_MaximizeWindow(this->window.get());
        }
        
        void Window::minimize() {
            SDL_MinimizeWindow(this->window.get());
        }
        
        void Window::raise() {
            SDL_RaiseWindow(this->window.get());
        }
        
        void Window::restore() {
            SDL_RestoreWindow(this->window.get());
        }
        
        void Window::show() {
            SDL_ShowWindow(this->window.get());
        }
        
        
        void Window::onShown() {
        }
        
        void Window::onHidden() {
        }
        
        void Window::onExposed() {
        }
        
        void Window::onMoved(Geom::Point newPosition) {
        }
        
        void Window::onResized(Geom::Size newSize) {
        }
        
        void Window::onMinimized() {
        }

        void Window::onMaximized() {
        }
        
        void Window::onRestored() {
        }
        
        void Window::onMouseEnter() {
        }
        
        void Window::onMouseMove(Geom::Point position) {
        }
        
        void Window::onMouseLeave() {
        }
        
        void Window::onGainedFocus() {
        }

        void Window::onLostFocus() {
        }
        
        bool Window::onClose() {
            return true;
        }
        
        void Window::onRender() {
        }
        
        Renderer& Window::getRenderer() {
            return *renderer.get();
        }
        
        void Window::processEvents(SDL_Event e) {
            switch (e.window.event) {
                case SDL_WINDOWEVENT_SHOWN:
                    this->onShown();
                    //this->shown().emit();
                    break;

                case SDL_WINDOWEVENT_HIDDEN:
                    this->onHidden();
                    //this->hidden().emit();
                    break;

                case SDL_WINDOWEVENT_EXPOSED:
                    this->onExposed();
                    //this->exposed().emit();
                    break;

                case SDL_WINDOWEVENT_MOVED:
                    this->onMoved(Geom::Point(e.window.data1, e.window.data2));
                    break;

                case SDL_WINDOWEVENT_RESIZED:
                    this->onResized(Geom::Size(e.window.data1, e.window.data2));
                    break;

                case SDL_WINDOWEVENT_MINIMIZED:
                    this->onMinimized();
                    break;

                case SDL_WINDOWEVENT_MAXIMIZED:
                    this->onMaximized();
                    break;

                case SDL_WINDOWEVENT_RESTORED:
                    this->onRestored();
                    break;

                case SDL_WINDOWEVENT_ENTER:
                    this->onMouseEnter();
                    break;
                    
                case SDL_MOUSEMOTION:
                    this->onMouseMove(Geom::Point{e.motion.x, e.motion.y});
                    break;

                case SDL_WINDOWEVENT_LEAVE:
                    this->onMouseLeave();
                    break;

                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    this->onGainedFocus();
                    break;

                case SDL_WINDOWEVENT_FOCUS_LOST:
                    this->onLostFocus();
                    break;

                case SDL_WINDOWEVENT_CLOSE:
                    if (this->onClose()) {
                        SDL_Event tmp;
                        tmp.type = SDL_QUIT;

                        SDL_PushEvent(&tmp);
                    }
                    break;
            }
        }
        
        
        void swap(Window& a, Window& b) noexcept {
            std::swap(a.window, b.window);
            std::swap(a.renderer, b.renderer);
        }
    }
}
