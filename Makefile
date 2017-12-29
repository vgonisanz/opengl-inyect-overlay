BUILD_PATH = build

all: init full overlay

	@echo "Compilation end!"

init:
	@mkdir -p ${BUILD_PATH}

overlay: binary.c overlay.c
	echo "Compiling lib"
	cc `pkg-config --cflags glfw3 glu freetype2` -o ${BUILD_PATH}/binary binary.c `pkg-config --libs glfw3 glu ftgl`
	cc `pkg-config --cflags glfw3 glu freetype2` -o ${BUILD_PATH}/liboverlay.so -shared -fPIC overlay.c `pkg-config --libs glfw3 glu ftgl`

full: full.c
	echo "Compiling full"
	cc `pkg-config --cflags glfw3 glu freetype2` -o ${BUILD_PATH}/full full.c `pkg-config --libs glfw3 glu ftgl`

clean:
	@rm -fr ${BUILD_PATH}
	@echo "Compilation cleaned!"

run-full:
	${BUILD_PATH}/full

run-binary:
	${BUILD_PATH}/binary

run-inyection:
	LD_PRELOAD=./${BUILD_PATH}/liboverlay.so ./${BUILD_PATH}/binary
