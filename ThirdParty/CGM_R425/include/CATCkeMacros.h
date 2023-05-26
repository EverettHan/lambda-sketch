/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef CATCkeMacros_h
#define CATCkeMacros_h
//////////////////////////////////////////////////////////////////////////
// Copyright (C) 1996 Dassault-Systemes 
//
// Cke implementation macros
// NB: 2 be used in classes that do not inherit from CATCkeContext
//
//////////////////////////////////////////////////////////////////////////
/*
$Log: CATCkeMacros.h,v $
 * Revision 1.3  1997/04/30  09:42:25  frh
 * nouveau modeleur feature
 *
 * Revision 1.2  1997/04/18  12:30:01  frh
 * J'enleve les define true et false pour NT
 *
 * Revision 1.1  1997/04/03  15:02:59  aal
 * Initial revision
 *
 * Revision 1.9  1997/01/29  10:09:33  obt
 * revue_types_de_base
 *
 * Revision 1.8  1997/01/20  16:39:36  obt
 * portage_brackets_include
 *
 * Revision 1.7  1997/01/10  14:26:34  obt
 * evolutions_pour_fwk_expr
 *
 * Revision 1.6  1996/12/17  14:44:22  obt
 * futur_fwk_EngineeringEquations
 *
 * Revision 1.5  1996/11/26  18:23:59  obt
 * freeze_06
 *
 * Revision 1.4  1996/11/21  17:05:23  obt
 * freeze_05
 *
 * Revision 1.3  1996/11/13  15:11:10  obt
 * IRIX
 *
 * Revision 1.3  1996/11/13  15:11:10  obt
 * IRIX
 *
 * Revision 1.2  1996/10/29  15:22:29  obt
 * freeze_03
 *
 * Revision 1.2  1996/10/29  15:22:29  obt
 * freeze_03
 *
 * Revision 1.1  1996/10/24  14:07:01  obt
 * freeze_02
 *
*/

// interface types
#include "CATCkeContext.h"

// types
#define stringType   CATParmDictionary::StringType
#define integerType  CATParmDictionary::IntegerType
#define realType     CATParmDictionary::RealType
#define booleanType  CATParmDictionary::BooleanType
#define enumType     CATCkeContext::EnumType
#define atomType     CATCkeContext::AtomType
#define holderType   CATCkeContext::HolderType
#define voidType     CATParmDictionary::VoidType
#define undefinedType CATCkeContext::UndefinedType

//#define Dictionnary  CATCkeContext::Dictionnary
#define UsrFactory   CATCkeContext::UsrFactory

#endif

