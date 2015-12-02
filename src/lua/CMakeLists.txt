set(lua_SRC
    lua5.2-5.2.4/src/lapi.c
    lua5.2-5.2.4/src/lauxlib.c
    lua5.2-5.2.4/src/lbaselib.c
    lua5.2-5.2.4/src/lbitlib.c
    lua5.2-5.2.4/src/lcode.c
    lua5.2-5.2.4/src/lcorolib.c
    lua5.2-5.2.4/src/lctype.c
    lua5.2-5.2.4/src/ldblib.c
    lua5.2-5.2.4/src/ldebug.c
    lua5.2-5.2.4/src/ldo.c
    lua5.2-5.2.4/src/ldump.c
    lua5.2-5.2.4/src/lfunc.c
    lua5.2-5.2.4/src/lgc.c
    lua5.2-5.2.4/src/linit.c
    lua5.2-5.2.4/src/liolib.c
    lua5.2-5.2.4/src/llex.c
    lua5.2-5.2.4/src/lmathlib.c
    lua5.2-5.2.4/src/lmem.c
    lua5.2-5.2.4/src/loadlib.c
    lua5.2-5.2.4/src/lobject.c
    lua5.2-5.2.4/src/lopcodes.c
    lua5.2-5.2.4/src/loslib.c
    lua5.2-5.2.4/src/lparser.c
    lua5.2-5.2.4/src/lstate.c
    lua5.2-5.2.4/src/lstring.c
    lua5.2-5.2.4/src/lstrlib.c
    lua5.2-5.2.4/src/ltable.c
    lua5.2-5.2.4/src/ltablib.c
    lua5.2-5.2.4/src/ltm.c
    lua5.2-5.2.4/src/lua.c
    lua5.2-5.2.4/src/luac.c
    lua5.2-5.2.4/src/lundump.c
    lua5.2-5.2.4/src/lvm.c
    lua5.2-5.2.4/src/lzio.c
)

file(COPY lua5.2-deb-multiarch.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lua5.2-5.2.4/src)

set_source_files_properties(${lua_SRC} PROPERTIES LANGUAGE CXX)

add_definitions(-DLUA_USE_LINUX -DLUA_COMPAT_ALL)

add_library(lua ${lua_SRC})
target_link_libraries(lua ${CMAKE_DL_LIBS})

