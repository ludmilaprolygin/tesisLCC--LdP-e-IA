def calcular_promedio_mayores_a_umbral(arreglo, umbral):
    # Convertir todos los elementos a floats para realizar la comparación y el cálculo
    numeros = [float(elemento) for elemento in arreglo if isinstance(elemento, (int, float))]
    
    # Filtrar los valores mayores al umbral
    valores_mayores = [numero for numero in numeros if numero > umbral]
    
    # Calcular el promedio si hay valores mayores al umbral
    if len(valores_mayores) > 0:
        promedio = sum(valores_mayores) / len(valores_mayores)
        return promedio
    else:
        return None

# Ejemplo de uso
arreglo = [1, '2', 30.0, '40', 'cinco', 50]
umbral = 25
promedio = calcular_promedio_mayores_a_umbral(arreglo, umbral)
print("Promedio:", promedio) 