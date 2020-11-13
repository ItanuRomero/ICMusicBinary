arq1 = open('./musicas/teste1.mid', 'rb')
arq2 = open('./musicas/teste2.mid', 'rb')
contador_iguais = 0
arquivo1 = list()
arquivo2 = list()
for leitura in range(0, 100):
    arquivo1.append(arq1.readline(1))
    arquivo2.append(arq2.readline(1))

for indice in range(0, 100):
    if arquivo1[indice] == arquivo2[indice]:
        contador_iguais += 1
print(arquivo1)
print(arquivo2)
