#pragma once

#include <vector>
#include <string>
#include "Size.h"
#include "Point.h"
#include "Scripting/Lua.h"

namespace RescueHim {
    class Level {
        public:
            Level() = default;
            virtual ~Level() = default;
            
            Level(const Level&) = delete;
            Level& operator=(const Level&) = delete;

            virtual void onStart() = 0;
          
            std::string Name;
            Geom::Point StartPosition;
            
            Geom::Size Size;
            
            luabind::object Map;
            luabind::object Enemies;
    };
}
