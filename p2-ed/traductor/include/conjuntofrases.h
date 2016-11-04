/**
 *	@brief Fichero cabecera del TDA ConjuntoFrases
 *
 */

#ifndef __CONJUNTO_FRASES_H
#define __CONJUNTO_FRASES_H

#include "frases.h"
#include <string>
#include <vector>
#include <iostream>

/**
 *	@brief TDA ConjuntoFrases
 *
 *	Una instancia @c cf del tipo de datos abstracto @c ConjuntoFrases es un objeto
 * 	contenedor de @e n elementos del tipo de datos abstracto @c Frase.
 *
 */
class ConjuntoFrases {
private:
	std::vector<Frase> frases; /*!< Contenedor de Frases */

public:
	/**
	 *	@brief @e Getter del tamaño del contenedor de frases
	 *
	 *	@return Devuelve la cantidad de datos @c Frase que contiene el conjunto
	 */
	unsigned long Size() const { return frases.size(); }

    /**
     *	@brief Comprueba si existe un elemento de tipo Frase en el conjunto
     *
     *	@return @c true si existe, @c false en caso contrario.
     */
    bool Vacio() const { return Size() == 0; }

    /**
     *	@brief Comprueba si existe un elemento de tipo Frase en el conjunto
     *
     *	@return @c true si existe, @c false en caso contrario.
     */
    bool Esta(const std::string& str) const;

    /**
	 *	@brief Añade un elemento al conjunto
	 *
	 *	@return Referencia a la frase añadida
	 */
    void AddFrase(const std::string origen, const std::string destino);

    /**
     *	@brief @e Getter del vector que representa todas las frases
     *
     *	@return Una referencia constante del vector que representa todas las frases
     */
    const std::vector<Frase>& GetFrases() const;

	/**
	 *	@brief @e Getter de la @c Frase que corresponde a la frase hecha @c str dada
	 *
	 *	@param str @c std::string que representa una frase hecha
	 *	@return Devuelve el objeto @c Frase correspondiente
	 *	@pre Debe existir la frase en la colección
	 */
    Frase& GetTraducciones(const std::string& str);

	/**
	 *	@brief Devuelve un subconjunto de tipo @c ConjuntoFrases
	 *
	 *	@return Devuelve la cantidad de @a Frase que contiene el conjunto
	 */
	ConjuntoFrases Contenga(const std::string& sub_str = "") const;

	/**
	 *	@brief Sobrecarga del operador de flujo de salida
	 *
	 *	@return Flujo de salida modificado
	 */
	friend std::ostream& operator<<(std::ostream& os, const ConjuntoFrases& cf);

	/**
	 *	@brief Sobrecarga del operador de flujo de entrada
	 *
	 *	@return Flujo de entrada modificado
	 */
	friend std::istream& operator>>(std::istream& is, ConjuntoFrases& cf);
};

#endif