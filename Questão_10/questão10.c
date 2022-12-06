/* 
Questão 10.
Considere a implementação de listas encadeadas utilizando apontadores vista em
sala. Escreva um procedimento Troca(TipoLista* pLista, TipoCelula* p) que, dado um
apontador para uma célula qualquer (p), troca de posição essa célula com a sua célula
seguinte da lista, como mostrado na figura abaixo. (Obs. Não vale trocar apenas o
campo item! Você deverá fazer a manipulação dos apontadores para trocar as duas
células de posição). Não esqueça de tratar os casos especiais.
*/
void
Troca (TipoLista * L, Apondador * P) 
{
struct no *ante;
  
struct no *prox = P->prox;
if (prox == NULL)
    {
      return;
    }
  
ante = L->cabeca;
  
while (ante->prox != P)
    {
      
ante = ante->prox;
    
}
  
ante->prox = prox;
  
P->prox = prox->prox;
  
prox->prox = P;
  
if (L->ultimo == prox)
    {
      L->ultimo = ante;
    }

}


