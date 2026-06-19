def promedio_mayores_que(precios, umbral):
    suma = 0
    cantidad = 0

    for precio in precios:
        if precio > umbral:
            suma += precio
            cantidad += 1

    return suma / cantidad if cantidad > 0 else 0

# Ejemplo de uso
precios = [10, 20, 30, 40, 50]
promedio = promedio_mayores_que(precios, 25)

print(promedio)  # 40.0