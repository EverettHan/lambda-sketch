#ifndef CATCDSGraphEdge_H
#define CATCDSGraphEdge_H

// COPYRIGHT DASSAULT SYSTEMES  2016

#include "CATCDSVirtual.h"
#include "CATCDSGraphVertex.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSGraph.h"

/**
 * A class for representing an edge in the graph.
 * If the edge is bi-directionnal, both arcs from first point to second point and from second point to first point exist.
 * Otherwise only first point to second point arc exists (another edge can define the reverse arc).
 */
class ExportedByGraph CATCDSGraphEdge : public CATCDSGraphObject
{
  friend class CATCDSGraphSolver;

public:
  /**
   * Constructor
   * @param ipFirstVertex  First edge vertex
   * @param ipSecondVertex Second edge vertex
   * @param iBidirectional A boolean to specify if both directions exist. 
   * if bidirectional, then create only one edge but precise it in CATCDSVertex attribute "_adjacent". 
   * Example 1 : if pV1--pV2 then
   * 1) pV1::_adjacent will contain pV2; 
   * 2) pV2::_adjacent will contain pV1;
   * Example 2 : if pV1->pV2 then
   * pV1::_adjacent will contain pV2 but not the contrary
   * @return The created edge
  */
  CATCDSGraphEdge(CATCDSString const& iName, CATCDSGraphVertex* ipFirstVertex, CATCDSGraphVertex* ipSecondVertex, CATCDSBoolean iBidirectional=TRUE);
  CATCDSGraphEdge();//constructeur par defaut necessaire pr faire des CATCDSArray<CATCDSGraphEdge*>
   
  ~CATCDSGraphEdge() {}

  void SetPriority(int const iPriority);
    /**
   * Retrieves the first vertex of the edge
   * @return The first vertex
   */
  CATCDSGraphVertex* GetFirstVertex();

  /**
   * Retrieves the second vertex of the edge
   * @return The second vertex
   */
  CATCDSGraphVertex* GetSecondVertex();

  /*
  *@ return _name
  */
  CATCDSString const& GetName() const CATCDSOverride;

  void SetWeight(double const iWeight );
  double GetWeight() const;

  /*
   * Returns TRUE if edge is bidirectional.
   * @return Returns TRUE if edge is bi-directional
   */
  CATCDSBoolean IsBidirectional() const;

  /*
  *@ return TRUE if the edge is involed in a chordless cycle, FALSE otherwise
  */
  CATCDSBoolean GetInvolved() const;

  /*
  *@return _priority (0 for P0, 1 for P1, 2 for P2)
  */
  int GetPriority() const;

  /*
  *@param TRUE or FALSE
  */
  void UpdateInvolved(CATCDSBoolean i);

private:
  CATCDSString _name;
  CATCDSGraphVertex* _pFirstVertex;
  CATCDSGraphVertex* _pSecondVertex;
  CATCDSBoolean _bidirectional;
  CATCDSBoolean _involved; //TRUE if this edge is involved in a chordless cycle
  int _priority; // 0 is more priority than 1, which is more priority than 2. (by default, priority = 2)
  double _weight;

};

#endif
