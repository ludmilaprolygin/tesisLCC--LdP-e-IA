def calcular_precio_final(precio_original, descuento):
    # Convertimos el descuento a un número flotante
    descuento = float(descuento)
    
    # Calculamos el monto del descuento
    monto_descuento = (descuento / 100) * precio_original
    
    # Restamos el monto del descuento al precio original para obtener el precio final
    precio_final = precio_original - monto_descuento
    
    return precio_final

# Llamada a la función con un precio de 50 y un descuento del "10%"
precio = 50
descuento = "10"
precio_final = calcular_precio_final(precio, descuento)

print(f"El precio final es: {precio_final}")