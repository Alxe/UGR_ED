
#ifndef __LISTA_H
#define __LISTA_H

/**
 * @brief Contenedor de datos genérico de lista enlazadas
 */
template<typename T>
class Lista {
    /**
     * @brief Celda que contiene los datos y un puntero a la siguiente celda
     */
	struct Cell {
		T value; /*< Valor contenido en la celda */
		Cell *next; /*< Puntero a la siguiente celda */

        /**
         * @brief Constructor de Celda sin enlace
         * @param value Valor que contiene la Celda
         * @return Una Celda con valor inicial, pero sin enlace a otra Celda.
         */
		inline Cell(T value) : Cell(value, nullptr) {}

        /**
         * @brief Constructor de Celda con enlace
         * @param value Valor que contiene la Celda
         * @param next Puntero a la siguiente Celda enlazada
         * @return Una Celda con valor inicial y enlace a otra celda.
         */
        Cell(T value, Cell *next);

        Cell(const Cell& o) : Cell(o.value, o.next) {}

        Cell& operator=(const Cell& o);

        /**
         * @brief Destructor de Celda
         */
		inline ~Cell() { if(next != nullptr) delete next; }
	};

private:
	Cell *origin = nullptr; /*< Puntero a la primera Celda */
	unsigned length = 0; /*< Tamaño de datos enlazados */

    /**
     * @brief Función auxiliar para copiar todos los datos de otra Lista
     * @param o Referencia constante a otra Lista
     */
	void copy_from(const Lista& o);

public:
    /**
     * @brief Constructor por defecto de Lista
     * @return Devuelve una Lista vacía
     */
	Lista();

    /**
     * @brief Constructor de copia de Lista
     * @param o Referencia constante a otra Lista
     * @return Devuelve una lista con los mismos valores
     */
	Lista(const Lista& o);

    /**
     * @brief Destructor de Lista
     */
	~Lista();

    /**
     * @brief Sobrecarga del operador de asignación
     * @param o Referencia constante a otra Lista
     * @return Referencia a la lista (this)
     */
	Lista& operator=(const Lista& o);

    /**
     * @brief Devuelve el número de elementos de la lista enlazada
     * @return Número de elementos de la lista enlazada
     */
	inline unsigned size() const { return length; }

    /**
     * @brief Inserta un nuevo elemento en una posición determinada
     * @param pos Posición donde introducir el elemento
     * @param value Valor del elemento a introducir
     * @pre @c pos >= 0
     * @pre @c pos < this->size()
     */
	void insert(unsigned pos, T value);

    /**
     * @brief Elimina un elemento de una posición determinada
     * @param pos Posición del elemento a eliminar
     * @pre @c pos >= 0
     * @pre @c pos < this->size()
     */
	void remove(unsigned pos);

    /**
     * @brief Consulta el elemento de una posición determinada
     * @param pos Posición del elemento a consultar
     * @return Referencia constante al elemento
     * @pre @c pos >= 0
     * @pre @c pos < this->size()
     */
	const T& peek(unsigned pos) const; /*< operator[] */

    /**
     * @brief Inserta un elemento en la última posición
     * Es idéntico a this->insert(this->size(), value)
     * @param value Valor del elemento a introducir
     */
    inline void push_back(T value) { insert(length, value); }

    /**
     * @brief Inserta un elemento en la primera posición
     * Es idéntico a this->insert(0, value)
     * @param value Valor del elemento a introducir
     */
    inline void push_front(T value) { insert(0, value); }

};

#include "lista.cpp"

#endif