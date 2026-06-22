from typing import Sequence

def promedio_mayores_a_umbral(precios: Sequence[float], umbral: float) -> float:
    suma = 0.0
    cantidad = 0

    for precio in precios:
        if precio > umbral:
            suma += precio
            cantidad += 1

    return 0.0 if cantidad == 0 else suma / cantidad

# Ejemplo de uso
precios = [10, 20, 30, 40, 50]
promedio = promedio_mayores_a_umbral(precios, 25)

print(promedio)  # 40.0