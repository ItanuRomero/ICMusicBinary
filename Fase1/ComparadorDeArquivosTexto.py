texto = open('/home/itanu/Área de Trabalho/com_imp.txt', 'r')
texto_copia = open('/home/itanu/Área de Trabalho/teste.txt', 'r')
contador_iguais = total = 0
texto_1 = texto.read()
texto_2 = texto_copia.read()
for indice in range(0, 100):
    if texto_1[indice] == texto_2[indice]:
        contador_iguais += 1
    total += 1
print(f'Em uma amostra com {total} caracteres\n'
      f'Possui um total de {contador_iguais} caracteres iguais')
texto.close()
texto_copia.close()
