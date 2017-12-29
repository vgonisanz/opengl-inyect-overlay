# Concept example

This is a example to show how is possible to use a overlay a library parsing on execution function calls.

The followings files are generated:

* libsimpleoverlay.so: A Library to catch glfwSwapBuffers, render a text, and calling the original glfwSwapBuffers.
* simpleapp: Binary with a raw test OpenGL app with a rotating triangle. We will add something here with the inyection at execute it.
* full: Binary with the final expected result without inyect the dinamic library.

# Full

Run full executable file to see the final expected result.

# Inyection

At build path, run LD_PRELOAD=./liboverlay.so ./simpleapp
