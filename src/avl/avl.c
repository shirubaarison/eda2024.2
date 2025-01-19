#include <stdio.h>
#include <stdlib.h>

#include "../../include/avl.h"

// esq
void caso1(No **pt, int *h)
{
  No *ptu = (*pt)->esq;

  // simples
  if (ptu->bal == -1) {
    (*pt)->esq = ptu->dir;
    ptu->dir = *pt;
    *pt = ptu;
    (*pt)->dir->bal = 0;
  } else {
    // duplo
    No *ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    (*pt)->esq = ptv->dir;
    ptv->dir = *pt;

    switch (ptv->bal) {
      case 1:
        (*pt)->bal = 0;
        ptu->bal = -1;
        break;
      case 0:
        (*pt)->bal = 0;
        ptu->bal = 0;
        break;
      case -1:
        (*pt)->bal = 1;
        ptu->bal = 0;
        break;
      }
    *pt = ptv;
  }

  (*pt)->bal = 0;
  *h = F;
}

//analogo ao caso1 so que pra direita
void caso2(No **pt, int *h)
{
  No *ptu = (*pt)->dir;

  if (ptu->bal == 1) {
    (*pt)->dir = ptu->esq;
    ptu->esq = *pt;
    *pt = ptu;
    (*pt)->esq->bal = 0;
  } else {
    No *ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    (*pt)->dir = ptv->esq;
    ptv->esq = *pt;

    switch (ptv->bal) {
      case 1:
        (*pt)->bal = -1;
        ptu->bal = 0;
        break;
      case 0:
        (*pt)->bal = 0;
        ptu->bal = 0;
        break;
      case -1:
        (*pt)->bal = 0;
        ptu->bal = 1;
        break;
      }

    *pt = ptv;
  }

  (*pt)->bal = 0;
  *h = F;
}

void iniciarNo(No **pt, int chave)
{
  *pt = malloc(sizeof(No));

  if (pt == NULL) {
    printf("Erro ao iniciar nó\n");
    exit(EXIT_FAILURE);
  }

  (*pt)->chave = chave;
  (*pt)->bal = 0;
  (*pt)->esq = (*pt)->dir = NULL;;
}

void ins_AVL(int chave, No **pt, int *h)
{
  if (*pt == NULL) {
    iniciarNo(pt, chave);
    *h = V;
  } else {
    if (chave == (*pt)->chave) {
      *h = F;
    }
    else if (chave < (*pt)->chave) {
      ins_AVL(chave, &(*pt)->esq, h);

      if (*h == V) {
        switch ((*pt)->bal) {
          case 1:
            (*pt)->bal = 0;
            *h = F;
            break;

          case 0:
            (*pt)->bal = -1;
            break;

          case -1:
            caso1(pt, h);
            break;
          }
      }
    }
    else {
      ins_AVL(chave, &(*pt)->dir, h);

      if (*h == V) {
        switch ((*pt)->bal) {
          case -1:
            (*pt)->bal = 0;
            *h = F;
            break;
          case 0:
            (*pt)->bal = 1;
            break;
          case 1:
            caso2(pt, h);
            break;
          }
      }
    }
  }
}

void Caso1R(No **pt, int *h)
{
  No *ptu = (*pt)->esq;

  if (ptu->bal <= 0) {
    (*pt)->esq = ptu->dir;
    ptu->dir = *pt;
    *pt = ptu;

    if (ptu->bal == -1) {
      ptu->bal = 0;
      (*pt)->dir->bal = 0;
      *h = V;
    } else {
      ptu->bal = 1;
      (*pt)->dir->bal = -1;
      *h = F;
    }
  } else {
    No *ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    (*pt)->esq = ptv->dir;
    ptv->dir = *pt;
    *pt = ptv;

    switch (ptv->bal) {
      case 1:
        ptu->bal = -1;
        (*pt)->dir->bal = 0;
        break;
      case 0:
        ptu->bal = 0;
        (*pt)->dir->bal = 0;
        break;
      case -1:
        ptu->bal = 0;
        (*pt)->dir->bal = 1;
        break;
      }

    (*pt)->bal = 0;
    *h = V;
  }
}

