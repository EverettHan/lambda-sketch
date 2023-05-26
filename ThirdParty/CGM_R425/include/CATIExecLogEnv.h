#ifndef CATIExecLogEnv_h
#define CATIExecLogEnv_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <stdio.h>

/* ----------------------------------------------------------------- */
/*                                                                   */
/*    fonction : journaling                                          */
/*    usage    : CATIA et autres                                     */
/*                                                                   */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*    description : Cette classe est une classe permettant de decrire*/
/*                  la liste des services necessaires pour           */
/*                  initialiser et acceder a l'environnement de      */
/*                  logging.                                         */
/*                  Cette classe ne contient aucune donnee hormis des*/
/*                  donnees statiques                                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#include "CATICallTrac2.h"
#include "JS0LOGRP.h"
#include "CATCORBATypes.h"

interface ITypeLib;
class CATIExecLog;
class CATExtendable;

class ExportedByJS0LOGRP CATIExecLogEnv {

	public :

	/*
	Cette méthode renvoie soit :
	· une interface CATICallTrac2 pour spécifier l'appel à journaliser si on est en mode
	journaling et qu'aucune autre " transaction " n'est ouverte et que le
	journaling n'est pas provisoirement suspendu.
	· NULL sinon
	*/
	static CATICallTrac2 * QueryActiveLog2();

	/* 
	Cette méthode doit être invoquéeà l'issue d'une " transaction " pour insérer la journalisation
	de l'appel représenté par le CATICallTrac2 dans le journal. Le parametre ioItem
	est detruit par InsertLogItem qui appelle Release sur cet objet (l'appelant ne doit donc
	surtout pas appeler lui-meme Release sur cet objet)
	*/
	static void InsertLogItem(CATICallTrac2 * & ioItem);


	/*
	Cette méthode permet, lorsqu'on est en mode journaling, de suspendre provisoirement
	la journalisation (ie : tous les appels à CATIExecLogEnv::QueryActiveLog2()renverront
	nul jusqu'au prochain appel à CATIExecLogEnv::LogAuthorized().
	Des appels successifs à CATIExecLogEnv::LogForbidden() sont possibles pour peu qu'ils
	soient contrebalancés par autant d'appels à CATIExecLogEnv::LogAuthorized()
	*/
	static void LogAuthorized();

	/*
	Cette méthode réactive le journalisation lorsque celle-ci a été provisoirement suspendue.
	*/
	static void LogForbidden();

	/**
	 * Retourne TRUE si le journaling est actif, FALSE sinon.
	 */
	static long IsLogActive();

	/*
	Cette méthode arrête le mode journaling. Le journal est généré dans le fichier
	qui avait été spécifié lors du Start Recording.
	Methode reservée pour usage interne.
	*/
	static void CloseLog();

	/*===================================================================
	Les methodes suivantes sont a usage interne et ne doivent pas etre appelées
	===================================================================*/
	static HRESULT GiveLib(
		char const ** filelib, 
		long nblib);
	static HRESULT GiveLib(
		ITypeLib **iLibs, 
		unsigned int iLibCount);
	static HRESULT InsertObjInLog(
		CATBaseDispatch *iObjectInLog, 
		char const * iNameInLog);
	static void GetLog(
		CATIExecLog *& journal);
};

#endif // CATIExecLogEnv_h
