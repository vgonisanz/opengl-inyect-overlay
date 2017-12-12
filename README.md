# Steam-like overlay

This project is a draft to test how create a library with OpenGL and apply over another binary bypassing glfwSwapBuffers.

# Dependencies

* ftgl-devel

# How to use

This code has been tested only in GNU/Linux. Just compile using ```make```. This command will generate a build folder containing 3 executables:

* full: The final expected result without inyect the dinamic library.
* liboverlay.so: A Library to catch glfwSwapBuffers, render a text, and calling the original glfwSwapBuffers.
* binary: Raw test OpenGL app with a rotating triangle. We will add something here with the inyection.

To run you can use:

* ```make run-full```: This command execute expected result WITHOUT inyection.
* ```make run-binary```: This command just execute raw binary.
* ```make run-inyection```: This command will inyect the shared library into the raw binary.

# Based on

Original idea from ZaneA's [gist](https://gist.github.com/ZaneA/4305411)
