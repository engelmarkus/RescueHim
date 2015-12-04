#include "Lua.h"

#include <iostream>
#include <memory>

#include <lauxlib.h>
#include <lualib.h>
#include <luabind/luabind.hpp>
#include <luabind/adopt_policy.hpp>

#include "Point.h"
#include "Size.h"
#include "Rect.h"
#include "Level.h"
#include "Player.h"
#include "Level_wrapper.h"
#include "Point_wrapper.h"
#include "Size_wrapper.h"
#include "Rect_wrapper.h"
#include "TableIterator.h"
#include "Player_wrapper.h"
#include "Singleton_wrapper.h"
#include "SdlError.h"
#include "ScopeFactory.h"
#include "Sdl.h"

#include <luabind/detail/deduce_signature.hpp>
#include <luabind/detail/format_signature.hpp>
#include <luabind/make_function.hpp>

#include <thread>

namespace RescueHim {
    namespace Lua {
        //Sdl::Surface loadImage(std::string const& path) {
        //    return SDL_image::instance().load(path);
        //}
        int loadImage(std::string const& str) {
            std::cout << str;
            //try {
            SDL_image::instance().load(str);
            //} catch(Sdl::SdlError const& error) { std::cout << error.what(); }
            return 52;
        }

        void registerWindow(std::shared_ptr<Sdl::Window> wnd) {
            SDL::instance().addWindow(wnd);
        }

        Lua::Lua()
            : state{luaL_newstate(), lua_close}
        {
            using namespace luabind;

            // Bind the new state to luabind.
            luaopen_base(state.get());

            // Load Lua's default libraries.
            luaL_openlibs(state.get());

            open(state.get());

            // Register wrappers for some C++ classes.
            module(state.get()) [
                //Point_wrapper::getClassDefinition(),
                //Size_wrapper::getClassDefinition(),
                //Rect_wrapper::getClassDefinition(),
                //Level_wrapper::getClassDefinition(),
                //Player_wrapper::getClassDefinition(),
                //Image_wrapper::getClassDefinition(),
                //Singleton_wrapper<Name, Sdl::Image>::getClassDefinition()

                namespace_("Sdl") [
                    //def("loadImage", &SDL_image::instance().load)

                    //def("loadImage", img->*ssff)

                    //def("loadImage", [](std::string const& path) { return SDL_image::instance().load(path); })
                    def("loadImage", &loadImage),
                    def("registerWindow", &registerWindow)
                ]
            ];

                for (auto const& type : ScopeFactory::instance().getTypes()) {
                    module(state.get()) [
                        type.second()
                    ];
                }


                // Load some convenience functions for later use.
                luaL_dofile(state.get(), "../data/scripts/internal.lua");

                try {
                    //bool errors = luaL_dofile(state.get(), "../data/scripts/level.lua");

                    // Man kann lua auch als c++ kompilieren, sodass es statt
                    // der fehlercodes direkt exceptions wirft...
                    // luabind::error ist eigentlich eh nicht die richtige.
                    //if (errors) {
                    //    throw luabind::error{state.get()};
                    //}

                    /*auto sig = luabind::detail::deduce_signature(&Geom::Rect::intersectWith);
                      luabind::detail::format_signature(state.get(), "funktionsname", sig);

                      object message{from_stack(state.get(), -1)};

                      std::cout << object_cast<std::string>(message) << std::endl;

                      lua_pop(state.get(), 1);
                      */



                    bool errors = luaL_loadfile(state.get(), "../data/scripts/level.lua");

                    if (errors) {
                        throw error{state.get()};
                    }

                    object script(from_stack(state.get(), -1));
                    call_function<void>(script);

                    lua_pop(state.get(), 1);

                    // Einen Zeiger auf die Klasse (!) holen
                    auto klasse = (*this)["DasLevel"];

                    // Ein Objekt davon konstruieren und das ownership an den unique_ptr übertragen.
                    auto level = std::unique_ptr<Level>(object_cast<Level*>(klasse(), adopt_policy<0>())); //adopt(result)));

                    level->onStart();

                    //std::this_thread::sleep_for(std::chrono::milliseconds(5000));

                    SDL::instance().run();

                    // über die enemies-table iterieren
                    for (auto i : level->Enemies) {
                        std::cout << object_cast<Geom::Point>(i) << std::endl;
                    }

                } catch(const error& error) {
                    //object message{from_stack(error.state(), -1)};

                    //std::cout << object_cast<std::string>(message) << std::endl;

                    //lua_pop(state.get(), 1);
                    std::cout << error.what() << std::endl;
                }
        }

        luabind::object Lua::operator[](const std::string& key) {
            return luabind::globals(state.get())[key];
        }
    }
}
