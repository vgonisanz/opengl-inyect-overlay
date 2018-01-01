# OpenGL Inyect overlay

This project is a draft to test how create a library with GLFW OpenGL and apply over another binary bypassing glfwSwapBuffers and another functions.

# Dependencies

## GLFW

Install devel version. In example for Fedora:

```
sudo dnf install glfw-devel.x86_64
```

## Freetype

Install freetype.


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
 to parse swapbuffers and keyboard into a GLFW app.

## Performance

This is a simple implementation to show performance:

* ```LD_PRELOAD=./../lib/libperformance_overlay.so ./fakeperformancegame```

# Based on

Original idea from ZaneA's [gist](https://gist.github.com/ZaneA/4305411)
