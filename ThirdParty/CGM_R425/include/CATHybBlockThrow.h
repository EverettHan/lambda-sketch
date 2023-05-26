// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATHybBlockThrow :
//    MACRO 
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Avril 97  Creation                                                       PCU
//=============================================================================
#ifndef CATHybBlockThrow_H
#define CATHybBlockThrow_H

// CATHybBlockThrow : macro qui cree un objet d'erreur
//                     et execute un throw de cette erreur
// ErrorClass : type de l'erreur
// ErrorId    : id de l'erreur

#define CATHybBlockThrow(ErrorClass, ErrorId) CATThrow(new ErrorClass(ErrorId))

#endif
