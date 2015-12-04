set(luabind_SRC
    luabind-deboostified/src/class.cpp
    luabind-deboostified/src/class_info.cpp
    luabind-deboostified/src/class_registry.cpp
    luabind-deboostified/src/class_rep.cpp
    luabind-deboostified/src/create_class.cpp
    luabind-deboostified/src/error.cpp
    luabind-deboostified/src/exception_handler.cpp
    luabind-deboostified/src/function.cpp
    luabind-deboostified/src/function_introspection.cpp
    luabind-deboostified/src/headertest.cpp
    luabind-deboostified/src/inheritance.cpp
    luabind-deboostified/src/link_compatibility.cpp
    luabind-deboostified/src/object_rep.cpp
    luabind-deboostified/src/open.cpp
    luabind-deboostified/src/operator.cpp
    luabind-deboostified/src/pcall.cpp
    luabind-deboostified/src/scope.cpp
    luabind-deboostified/src/set_package_preload.cpp
    luabind-deboostified/src/stack_content_by_name.cpp
    luabind-deboostified/src/weak_ref.cpp
    luabind-deboostified/src/wrapper_base.cpp
)

include_directories(SYSTEM ../lua/lua5.2-5.2.4/src)
include_directories(SYSTEM luabind-deboostified)

add_library(luabind ${luabind_SRC})
add_definitions(-DLUABIND_CPLUSPLUS_LUA)
