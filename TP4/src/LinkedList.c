#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc (sizeof(LinkedList));
    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}
/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* retorno = NULL;
	int i;
	if(this !=NULL && nodeIndex >=0 && nodeIndex < ll_len(this)){
		retorno = (Node*) malloc(sizeof(Node));
			retorno = this->pFirstNode; //nodo 1
			for(i = 0; i < nodeIndex; i++){
				if(i  == nodeIndex){
					break;
				}
				else{
					retorno = retorno->pNextNode;
				}
			}
	}

    return retorno;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this)){
    	  Node* nuevoNodo = (Node*) malloc(sizeof(Node));
    	  if(nuevoNodo != NULL){
    		  if(nodeIndex == 0){//Si es el primer elemento
    			  nuevoNodo->pNextNode  = this->pFirstNode;
    			  this->pFirstNode = nuevoNodo;
    		  }
    		  else{//Si lo agrego entre elementos
    			  Node* nodoAux  = getNode(this, nodeIndex-1);
    			  nuevoNodo->pNextNode = nodoAux->pNextNode;
    			  nodoAux->pNextNode = nuevoNodo;
    		  }
    		  nuevoNodo->pElement = pElement;
    		  this->size++;
    		  returnAux = 0;
    	  }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	//corregir con el addNode
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && len >= 0){
        Node* nuevoNodo = (Node*) malloc(sizeof(Node));
    	if(len == 0){ //si es el primer elemento
    		this->pFirstNode = nuevoNodo;
    	}
    	else{//para elementos mayores al primero
    		Node* ultimoNodo;
    		ultimoNodo = getNode(this, len-1);
    		ultimoNodo->pNextNode = nuevoNodo;
    		nuevoNodo->pNextNode = NULL;

    	}
    	nuevoNodo->pElement = pElement;
		this->size++;//incremento la longitud de la linkedList
		returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	Node* nodoBuscado = getNode(this, index);
    	if(nodoBuscado != NULL){ //Si el nodo buscado es distinto es distinto de null, retorno el valor
    		returnAux = nodoBuscado->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this !=NULL && index >=0 && index < ll_len(this)){
    	Node* nodoBuscado = getNode(this, index);
    	if(nodoBuscado != NULL){
    		nodoBuscado->pElement = pElement; //seteo el elemento en el nodo
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	Node* nodoBuscado = getNode(this, index);
    	if(nodoBuscado != NULL){
    		if(index == 0){ //si es el primer elemento
    			this->pFirstNode = getNode(this,index+1);
    		}
    		else{
        		Node* nodoAnterior = getNode(this, index-1);
        		nodoAnterior->pNextNode = nodoBuscado->pNextNode;
    		}
    		this->size--;
    		returnAux = 0;
    		free(nodoBuscado);
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	//funcion corregida 21-06-22
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL){
     for(int i = len-1; i>= 0; i--){
    	 ll_remove(this,i);
     }
     returnAux =0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	//funcion corregida 21-06-22
    int returnAux = -1;
    if(this != NULL){
    	if(ll_clear(this)== 0){
        	free(this);
        	returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{

    int returnAux = -1;
    int i;
    if(this != NULL){
    	int len = ll_len(this);
    	void* pBuscado;
    	for(i = 0; i < len; i++){
    		pBuscado=ll_get(this,i);
    		if(pBuscado == pElement){// busco el elemento y si son iguales, return 0
    			returnAux = i;
    			break;
    		}
    	}

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	if(this->pFirstNode == NULL){
    		returnAux = 1;
    	}
    	else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){
    	int len = ll_len(this);
    	if(index >= 0 && index <= len){
    		if(addNode(this, index,pElement) == 0){
    			returnAux = 0;
    		}
    }

}
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL){ //Verifica que la lista no sea nula
    	int len = ll_len(this);
    	if(index >= 0 && index <len){
    		Node* nodoBuscado = getNode(this, index); //cambiar por get solo

    		if(nodoBuscado->pElement != NULL){
    			ll_remove(this,index); //remuevo el nodo, aqui returnAux (corregido)
    			returnAux = nodoBuscado->pElement;
    		}
    	}

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	//corregido el 23-06-22
    int returnAux = -1;
    if(this != NULL){
    	returnAux = 0;
        	if(ll_indexOf(this,pElement) !=-1 ){
        		returnAux = 1;
        	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	//funcion corregida el 21-06-22
    int returnAux = -1;
    if(this != NULL && this2 != NULL){
    		int len2 = ll_len(this2);
    		void* pElement;
			returnAux = 1;
    			for(int i = 0; i < len2; i++){
    				pElement = ll_get(this2,i);
    					if(ll_contains(this,pElement) == 0){
    						returnAux = 0;
    						break;
    					}
    			}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    //compruebo las condiciones para los parametros
    if(this !=NULL && from >= 0 && from < to && to <= ll_len(this)){
    		LinkedList* cloneArray2 = ll_newLinkedList();
    		for(int i = from; i<to; i++){
    			ll_add(cloneArray2, ll_get(this,i));
    		}
    		cloneArray = ll_newLinkedList();
    		//verifico que la sublista no sea nula y que los elementos de la lista principal estn contenidos
    		if(cloneArray != NULL && ll_containsAll(this,cloneArray2)== 1){
    			cloneArray = cloneArray2;
    		}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	//funcion corregida el 21-06-22
    LinkedList* cloneArray = NULL;

    if(this != NULL){ //compruebo que la lista no sea nula
    	cloneArray = ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int criterio;
    if(this !=NULL && pFunc != NULL && (order == 0 || order == 1)){
    	void* pElement1 = NULL;
    	void* pElement2 = NULL;
    	int len = ll_len(this);
    	//itero la lista y ordeno segun el order pasado por parametros
    	for(int i = 0; i< len-1;i++){
    		for(int j = i+1; j < len; j++){
    			pElement1 = ll_get(this,i);
    			pElement2 = ll_get(this,j);
    			if(pElement1 != NULL && pElement2 != NULL){
    			switch(order){
    			case 0: //orden descendente
        		criterio = pFunc(pElement1,pElement2); //retorna 1 si pEle1 es mayor que pEle2, -1 viceversa, 0 son iguales
        		if(criterio == -1){ //cambio el orden solo si pElem1 < pElem2
        		ll_set(this,i,pElement2);
        		ll_set(this,j,pElement1);
        		}
        		break;

    			case 1: //orden ascendente
        		criterio = pFunc(pElement1,pElement2); //retorna 1 si pEle1 es mayor que pEle2, -1 viceversa, 0 son iguales
        		if(criterio == 1){ //cambio el orden solo si pElem1 > pElem2
        		ll_set(this,i,pElement2);
        		ll_set(this,j,pElement1);
        		}
        		break;

    			}
    			}
    			returnAux =0;
    	}
    	}
    }
    return returnAux;

}

