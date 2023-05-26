//===================================================================
// COPYRIGHT Dassault Systemes 2017/12/04
//===================================================================
// CATOmyGanttDiagramEntry.cpp
// Header definition of class CATOmyGanttDiagramEntry
//===================================================================
//
// Usage notes:
// This is a line of the diagram
//
//===================================================================
//  2017/12/04 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmyGanttDiagramEntry_H
#define CATOmyGanttDiagramEntry_H

#include "CATOmyGanttDiagram.h"
#include "CATOmxSharable.h"
#include "CATUnicodeString.h"
#include "CATOmxCollecManager.h"

class ExportedByCATOmyGanttDiagram CATOmyGanttDiagramEntry : public CATOmxSharable
{
public:
  CATOmyGanttDiagramEntry(const CATUnicodeString& iName, const CATUnicodeString& iType, CATLONG64 iStartValue, CATLONG64 iEndValue, const CATUnicodeString& iRepresentationChar);
  virtual ~CATOmyGanttDiagramEntry ();

  CATUnicodeString GetName();
  CATUnicodeString GetType();
  CATLONG64 GetStartValue();
  CATLONG64 GetEndValue();
  CATUnicodeString GetRepresentationChar();

private:
  CATOmyGanttDiagramEntry(CATOmyGanttDiagramEntry &);
  CATOmyGanttDiagramEntry& operator=(CATOmyGanttDiagramEntry&);

  CATUnicodeString _Name;
  CATUnicodeString _Type;
  CATUnicodeString _RepresentationChar;

  CATLONG64 _StartValue;
  CATLONG64 _EndValue;
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmyGanttDiagramEntry*>::manager();

#endif
