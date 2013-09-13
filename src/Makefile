CXX = g++-4.8
CXXFLAGS += -g3 -O0 -std=c++11 -Weffc++ -Wall -Wextra -pedantic $(shell pkg-config --cflags sdl2 SDL2_image lua5.1 luabind)
LDFLAGS += $(shell pkg-config --libs sdl2 SDL2_image lua5.1 luabind)

OBJECTS = \
	main.o \
	Point.o \
	Size.o \
	Rect.o \
	Sdl.o \
	Surface.o

all: rescuehim

rescuehim: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf rescuehim $(OBJECTS)

