/* -*-c++-*- */
//===========================================================================
// Class CATDynSolidShellCNEXT
//---------------------------------------------------------------------------
// Classe qui assure le branchement entre Part et le modeleur CNext.
//---------------------------------------------------------------------------
// Mar. 98  Creation                                           L. Alt
// Aug. 00  Ajout de la methode SetSoftwareConfiguration       L. Alt
// Sep. 00  Migration sur les CATTopData. A terme, c'est ce constructeur
//          qui devra rester, l'autre (avec journal) devenant inutile.
//                                                             L. Alt
//===========================================================================
#ifndef CATDynSolidShell_H_
#define CATDynSolidShell_H_

#include <CATDynShell.h>
#include <CATDynCNEXT.h>
#include "CATShellOperator.h"


class CATDynSolidShellCGM : public CATDynShell
{
 public:

  CATDynSolidShellCGM( CATGeoFactory     * iContainer,
		                   CATBody           * iPart,
		                   CATLength           iInternalOffset,
		                   CATLength           iExternalOffset,
		                   CATCGMJournalList * journal=NULL);

  CATDynSolidShellCGM( CATGeoFactory * iContainer,
		                   CATBody       * iPart,
		                   CATLength       iInternalOffset,
		                   CATLength       iExternalOffset,
		                   CATTopData    * iTopData);

  virtual ~CATDynSolidShellCGM();
  
  virtual int  Run();

  virtual void Append( const CATLISTP(CATFace) & iOpeningFaces )  ;
  virtual void Append( const CATLISTP(CATFace) & iSpecialOffset,
		                   CATLength                 iInternalSpecialOffset,
		                   CATLength                 iExternalSpecialOffset );

  virtual void SetSoftwareConfiguration(CATSoftwareConfiguration * iNewConfig );

  virtual void SetMandatoryFacesToRemove(const CATLISTP(CATFace) &iFacesToRemove,
                                         short iExternalThick = 0 );

  virtual void SetCandidateFacesToRemove(const CATLISTP(CATFace) &iFacesToRemove,
                                         short iExternalThick = 0 );

  virtual void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces,
                                         short iExternalThick = 0 );

  virtual void GetFacesToIgnore( CATLISTP(CATFace) &oFacesToIgnore, 
                                 short iExternalThick = 0 );

  // For GetLiveResult
  void RequireDefinitionOfInputAndOutputObjects();

	//KY1 : 10-12-2010
	/**	@nodoc @nocgmitf */ 
	static const  CATString  *GetDefaultOperatorId();

	//KY1 : 10-12-2010
protected:
	/**	@nodoc @nocgmitf */
	int RunOperator();
	/**	@nodoc @nocgmitf */
	//static  CATString  _OperatorId; // Voir ds CATThickenOpImpl
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
	/**  @nodoc @nocgmitf */
	//void   RequireDefinitionOfInputAndOutputObjects();

 private :

  // Implementation de l'operateur.
  CATShellOperator * _ShellOperator;

};



#endif
