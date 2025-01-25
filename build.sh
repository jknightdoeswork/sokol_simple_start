gcc src/*.c src/*.cc -c -Isrc -Ilibs/imgui -Isokol -Isokol/util -Isokol/dbgui -DSOKOL_GLCORE &&\
g++ *.o libs/imgui/*.o -o bin/triangle -pthread -lGL -ldl -lm -lX11 -lasound -lXi -lXcursor &&\
ls -l bin/triangle

