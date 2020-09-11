# Sistema de recomendação de músicas a partir de seu código binário

1. **QUAL TIPO DE ARQUIVO USAR**
Será utilizado um arquivo .mp3 do banco de músicas disponível, porém o mesmo será transformado em .wav por conta da forma que é disposto os dados, segue:
Um arquivo comprimido como o mp3 tende a perder informações, assim como também pode ser escrito de outra forma, sem seguir uma linha de informações direta.
Como nosso objetivo é verificar o código binário da música, é importante termos o arquivo mais limpo possível, que no caso significa que precisamos de um arquivo o mais próximo do PCM (Pulse code modulation) que conseguirmos, o que nos leva ao WAV.

2. **COMO SERÁ FEITO**
A partir de um programa em C, faremos a leitura de um arquivo e criaremos uma assinatura digital única, a qual pode ser utilizada para verificar similaridade com outra música.
Porém antes disso, temos que comprovar que existe semelhança tanto no que ouvimos quando no low code do arquivo, o que nos leva aos seguintes passos.

* Temos um programa para verificar conjuntos de bits em comum em determinadas músicas.

O grande problema é que em cada segundo de música, em média temos cerca de 128Kb, ou seja, a cada segundo temos que ler essa diversidade de código, então teremos que tratar de conjuntos grandes de bits para poder fazê-lo de forma acessível para nossas possibilidades técnicas.
