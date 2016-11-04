Práctica 2: Abstración
===

Alejandro Núñez Pérez
---

A continuación se especifican los dos tipos de dato abstractos que debían ofrecerse, debidamente descritos y definidos.

Frase
---

Una frase es un T.D.A. que representa una traducción entre dos idiomas, una frase en el idioma de origen y una frase (o varias) en el idioma de origen. Es decir, tiene un órden 1:N.

Las frases deben proveer la consulta tanto del origen como de los destinos, así como funcionalidad para añadir más destinos.

La representación elegida en esta práctica es aquella formada por una cadena de caracteres de la STD de C++ (`std::string`) y un vector dinámico de la STL de C++ que contiene el mismo tipo de cadenas ya mencionadas (`std::vector<std::string>`).

La invariante de esta representación es que una frase debe tener un origen y al menos un destino, y una construcción donde no haya origen o ningún destino es errónea.



ConjuntoFrases
---

Un conjunto de frases, como bien indica su nombre, es un T.D.A. que encapsula las ya mencionadas Frases.

Un conjunto de frases debe ofrecer métodos de acceso a las frases que contiene, así como proveer la inserción de nuevas frases, la selección de un subconjunto y también el fácil acceso de escritura y lectura en _bulk_.

La representación elegida consiste en un vector dinámico de la STL de C++ que contiene Frases (`std::vector<Frase>`).

No existe una invariante de este tipo de dato, ya que la colección puede estar vacía como infinitamente llena, siempre que se adapte al soporte físico.