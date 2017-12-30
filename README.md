# Steam-like overlay

SLO project is a draft to test how create a library with OpenGL and apply over another binary bypassing glfwSwapBuffers.

# Dependencies

## GLFW

Install devel version. In example for Fedora:

```
sudo dnf install glfw-devel.x86_64
```

## Freetype

...

## nanogui

It is a repository to create simple GUI based on OpenGL. Use GLFW as dependency! This is required to use a sample of steamlike overlay.

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

After compile and install (default path install inside build folder) go to install path an execute them:

## Concept example

This is a basic example for inyection:

* ```./full```: If you want to see the expected result WITHOUT inyection code. This executable shows a simple OpenGL app.
* ```./binary```: If you want to see the a simple OpenGL app. We will use this binary to overlay a library.
* ```LD_PRELOAD=./../lib/libsimpleoverlay.so ./binary```: This command will inyect shared library ```libsimpleoverlay.so``` into raw binary ```binary```. This combination shows how inyect a library to parse swapbuffers and keyboard into a GLFW app.

## Steamlike

**steam schema** **TODO**

# Based on

Original idea from ZaneA's [gist](https://gist.github.com/ZaneA/4305411)
