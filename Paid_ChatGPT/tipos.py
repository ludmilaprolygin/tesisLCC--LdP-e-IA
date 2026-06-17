def calcular_precio_final(precio, descuento):
    return precio * (1.0 - descuento / 100)

precio_final = calcular_precio_final(50, float("10"))

print(f"Precio final: {precio_final}")