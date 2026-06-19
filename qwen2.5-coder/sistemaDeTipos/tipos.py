def calcular_promedio_mayores_a_umbral(precios, umbral):
    # Filtrar los precios mayores al umbral
    precios_filtrados = [precio for precio in precios if precio > umbral]
    
    # Calcular el promedio si hay elementos filtrados, de lo contrario retornar 0
    promedio = sum(precios_filtrados) / len(precios_filtrados) if precios_filtrados else 0
    
    return promedio

# Ejemplo de uso
precios = [10, 20, 30, 40, 50]
promedio = calcular_promedio_mayores_a_umbral(precios, 25)

print(promedio)  # 40.0