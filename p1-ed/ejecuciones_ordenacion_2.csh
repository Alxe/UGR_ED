#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio

echo > "t_ord_rand.dat"
echo > "t_ord_best.dat"
echo > "t_ord_worst.dat"
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./ord_rand $i $i` >> "t_ord_rand.dat"
  echo `./ord_best $i` >> "t_ord_best.dat"
  echo `./ord_worst $i` >> "t_ord_worst.dat"
  @ i += $incremento
end
