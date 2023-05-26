/**
* @quickReview AUW 11:09:29 R2013: Incrementing KweRecordVersion to 10.
*/

// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATKweRecServices.h
// Header definition of CATKweRecServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2005  Creation: Code generated by the CAA wizard  tvq
//===================================================================
#ifndef CATKweRecServices_H
#define CATKweRecServices_H

#include "CATBaseUnknown.h"
#include "CATLifSpecs.h"


//-----------------------------------------------------------------------------------------------------------------------------
//====================================================================
// 같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같�

//  IMPORTANT :: UPDATE the file KnowledgeInterfaces\CATLifSpecs.m\src\CATKweRecServices_versions.txt

//-----------------------------------------------------------------------------------------------------------------------------
//====================================================================
// 같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같�
/*
Pour utiliser ces services :

un exemple de test avec derrire un code qui d�stabilise les records enregistr�s jusqu'a la version 1.
if (CATKweRecordServices::GetRecordVersion() >= 2 || CATKweRecordServices::IsRecording())
{
CATKweRecordServices::SetRecordVersion(2); // si >= 2, ne fait rien.
}
*/
class ExportedByCATLifSpecs CATKweRecServices
{
  public:
	  // renvoie la version (kwe) du record. 0 si pas de version, ou pas en contexte record
	  static int GetRecordVersion();

	  // modifie la version (kwe) du record en train d'etre enregistre
	  // ne fait rien si : pas en contexte record, ou si version < GetRecordVersion
	  static void SetRecordVersion(int version);

	  // 1 si on est en train de rejouer, 0 sinon
	  static int IsReplaying();

	  // 1 si on est en train d'enregistrer, 0 sinon
	  static int IsRecording();

	  // 1 si on est en train d'enregistrer ou de rejouer, 0 sinon
	  static int RecordContext();

 	 /**
  	  * Is an XML ODT running ?
	  *	@return
	  *       1, if an XML ODT is running
	  *       0, if not
	  */
	  static int IsXMLODTReplay();

private:

	// Standard constructors and destructors
	// -------------------------------------
	CATKweRecServices ();
	virtual ~CATKweRecServices ();

	// Copy constructor and equal operator
	// -----------------------------------
	CATKweRecServices (CATKweRecServices &);
	CATKweRecServices& operator=(CATKweRecServices&);

	static int _CurrentVersion;
};

//-----------------------------------------------------------------------

#endif
