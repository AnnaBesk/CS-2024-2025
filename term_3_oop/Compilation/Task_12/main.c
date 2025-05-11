#include "alice.h"
#include "bob.h"
#include <dlfcn.h> 

typedef void (*animal_func_t)(void);

int main()
{
    void* lib_handle;

    lib_handle = dlopen("external/lib/libhouse.dylib", RTLD_LAZY);

    animal_func_t cat = (animal_func_t)dlsym(lib_handle, "cat");
    animal_func_t mouse = (animal_func_t)dlsym(lib_handle, "mouse");
    animal_func_t elephant = (animal_func_t)dlsym(lib_handle, "elephant");

    animal_func_t dog = (animal_func_t)dlsym(lib_handle, "dog");
    animal_func_t tiger = (animal_func_t)dlsym(lib_handle, "tiger");
    animal_func_t axolotl = (animal_func_t)dlsym(lib_handle, "axolotl");

    cat();
    mouse();
    elephant();

    dog();
    tiger();
    axolotl();

    dlclose(lib_handle);
}