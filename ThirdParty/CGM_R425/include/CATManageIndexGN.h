/**
 * @level Protected
 * @usage U1
 */
#ifndef	CATManageIndexGN_h
#define	CATManageIndexGN_h

/*//////////////////////////////////////////////////////////////////////////////
  //
  //
  //
  //	Class :		CATManageIndexGN + CATHTAB(CATBrpJele) + CATBrpJele
  //	=====
  //
  //	Purpose :	Hash-Dictionary of jele indexed by numele
  //	=======
  //			Note : la classe CATBrpJele n existe pas, elle me
  //			sert a faire passer les jele pour des pointeurs
  //                      sur quelquechose. La classe CATManageIndexGN n apporte
  //                      pas grand chose non plus, essentiellement de 
  //                      pouvoir declarer cette index en forward sans 
  //                      me referer a Collections.   		  
  //
  //	Authors : 	PYR
  //	=======
  //
  //
  //	Abstract :	1- Generate a non-template collection-class with MACROS
  //	========	   (documentation on "Hash-Coding Dictionaries")
  //
  //
///////////////////////////////////////////////////////////////////////////////*/

class CATBrpJele; /* qui n existe pas  */
typedef int JeleCatia;
typedef int Numele;
typedef int Stdrc; // 0 pour ok, sinon KO : ma convention pour les codes retours  

// clean previous functions requests
#include  <CATHTAB_Clean.h>

// require needed functions
//#include  <CATHTAB_AllFunct.h>
#define  CATHTAB_KeyLocate
#define  CATHTAB_Insert
// get macros
#include  <CATHTAB_Declare.h>

//
// generate interface of collection-class
// (functions declarations)
//
CATHTAB_DECLARE( CATBrpJele )


class CATManageIndexGN
{
  public:
  CATManageIndexGN();
  inline ~CATManageIndexGN(){};
  
  Stdrc Insert(JeleCatia);
  JeleCatia Locate(Numele ) const;
  
  Numele    GetNumele(JeleCatia);
   
  private :
  CATHTAB(CATBrpJele) _Index;

};


#endif	// CATHashTableOfRCoeTokenCopy_h
