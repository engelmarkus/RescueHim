#include "Window.h"

#include <memory>

#include <SDL_error.h>

#include "Point.h"
#include "Renderer.h"
#include "SdlError.h"
#include "Size.h"

namespace RescueHim {
    namespace Sdl {
        Window::Window(std::string const& title, Geom::Point const& location, Geom::Size const& size)
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
            return SDL_GetWindowTitle(window.get());
        }

        void Window::setTitle(std::string const& title) {
            SDL_SetWindowTitle(window.get(), title.c_str());
        }

        Geom::Size Window::getSize() const {
            int w, h;

            SDL_GetWindowSize(window.get(), &w, &h);

            return Geom::Size { static_cast<unsigned int>(w), static_cast<unsigned int>(h) };
        }

        void Window::setSize(Geom::Size const& size) {
            SDL_SetWindowSize(window.get(), size.width, size.height);
        }

        Geom::Point Window::getPosition() const {
            Geom::Point position;

            SDL_GetWindowPosition(window.get(), &position.x, &position.y);

            return position;
        }

        void Window::setPosition(Geom::Point const& position) {
            SDL_SetWindowPosition(window.get(), position.x, position.y);
        }

        void Window::hide() {
            SDL_HideWindow(window.get());
        }

        void Window::maximize() {
            SDL_MaximizeWindow(window.get());
        }

        void Window::minimize() {
            SDL_MinimizeWindow(window.get());
        }

        void Window::raise() {
            SDL_RaiseWindow(window.get());
        }

        void Window::restore() {
            SDL_RestoreWindow(window.get());
        }

        void Window::show() {
            SDL_ShowWindow(window.get());
        }

        void Window::onShown() {
        }

        void Window::onHidden() {
        }

        void Window::onExposed() {
        }

        void Window::onMoved(Geom::Point) {
        }

        void Window::onResized(Geom::Size) {
        }

        void Window::onMinimized() {
        }

        void Window::onMaximized() {
        }

        void Window::onRestored() {
        }

        void Window::onMouseEnter() {
        }

        void Window::onMouseMove(Geom::Point) {
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
                break;

            case SDL_WINDOWEVENT_HIDDEN:
                this->onHidden();
                break;

            case SDL_WINDOWEVENT_EXPOSED:
                this->onExposed();
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
