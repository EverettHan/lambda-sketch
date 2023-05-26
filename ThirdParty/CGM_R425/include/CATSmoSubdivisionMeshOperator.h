//===================================================================================
// Copyright Dassault Systemes Provence 2003-2007, All Rights Reserved 
//===================================================================================
//
// CATSmoSubdivisionMeshOperator.h
//
//===================================================================================
//
// Usage notes: Base class for all mesh operators
//
//===================================================================================
//  June       2008 : UIQ : Ajout de Get de Liste pour l'operateur de Minimisation
//  November,  2007 : MMO : Correction des erreurs BAD004 (headerruler)
//  January,   2006 : RAQ : Modif pour nouveaux op�rateurs topo sur CATSubdivMesh
//  January,   2004 : RAQ : Changement d'architecture des subdivisions
//  September, 2003 : JCV : Creation
//===================================================================================
#ifndef CATSmoSubdivisionMeshOperator_H
#define CATSmoSubdivisionMeshOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Objets Subdivision
#include "CATSobDiag.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfFace.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"

//Divers
#include "CATBoolean.h"

class CATSobMesh;
class CATSobFace;
class CATSobEdge;
class CATSobVertex;

class CATSmoMeshTopoModifOperator;
class CATSmoDebugFactory;

class ExportedByCATSmoOperators CATSmoSubdivisionMeshOperator
{
public:
	
	//Destructeur
  virtual ~CATSmoSubdivisionMeshOperator();
	
  //Set d'un level pour versionning
  void SetVersionningLevel(const short iLevel);
	
	//Run de l'op�rateur
  virtual CATSobDiag Run();
	
  //Diag de l'op�rateur
  CATSobDiag GetDiag() const;

  //Obtention du mesh r�sultat
  CATSobMesh* GetResultMesh();

  //Test si le run a d�j� �t� fait
  CATBoolean HasAlreadyRun() const;

  //Test si l'op�rateur est multi-run
  CATBoolean IsMultiRun() const;

  //D�sactivation du multi-run
  void DisableMultiRun();

  // Passe une factory de debug (instance de debug sera detruite par cet objet)
  void SetDebugFactory(CATSmoDebugFactory * iFactory);

  //M�thode de Get pour l'operateur de Minimisation
  CATListOfInt& GetListOldFaceForMinimise();
  CATListOfInt& GetListNewFaceForMinimise();
  CATListOfInt& GetListFaceTamponForMinimise();

  //Set pour remplir les listes de minimisation ou non
  void SetIsMinimisation(CATBoolean iIsMinimisation);

protected:

	//Constructeurs
  CATSmoSubdivisionMeshOperator(CATSobMesh* iMesh = 0);
  CATSmoSubdivisionMeshOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

  //Set du mesh en cas de constructeur par d�fault
  void SetCurrentMesh(CATSobMesh* iCurrentMesh);

  //L'op�rateur est multi-run
  void SetMultiRunOperator(const CATBoolean iIsMultiRun = FALSE);

  //Run de l'impl�mentation
  virtual CATSobDiag RunOperator() = 0;

  //Cr�ation d'une face, � surcharger par les op�rateurs topo
  virtual CATSobDiag CreateFace(CATLISTP(CATSobEdge)& iEdgesOfFace, CATSobFace*& oNewFace);

  // Creation de plusieurs faces, l'ordre de creation respectant la connexite
  // NE PAS surcharger dans l'op�rateur topo
  virtual CATSobDiag MultiFacesCreation(const int iNbFacesToCreate,
                                        CATLISTP(CATSobEdge) iEdgesOfFacesToCreate[],
                                        CATSobFace** ioCreatedFaces = 0);

  //Ajout de plusieurs faces dans un mesh (sans join !!!)
  virtual CATSobDiag AddFaces(CATLISTP(CATSobFace)& iFacesToAdd, CATLISTP(CATSobFace)* ioCopiedFaces = 0);

  //Destruction d'une face, � surcharger par les op�rateurs topo
  virtual CATSobDiag RemoveFace(CATSobFace* iFaceToRemove);

  //Cr�ation d'une edge, � surcharger par les op�rateurs topo
  virtual CATSobDiag CreateEdge(CATSobVertex* iStartVertex, CATSobVertex* iEndVertex, CATSobEdge*& oCreatedEdge);

  //Destruction d'une edge, � surcharger par les op�rateurs topo
  virtual CATSobDiag RemoveEdge(CATSobEdge* iEdgeToRemove);

  //Cr�ation d'un vertex, � surcharger par les op�rateurs topo
  virtual CATSobDiag CreateVertex(const double* iVertexCoords, CATSobVertex*& oCreatedVertex);
  virtual CATSobDiag CreateVertex(const double iX, const double iY, const double iZ, CATSobVertex*& oCreatedVertex);

  //Destruction d'un vertex, � surcharger par les op�rateurs topo
  virtual CATSobDiag RemoveVertex(CATSobVertex* iVertexToRemove);

  //Mise � jour du mesh courant
  CATSobDiag UpdateCurrentMesh();
	
	//Distance entre deux points
  double SquareDistance(const double Pt1[], const double Pt2[]);

  //Gestion du diag
  CATSobDiag SetDiag(const CATSobDiag iDiag);
  CATSobDiag ReturnErrorDiag(const char* iString, int iLine, const CATSobDiag iDiag, const CATBoolean iWithSetDiag=TRUE) const;
	
	//------ Data:
  short _VersionningLevel;
  CATSobMesh* _CurrentMesh;
  CATSmoDebugFactory* _DBGFactory;
  CATSobDiag _Diag;
  CATBoolean _OperatorAlreadyRun, _IsMultiRunOperator;

  CATSmoMeshTopoModifOperator* _TopoModifOpe;

  //List de tag de Face pour l'op�rateur de Minimise
  CATListOfInt _TagOldFaceForMinimise;
  CATListOfInt _TagNewFaceForMinimise;
  CATListOfInt _FaceTamponForMinimise;
  CATBoolean _IsMinimisation;

  //Fonction pour incr�menter les listes liste de la minimisation
  void AppendOldFaceForMinimise(int iTag);
  void AppendNewFaceForMinimise(int iTag);
  void AppendFaceTamponForMinimise(int iTag);

  //Fonction qui retourne vrai si le tag existe dans la liste
  //des Faces Tampons et faux sinon
  CATBoolean ExistFaceTampon(int iTag);

};


#endif


