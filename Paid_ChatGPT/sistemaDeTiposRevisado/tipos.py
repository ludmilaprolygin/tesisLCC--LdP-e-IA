def promedio_mayores_a_umbral(arreglo, umbral):
    suma = 0.0
    cantidad = 0

    umbral_num = float(umbral)

    for elemento in arreglo:
        valor = float(elemento)

        if valor > umbral_num:
            suma += valor
            cantidad += 1

    if cantidad == 0:
        return 0

    return suma / cantidad