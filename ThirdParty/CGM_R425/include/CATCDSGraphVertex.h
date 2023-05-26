// COPYRIGHT Dassault Systemes 2016
//===================================================================
//  2016                                      
//===================================================================
#ifndef CATCDSGraphVertex_H
#define CATCDSGraphVertex_H

#include "CATCDSVirtual.h"
#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSGraphClasses.h"

class CATCDSGraphSolver;

class ExportedByGraph CATCDSGraphVertex : public CATCDSGraphObject
{
  friend class CATCDSGraphSolver;

private:

	//streamed name (must be unique)
	CATCDSString _name;
	//useful for diverse algo. For chordlessCycles algo, index (also called "label") must be unique, and is useful to find the vertices listed in an array.
	int _index;
  //algorithms often require 2 indices for the vertices, to label them
  int _otherIndex;
	// color can help to know if we yet studied the vertex
	CATCDSBoolean _color;
	//blocked is useful for chordless path/cycle search (corresponds to the number of neighbors wich are yet in the cordless path/cycle)
	unsigned int _blocked;
	//couples (pVertex, pEdge) where pVertex refers to the vertex neighbor and pEdge refers to the edge "this--pVertex".
  // For directed graph, pVertex appears in Adjacent if there exist an oriented edge "this-->pVertex", but does not appear if only edge "pVertex-->this" exsits.
  //Beware : ordered array! vertices are put in order according to their label (_index). Increasing _index
	CATCDSAdjacent _adjacentVertices;
  // index of the first adjacent vertex that has a label strictly larger than this. 
  //example :  if k=>_labelLimit, then _adjacentVertices[k] contains a pointer to a vertex that has a label (_index) superior to this._index
	int _labelLimit;

	
public:	
  /** Constructor. */
  CATCDSGraphVertex(CATCDSString const& iName);
  /** Constructor by default (not really used but we need it for CATCDSArray) */
  CATCDSGraphVertex();
  ~CATCDSGraphVertex(){}

  void SetIndex(int const i);
  int GetIndex() const;
  void SetOtherIndex(int const i);
  int GetOtherIndex() const;
  void SetColor(CATCDSBoolean iColor);
  CATCDSBoolean GetColor() const;


  /**
   * @return
   * _name
  */
  CATCDSString const& GetName() const CATCDSOverride;

  /**
   * @return
   * _labelLimit 
  */
  int const GetLabelLimit() const;

   /**
   * @return
   * _adjacentVertices
  */
  CATCDSAdjacent& GetAdjacentVertices();

  CATCDSAdjacent const& GetAdjacentVertices() const;
  /**
   * update neighbors' _blocked attribute 
   */
  void BlockNeighbors();

   /**
   * update neighbors' _blocked attribute 
   */
  void UnBlockNeighbors();
  
   /**
   * 
   @return
   *    the number of its neighbors (adjacent vertex) wich are involved in the path (0 if no one of its neightbors is in the path)
   */
  unsigned int const GetBlocked() const;

  /**
  * set _bloked=0
  *
  */
  void InitializeBlocked();
   
  /**
  * update _blocked
  * @param i
  *	i>0 or <0. But _blocked has to stay>=0.
  */
  void UpdateBlocked(int i);

    /**
   * add a vertex to adjacentVertices array
   * @param ipVertex
   *	pointer to the neighbor to add
   */
  void AddAdjacentVertex(CATCDSGraphVertex* ipVertex, CATCDSGraphEdge* ipEdge);

    /**
   * put in order adjacentVertices array. Increasing _index : _adjacentVertices[k]->GetIndex < _adjacentVertices[k]->GetIndex[k+1]
   */
  void PutInOrderAdjacentVertices();

   /**
   * find triplets (pV1,this,pV2) such that 
   * a) this->_index <  pV1->index < pV2->index
   * b) pV1 and pV2 are adjacent to "this"
   * c) pV1 and pV2 are not adjacent
   * Add these triplets to ipSolver-> _feasibleTriplets
   */
  void FindTriplets(CATCDSGraphSolver* ipSolver);
};

#endif


