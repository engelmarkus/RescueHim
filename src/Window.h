#pragma once

#include <memory>
#include <string>

#include <SDL_events.h>
#include <SDL_stdinc.h>
#include <SDL_video.h>

#include "Point.h"
#include "Renderer.h"
#include "Size.h"

namespace RescueHim {
    namespace Sdl {
        class Window {
        public:
            using window_ptr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

            Window() = delete;
            Window(std::string const& title, Geom::Point const& location, Geom::Size const& size);

            Window(Window const&) = delete;
            Window(Window&& other) noexcept;

            Window& operator=(Window const&) = delete;
            Window& operator=(Window&& other);

            virtual ~Window() = default;

            Uint32 getId() const;

            std::string getTitle() const;
            void setTitle(std::string const& title);

            Geom::Size getSize() const;
            void setSize(Geom::Size const& size);

            Geom::Point getPosition() const;
            void setPosition(Geom::Point const& position);

            void hide();
            void maximize();
            void minimize();
            void raise();
            void restore();
            void show();

            virtual void onShown();
            virtual void onHidden();
            virtual void onExposed();

            virtual void onMoved(Geom::Point newPosition);
            virtual void onResized(Geom::Size newSize);

            virtual void onMinimized();
            virtual void onMaximized();
            virtual void onRestored();

            virtual void onMouseEnter();
            virtual void onMouseMove(Geom::Point position);
            virtual void onMouseLeave();

            virtual void onGainedFocus();
            virtual void onLostFocus();

            virtual bool onClose();

            virtual void onRender();

            virtual void processEvents(SDL_Event e);

            Renderer& getRenderer();

            friend class Renderer;
            friend void swap(Window& a, Window& b) noexcept;

        protected:
            window_ptr window;
            std::unique_ptr<Renderer> renderer;
        };
    }
}
