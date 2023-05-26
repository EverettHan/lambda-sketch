
#ifndef _CATICallTrac2
#define _CATICallTrac2


// COPYRIGHT DASSAULT SYSTEMES 2000

/* ----------------------------------------------------------------- */
/*                                                                   */
/*    fonction : journaling                                          */
/*    usage    : CATIA et autres                                     */
/*    responsble: JHN                                                */
/*                                                                   */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*    description :                                                  */
/*                                                                   */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*    historique  :                                                  */
/*                                                                   */
/*           numero de modif : 00                                    */
/*           raison          : creation                              */
/*           date            : 06/06/96                              */
/*           explication     : design                                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#include "CATErrors.h"
#include "CATCORBABoolean.h"
#include "CATBaseUnknown.h"
#include "CATBaseDispatch.h"
#include "CATBSTR.h"
#include "CATVariant.h"
#include "CATSafeArray.h"
#include "JS0LOGRP.h"

extern ExportedByJS0LOGRP GUID IID_CATICallTrac2;

typedef char const * CATMethodName;
typedef char const * CATClassName;

class ExportedByJS0LOGRP CATICallTrac2 : public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/* 
		Cette m�thode sp�cifie l'objet sur lequel on invoque la m�thode expos�e.
		Elle prend en entr�e un pointeur sur une interface expos�e support�e par cet objet.
		Par exemple, si on d�sire invoquer sur un CATIAPad la m�thode put_Sketch
		(m�thode expos�e par une CATIASketchBasedShape dont descend CATIAPad),
		c'est un pointeur sur CATIAPad que l'on passera � cette m�thode.
		L'objet doit �tre pr�t � r�pondre aux m�thodes de gestion des irr�solus,
		qui sont appel�es par SetInstanceRef si l'objet est rencontr� pour la premi�re fois.
		*/

		virtual void SetInstanceRef(CATBaseDispatch *obj1)=0;
		virtual CATBaseDispatch* GetInstanceRef()=0;


		/*
		Cette m�thode sp�cifie le type de l'objet sur lequel on invoque la m�thode expos�e.
		Elle prend en entr�e une cha�ne de caract�res C qui correspond
		au nom de l'interface pass�e � SetInstanceRef.
		Pour reprendre l'exemple ci-dessus, on passera la cha�ne "CATIAPad".
		*/

		virtual void SetClass(CATClassId name)=0;
		virtual CATClassName GetClass()=0;

		/* 
		Cette m�thode sp�cifie le nom de la m�thode expos�e appel�e. 
		Le premier param�tre est le nom de la m�thode (une cha�ne de caract�res C),
		le second est l'indice du param�tre qui correspond � la valeur de retour
		de la m�thode, ou 0 si la m�thode n'a pas de valeur de retour).
		Le premier param�re � l'indice 1.
		*/

		virtual void SetMethod(CATMethodName name, long iret)=0;
		virtual CATMethodName GetMethod()=0;

		/*
		Cette s�rie de m�thodes permet de sp�cifier un argument en entr�e (in)
		de la m�thode expos�e appel�e. Il y a une m�thode pour chaque type scalaire
		(short, CATLONG, float), plus une m�thode pour les tableaux SafeArrayVariant.
		Pour les m�thodes qui prennent un objet en param�tre, il faut appeler AppendParInRef.
		Le premier param�tre est la valeur du param�tre, le second son indice
		dans le tableau de param�tres. Le premier param�tre � l'indice 1.
		*/

		virtual void AppendParInVal(unsigned long t, long ipos)=0;
		virtual void AppendParInVal(CATLONG t, long ipos)=0;
		virtual void AppendParInVal(struct stroct t, long ipos)=0;
		virtual void AppendParInVal(boolean t, long ipos)=0;
		virtual void AppendParInVal(double t, long ipos)=0;
		virtual void AppendParInVal(float t, long ipos)=0;
		virtual void AppendParInVal(char t, long ipos)=0;
		virtual void AppendParInVal(unsigned short t, long ipos)=0;
		virtual void AppendParInVal(short t, long ipos)=0;
		virtual void AppendParInVal(const char * t, long ipos)=0;
		virtual void AppendParInVal(const CATBaseUnknown * t, long ipos)=0;
		virtual void AppendParInVal(const CATBSTR & t, long ipos)=0;
		virtual void AppendParInVal(const CATVariant & t, long ipos)=0;
		virtual void AppendParInVal(const CATSafeArray & t, long ipos)=0;

		/*
		Cette m�thode permet de sp�cifier un argument en entr�e de type objet
		pour la m�thode expos�e appel�e. Le premier param�tre est un pointeur sur
		l'interface expos�e correspondant au param�tre, le second doit toujours valoir 1,
		le troisieme est l'indice du param�tre dans
		le tableau de param�tres. Le premier param�tre � l'indice 1
		Le param�tre doit �tre pr�t � r�pondre aux m�thodes de gestion
		des irr�solus, qui sont appel�es par SetInstanceRef si l'objet
		est rencontr� pour la premi�re fois.
		*/

		virtual void AppendParInRef(CATBaseDispatch * t,int parin, long ipos)=0;

		/*
		Cette s�rie de m�thodes permet de sp�cifier un argument en sortie
		(out et inout) de la m�thode expos�e appel�e. Il y a une m�thode
		pour chaque type scalaire (short, CATLONG, float...), plus une m�thode pour les
		tableaux SafeArrayVariant. Pour les m�thodes qui prennent un objet en param�tre,
		il faut appeler AppendParOutRef. Le premier param�tre est la valeur du param�tre,
		le second son indice dans le tableau de param�tres.
		Le premier param�tre � l'indice 1.
		*/

		virtual void AppendParOutVal(unsigned long t, long ipos)=0;
		virtual void AppendParOutVal(CATLONG t, long ipos)=0;
		virtual void AppendParOutVal(struct stroct t, long ipos)=0;
		virtual void AppendParOutVal(boolean t, long ipos)=0;
		virtual void AppendParOutVal(double t, long ipos)=0;
		virtual void AppendParOutVal(float t, long ipos)=0;
		virtual void AppendParOutVal(char t, long ipos)=0;
		virtual void AppendParOutVal(unsigned short t, long ipos)=0;
		virtual void AppendParOutVal(short t, long ipos)=0;
		virtual void AppendParOutVal(const char * t, long ipos)=0;
		virtual void AppendParOutVal(const CATBaseUnknown * t, long ipos)=0;
		virtual void AppendParOutVal(const CATBSTR & t, long ipos)=0;
		virtual void AppendParOutVal(const CATVariant & t, long ipos)=0;
		virtual void AppendParOutVal(const CATSafeArray & t, long ipos)=0;

		/* 
		Cette m�thode permet de sp�cifier un argument en sortie de type objet pour
		la m�thode expos�e appel�e. Le premier param�tre est un pointeur sur
		l'interface expos�e correspondant au param�tre, le second doit toujours valoir 1,
		le toisi�me est l'indice du param�tre dans le tableau de param�tres.
		Le premier param�tre � l'indice 1
		Le param�tre doit �tre pr�t � r�pondre aux m�thodes de gestion des irr�solus,
		qui sont appel�es par SetInstanceRef si l'objet est rencontr� pour la premi�re fois.
		*/


		virtual void AppendParOutRef(CATBaseDispatch * t,int parin, long ipos)=0;

		/* Gestion de l'undo et du redo */
		virtual void Undo()=0;
		virtual void Redo()=0;

		/* Deprecated */
		virtual void AppendParInRefArray(CATBaseDispatch**t,long dim,int parin, long ipos)=0;

};

#endif





