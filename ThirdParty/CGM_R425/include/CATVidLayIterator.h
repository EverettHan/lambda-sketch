#ifndef CATVidLayIterator_H
#define CATVidLayIterator_H

// COPYRIGHT Dassault Systemes 2009

// VisuImmersiveDialog framework
#include <VisuDialog.h>

// System framework
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_WR.h>
#include <CATBoolean.h>

class CATSysWeakRef;
class CATVidLayCollection;
class CATVidCtlCollection;
class CATVidWidget;

/**
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayIterator: public CATBaseUnknown
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  CATVidLayIterator(const CATVidLayCollection& i_collection);
  CATVidLayIterator(const CATVidCtlCollection& i_ctlCollection);
  
  virtual ~CATVidLayIterator();

  void Start();
  void End();
  CATVidWidget* GetAndIterate();
  CATVidWidget* operator++();
  void SetReverseFlag(CATBoolean i_reverseFlag);

  virtual CATVidWidget* GetAt(int i_index);

protected:

  CATVidLayCollection * GetCollection() const;

  CATVidCtlCollection * GetCtlCollection() const;

private:

  // Copy constructor and equal operator
  CATVidLayIterator (const CATVidLayIterator &);
  CATVidLayIterator& operator=(const CATVidLayIterator&);

private:

  CATBaseUnknown_WR _collectionWR;
  int _index;
  CATBoolean _reverseFlag;
};

#endif
