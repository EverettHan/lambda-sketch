//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATFillingDebugOptions:
// Class for Body Filling Option
//
//==========================================================================
// Usage Notes:
//
//==========================================================================
// Juil. 99     Creation                       J. PANCIATICI
//========================================================================== 

#ifndef CATFillingDebugOptions_H
#define CATFillingDebugOptions_H

#include "GeoPlate.h"
#include "CATMathDef.h"
#include "CATGeometryType.h"

class ExportedByGeoPlate CATFillingDebugOptions
{

  public:
 
	//------------------------------
	// ToDefine algorithm parameter
	//-------------------------------

    // To define the solver to be used.
    // <iMode> can be  
    //  1 : Plate
    //  2 : PlateFE Global
    //  3 : PlateFE LocalRelax
   
		static void SetPlateMode(const int iPlateMode);

    // To define if Energie must be computed.
    // <iEnergie> can be  
    //  0 : no computation
    //  1 : computation

		static void SetCompareEnergy(const int iCompareEnergy);

   // To define if Compatibility of Comb is used
   // 0 : no used 
   // 1 : used 
	    static void SetCombMode(const int iCombMode);


	// To define if PlateFE Puissance 8
	// 0 : no used
	// 1 : used


		static void SetHigherExponent(const int iHigherExponent);
		
		/// To impose ccutting values to plateFE
		///  1 to impose and 0 to not 
		/// when _imposedCutting set to 1, it must be set to 0 after job.
		static void SetImposedCutting(const int iChoise);

		 // To define if CleanCurve  is used
         // 0 : no used 
         // 1 : used 
	    static void SetCleanCurve(const int iCleanCurve);


	// To define if PlateFE Puissance 8
	// 0 : no used
	// 1 : used

      /*
       * ktu 19/11/01
       * Ds le cadre des courbes de passages avec incompatibile, la tolerance finale peut ne pas etre 
       * celle donnees en entree. Car gestion des compatibilites. 
       * Cette option si est vrai on utile les tolerances calculees ds la gestion des imcompatibilites 
       * pour les tests finaux. Dans le cas contraire on s'en tiendra au tolerances utilisateur.
       * La variable activee  est: _WithInteriorTol
       * ATTENTION: comme toute variable static, On a interet a le desactiver par la suite.
       */
      static void SetWithInteriorTol(const CATBoolean iOption);
      static CATBoolean _WithInteriorTol;
      
	  static int ForceGeoFillLevel4;
      static void SetForceGeoFillLevel4(const int ival);

		static int ImposedCuttingToFE ;

		static int PlateMode;
		static int CompareEnergy;
		static int CombMode;
		static int HigherExponent;
	
		// To Manage EnergyzationCoef;
		static double NormalizationCoef;	
		static double E1Coeff;
		static int CleanCurve;
		static const char * CGMReplay;

};
///

#endif
