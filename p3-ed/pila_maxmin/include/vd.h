
#ifndef __VD_H
#define __VD_H
/**
 * @brief Clase que representa un vector dinámico (array de 1-d con redimensionamiento)
 */
template<typename T>
class VD {
private:
	T *data = nullptr; /*< Array de C que contiene los datos */
	unsigned length = 0; /* Número de elementos del contenedor */
	unsigned capacity = 0; /* Número de elementos que puede almancenar el contenedor */

	/**
	* @brief Función auxiliar para copiar todos los datos de otro VD
	* @param o Referencia constante a otro VD
	*/
	void copy_from(const VD& o);

	/**
	 * @brief Función auxiliar para redimensionar el contenedor de datos
	 * @param capacity Nueva capacidad del contenedor
	 * @pre @c 0 <= capacity
	 */
	void resize(const unsigned capacity);

public:
	/**
	 * @brief Constructor con capacidad inicial (por defecto 10)
	 * @param capacity Capacidad inicial del VD
	 * @return VD con capacidad incicial @c capacity
	 */
	VD(unsigned capacity = 10);

	/**
	 * @brief Constructor de copia
	 * @param o Referencia constante a otro VD
	 * @return VD con los mismos datos que @c o
	 */
	VD(const VD& o);

	/**
	 * @brief Destructor de VD
	 */
	~VD();

	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param o Referencia constante a otro VD
	 * @return Referencia al VD (this)
	 */
	VD& operator=(const VD& o);

	/**
	 * @brief Consultor de datos en una posición concreta
	 * @param pos Posición sobre la que consultar
	 * @return Referencia constante al elemento
	 * @pre <tt>0 <= pos < size()</tt>
	 */
	const T& operator[](unsigned pos) const;

	inline unsigned size() const { return length; }

	void insert(unsigned pos, T value);

	inline void push_back(T value) { insert(length, value); }

	inline void push_front(T value) { insert(0, value); }

	void remove(unsigned pos);

	inline void trim() { resize(length); }

};

#include "vd.cpp"

#endif