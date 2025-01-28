gcc src/*.c -c -g -Isrc -Ilibs -Ilibs/imgui -Isokol -Isokol/util -DSOKOL_GLCORE &&\
g++ src/*.cc -c -g -Isrc -Ilibs -Ilibs/imgui -Isokol -Isokol/util -DSOKOL_GLCORE &&\
g++ *.o libs/imgui/*.o -o bin/app-pthread -lGL -ldl -lm -lX11 -lasound -lXi -lXcursor &&\
ls -l bin/app