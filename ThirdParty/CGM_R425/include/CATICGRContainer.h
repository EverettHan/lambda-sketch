// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATICGRContainer.h
// Define the CATICGRContainer interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2003  Creation: Code generated by the CAA wizard  jut
//===================================================================
#ifndef CATICGRContainer_H
#define CATICGRContainer_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"
class CATCGRContainer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATICGRContainer;
#else
extern "C" const IID IID_CATICGRContainer ;
#endif

//------------------------------------------------------------------

class CATBaseUnknown;
class CATRep;

/**
 * Describe the functionality of your interface here
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedBySGInfra CATICGRContainer: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

     /**
      * This method builds the container that will be streamed
      * Into the CGR.
      */
     virtual HRESULT GetContainer(CATCGRContainer * iContainer, CATBaseUnknown * model, CATRep * rep) = 0;

      /**
     * Returns the applicative container prerequisites on CGR Main container stream (noshow geometry).
     * Note that noshow will be triggered as soon as one applicative container requests it.
     * @param ipModel
     * The model which is streamed.
     * @param ipRep
     * The representation which is streamed.
     * @param oForceNoShowStream
     * <ol>
     *<li> TRUE  : container prerequisites elements in noshow to be streamed in CGR Main container</li>
     *<li> FALSE : no-show elements' stream not required by applicative container </li>
     * </ol>
     */
     virtual HRESULT GetContainerPrerequisites_NoShow(CATBaseUnknown * ipModel, CATRep * ipRep, CATBoolean &oForceNoShowStream) = 0;

};

//------------------------------------------------------------------

#endif
