SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
INC=$(wildcard *.h)

LIBRARY=libmario.so
EXECUTABLE=execlib

all: $(LIBRARY) $(EXECUTABLE)

debug:
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(INC)

%.o: %.c $(INC)
	gcc -c $< -o $@

$(LIBRARY): $(OBJ)
	gcc -shared -o $@ $^

$(EXECUTABLE): main.o $(LIBRARY)
	gcc -fsanitize=address -o $@ main.o -L. -lmario -Wl,-rpath,'$$ORIGIN'


doc:
	doxygen Doxyfile

clean:
	rm -f *.o
	rm -f $(LIBRARY) $(EXECUTABLE)
	rm -rf doc exec
