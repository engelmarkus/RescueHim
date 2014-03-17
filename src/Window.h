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
                typedef std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_ptr;
                
                Window() = delete;
                Window(const std::string& title, const Geom::Point& location, const Geom::Size& size);
                
                Window(const Window&) = delete;
                Window(Window&& other) noexcept;
                
                Window& operator=(const Window&) = delete;
                Window& operator=(Window&& other);
                
                virtual ~Window() = default;
                
                Uint32 getId() const;
                
                std::string getTitle() const;
                void setTitle(const std::string& title);
                
                Geom::Size getSize() const;
                void setSize(const Geom::Size& size);
                
                Geom::Point getPosition() const;
                void setPosition(const Geom::Point& position);
                
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
                virtual void onMouseLeave();
                
                virtual void onGainedFocus();
                virtual void onLostFocus();
                
                virtual bool onClose();

                virtual void onRender();
                
                virtual void processEvents(SDL_Event e);
                

                friend class Renderer;                
                friend void swap(Window& a, Window& b) noexcept;
                
            protected:
                window_ptr window;
                std::unique_ptr<Renderer> renderer;
        };
    }
}
