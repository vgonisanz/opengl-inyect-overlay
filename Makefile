BUILD_PATH = build

all: init full

	@echo "Compilation end!"

init:
	@mkdir ${BUILD_PATH}

overlay: front.c back.c
	echo "Compiling lib"
	cc `pkg-config --cflags glfw3 glu freetype2` -o ${BUILD_PATH}/front front.c `pkg-config --libs glfw3 glu ftgl`
	cc `pkg-config --cflags glfw3 glu freetype2` -o ${BUILD_PATH}/back back.c `pkg-config --libs glfw3 glu ftgl`
	gcc -o liboverlay.so -shared -fPIC main.c

full: full.c
	echo "Compiling full"
	cc `pkg-config --cflags glfw3 glu freetype2` -o ${BUILD_PATH}/full full.c `pkg-config --libs glfw3 glu ftgl`

clean:
	@rm -fr ${BUILD_PATH}
	@echo "Compilation cleaned!"
