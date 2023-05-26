// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <IntroInfra.h>
#include <CATSYPVisitorActorAdapter.h>

class CATSYPVisitor;
class CATBaseUnknown_var;
class CATSYPMetaClass;
class CATISYPPresenter_var;
class CATISYPCollection_var;
class CATUnicodeString;

/**
 * Adapter for CATISYPVisitorActor implementation dedicated to introspectable objects.
 * They have to implement CATISYPIntrospectable interface at least. If they have children,
 * they are suppose to implement CATISYPCollection or CATISYPPresenter.
 * 
 * If your component is not one of the CID team components, you can use this adapter that provides 
 * a generic implementation using interface described above.
 * 
 * If not, you just to create an extension inheriting from this adapter.
 *
 * @see CATISYPVisitorActor
 */
class ExportedByIntroInfra CATSYPObjectVisitorActorAdapter : public CATSYPVisitorActorAdapter
{
public:
  CATSYPObjectVisitorActorAdapter();
  virtual ~CATSYPObjectVisitorActorAdapter();

protected:
  virtual int AcceptContent(CATSYPVisitor &iVisitor) override;

private:
  CATSYPObjectVisitorActorAdapter(const CATSYPObjectVisitorActorAdapter &);
  CATSYPObjectVisitorActorAdapter &operator=(const CATSYPObjectVisitorActorAdapter &);

  CATBaseUnknown_var GetImplicitPresenter(CATBaseUnknown *iObj, const CATSYPMetaClass &iMetaClass);
  CATBaseUnknown_var GetImplicitCollection(CATBaseUnknown *iObj, const CATSYPMetaClass &iMetaClass);
  CATBaseUnknown_var sGetSYPProperty(const CATUnicodeString &iPropertyName, const CATSYPMetaClass &iSYPMetaClass, CATBaseUnknown *iObj);
};
