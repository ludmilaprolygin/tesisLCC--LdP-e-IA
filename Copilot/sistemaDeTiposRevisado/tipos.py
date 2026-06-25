from typing import Sequence

def promedio_mayores_a_umbral(valores: Sequence[int | float | str], umbral: float) -> float:
    suma = 0.0
    cantidad = 0

    for valor in valores:
        numero = float(valor)
        if numero > umbral:
            suma += numero
            cantidad += 1

    return 0.0 if cantidad == 0 else suma / cantidad

print(promedio_mayores_a_umbral([1, '2', 30.0, "40", 50], 25))      