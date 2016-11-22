SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usocolas $(BIN)/usopilas_max

$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o 
$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o $(OBJ)/pila_maxmin.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o $(OBJ)/pila_maxmin.o
$(OBJ)/usopilas_max.o: $(INC)/pila_maxmin.h $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o

$(OBJ)/pila_maxmin.o: $(INC)/pila_maxmin.h
	$(CXX) $(CPPFLAGS) $(SRC)/pila_maxmin.cpp -o $(OBJ)/pila_maxmin.o


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
