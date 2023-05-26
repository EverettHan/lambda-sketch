#ifndef _CATVizPtrHeap_
#define _CATVizPtrHeap_

#include "SGInfra.h"

class CATVizPtrHeapNode
{
public:
  void *ptr;
  void *value;
  CATVizPtrHeapNode *lowerNode;
  CATVizPtrHeapNode *higherNode;
};

class ExportedBySGInfra CATVizPtrHeap
{
public:
  CATVizPtrHeap();
  ~CATVizPtrHeap();

  bool Add(void *ptr, void *value);
  void *Remove( void *ptr);
  bool Find(void *ptr, void ** & data);
  void *RemoveLowest();
  void *RemoveHighest();
  
private:

  bool Add(void *ptr, void *value, CATVizPtrHeapNode& node);
  bool Find(void *ptr, CATVizPtrHeapNode& from, void ** & data);
  void *Remove( void *ptr, CATVizPtrHeapNode **node);


  CATVizPtrHeapNode *_root;
};

#endif
