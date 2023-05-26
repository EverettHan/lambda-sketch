//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//=============================================================================
/**
* @level Private
* @usage U3
*/

//-- [chd:11.03.2014] VPMIDicFunction devient un VPMIDicElement (et non plus un VPMIDicSubRoutine)

#ifndef VPMIDicFunction_H
#define VPMIDicFunction_H

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"

class VPMIDicImplementation_var; 

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicFunction;
#else
extern "C" const IID IID_VPMIDicFunction;
#endif

//------------------------------------------------------------------

class ExportedByVPMIDicInterfaces VPMIDicFunction: public VPMIDicElement
{
  CATDeclareInterface;

public:

/**
* get the Implementation of the Function
*/
  virtual HRESULT GetImplementation ( VPMIDicImplementation_var & oImplementation ) = 0;



  //------------------------------------------------------------------
  //-- faut quand même que je récupère ici les $#@%! de méthodes historiques de VPMIDicSubRoutine
  //------------------------------------------------------------------

  /**
  * Return for Name of this Function
  * @param oName
  */
  virtual HRESULT getName ( CATString & oName ) = 0; //-- seriously ??? 

  //------------------------------------------------------------------
  //-- toutes les methodes ci dessous sont quasi obsoletes: methodes avec smart pointers à venir !

  /**
* @deprecated
  * Return for this Function the Implementations
  * @param oListOfImplementations List of VPMIDicImplementation
  */
  virtual HRESULT getImplementations(CATLISTP(IUnknown) & oListOfImplementations ) = 0;

 
  /**
  * Return for this Function the Parameters in the order defined by the "Order" declaration-attribute (XML Attribute)
  * @param oListOfParameters List of VPMIDicParameterB
  */
  virtual HRESULT getParameters ( CATLISTP(IUnknown) & oListOfParameters ) = 0;

  /**
  * Return for this Function the input-Parameters  in the order defined by the "Order" declaration-attribute (XML Attribute)
  * @param oListOfParameters List of VPMIDicParameterB
  */
  virtual HRESULT getInputParameters ( CATLISTP(IUnknown) & oListOfInputParameters ) = 0;

  /**
  * Return for this Function the output-Parameters  in the order defined by the "Order" declaration-attribute (XML Attribute)
  * @param oListOfParameters List of VPMIDicParameterB
  */
  virtual HRESULT getOutputParameters ( CATLISTP(IUnknown) & oListOfOutputParameters ) = 0;

};

CATDeclareHandler (  VPMIDicFunction,  VPMIDicElement );
//------------------------------------------------------------------

#endif
