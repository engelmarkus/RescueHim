set(lua_SRC
    lua5.2-5.2.3/src/lapi.c
    lua5.2-5.2.3/src/lauxlib.c
    lua5.2-5.2.3/src/lbaselib.c
    lua5.2-5.2.3/src/lbitlib.c
    lua5.2-5.2.3/src/lcode.c
    lua5.2-5.2.3/src/lcorolib.c
    lua5.2-5.2.3/src/lctype.c
    lua5.2-5.2.3/src/ldblib.c
    lua5.2-5.2.3/src/ldebug.c
    lua5.2-5.2.3/src/ldo.c
    lua5.2-5.2.3/src/ldump.c
    lua5.2-5.2.3/src/lfunc.c
    lua5.2-5.2.3/src/lgc.c
    lua5.2-5.2.3/src/linit.c
    lua5.2-5.2.3/src/liolib.c
    lua5.2-5.2.3/src/llex.c
    lua5.2-5.2.3/src/lmathlib.c
    lua5.2-5.2.3/src/lmem.c
    lua5.2-5.2.3/src/loadlib.c
    lua5.2-5.2.3/src/lobject.c
    lua5.2-5.2.3/src/lopcodes.c
    lua5.2-5.2.3/src/loslib.c
    lua5.2-5.2.3/src/lparser.c
    lua5.2-5.2.3/src/lstate.c
    lua5.2-5.2.3/src/lstring.c
    lua5.2-5.2.3/src/lstrlib.c
    lua5.2-5.2.3/src/ltable.c
    lua5.2-5.2.3/src/ltablib.c
    lua5.2-5.2.3/src/ltm.c
    lua5.2-5.2.3/src/lua.c
    lua5.2-5.2.3/src/luac.c
    lua5.2-5.2.3/src/lundump.c
    lua5.2-5.2.3/src/lvm.c
    lua5.2-5.2.3/src/lzio.c
)

file(COPY lua5.2-deb-multiarch.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lua5.2-5.2.3/src)

set_source_files_properties(${lua_SRC} PROPERTIES LANGUAGE CXX)

add_definitions(-DLUA_USE_LINUX -DLUA_COMPAT_ALL)

add_library(lua ${lua_SRC})
target_link_libraries(lua ${CMAKE_DL_LIBS})

