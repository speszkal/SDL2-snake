OBJS = main.cpp src/Game.cpp src/Body.cpp src/Head.cpp src/Apple.cpp src/globals.cpp

OBJS_NAME = main.exe

INCLUDE_PATHS = -Ilibs/SDL2/include

LIBRARY_PATHS = -Llibs/SDL2/lib

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

all:
	g++ $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o $(OBJS_NAME) $(OBJS) $(LINKER_FLAGS)