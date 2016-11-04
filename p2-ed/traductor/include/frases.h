/**
 *	@brief Fichero cabecera del TDA Frase
 *
 */

#ifndef __FRASES_H
#define __FRASES_H

#include <string>
#include <vector>

class Frase {
private:

	std::string origen; /*!< Frase hecha de referencia */

	std::vector<std::string> destino; /*!< Conjunto de traduciones */

public:

	/**
	 * @brief Constructor para un único valor
	 *
	 * @param origen Frase hecha de origen
	 * @param destino Traducción de la frase de origen
	 * @return Un objeto Frase con una única traducción
	 */
	Frase(const std::string origen, std::string destino) :
			origen(origen),
			destino(std::vector<std::string>(1, destino)) {}

	/**
	 * @brief Constructor con @em N valores
	 *
	 * @param origen Frase hecha de origen
	 * @param destino Traducciones de la frase de origen
	 * @return Un objeto Frase con @em N traducciones
	 */
	Frase(const std::string origen, std::vector<std::string> destino) :
			origen(origen),
			destino(destino) {}

	/**
	 *	@brief @e Getter de la frase hecha de origen
	 *
	 *	@return Frase hecha de origen
	 */
	const std::string& GetOrigen() const { return origen; }

    /**
     *	@brief @e Getter del conjunto de traducciones
     *
     *	@return Vector de frases de destino
     */
    const std::vector<std::string>& GetDestino() const { return destino; }

    /**
	 *	@brief @e Getter del conjunto de traducciones
	 *
	 *	@return Vector de frases de destino
	 */
    std::vector<std::string>& GetDestino() { return destino; }

	/**
	 * @brief Añade una frase de traducción adicional
	 *
	 * @param destino Frase hecha de traducción
	 */
	void AddDestino(const std::string& destino);

	/**
	 * @brief Devuelve la cantidad de traducciones que la Frase
	 *
	 * @return Número de traducciones para la frase de origen
	 */
	unsigned long Size() const { return destino.size(); }

	friend bool operator<(const Frase& lhs, const Frase& rhs);

	friend bool operator>(const Frase& lhs, const Frase& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Frase& lhs, const Frase& rhs) {
		return !(lhs < rhs);
	}

	friend bool operator<=(const Frase& lhs, const Frase& rhs) {
		return !(rhs < lhs);
	}
};

#endif
