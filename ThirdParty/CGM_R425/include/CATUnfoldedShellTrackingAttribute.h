#ifndef UnfoldedShellTrackingAttribute_H
#define UnfoldedShellTrackingAttribute_H
/*
=============================================================================
 COPYRIGHT   : DASSAULT SYSTEMES 2020
=============================================================================
*/
#include "CATCGMStreamAttribute.h"
#include "CATGMOperatorsInterfaces.h"
#include "FrFTopologicalOpe.h" // exported by

class CATExtClonableManager;
class CATICGMObject;

class ExportedByFrFTopologicalOpe CATUnfoldedShellTrackingAttribute
  : public CATCGMStreamAttribute
{
public:
  CATCGMDeclareAttribute(CATUnfoldedShellTrackingAttribute,
    CATCGMStreamAttribute);

  CATUnfoldedShellTrackingAttribute();
  virtual ~CATUnfoldedShellTrackingAttribute();

  virtual void Stream(CATCGMStream &ioStream) const;
  virtual void UnStream(CATCGMStream &ioStr);

  CATLONG32 GetUnfoldedShellTag() const;
  void SetUnfoldedShellTag(CATLONG32 iUnfoldedShellTag);

protected:
  CATLONG32 _UnfoldedShellTag;
};

ExportedByFrFTopologicalOpe CATUnfoldedShellTrackingAttribute *
CATCreateUnfoldedShellTrackingAttribute();

#endif // UnfoldedShellTrackingAttribute_H


