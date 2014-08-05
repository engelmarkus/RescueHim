set(luabind_SRC
    luabind-0.9.1+dfsg/src/class.cpp
    luabind-0.9.1+dfsg/src/class_info.cpp
    luabind-0.9.1+dfsg/src/class_registry.cpp
    luabind-0.9.1+dfsg/src/class_rep.cpp
    luabind-0.9.1+dfsg/src/create_class.cpp
    luabind-0.9.1+dfsg/src/error.cpp
    luabind-0.9.1+dfsg/src/exception_handler.cpp
    luabind-0.9.1+dfsg/src/function.cpp
    luabind-0.9.1+dfsg/src/inheritance.cpp
    luabind-0.9.1+dfsg/src/link_compatibility.cpp
    luabind-0.9.1+dfsg/src/object_rep.cpp
    luabind-0.9.1+dfsg/src/open.cpp
    luabind-0.9.1+dfsg/src/pcall.cpp
    luabind-0.9.1+dfsg/src/scope.cpp
    luabind-0.9.1+dfsg/src/stack_content_by_name.cpp
    luabind-0.9.1+dfsg/src/weak_ref.cpp
    luabind-0.9.1+dfsg/src/wrapper_base.cpp
)

include_directories(SYSTEM ../lua/lua5.2-5.2.3/src)
include_directories(SYSTEM luabind-0.9.1+dfsg)

add_library(luabind ${luabind_SRC})
add_definitions(-DLUABIND_CPLUSPLUS_LUA)
