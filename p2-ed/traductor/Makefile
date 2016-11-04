SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC)

#Rellenad el makefile para compilar el proyecto
all: $(BIN)/traductor 
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/traductor: $(OBJ)/frases.o $(OBJ)/conjuntofrases.o
	g++ $(CPPFLAGS) $(SRC)/pruebatrad_test.cpp $(OBJ)/frases.o $(OBJ)/conjuntofrases.o -o $(BIN)/traductor

$(OBJ)/frases.o: $(INC)/frases.h $(SRC)/frases.cpp
	g++ -c $(CPPFLAGS) $(SRC)/frases.cpp -o $(OBJ)/frases.o

$(OBJ)/conjuntofrases.o: $(INC)/conjuntofrases.h $(INC)/frases.h $(SRC)/conjuntofrases.cpp $(SRC)/frases.cpp
	g++ -c $(CPPFLAGS) $(SRC)/conjuntofrases.cpp -o $(OBJ)/conjuntofrases.o
	

# ************ Limpieza ************
clean :
	-@rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ 2> /dev/null

mrproper : clean
	-@rm $(BIN)/* doc/html/* doc/latex/* 2> /dev/null
