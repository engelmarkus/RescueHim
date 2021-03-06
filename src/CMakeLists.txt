set(rescuehim_SRC
    main.cpp

    Point.cpp
    Rect.cpp
    Size.cpp

    Sdl.cpp
    Surface.cpp
    Window.cpp
    Renderer.cpp
    Texture.cpp
    AnimatedTexture.cpp
    Image.cpp

    Game.cpp
    Intro.cpp
    MainMenu.cpp
    MainWindow.cpp

    Player.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Scripting)
add_subdirectory(lua)
add_subdirectory(luabind)

set_source_files_properties(${rescuehim_SRC} PROPERTIES
    COMPILE_FLAGS "-pedantic -Wall -Wextra -Wnon-virtual-dtor -Weffc++ -Wcast-qual -Winit-self -Wconversion -Wshadow"
)

add_executable(rescuehim ${rescuehim_SRC})

find_package(PkgConfig REQUIRED)

pkg_check_modules(LIBS REQUIRED sdl2 SDL2_image sigc++-2.0)
include_directories(SYSTEM ${LIBS_INCLUDE_DIRS})
target_link_libraries(rescuehim ${LIBS_LIBRARIES})

include_directories(SYSTEM lua/lua5.2-5.2.4/src)
link_directories(SYSTEM lua/lua5.2-5.2.4/src)
add_definitions(-DLUABIND_CPLUSPLUS_LUA)
target_link_libraries(rescuehim lua)

include_directories(SYSTEM luabind/luabind-deboostified)
link_directories(SYSTEM luabind/luabind-deboostified/src)
target_link_libraries(rescuehim luabind)
