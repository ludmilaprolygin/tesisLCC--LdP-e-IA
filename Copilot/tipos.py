def precio_final(precio, descuento_texto):
	descuento = float(descuento_texto)
	return precio - (precio * descuento / 100)


if __name__ == "__main__":
	precio_final_resultado = precio_final(50, "10")
	print(precio_final_resultado)
