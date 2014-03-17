set(rescuehim_SRC
    main.cpp
    Point.cpp
    Rect.cpp
    Sdl.cpp
    Size.cpp
    Surface.cpp
    Window.cpp
    Renderer.cpp
    Texture.cpp
    AnimatedTexture.cpp
    Image.cpp
)

add_executable(rescuehim ${rescuehim_SRC})

find_package(PkgConfig REQUIRED)

pkg_check_modules(LIBS REQUIRED sdl2 SDL2_image sigc++-2.0 lua5.2 luabind)
include_directories(SYSTEM ${LIBS_INCLUDE_DIRS})
target_link_libraries(rescuehim ${LIBS_LIBRARIES})

