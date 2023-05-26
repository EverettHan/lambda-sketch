#ifndef CATCkeObjectFacetManagement_h
#define CATCkeObjectFacetManagement_h

// COPYRIGHT DASSAULT SYSTEMES 2014


#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListValCATICkeParm.h"

class CATIKweInternalPC2;

class ExportedByCATLifSpecs CATCkeObjectFacetManagement
{
public:

  // At the moment, only one facet supported
  enum Facet { StandardNotion, FormerTypingV5Data };

  // We build the facet management from the facet and a PLMCore Object passed as a CATBaseUnknown_var
  // Note that no AddRef is done on the object. So please do not keep CATCkeObjectFacetManagement in memory. It is some kind of a service class
  CATCkeObjectFacetManagement (const Facet iFacet,const CATBaseUnknown_var &iObject);

  virtual ~CATCkeObjectFacetManagement();

  // We can tell if the object is valid for supporting facets (is it a PC2 object?)
  CATBoolean IsValid() const;

  // We can tell if the object supports this facet already
  // It may return the list of attributes set on this facet if any
  // The principle is that the list must be filled in input (with the attributes you're interested in) and the service valuates them
  CATBoolean IsFacetAlreadySupported(CATLISTV(CATICkeParm_var) &iListDefaultAttributeValues) const;

   /**
    * Adding the facet on the object.
    * @param iListDefaultAttributeValues
    * Some facet may require some attribute values (modeled as CATICkeParm for the couple name/Value)
    * @return
    *  <ol>
    * 	 <li> E_INVALIDARG if the input (or the object) was invalid
    * 	 <li> E_FAIL if failure
    * 	 <li> E_ACCESSDENIED if unable to modify the object
    * 	 <li> S_OK 
    *  </ol>
    */
   HRESULT SetFacet(const CATLISTV(CATICkeParm_var) &iListDefaultAttributeValues);

   /**
    * Removing the facet on the object.
    * @return
    *  <ol>
    * 	 <li> E_INVALIDARG if the input (or the object)  was invalid
    * 	 <li> E_ACCESSDENIED if unable to modify the object
    * 	 <li> S_OK 
    * 	 <li> S_FALSE if the facet was not existing on the object 
    *  </ol>
    */
   HRESULT RemoveFacet();
   
private:
  
  CATCkeObjectFacetManagement (const CATCkeObjectFacetManagement&);
  Facet _Facet;
  CATBaseUnknown_var _object;
  CATIKweInternalPC2 *_internal;
};

#endif 
