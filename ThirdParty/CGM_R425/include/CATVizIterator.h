#ifndef CATVizIterator_H
#define CATVizIterator_H

#include "CATVizIterators.h"

#include "CATVizBaseIUnknown.h"
#include "CATVizMacForMetaClass.h"

class CATVizIteratorVisitor;

typedef void * CATVizListIterator; 

// Root class for all iterators interfaces
class ExportedByCATVisFoundationIterators CATVizIterator : public CATVizBaseIUnknown
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizIterator);

public:

   // AddRef/Release Mechanism handled by CATVizBaseIUnknown
   // GetRefCount added here
   inline ULONG GetRefCount();

   // Visitor pattern
   virtual void Accept(CATVizIteratorVisitor & iVisitor, void * iReservedData);

   // Retrieves the unique ID of the underlying node
   virtual unsigned int GetID() const;

protected:

   CATVizIterator();
   virtual ~CATVizIterator();
};

inline ULONG CATVizIterator::GetRefCount()
{
   return m_cRef;
}

#endif