void CasoR2(No **pt, int *h)
{
  No *ptu = (*pt)->dir;

  if (ptu->bal >= 0) {
    (*pt)->dir = ptu->esq;
    ptu->esq = *pt;
    *pt = ptu;

    if (ptu->bal == 1) {
      ptu->bal = 0;
      (*pt)->esq->bal = 0;
      *h = V;
    }
    else {
      ptu->bal = -1;
      (*pt)->esq->bal = 1;
      *h = F;
    }
  } else {
    No *ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    (*pt)->dir = ptv->esq;
    ptv->esq = *pt;
    *pt = ptv;

    switch (ptv->bal) {
      case 1:
        ptu->bal = 0;
        (*pt)->esq->bal = -1;
        break;
      case 0:
        ptu->bal = 0;
        (*pt)->esq->bal = 0;
        break;
      case -1:
        ptu->bal = 1;
        (*pt)->esq->bal = 0;
        break;
      }

    (*pt)->bal = 0;
    *h = V;
  }
}

void balancear(No **pt, char R, int *h) {
  if (*h == V) {
    if (R == 'D') {
      switch ((*pt)->bal) {
        case 1:
          (*pt)->bal = 0;
          break;
        case 0:
          (*pt)->bal = -1;
          *h = F;
          break;
        case -1:
          Caso1R(pt, h);
          break;
        }
    } else {
      switch ((*pt)->bal) {
        case -1:
          (*pt)->bal = 0;
          break;
        case 0:
          (*pt)->bal = 1;
          *h = F;
          break;
        case 1:
          CasoR2(pt, h);
          break;
        }
    }
  }
}

void trocar(No **pt, No **pt2) {
  No *pt_aux = *pt2;
  *pt2 = *pt;
  *pt = pt_aux;

  No *esq_aux = (*pt2)->esq;
  No *dir_aux = (*pt2)->dir;
  int bal_aux = (*pt2)->bal;

  (*pt2)->esq = (*pt)->esq;
  (*pt2)->dir = (*pt)->dir;
  (*pt2)->bal = (*pt)->bal;

  (*pt)->esq = esq_aux;
  (*pt)->dir = dir_aux;
  (*pt)->bal = bal_aux;
}

void remover_avl(int chave, No **pt, int *h) {
  if (*pt == NULL) {
    *h = F;
  }
  else {
    if (chave < (*pt)->chave) {
      remover_avl(chave, &(*pt)->esq, h);
      balancear(pt, 'E', h);
    } else {
      if (chave > (*pt)->chave) {
        remover_avl(chave, &(*pt)->dir, h);
        balancear(pt, 'D', h);
      } else {
        No *aux = *pt;

        if ((*pt)->esq == NULL) {
          *pt = (*pt)->dir;
          *h = V;

          free(aux);
        } else {
          if ((*pt)->dir == NULL) {
            *pt = (*pt)->esq;
            *h = V;

            free(aux);
          } else {
            No *s = (*pt)->dir;

            if (s->esq == NULL) {
              s->esq = (*pt)->esq;
              s->bal = (*pt)->bal;
              *pt = s;
              *h = V;

              free(aux);
            } else {
              No *PaiS;

              while (s->esq != NULL) {
                PaiS = s;
                s = s->esq;
              }

              trocar(pt, &PaiS->esq);
              remover_avl(chave, &(*pt)->dir, h);
            }

            balancear(pt, 'D', h);
          }
        }
      }
    }
  }
}

int altura(No *pt)
{
  if (pt == NULL)
    return 0;
  else {
    int esq = altura(pt->esq);
    int dir = altura(pt->dir);

    if (esq >= dir) 
      return esq + 1;
    else 
      return dir + 1;
  }
}

int eh_avl(No *pt)
{
  if (pt == NULL) {
    return V;
  }
  else {
    int bal = altura(pt->dir) - altura(pt->esq);

    if (bal < -1 || bal > 1 || pt->bal != bal) {
      return F;
    } else {
      int esq = eh_avl(pt->esq);
      int dir = eh_avl(pt->dir);

      if (esq == F || dir == F) {
        return F;
      } else {
        return V;
      }
    }
  }
}

int qtd_nos(No *pt)
{
  if (pt == NULL)
    return 0;
  else
    return 1 + qtd_nos(pt->esq) + qtd_nos(pt->dir);
}