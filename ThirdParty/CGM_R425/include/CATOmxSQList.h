#ifndef __CATOmxSQList_h__
#define __CATOmxSQList_h__
#include "CATOmxPortability.h"
#include "CATOmxMutex.h"
#include "CATOmxKernel.h"
/**
 * Interthread communication queue.
 */
class ExportedByCATOmxKernel CATOmxSQBaseList {
  typedef CATOmx::mutex MutexType;
  typedef CATOmx::unique_lock<MutexType> Guard;
  MutexType m;
  CATOmx::condition_variable available;
  CATOmx::condition_variable overflow;
 public:
  class BaseNode {
    friend class CATOmxSQBaseList;
    BaseNode *next;
  public:
    virtual ~BaseNode() {}
    inline BaseNode() : next(NULL) {}
    inline BaseNode *Next() { return next; }
  };
 private:
  BaseNode *head;
  BaseNode *tail;
  int size;
  CATOmxSQBaseList(const CATOmxSQBaseList &iFrom);
  CATOmxSQBaseList & operator =(const CATOmxSQBaseList &iFrom);
  HRESULT _PutMany(BaseNode *&ioFirst, BaseNode *&ioLast,int tsize);
  
public:
  CATOmxSQBaseList() : head(NULL), tail(NULL), size(0) {
  }
  ~CATOmxSQBaseList() {
    RemoveAll();
  }
  void RemoveAll();
  /** usefull to prevent deadlock related to a spurious wakeup. */
  void NotifyDataAvailable();
  /** usefull to prevent deadlock related to a spurious wakeup */
  void NotifyDataRequest();
  /** return true if empty. */
  inline int IsEmpty() const { return head == NULL; }
  /** indicate the number of enqueued items. */
  inline int Count() const { return size; }
protected:
  /** Move list content into another. */
  void _Move(CATOmxSQBaseList &iFrom) ;
  void _PutMany(CATOmxSQBaseList &iFrom); 

  /** put a whole list in one shot. */
  HRESULT _PutMany(BaseNode *&ioFirst, BaseNode *&ioLast);
  /** Get All list in one shot */
  void _GetAll(BaseNode *&oFirst, BaseNode*&oLast, int &oSize, int wait); 
  /** Get All list in one shot. Wait if empty. */
  BaseNode *_GetAll() ;
  /** Put in queue but eventually wate for drain */
  HRESULT _PutWait(BaseNode *n,int hiWater);
  /** return the first enqueued node. */
  BaseNode *_GetNoWait(int loWater);
  BaseNode *_Get(int loWater); 
  BaseNode *_GetWithTimeout(int loWater, const CATOmx::chrono::fake_ratio iTimeout);
};
template <typename Data,int Size=32, int hiWater=32, int loWater=hiWater/2> class CATOmxSQList : public CATOmxSQBaseList {
public:
  typedef CATOmxSQList<Data,Size> SelfType;
  class Node : public BaseNode {
  public:
    inline Node() : count(0) {}
    int count;
    Data data[Size];
  };
  
  /** Put one node at end of list */
  inline HRESULT Put(Node *n) { return _PutWait(n,hiWater); }
  /** Put in queue but eventually wait for drain */
  inline HRESULT PutWait(Node *n,int iHiWater) { return _PutWait(n,iHiWater); }
  /** Move list content into another. */
  inline void Move(SelfType &iFrom) { _Move(iFrom); }
  /** put a whole list in one shot. */
  inline void PutMany(SelfType &iFrom) { _PutMany(iFrom); }
  inline HRESULT PutMany(Node *&ioFirst, Node *&ioLast) { return _PutMany(reinterpret_cast<BaseNode*&>(ioFirst),reinterpret_cast<BaseNode*&>(ioLast)); }
  /** Get All list in one shot */
  inline void GetAll(Node *&oFirst, Node*&oLast, int &oSize, int wait=1) { _GetAll(reinterpret_cast<BaseNode*&>(oFirst),reinterpret_cast<BaseNode*&>(oLast),oSize,wait); } 
  /** Get All list in one shot. Wait if empty. */
  inline Node *GetAll() { return static_cast<Node*>(_GetAll()); }
  /** return the first enqueued node (may return null). */
  inline Node *GetNoWait() { return static_cast<Node*>(_GetNoWait(loWater)); }
  /** return the first enqueued node (never return null). */
  inline Node *Get() { return static_cast<Node*>(_Get(loWater)); }
  template <class Rep, CATOmx::chrono::fake_ratio Period> inline Node *GetWithTimeout(const CATOmx::chrono::duration<Rep,Period> & iTimeout= CATOmx::chrono::milliseconds(10)) {
     return static_cast<Node*>(_GetWithTimeout(loWater,iTimeout.ticks));
  }
};
#endif
