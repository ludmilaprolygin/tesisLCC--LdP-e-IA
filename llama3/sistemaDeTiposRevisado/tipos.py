def calcular_promedio_mayores_umbral(arr, umbral):
    suma = 0
    cuenta = 0
    for elemento in arr:
        if isinstance(elemento, (int, float)):
            valor = float(elemento)
        elif isinstance(elemento, str):
            try:
                valor = float(elemento)
            except ValueError:
                continue
        else:
            raise TypeError(f"Tipo de dato no válido: {type(elemento)}")

        if valor > umbral:
            suma += valor
            cuenta += 1

    if cuenta == 0:
        return None
    else:
        return suma / cuenta

arr = [1, 2, "30", 40, 50.0]
umbral = 25
print(calcular_promedio_mayores_umbral(arr, umbral))