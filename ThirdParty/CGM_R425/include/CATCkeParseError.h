/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//=============================================================================

#ifndef CATCkeParseError_H
#define CATCkeParseError_H

// module
#include "CATLifDictionary.h"

// Includes Vom
#include "CATCkeContext.h"
#include "CATCkeEquationContext.h"



//---------------------------------------------------------------------------
class ExportedByCATLifDictionary CATCkeParseError : public CATCkeContext
{
  public :
    // dans un premier temps, cela pointe vers une string
    CATCkeParseError (const CATUnicodeString,const int,const Boolean =CATCke::True);
    CATCkeParseError (const CATCkeParseError &); 
    virtual ~CATCkeParseError () ;
   
    virtual CATCkeParseError* Clone () const;

    // produit le message d'erreur associe
    CATUnicodeString errmsg ();
    CATUnicodeString errtitle ();
    void Set (const CATUnicodeString &s){msg_=s;}
	int GetLineNo()
	{
		return lineno_;
	};

  private :

    CATUnicodeString msg_;      
    int    lineno_;
    Boolean severity_;
} ;





#endif







































































