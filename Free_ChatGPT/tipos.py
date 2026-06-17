def precio_final(precio, descuento):
    descuento = float(descuento)  # convierte la cadena a número
    return precio * (1 - descuento / 100)

# Llamada de ejemplo
resultado = precio_final(50, "10")
print(resultado)