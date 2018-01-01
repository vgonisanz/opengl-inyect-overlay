#include <glfwParser.h>

#include <dlfcn.h>
#include <stdio.h>

namespace glfwParser
{
    bool parseFunction(void **original_pointer_to_function, const char *library_name, const char *symbol)
    {
        if (*original_pointer_to_function == nullptr)
        {
            printf("Trying to parse %s from %s...\n", symbol, library_name);

            void *handle = dlopen(library_name, RTLD_LAZY);
            if (handle)
            {
                void *symbol_pointer = dlsym(handle, symbol);
                if (symbol_pointer)
                {
                    *original_pointer_to_function = reinterpret_cast<void *>(symbol_pointer);
                    dlclose(handle);
                    printf("Handled %s!\n", symbol);
                    return true;
                }
                else
                {
                    printf("Cannot handle %s!\n", symbol);
                }
            }
            else
            {
                printf("Cannot open %s!\n", library_name);
            }
        }
        return false;
    }
}
