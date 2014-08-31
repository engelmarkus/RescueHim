#include "Player_wrapper.h"

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>
#include "../Point.h"
#include "../Player.h"

namespace RescueHim 
{
    namespace Lua 
    {
      luabind::scope Player_wrapper::getClassDefinition()
      {
	using namespace luabind;
	
	return (
	  luabind::class_<Player>("Player")
		.def(constructor<int, int>())
		.def(constructor<Geom::Point>())
		.def(constructor<const Player&>())
		
		.property("position", &Player::getPosition)
	);
      }
    }
}