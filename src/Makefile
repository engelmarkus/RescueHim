CC = g++
CXXFLAGS += -g3 -std=c++11 -Wall -Wextra -pedantic $(shell pkg-config --cflags sdl2 SDL2_image lua5.1 luabind)
LDFLAGS += $(shell pkg-config --libs sdl2 SDL2_image lua5.1 luabind)

OBJECTS = \
	main.o \
	Point.o \
	Size.o \
	Rect.o

all: rescuehim

rescuehim: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf rescuehim $(OBJECTS)

