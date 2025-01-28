TARGET = bin/app
SHADER_LANGS = glsl430
SOKOL_FLAGS = -DSOKOL_GLCORE

# sources
C_SOURCES = $(wildcard src/*.c)
CXX_SOURCES = $(wildcard src/*.cc)
IMGUI_SOURCES = $(wildcard libs/imgui/*.cpp)
SHADER_SOURCES = $(wildcard src/shaders/*.glsl)

# intermediate files
OBJS = $(C_SOURCES:.c=.o) $(CXX_SOURCES:.cc=.o) $(IMGUI_SOURCES:.cpp=.o)
SHADERS = $(SHADER_SOURCES:.glsl=.glsl.h)

# Compiler variables
CC = gcc
CXX = g++
INCLUDES = -Isrc -Isrc/shaders -Ilibs -Ilibs/imgui -Isokol -Isokol/util
CFLAGS = $(INCLUDES) -Wall -Werror $(SOKOL_FLAGS)
CXXFLAGS = $(INCLUDES) -Wall -Werror -std=c++11 $(SOKOL_FLAGS)
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2
LDFLAGS = -fuse-ld=mold -pthread -lGL -ldl -lm -lX11 -lasound -lXi -lXcursor

# build=release enables optimizations
# otherwise enables debugging symbols
build ?= debug
$(info building $(build))

ifeq ($(build), debug)
    CFLAGS += $(DEBUG_FLAGS)
    CXXFLAGS += $(DEBUG_FLAGS)
else ifeq ($(build), release)
    CFLAGS += $(RELEASE_FLAGS)
    CXXFLAGS += $(RELEASE_FLAGS)
endif

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

shaders: $(SHADERS)

%.o: %.c $(SHADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.glsl.h: %.glsl
	bin/sokol-shdc -i $< -o $@ -l $(SHADER_LANGS)

clean:
	rm -f $(OBJS) $(TARGET) $(SHADERS)

.PHONY: clean
