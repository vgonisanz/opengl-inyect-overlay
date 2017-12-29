# Steam-like overlay

SLO project is a draft to test how create a library with OpenGL and apply over another binary bypassing glfwSwapBuffers.

# Dependencies

## GLFW

Install devel version

```
sudo dnf install glfw-devel.x86_64
```

## Freetype

...

## nanogui

It is a repository to create simple GUI based on OpenGL. Use GLFW as dependency!

* Note I: Do the following commands where you want to put the dependencies source code.
* Note II: Change path ```~/install/nanogui``` for your desired installing path.
* Note III: This path shall be provided when cmake this project. If not error ```Provide dependencies path``` will be generated.

```
git clone --recursive git@github.com:wjakob/nanogui.git
mkdir build && cd build
cmake ..
make
make -j4
make install
```

# Compiling

```
mkdir build && cd build
cmake ..
make -j4
make install
```


# How to use

This code has been tested only in GNU/Linux. Just compile using ```make```. This command will generate a build folder containing 3 executables:

* ./full
* LD_PRELOAD=./../lib/libsimpleoverlay.so ./binary

To run you can use:

* ```make run-full```: This command execute expected result WITHOUT inyection.
* ```make run-binary```: This command just execute raw binary.
* ```make run-inyection```: This command will inyect the shared library into the raw binary.

# Based on

Original idea from ZaneA's [gist](https://gist.github.com/ZaneA/4305411)
