//======================================================================
// Copyright Dassault Systemes Provence 2010, All Rights Reserved
//======================================================================
//
// CATStoFadingEdgeImpl.h
//
//======================================================================
//
// Usage notes: Objet fading edge.
//
//======================================================================
// March,    2010 : RAQ : Cr�ation
//======================================================================
#ifndef CATStoFadingEdgeImpl_H
#define CATStoFadingEdgeImpl_H

//Pour l'export
#include "YP0LOGRP.h"

//Fading edge
#include "CATStoFadingEdgeState.h"
#include "CATStoFadingEdgeDefine.h"

//Divers
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATMathVector.h"
#include "CATCGMOutput.h"

class CATMathStream;


class ExportedByYP0LOGRP CATStoFadingEdgeImpl
{
public:

  //Constructeur
  CATStoFadingEdgeImpl();

  //Destructeur
  virtual ~CATStoFadingEdgeImpl();

  //Op�rateur de recopie
  CATStoFadingEdgeImpl& operator=(const CATStoFadingEdgeImpl& iToCopy);


  //********************************************* Services *********************************************//
  //R�cup�ration des tags des vertex des edges du fading edge
  const CATListOfInt& GetVerticesTags() const;

  //Test de fermeture
  CATBoolean IsClosed() const;

  //Obtention des param�tres
  double GetStartParam() const;
  double GetEndParam() const;
  void GetParams(double& oStartParam, double& oEndParam) const;

  //Imposition du d�placement du point de fin de FE
  CATBoolean MustSlideEndPoint() const;
  CATBoolean GetEndPointSlidingParams(CATStoFE_Side& oSide, double& oRatio) const;  //Renvoie TRUE si un glissement est impos�

  //Imposition de la direction de fin de FE
  CATBoolean HasEndingDirection() const;
  CATBoolean GetEndingDirection(CATMathVector& oDirection) const;  //Renvoie TRUE si une direction existe

  //Imposition de la tension en fin de FE
  CATBoolean HasEndingTension() const;
  CATBoolean GetEndingTension(double& oTension) const;  //Renvoie TRUE si une tension est impos�e

  //Diags de validit�
  void SetState(const CATStoFadingEdgeState iState);
  inline CATStoFadingEdgeState GetState() const { return _FadingEdgeState; }
  CATBoolean IsValid() const;

  //********************************************* Stream *********************************************//
  virtual void Stream(CATMathStream& ioStream) const;
  virtual void UnStream(CATMathStream& ioStream);

  //Dump
  void Dump(CATCGMOutput& os);

  //***************************************** Acc�s restreint *****************************************//
  //Temporaire : Nouvelle version des fading edges
  CATBoolean IsTOPOFadingEdge() const;
  void SetTOPOFadingEdge();

  //Modification des param�tres
  void SetParameters(const double iStartParam, const double iEndParam);

  //Imposition du d�placement du point de fin de FE
  void SetEndPointSlidingParams(const CATStoFE_Side iSide, const double iRatio);
  void RemoveEndPointSliding();

  //Imposition de la direction de fin de FE
  void SetEndingDirection(const CATMathVector& iDirection);
  void RemoveEndingDirection();

  //Imposition de la tension en fin de FE
  void SetEndingTension(const double iTension);
  void RemoveEndingTension();

  //Modification des donn�es
  void SetData(const CATListOfInt & iVerticesTags, const double iStartParam, const double iEndParam, const CATBoolean iIsClosed = FALSE);

  //Inversion de l'orientation du fading edge
  void Reverse();

private:

  //Flag de fermeture
  void SetClosed(const CATBoolean iIsClosed);

  //Non impl�ment�
  CATStoFadingEdgeImpl(const CATStoFadingEdgeImpl&);


  //-------- Data:
  CATListOfInt _VerticesTags;
  double _StartParam, _EndParam;
  CATStoFE_Side _SlideSide; //C�t� vers lequel il faut d�placer le point de fin de la FE
  double _EndSlideRatio;  //Ratio pour le d�placement du point de fin de FE, 0.0 --> pas de d�placement impos�
  CATMathVector _EndingDirection;
  double _EndingTension;

  CATStoFadingEdgeState _FadingEdgeState;

  //Codage des infos binaires
  // Bit 0x01 : (0) Fading edge ouvert, (1) Fading edge ferm�
  // Bit 0x02 : (0) Pas de d�placement du vertex de fin, (1) Imposition du d�placement du vertex de fin
  // Bit 0x04 : (0) Pas de direction impos�e � la fin, (1) Direction impos�e � la fin
  // Bit 0x08 : (0) Pas de tension impos�e � la fin, (1) Tension impos�e
  // Bit 0x10 : 
  // Bit 0x20 : 
  // Bit 0x40 : 
  // Bit 0x80 : (0) Fading Edge PCCM, (1) TOPO Fading Edge, pour compatibilit� de structure et doit dispara�tre
  unsigned char _BinaryInfos;

};


#endif

