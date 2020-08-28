'''
Ainda em construcao...
'''
def abre_e_mostra_arquivo():
    string_binaria_arquivo = list()
    arquivo = open('/home/itanu/Área de Trabalho/teste.txt', 'rb')
    for line in arquivo:
        for letra in line:
            print(bin(letra), end=' ')
            string_binaria_arquivo.append(bin(letra))
    arquivo.close()
abre_e_mostra_arquivo()
