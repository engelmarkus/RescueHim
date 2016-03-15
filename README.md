RescueHim
=========
A small project implementing a game engine using sdl2 for graphics and lua for scripting.

## Compilation
Lua and luabind will be linked in statically as the luabind packages provided by most distributions are currently unusable with c++11 compilers as destructors are nothrow by default now.

```
git clone https://github.com/engelmarkus/RescueHim.git
cd src/lua
apt-get source lua5.2
cd ../luabind
git clone https://github.com/decimad/luabind-deboostified.git
cd ../../
mkdir build
cd build
cmake ..
make
src/rescuehim
```
