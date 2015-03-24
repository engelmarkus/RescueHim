#pragma once

#include <memory>

#include <SDL_surface.h>

namespace RescueHim {
    namespace Geom {
        class Size;
    }

    namespace Sdl {
        /**
          * @brief Encapsulates an SDL_Surface.
          */
        class Surface final {
            public:
                typedef std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface_ptr;
                
                /**
                  * @brief Creates a new empty Surface with the given size.
                  * @throws SdlError If the call to SDL_CreateRGBSurface did not succeed.
                  */
                Surface(const Geom::Size& size, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

                /**
                  * @brief Creates a new Surface by taking ownership of the given SDL_Surface.
                  */
                Surface(surface_ptr surface);

                Surface(const Surface& other);
                Surface(Surface&& other) noexcept;
                
                Surface& operator=(Surface other);

                ~Surface() = default;
                
                /// @returns The width.
                unsigned int getWidth() const;
                
                /// @returns The height.
                unsigned int getHeight() const;
                
                /// @returns The size.
                Geom::Size getSize() const;
                
                /**
                 * @brief Retrieves a raw pointer to the underlying SDL_Surface.
                 * @attention The returned pointer must not be freed (don't delete it / call SDL_FreeSurface on it)!
                 */
                SDL_Surface* getSdlSurface() const;
                
                /**
                 * @returns A value indicating whether the underlying SDL_Surface must be locked before accessing its raw data.
                 * @see lock
                 */
                bool mustLock() const;
                
                /**
                 * @brief Locks the underlying SDL_Surface so that its raw data can be accessed.
                 * @remarks In order to provide exception safety, don't call lock or unlock directly.
                 * Instead, use some kind of "guard":
                 * @code
                 * #include <mutex>
                 * // ...
                 * auto s = Surface{{width, height}};
                 * // ...
                 * {
                 *     std::lock_guard<Surface> lock{s};
                 *     
                 *     // Now modify the surface's raw pixel data.
                 *     auto* buffer = s.getSdlSurface()->pixels;
                 * }
                 * // Unlock is automatically called at the end of the scope.
                 * @endcode
                 * Note that in this example std::lock_guard does not protect from parallel access.
                 * It rather makes sure that the pixels member points to valid raw data and that SDL
                 * will not move the data in memory until unlock is called.
                 * If using std::lock_guard, make sure that there is only ever exactly one lock on a certain Surface
                 * as the first lock that goes out of scope will unconditionally unlock the underlying SDL_Surface.
                 * @see mustLock
                 * @see unlock
                 */
                void lock();
                
                /**
                 * @brief Unlocks the underlying SDL_Surface if it has been locked by a call to lock before.
                 * @see lock
                 */
                void unlock();

                friend void swap(Surface& a, Surface& b) noexcept;
                
            private:
                surface_ptr surface;
        };
    }
}
