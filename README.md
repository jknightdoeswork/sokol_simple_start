## Sokol Simple Start

This repo is simply a project structure to get started using the [sokol](https://github.com/floooh/sokol) libs along with [imgui](https://github.com/ocornut/imgui). The project primarily uses the Makefile, which compiles all the src and shaders, but it also has shell scripts that run the raw build commands. You can copy paste samples from [sokol-samples](https://github.com/floooh/sokol-samples/tree/master/sapp) direcly into the src/app.c file here (along with the relevant shader into src/shaders) and it should compile.

The Makefile is setup to compile `src/*.c` and `src/*.cc` and to compile shaders `src/shaders/*.glsl`.


To compile shaders you must build bin/sokol_shdc:

```
git clone https://github.com/floooh/sokol-tools/
cd sokol-tools
sh docker_build
cp sokol-shdc path/to/this_project/bin
```