CC := g++
INC := inc/
SRC := src/
OBJ := obj/
CFLAGS := -g -Wall -Werror -Wpedantic -lstdc++ -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc
OBJS := $(OBJ)main.o $(OBJ)algorithms.o $(OBJ)io_funcs.o

.PHONY : clean func 	

app.exe: obj $(OBJS)
	$(CC) -o $@ $(OBJS)

obj/main.o: $(SRC)main.cpp $(INC)algorithms.hpp $(INC)io_funcs.hpp $(INC)return_codes.hpp
	$(CC) $(CFLAGS) -o $@ -c $<

obj/algorithms.o: $(SRC)algorithms.cpp $(INC)algorithms.hpp $(INC)return_codes.hpp $(INC)io_funcs.hpp
	$(CC) $(CFLAGS) -o $@ -c $<

obj/io_funcs.o: $(SRC)io_funcs.cpp $(INC)io_funcs.hpp
	$(CC) $(CFLAGS) -o $@ -c $< 

obj:
	mkdir -p obj

clean :
	rm -rf .vscode
	rm -fr obj/
	rm *.exe 