#ifndef FrFVisuGeom_H
#define FrFVisuGeom_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#define FrFVisuGeom_CloneManager
//-----------------------------------------------------------------------------
//-- debut FrFVisuGeom.h: visualisation de debug d'elements geometriques-------
//-----------------------------------------------------------------------------
//              Remarque : le debuggeur Sun Workshop sait faire sans 
//              probleme du step over et meme du step into sur ces macros
//----------------------------------------------------------------------------
// NLD 24 02 98 Creation 
// NLD 16 03 98 L'activation doit desormais se faire par
//              #define FrFVisuGeom_Cond 1
// NLD 06 12 99 On clone desormais par le CloneManager
// NLD 15 03 02 FrFVisuGeomColorDbg pour possibilite de debrancher
//              la validation topologique, et pour rendre l'element duplique
//----------------------------------------------------------------------------
// Macros de duplication/visualisation d'elements geometriques 
//----------------------------------------------------------------------------
// Exemple d'utilisation
//----------------------------------------------------------------------------
// !---------------------------------------------------------------------------
// ! // Activation de la visu (a mettre en commentaires dans le code livre) 
// ! // (avant inclusion de la macro de definition)
// ! #define FrFVisuGeom_Cond 1 
// ! // Definition des couleurs de visualisation par defaut (niveau de  0 a 15)
// ! // (optionnel, a un endroit quelconque avant l'utilisation des macros) 
// ! #define FrFVisuGeom_RedLevel   5
// ! #define FrFVisuGeom_GreenLevel 8
// ! #define FrFVisuGeom_BlueLevel 12
// ! // Definition des macros
// ! #include "FrFVisuGeom.h"
// ! // Definition de la factory de creation (meme si elle est la
// ! // factory implicite, les elements seront rendus explicites) 
// ! CATGeoFactory* MyFactory=....
// ! #define FrFVisuGeom_Factory=MyFactory
// ! // definition des elements a visualiser
// ! CATGeometry *Elem1=; *Elem2= ;
// ! // visualisation des elements (element, red, green, blue) (entre 0 et 15)
// ! FrFVisuGeomColor(Elem1,10,5,0)
// ! FrFVisuGeom(Elem2) // Dans les couleurs par defaut
// !---------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Definition de la condition par defaut (ON/OFF, defaut: OFF)
//----------------------------------------------------------------------------
#ifndef FrFVisuGeom_Cond
#define FrFVisuGeom_Cond 0
#endif
//----------------------------------------------------------------------------
// Definition des niveaux de couleur par defaut
//----------------------------------------------------------------------------
#ifndef FrFVisuGeom_RedLevel
#define FrFVisuGeom_RedLevel 12
#endif
#ifndef FrFVisuGeom_GreenLevel
#define FrFVisuGeom_GreenLevel 3
#endif
#ifndef FrFVisuGeom_BlueLevel
#define FrFVisuGeom_BlueLevel 4
#endif
//----------------------------------------------------------------------------
// Prerequis 
//----------------------------------------------------------------------------
#include <CATGeometry.h>
#include <CATCGMDebug.h>
#include <CATGeoFactory.h>
#ifdef FrFVisuGeom_CloneManager
#include <CATCloneManager.h>
#endif
//----------------------------------------------------------------------------
// Visu de debug d'un element géométrique avec les couleurs par defaut
// FrFVisuGeom(CATGeometry* ObjectToVisualize)
//----------------------------------------------------------------------------
#define FrFVisuGeom(ObjectToVisualize)\
 FrFVisuGeomColor(ObjectToVisualize, \
                  FrFVisuGeom_RedLevel, \
                  FrFVisuGeom_GreenLevel, \
                  FrFVisuGeom_BlueLevel)
//----------------------------------------------------------------------------
// Visu de debug d'un element géométrique, en couleurs
// FrFVisuGeomColor(CATGeometry* ObjectToVisualize, 
//             int redlevel, int greenlevel, int bluelevel)
//----------------------------------------------------------------------------
#define FrFVisuGeomColor(ObjectToVisualize, redlev, greenlev, bluelev)\
 {CATGeometry* BidDup=NULL;\
 FrFVisuGeomColorDbg(ObjectToVisualize, \
                  redlev, \
                  greenlev, \
                  bluelev, \
                  1, BidDup)}
//----------------------------------------------------------------------------
// Visu de debug d'un element géométrique, en couleurs,
// avec validation optionnelle (active par defaut)
// et recuperation de pointeur vers l'element duplique
// FrFVisuGeomColorDbg(CATGeometry* objecttovisualize, 
//             int redlevel, int greenlevel, int bluelevel,
//             int validation, CATGeometry*& oDuplicatedElement)
//----------------------------------------------------------------------------
#if FrFVisuGeom_Cond 
 #define FrFVisuGeomColorDbg(objecttovisualize, redlev, greenlev, bluelev, validation, oDuplicatedElement)\
   { \
    CATCloneManager* CloneManager = new CATCloneManager(FrFVisuGeom_Factory);\
    if (!validation) CloneManager->SetResultStatus(0,1);\
    CloneManager->Add((CATICGMObject*)objecttovisualize);\
    CloneManager->Run();\
    CATICGMObject* NewObject\
    = CloneManager->ReadImage((CATICGMObject*)objecttovisualize);\
    delete CloneManager ;\
    CATGeometry* Dup=(CATGeometry*)NewObject;\
    CATLONG32 oldtag =((const CATGeometry*)objecttovisualize)->GetPersistentTag();\
    cout<< "Geometry duplicated (debug):"<<objecttovisualize<<\
       " tag="<<oldtag<<\
        "  --->  "<<Dup<<\
        " tag="<<Dup->GetPersistentTag()<<endl;\
    oDuplicatedElement=Dup;\
    if (Dup) Dup->SetMode(CatCGMExplicit);\
    CATCGMDebug::Show(Dup);\
    CATCGMDebug::PutColor(Dup,redlev,greenlev,bluelev);}
#else
 #define FrFVisuGeomColorDbg(objecttovisualize, redlev, greenlev, bluelev, validation, oDuplicatedElement)
#endif 
//----------------------------------------------------------------------------
//-- fin FrFVisuGeom.h: visualisation de debug d'elements geometriques---------
//-----------------------------------------------------------------------------
#endif





