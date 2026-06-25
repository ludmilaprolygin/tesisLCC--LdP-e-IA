def promedio_mayores(precios, umbral):
    suma = 0.0
    cantidad = 0

    umbral = float(umbral)

    for precio in precios:
        valor = float(precio)

        if valor > umbral:
            suma += valor
            cantidad += 1

    return 0 if cantidad == 0 else suma / cantidad


# Ejemplos de uso
print(promedio_mayores([10, 20, "30", 40.0, 50], 25))          