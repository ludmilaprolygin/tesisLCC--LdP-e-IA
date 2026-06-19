def promedio_sobre_umbral(precios, umbral):
    # Comenzamos con un valor inicial de 0
    total = 0
    count = 0
    
    # Iteramos sobre la lista original sin modificarla
    for precio in precios[:]:
        if precio > umbral:
            # Aumentamos el total y el conteo si el precio es mayor al umbral
            total += precio
            count += 1
    
    # Si no hay elementos que superen el umbral, devolvemos 0
    if count == 0:
        return 0
    
    # Calculamos el promedio y lo devolvemos
    return total / count

# Ejemplo de uso
precios = [10, 20, 30, 40, 50]
promedio = promedio_sobre_umbral(precios, 25)

print(promedio)  # 40.0