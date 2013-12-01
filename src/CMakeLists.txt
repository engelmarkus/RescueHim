set(rescuehim_SRC
    main.cpp
    Point.cpp
    Rect.cpp
    Sdl.cpp
    Size.cpp
    Surface.cpp
)

add_executable(rescuehim ${rescuehim_SRC})

find_package(PkgConfig REQUIRED)

pkg_check_modules(LIBS REQUIRED sdl2 SDL2_image lua5.2 luabind)
include_directories(${LIBS_INCLUDE_DIRS})
target_link_libraries(rescuehim ${LIBS_LIBRARIES})

