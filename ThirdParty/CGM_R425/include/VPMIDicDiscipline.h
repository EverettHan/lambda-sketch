// COPYRIGHT Dassault Systemes 2007
// This concept is obsolete
//===================================================================
/**
 * @level Private
 * @usage U3
 */
//
// VPMIDicDiscipline.h
// Define the VPMIDicDiscipline interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Nov 2007  Creation: Code generated by the CAA wizard  IWI
//===================================================================
#ifndef VPMIDicDiscipline_H
#define VPMIDicDiscipline_H

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"
#include "VPMIDicProcedure.h"
#include "VPMDicCUSTOMEREXPOSITION.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces const IID IID_VPMIDicDiscipline;
#else
extern "C" const IID IID_VPMIDicDiscipline;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* VPMIDicDiscipline are ...
* <p>
* Do not use the VPMIDicDiscipline interface for such and such
*
* @example
*  // example is optional
*  VPMIDicDiscipline* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_VPMIDicDiscipline,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByVPMIDicInterfaces VPMIDicDiscipline : public VPMIDicElement
{
  CATDeclareInterface;

public:
  
  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   returns S_OK when the Discipline is a 3DXML Discipline.
  *   returns S_FALSE otherwise.
  * </pre>
  * </dl>
  */
  virtual HRESULT has3DXMLExposure () = 0;

  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Get if the discipline is a CustoDiscipline or not
  *   @param oIsCusto
  *      true if the discipline is a custo discipline
  *   @return
  *      Error code of function.
  *
  * </pre>
  * </dl>
  */
  virtual HRESULT GetIsCustoDiscipline ( boolean & oIsCusto ) = 0;

  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   return true if the Discipline has a Method that realizes the MethodType with the name methodTypeName. Otherwise return false
  *   @param iMethodTypeName
  *      The name of MethodType
  *   @param oIsSupported
  *   @return
  *      E_FAILED if error
  *      S_OK else
  * </pre>
  * </dl>
  */
  virtual HRESULT supportMethodType(const CATString & iMethodTypeName,boolean & oIsSupported ) = 0;

  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   If the Method has only a single Usage, return for this Discipline the Procedure associated to this Usage.
  *   If the Method has more than one Usage, return for this Discipline the Procedure associated to the first Usage;
  *   @param iMethodTypeName
  *      The name of MethodType
  *   @param oppProcedure
  *      The Procedure
  *   @return
  *      E_FAILED if error
  *      S_OK else
  * </pre>
  * </dl>
  */
  virtual HRESULT getProcedureForMethodType(const CATString & iMethodTypeName,VPMIDicProcedure ** oppProcedure ) = 0;

  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Return for this Discipline the Procedure associated to this Usage.
  *   @param iMethodTypeName
  *      The name of a MethodType
  *   @param iMethodUsageName
  *      The name of a Usage of the MethodType
  *   @param oppProcedure
  *      The Procedure
  *   @return
  *      E_FAILED if error
  *      S_OK else
  * </pre>
  * </dl>
  */
  virtual HRESULT getProcedureForMethodUsage(const CATString & iMethodTypeName,const CATString & iMethodUsageName,VPMIDicProcedure ** oppProcedure ) = 0;




#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicDiscipline:::GetCreationMode shoun't be used anymore.")

#else
  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Get if the discipline is in creationMode or not
  *   @param iCreation
  *      true if the discipline is in creationMode
  *   @return
  *      Error code of function.
  *
  * </pre>
  * </dl>
  */
  virtual HRESULT GetCreationMode ( boolean & oCreation ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicDiscipline:::IsClassInDiscipline shoun't be used anymore.")

#else
  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Return oIsInDiscipline=true if the Class with the name iClassName belongs to this discipline
  *   @param iClassName
  *      The name of the class
  *   @return
  *      Error code of function.
  *
  * </pre>
  * </dl>
  */
  virtual HRESULT IsClassInDiscipline ( const CATString * iClassName,boolean & oIsInDiscipline ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicDiscipline:::getProcedureForMethodUsage shoun't be used anymore.")

#else
  /**
  * @deprecated
  */
  virtual HRESULT getProcedureForMethodUsage(const CATString & iMethodUsageName,VPMIDicProcedure ** oppProcedure ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicDiscipline:::SetIsCustoDiscipline shoun't be used anymore.")

#else
  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Set if the discipline is a custo discipline or not
  *   @param iCustoDiscipline
  *      true if the discipline is a custo Discipline
  *   @return
  *      Error code of function.
  *
  * </pre>
  * </dl>
  */
  virtual HRESULT SetIsCustoDiscipline ( boolean iCustoDiscipline ) = 0;
#endif
  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------




#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicDiscipline:::IsExposedForPurpose shoun't be used anymore.")

#else
  /**
  * @nodoc
  */
  virtual HRESULT IsExposedForPurpose ( const VPMDicCUSTOMEREXPOSITIONPURPOSE iPurpose, boolean & oIsExposed  )const  = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicDiscipline:::GetClasses shoun't be used anymore.")

#else
  /**
  * @nodoc
  */
  virtual HRESULT GetClasses ( CATLISTP(IUnknown) * oClasses ) = 0;
#endif
 //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING"   " VPMIDicDiscipline::SetCreationMode is useless. Its usage should be suppressed.")

#else
  /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Set if the discipline is in creationMode or not
  *   @param iCreation
  *      true if the discipline is in creationMode
  *   @return
  *      Error code of function.
  *
  * </pre>
  * </dl>
  */
  virtual HRESULT SetCreationMode ( boolean iCreation ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING"   " VPMIDicDiscipline::SetCustomerExposition is useless. Its usage should be suppressed.")

#else
    /**
  * @nodoc
  */
  virtual HRESULT SetCustomerExposition ( const VPMDicCUSTOMEREXPOSITION iCustomerExposition ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING"   " VPMIDicDiscipline::AddClass is useless. Its usage should be suppressed.")

#else
    /**
  * <dl>
  * <dt>
  * <pre>
  *
  *   Add a class to the discipline
  *   @param iClassName
  *      The name of the class
  *   @return
  *      E_FAILED if error
  *      S_FALSE if Class already in the Discipline
  *      S_OK else
  * </pre>
  * </dl>
  */
  virtual HRESULT AddClass (const CATString iClassName ) = 0;
#endif
};

CATDeclareHandler( VPMIDicDiscipline, CATBaseUnknown );

#endif
