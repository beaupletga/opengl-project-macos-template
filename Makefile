
FILES = ./src/*.cpp

APP_INCLUDES:= -I./src/vendors/GLFW -framework Cocoa -framework OpenGL -framework IOKit
APP_LINKERS:= -L./src/vendors/GLFW/lib  -lglfw3

build:
	g++ $(FILES) -o main -std=c++11 $(APP_INCLUDES) $(APP_LINKERS)

run: build
	./main