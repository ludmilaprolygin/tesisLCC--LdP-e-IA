def calcular_precio_final(precio, descuento):
    # Convertimos el descuento a un porcentaje
    descuento_porcentual = int(descuento[:-1])  # Sacamos el número sin el "%"

    # Calculamos el precio final aplicando el descuento
    precio_final = precio - (precio * (descuento_porcentual / 100))

    return precio_final

# Llamada a la función con precio inicial de 50 y descuento de "10%"
precio_inicial = 50
descuento = "10%"
precio_final = calcular_precio_final(precio_inicial, descuento)

print(f"El precio final es: {precio_final:.2f}")