// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCreateLawOnWire :
// Creation of Laws on Wire
// It is possible to specify A Value that wil be applied on a wire
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// 10 01 02 MNA Creation
// 20 10 03 NLD Ajout SetValueForLinearLaw(), pour creer des lois linéaires
//              par morceaux.
//              Ajout _LinearCase
//=============================================================================

#ifndef CATCreateLawOnWire_H
#define CATCreateLawOnWire_H

#include <AdvTopoUtil.h>
#include <CATTopOperator.h>
#include <CATListOfDouble.h>


class CATGeoFactory;
class CATBody;
class CATTopData;
class CATSoftwareConfiguration;
class CATCompositeLaw;
class CATString;


class ExportedByAdvTopoUtil CATCreateLawOnWire  : public CATTopOperator

{
  CATCGMVirtualDeclareClass(CATCreateLawOnWire);
public :
  
/**
* @nodoc
* Constructor 
*/
  
  CATCreateLawOnWire (CATGeoFactory * iFactory,
                      CATTopData    * iTopData,
                      CATBody       * iWire   );
  
  // Destructor
  ~CATCreateLawOnWire ();
  
  // SetValueForConstantLaw : Cette methode permet de donner les valeurs des contraintes
  //a imposer sur l'edge pour obtenir une loi constante.
  void SetValueForConstantLaw (double * iValues, CATLONG32 nb_Values);
  // SetValueForLinearLaw : Cette methode permet de donner les valeurs des contraintes
  //a imposer sur l'edge pour obtenir une loi linéaire.
  // donner une valeur de plus que le nombre d'edges
  void SetValueForLinearLaw   (double * iValues, CATLONG32 nb_Values);

  //Methode Run Calcul de la compositeLaw

  int Run();

  CATCompositeLaw * GetLaw();

  //KY1 : 10-12-2010

  /**  @nodoc @nocgmitf*/ 
  static const  CATString  *GetDefaultOperatorId();

protected:

  //KY1 : 10-12-2010
  /**  @nodoc*/
  int RunOperator();

  /**  @nodoc @nocgmitf */
  const  CATString  *GetOperatorId();
  /**  @nodoc @nocgmitf */
  void   RequireDefinitionOfInputAndOutputObjects();

protected:
  /**  @nodoc @nocgmitf */
  static  CATString                  _OperatorId;
  
private :
  
          CATSoftwareConfiguration * _SoftwareConfig;
          CATBody                  * _InputWire;
          double                   * _Values;
          int                        _nbValues;
          double                   * _ParameterForLaw ; 
          CATCompositeLaw          * _LawCreated;
          int                        _LinearCase;
};

#endif






