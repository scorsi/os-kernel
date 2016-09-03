OBJ = kernel

all: $(OBJ)

kernel:
        make -C src
        mv src/kernel .

clean:
        rm -f $(OBJ) *.o
        make -C src clean
