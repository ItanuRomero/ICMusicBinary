# Shift de dados

Shift (do inglês mudança ou deslocamento) de dados é a ação que no contexto de nosso trabalho faz com que músicas com melodias parecidas e com padrões binários semelhantes acabem se perdendo por não permitir a análise do código de forma correta.

Para explicar usaremos um exemplo de notas musicais:
C - Dó
D - Ré
E - Mi
F - Fá
G - Sol
A - Lá
B - Si

Em uma certa melodia, colocamos o padrão:

**C - G - D - C - G - D - E.**

Se comparamos a melodia anterior com ela mesma, teremos uma similaridade de 100%. Dessa forma:

C - G - D - C - G - D - E.
| - | - | - | - | - | - |       (Estes riscos verticais simbolizam a comparação de uma nota com outra).
C - G - D - C - G - D - E.

Porém, se por algum acaso, o mesmo padrão em vez de terminar com Mi, começa com essa nota, como mostrado abaixo:

**E - C - G - D - C - G - D.**

Na hora de fazer uma análise utilizando o sistema de hamming, ele fará dessa forma:

C - G - D - C - G - D - E.
| - | - | - | - | - | - |
E - C - G - D - C - G - D.

O que nos retornaria uma similaridade de 0%, mesmo sendo visível o padrão *C - G - D - C - G - D* em ambas melodias, como o sistema é linear, ele não consegue perceber que existem esses padrões, pois apenas lê informações diretas, nota a nota, ou como é o caso, bit a bit.
