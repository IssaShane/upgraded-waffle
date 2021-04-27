#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/Menu.cc src/Enemy.cpp src/Graphics.cpp src/Hud.cpp src/Item.cpp src/ItemManager.cpp src/Level.cpp src/LevelManager.cpp src/Player.cpp src/System.cpp src/GameObject.cc src/Fighter.cc src/Subject.cc src/Observer.cc src/Controller.cc src/ComputerPlayer.cc

#CC specifies which compiler we're using
CC = g++ 

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/usr/include/SDL2

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -std=c++14 

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = XFighter

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)