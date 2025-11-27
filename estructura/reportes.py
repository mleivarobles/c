"""
3.- Finalmente debes leer el archivo desde python y mostrar los siguientes resultados por pantalla
    * Promedio General
    * Promedio más alto
    * Promedio más bajo
"""

import csv
col_promedio = []

with open("listado.txt", newline='', encoding="utf-8") as f:
    lector = csv.reader(f, delimiter="\t")
    next(lector) #me salto el encabezado
    for fila in lector:
        if fila:
            prom = float(fila[-1])  
            col_promedio.append(prom)

print(f"Columna Promedio: {col_promedio}")

min_pro = min(col_promedio)
max_pro = max(col_promedio)
promedio = sum(col_promedio) / len(col_promedio)


print(f"Promedio general: {promedio:.2f}")
print(f"Proemdio más alto: {max_pro}")
print(f"Promedio más bajo: {min_pro}")
