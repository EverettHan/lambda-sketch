
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
		Cette méthode spécifie l'objet sur lequel on invoque la méthode exposée.
		Elle prend en entrée un pointeur sur une interface exposée supportée par cet objet.
		Par exemple, si on désire invoquer sur un CATIAPad la méthode put_Sketch
		(méthode exposée par une CATIASketchBasedShape dont descend CATIAPad),
		c'est un pointeur sur CATIAPad que l'on passera à cette méthode.
		L'objet doit être prêt à répondre aux méthodes de gestion des irrésolus,
		qui sont appelées par SetInstanceRef si l'objet est rencontré pour la première fois.
		*/

		virtual void SetInstanceRef(CATBaseDispatch *obj1)=0;
		virtual CATBaseDispatch* GetInstanceRef()=0;


		/*
		Cette méthode spécifie le type de l'objet sur lequel on invoque la méthode exposée.
		Elle prend en entrée une chaîne de caractères C qui correspond
		au nom de l'interface passée à SetInstanceRef.
		Pour reprendre l'exemple ci-dessus, on passera la chaîne "CATIAPad".
		*/

		virtual void SetClass(CATClassId name)=0;
		virtual CATClassName GetClass()=0;

		/* 
		Cette méthode spécifie le nom de la méthode exposée appelée. 
		Le premier paramètre est le nom de la méthode (une chaîne de caractères C),
		le second est l'indice du paramètre qui correspond à la valeur de retour
		de la méthode, ou 0 si la méthode n'a pas de valeur de retour).
		Le premier paramère à l'indice 1.
		*/

		virtual void SetMethod(CATMethodName name, long iret)=0;
		virtual CATMethodName GetMethod()=0;

		/*
		Cette série de méthodes permet de spécifier un argument en entrée (in)
		de la méthode exposée appelée. Il y a une méthode pour chaque type scalaire
		(short, CATLONG, float), plus une méthode pour les tableaux SafeArrayVariant.
		Pour les méthodes qui prennent un objet en paramètre, il faut appeler AppendParInRef.
		Le premier paramètre est la valeur du paramètre, le second son indice
		dans le tableau de paramètres. Le premier paramètre à l'indice 1.
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
		Cette méthode permet de spécifier un argument en entrée de type objet
		pour la méthode exposée appelée. Le premier paramètre est un pointeur sur
		l'interface exposée correspondant au paramètre, le second doit toujours valoir 1,
		le troisieme est l'indice du paramètre dans
		le tableau de paramètres. Le premier paramètre à l'indice 1
		Le paramètre doit être prêt à répondre aux méthodes de gestion
		des irrésolus, qui sont appelées par SetInstanceRef si l'objet
		est rencontré pour la première fois.
		*/

		virtual void AppendParInRef(CATBaseDispatch * t,int parin, long ipos)=0;

		/*
		Cette série de méthodes permet de spécifier un argument en sortie
		(out et inout) de la méthode exposée appelée. Il y a une méthode
		pour chaque type scalaire (short, CATLONG, float...), plus une méthode pour les
		tableaux SafeArrayVariant. Pour les méthodes qui prennent un objet en paramètre,
		il faut appeler AppendParOutRef. Le premier paramètre est la valeur du paramètre,
		le second son indice dans le tableau de paramètres.
		Le premier paramètre à l'indice 1.
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
		Cette méthode permet de spécifier un argument en sortie de type objet pour
		la méthode exposée appelée. Le premier paramètre est un pointeur sur
		l'interface exposée correspondant au paramètre, le second doit toujours valoir 1,
		le toisième est l'indice du paramètre dans le tableau de paramètres.
		Le premier paramètre à l'indice 1
		Le paramètre doit être prêt à répondre aux méthodes de gestion des irrésolus,
		qui sont appelées par SetInstanceRef si l'objet est rencontré pour la première fois.
		*/


		virtual void AppendParOutRef(CATBaseDispatch * t,int parin, long ipos)=0;

		/* Gestion de l'undo et du redo */
		virtual void Undo()=0;
		virtual void Redo()=0;

		/* Deprecated */
		virtual void AppendParInRefArray(CATBaseDispatch**t,long dim,int parin, long ipos)=0;

};

#endif





