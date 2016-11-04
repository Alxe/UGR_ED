#!/bin/csh
@ inicio = 100000
@ fin = 30000000
@ incremento = 500000
set ejecutable = bsearch
set salida = t_bsearch.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
