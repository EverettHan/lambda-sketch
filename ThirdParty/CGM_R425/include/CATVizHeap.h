#ifndef _CATVizHeap_
#define _CATVizHeap_

#include "CATVizAllocator.h"
#include "CATBoolean.h"
#include "SGInfra.h"

class ExportedBySGInfra CATVizBinaryNode
{
public:
   CATVizBinaryNode()
   {
      _key = NULL;
      _child[0] = NULL;
      _child[1] = NULL;
   }

   CATVizBinaryNode(void *iKey)
   {
      _key = iKey;
      _child[0] = NULL;
      _child[1] = NULL;
   }
/*
   void DestroyKey()
   {
      if(_key)
         delete _key;
      _key = NULL;
   }
*/
   void *_key;
   CATVizBinaryNode *_child[2];
   CATVizDeclarePagedNewOverride(CATVizBinaryNode);
};

template <class T>
class CATVizHeap
{
public:
   CATVizHeap( int (*compareFunc)(const T *elem1, const T *elem2) );
   ~CATVizHeap();

   // interface
   bool Insert(T *iKey);
   bool Remove(T *iKey);

   // browse tree
   CATVizBinaryNode* GetRoot();
   CATVizBinaryNode* GetChild(CATVizBinaryNode *iNode, bool lr);
   bool Lookup(T *iKey, CATVizBinaryNode *&iNode);

   // set tree
   void SetRoot(CATVizBinaryNode *iRoot);
   void SetChild(CATVizBinaryNode *iNode, bool lr, CATVizBinaryNode *iChildNode);

protected:
   void Clear();
   void Clear(CATVizBinaryNode *iNode);
   bool Lookup(T *iKey, CATVizBinaryNode *&iNode, CATVizBinaryNode *&iNodeParent, bool &iNumChild);

   T* DeleteInOrderSuccessor(CATVizBinaryNode *iNode);

   CATVizBinaryNode *_root;
   unsigned int _nbNodes;
   int (*_compareFunc)(const T *elem1, const T *elem2);
};







template <class T>
CATVizHeap<T>::CATVizHeap( int (*compareFunc)(const T *elem1, const T *elem2) )
{
   _compareFunc = compareFunc;
   _nbNodes = 0;
   _root = NULL;
}

template <class T>
CATVizHeap<T>::~CATVizHeap()
{
   Clear(_root);
   _root = NULL;
   _nbNodes = 0;
}

template <class T>
bool CATVizHeap<T>::Insert(T *iKey)
{
   CATVizBinaryNode *node = new CATVizBinaryNode();
   if( !node ) return false;
   node->_key = iKey;

   if( _root == NULL ){
      _root = node;
      ++_nbNodes;
      return true;
   }

   bool numChild = 0;
   CATVizBinaryNode *currNode = _root;
   CATVizBinaryNode *parentNode = NULL;

   if( Lookup(iKey, currNode, parentNode, numChild) ){
      delete node;
      return false; // iKey is already in the binary tree
   }

   parentNode->_child[numChild] = node;
   ++_nbNodes;

   return true;
}

template <class T>
bool CATVizHeap<T>::Remove(T *iKey)
{
   bool numChild = 0;
   CATVizBinaryNode *node = _root;
   CATVizBinaryNode *parentNode = NULL;

   if( !Lookup(iKey, node, parentNode, numChild) )
      return false;

   unsigned int nbChildren = ((NULL != node->_child[1]) << 1) + (NULL != node->_child[0]);

   switch(nbChildren){
      case 0: // no children
      case 1: // left child
      case 2: // right child
         if( node == _root )
            _root = node->_child[nbChildren > 1];
         else
            parentNode->_child[numChild] = node->_child[nbChildren > 1];
         //node->DestroyKey();
         delete (T*)node->_key;
         node->_key = NULL;
         delete node;
         break;
      case 3: // 2 children
         delete (T*)node->_key;
         node->_key = DeleteInOrderSuccessor(node);
         break;
      default:
         break;
   }

   --_nbNodes;
   return true;
}

template <class T>
CATVizBinaryNode* CATVizHeap<T>::GetRoot()
{
   return _root;
}

template <class T>
CATVizBinaryNode* CATVizHeap<T>::GetChild(CATVizBinaryNode *iNode, bool lr)
{
   if(!iNode) return NULL;
   return iNode->_child[lr];
}

template <class T>
bool CATVizHeap<T>::Lookup(T *iKey, CATVizBinaryNode *&iNode)
{
   bool numChild;
   CATVizBinaryNode *nodeParent;
   return Lookup(iKey, iNode, nodeParent, numChild);
}

template <class T>
void CATVizHeap<T>::SetRoot(CATVizBinaryNode *iRoot)
{
   _root = iRoot;
}

template <class T>
void CATVizHeap<T>::SetChild(CATVizBinaryNode *iNode, bool lr, CATVizBinaryNode *iChildNode)
{
   if(!iNode) return;
   iNode->_child[lr] = iChildNode;
}

template <class T>
void CATVizHeap<T>::Clear()
{
   Clear(_root);
   _root = NULL;
   _nbNodes = 0;
}

template <class T>
void CATVizHeap<T>::Clear(CATVizBinaryNode *iNode)
{
   if( iNode ){
      Clear(iNode->_child[0]);
      Clear(iNode->_child[1]);
      //iNode->DestroyKey();
      delete (T*)iNode->_key;
      iNode->_key = NULL;
      delete iNode;
   }
}

template <class T>
bool CATVizHeap<T>::Lookup(T *iKey, CATVizBinaryNode *&iNode, CATVizBinaryNode *&iNodeParent, bool &iNumChild)
{
   while( iNode != NULL ){
      int cmp = _compareFunc(iKey, (T*)iNode->_key);
      if( cmp == 0 )
         return true;
      iNumChild = (cmp > 0);
      iNodeParent = iNode;
      iNode = iNode->_child[iNumChild];
   }

   return false;
}

template <class T>
T* CATVizHeap<T>::DeleteInOrderSuccessor(CATVizBinaryNode *iNode)
{
   CATVizBinaryNode *prev = iNode;
   CATVizBinaryNode *curr = iNode->_child[1];

   if( curr->_child[0] == NULL ){
      prev->_child[1] = curr->_child[1];
      T *tmp = (T*)curr->_key;
      delete curr;
      return tmp;
   }

   while( curr->_child[0] != NULL ){
      prev = curr;
      curr = curr->_child[0];
   }

   prev->_child[0] = curr->_child[1];
   T *tmp = (T*)curr->_key;
   delete curr;
   return tmp;
}

#endif
