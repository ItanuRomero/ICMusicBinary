from math import trunc


def write_data(media_porcentagem, musica_1, musica_2):
    arquivo_escrita = open('result.txt', 'a')
    arquivo_escrita.write(f'\nA media entre as musicas\n'
                          f'{musica_1} e {musica_2} e de: {media_porcentagem:.3f}%\n')
    arquivo_escrita.close()


def percent_math(total, igual, diferente):
    resultado = total / 100
    porcentagem_iguais = igual / resultado
    porcentagem_diferentes = diferente / resultado
    return porcentagem_iguais, porcentagem_diferentes


def show_data(tempo, igual, diferente, total, porcentagem_iguais, porcentagem_diferentes):
    print(f'No {tempo} da musica temos:')
    print(f'{igual} dados iguais')
    print(f'{diferente} dados diferentes\n'
          f'Totalizando {total}\n'
          f'Porcentagem de semelhanca: {porcentagem_iguais:.2f}%\n'
          f'Logo, {porcentagem_diferentes:.2f}% de diferenca')
    print('-' * 15)


def analize(nome_arquivo_1, nome_arquivo_2):
    igual = diferente = total = 0
    for linha in nome_arquivo_1:
        for linha_2 in nome_arquivo_2:
            for char in linha:
                for char_2 in linha_2:
                    if char == char_2:
                        igual += 1
                    else:
                        diferente += 1
                    total +=1
    return igual, diferente, total


def add(nome_arquivo, inicio, meio, fim):
    for linha in range(0, len(nome_arquivo)):
        if linha < trunc(len(nome_arquivo) / 3):
            inicio.append(nome_arquivo[linha])
        elif linha < trunc((len(nome_arquivo) / 3) + (len(nome_arquivo) / 3)):
            meio.append(nome_arquivo[linha])
        else:
            fim.append(nome_arquivo[linha])


nome_1 = str(input('Insira o nome do primeiro arquivo: '))
nome_2 = str(input('Insira o nome do segundo arquivo: '))
arq1 = open(f'./musicas/{nome_1}.mid', 'rb')
arq2 = open(f'./musicas/{nome_2}.mid', 'rb')

total_porcentagens = media_porcentagens = 0

arquivo1 = list(arq1.readlines())
arquivo2 = list(arq2.readlines())

inicio_1 = list()
meio_1 = list()
fim_1 = list()

inicio_2 = list()
meio_2 = list()
fim_2 = list()

add(arquivo1, inicio_1, meio_1, fim_1)
add(arquivo2, inicio_2, meio_2, fim_2)

igual, diferente, total = analize(inicio_1, inicio_2)

porcentagem_iguais, porcentagem_diferentes = percent_math(total, igual, diferente)
total_porcentagens += porcentagem_iguais

show_data('inicio', igual, diferente, total, porcentagem_iguais, porcentagem_diferentes)

igual, diferente, total = analize(meio_1, meio_2)

porcentagem_iguais, porcentagem_diferentes = percent_math(total, igual, diferente)
total_porcentagens += porcentagem_iguais

show_data('meio', igual, diferente, total, porcentagem_iguais, porcentagem_diferentes)

igual, diferente, total = analize(fim_1, fim_2)

porcentagem_iguais, porcentagem_diferentes = percent_math(total, igual, diferente)
total_porcentagens += porcentagem_iguais

show_data('fim', igual, diferente, total, porcentagem_iguais, porcentagem_diferentes)

media_porcentagens = total_porcentagens / 3

print(f'A media de dados iguais e de: {media_porcentagens:.2f}%')

write_data(media_porcentagens, nome_1, nome_2)

arq1.close()
arq2.close()
