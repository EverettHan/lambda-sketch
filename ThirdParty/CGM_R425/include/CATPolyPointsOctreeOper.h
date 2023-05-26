// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011, ALL RIGHTS RESERVED.
//===================================================================
//
//CATPolyPointsPrimDetectOctreeOper.h
// Header definition of CATPolyPointsPrimDetect
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 17-Jui-2013 - ANR - Création ( D'apres H32 ).
//===================================================================

#ifndef CATPolyPointsOctreeOper_H
#define CATPolyPointsOctreeOper_H

#include "CATPolyCanonicOperators.h"
#include "CATBooleanDef.h" 

#include "CATMathPoolThread.h"
#include "CATCGMThread.h"
#include "CATCGMThreadManager.h"
#include "CATCGMMutex.h"
#include "CATBaseComputation.h"
#include "CATArithTypes.h"
#include "CATListOfInt.h"
//05082013#include "CATListOfDouble.h"
#include "CATMathLine.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATListPV.h"

class CATMathPoint;
class CATMathVector;
class CATMathBox; 

//----------------
// Octrees
//--------------------------------

/*
3-----7               DTT ---- TTT
/|    /|              /|         /|
1-----5 |             / |        / |
| 2---|-6            DDT|---- TDT  |
|/    |/             |  |       |  |
0-----4              |  DTD ----|TTD
| /        | /
Z                             |/         |/
| Y                           DDD ---- TDD
|/
+--- X 
*/

class ExportedByCATPolyCanonicOperators CATPolyPointsOctree
{
public:

  //-------------------------------------------------------------------------//
  //                       Definitions et outils                             //
  //-------------------------------------------------------------------------//

  // ATTENTION l'ordre et la valeur des enum sont significatif.
  // Notament pour des calculs, bases sur l'interpretation des lettres D et T,
  // respectivement 0 et 1.

  // Position des fils : T = Top; D = Down; TDT = Top X, Down Y, Top Z;
  // la valeur None est specifique a la racine
  enum Position {DDD = 0, DDT = 1, DTD = 2, DTT = 3, 
    TDD = 4, TDT = 5, TTD = 6, TTT = 7};
  const static int NbPos = 8;
  // Direction d'une case vers ses voisines
  enum Direction {F_DYZ, F_TYZ, F_XDZ, F_XTZ, F_XYD, F_XYT,   // Faces
    E_XTT, E_XDT, E_XDD, E_XTD, E_TYT, E_DYT,
    E_DYD, E_TYD, E_TTZ, E_DTZ, E_DDZ, E_TDZ,   // Aretes
    V_TTT, V_TTD, V_TDT, V_TDD,
    V_DTT, V_DTD, V_DDT, V_DDD};                // Sommets
  const static int NbDir = 26;

  // Type de voisin
  enum Type {Brother, Face, Edge, Vertex};

  class StackPosition
  {
  public:
    StackPosition(int iMaxSize);
    StackPosition(const StackPosition &iOther);
    ~StackPosition();

    int Size();

    CATBoolean Push(Position iVal);
    CATBoolean Push(StackPosition &ioOther);
    CATBoolean Pop(Position &oVal);

    void Clear();
    // Si iNbToClear est negatif les -iNbToClear dernier elements ne seront pas supprime
    void Clear(int iNbToClear);

    // iIndex : 1 ... Size()
    Position& operator[](int iIndex);

  private:
    Position *_table;
    int _pos, _max;
  };

  //-------------------------------------------------------------------------//
  //                             OCTREE Node                                 //
  //-------------------------------------------------------------------------//

  class Node 
  {
  public:
    virtual ~Node();
    virtual CATBoolean IsLeaf() const = 0;

    virtual void GetPoint(CATListOfInt &oList) const = 0;
#ifdef forCoverage
    virtual int GetPoint(int *oPoints, const int iMaxPoints) const = 0;
#endif
    virtual int GetPoint(const int iPos) const = 0;
    virtual CATBoolean AddPoint(int iIndex);
    virtual CATBoolean RemovePoint(int iIndex) = 0;
    virtual int GetNbPoint() const = 0;

#ifdef forCoverage
    virtual Node** GetChild();
#endif
    virtual const Node* GetChild(const Position iPos) const;
    virtual Node* GetChild(const Position iPos);
    virtual CATBoolean SetChild (const Position iPos, Node *iNode);

    virtual unsigned char GetSignature() const = 0;

    struct Children
    {
      unsigned char DDD : 1;
      unsigned char DDT : 1;
      unsigned char DTD : 1;
      unsigned char DTT : 1;
      unsigned char TDD : 1;
      unsigned char TDT : 1;
      unsigned char TTD : 1;
      unsigned char TTT : 1;
    };

    union Signature
    {
      unsigned char value;
      struct Children Child;
    };
  };

  class Box : public Node
  {
  public:
    Box();
    virtual ~Box();
    virtual CATBoolean IsLeaf() const;

    virtual void GetPoint(CATListOfInt &oList) const;
#ifdef forCoverage
    virtual int GetPoint(int *oPoints, const int iMaxPoints) const;
#endif
    virtual int GetPoint(const int iPos) const;
    virtual CATBoolean RemovePoint(int iIndex);
    virtual int GetNbPoint() const;

#ifdef forCoverage
    virtual Node ** GetChild ();
#endif
    virtual Node * GetChild (const Position iPos);
    virtual const Node * GetChild (const Position iPos) const;
    virtual CATBoolean SetChild (const Position iPos, Node *iNode);

    virtual unsigned char GetSignature() const;

  private :
    Node *_child[8];
  };

  class Leaf : public Node 
  {
  public:
    Leaf(int iInitAlloc = 0);
    Leaf(const int iNbPnt, const int *iPntIndex);
    Leaf(const int iNbPnt, const int *iPosIndex, const int *PntIndex);
    virtual ~Leaf();
    virtual CATBoolean IsLeaf() const;

    virtual void GetPoint(CATListOfInt &oList) const;
    virtual int GetPoint(int *oPoints, const int iMaxPoints) const;
    virtual int GetPoint(const int iPos) const;
    virtual int GetNbPoint() const;
    virtual CATBoolean AddPoint(int iIndex);
    virtual CATBoolean RemovePoint(int iIndex);

    virtual unsigned char GetSignature() const;

  private :
    CATListOfInt _points;
  };


  //-------------------------------------------------------------------------//
  //                         OCTREE Strategy                                 //
  //-------------------------------------------------------------------------//

  class Strategy
  {
  public:
    enum Constraint {AND, OR, SIZE, COUNT};

    Strategy(const int iMaxCount, const double iMinSize, 
      const Constraint iStrat);
    Strategy(const int iMaxCount, const double iMinSize);
    Strategy(const double iMinSize);
    Strategy(const int iMaxCount);
    Strategy();

    int MaxCount() const;
    double MinSize() const;

    void SetMaxCount(const int iMaxCount);
    void SetMinSize(const double iMinSize);
    void SetStrategy(Constraint iStrat);

    inline CATBoolean operator() (const double *iOrigin, const double iSize, 
      const int iNbPnt) const;
    inline CATBoolean IsLeaf(const double *iOrigin, const double iSize, 
      const int iNbPnt) const;
  private:
    int _maxCount;
    double _minSize, _minBorne;
    Constraint _strat;
  };


  //-------------------------------------------------------------------------//
  //                          OCTREE Walkers                                 //
  //-------------------------------------------------------------------------//

  //class LevelWalker
  //{
  //public:
  //  LevelWalker(Node *iNode, int iLevel);
  //  ~LevelWalker();
  //  Node *Next();
  //  Node *Node();

  //private:
  //  Node *GetChild(const int iLevel);
  //  CATBoolean NextPos(const int iUp);

  //  Node **_branchNode;
  //  short *_branchPos;
  //  int _branchSize;

  //  Node *_curNode;
  //};

  class LeafWalker
  {
  public:
    LeafWalker(CATPolyPointsOctree &Octree);
    ~LeafWalker();
    Node *Next();
    Node *Leaf();

  private:
    Node *GetChild(const int iLevel);
    CATBoolean NextPos(const int iUp);

    Node **_branchNode;
    short *_branchPos;
    int _branchSize;
    int _Level;

    Node *_curNode;
  };

  class ExportedByCATPolyCanonicOperators NodeWalker
  {
  public :
    NodeWalker();
    NodeWalker(const NodeWalker & iNrun); 
    NodeWalker(CATPolyPointsOctree &iOctree);

    void Init(CATPolyPointsOctree &iOctree);
    void Init(const NodeWalker &iNW);
    void Init(Node *iRoot, const double *iRootOrigin, const double iRootSize);

    Node *CurNode();
    const Node *GetNode() const;
    const double *GetOrigin() const;
    double GetSize() const;
    void GetBox(CATMathBox &oBox, double iTol = 0.) const;
    void GetOrigin(CATMathPoint &oOrigin) const;

    inline virtual CATBoolean GoToChild(const Position iChildPos);
    inline CATBoolean GoToChild(const double *iPntInChild);
    inline CATBoolean GoToLeaf(const double *iPntInChild);
    inline CATBoolean GoToLeaf(const double *iPntInChild, 
      CATListOfInt &oPointOfLeaf);

    NodeWalker GetChildRunner(Position iPos) const;

    NodeWalker& operator=(const NodeWalker&);

  protected:
    void SetCurNode(Node *iNode);

  private:
    Node *_curNode;
    double _curOrigin[3];
    double _curSize;
  };

  class ExportedByCATPolyCanonicOperators NodeRunner : public NodeWalker
  {
  public :
    NodeRunner ();
    NodeRunner(const NodeRunner & iNrun); 
    NodeRunner (CATPolyPointsOctree &iOctree);

    void Init(CATPolyPointsOctree &iOctree);

    const Node *FatherNode() const;
    Position CurPosInFather() const;

    void SetCurNodeInFather(Node *iNewNode);

    virtual CATBoolean GoToChild(const Position iChildPos);
    CATBoolean GoToChild(const double *iPntInChild);

    NodeRunner GetChildRunner(const Position iPos) const;

    NodeRunner& operator=(const NodeRunner& nr);

  protected :
    void Init(Node *iRoot, const double *iRootOrigin, const double iRootSize);
    void Init(Node *iCurNode, const double *iCurOrigin, const double iRootSize,
      Node *iPrecNode = NULL, const Position iPrecPosition = DDD);

  private :
    Node  *_precNode;
    Position _precPos;
  };

  class ExportedByCATPolyCanonicOperators BranchRunner : public NodeRunner
  {
  public:
    BranchRunner (CATPolyPointsOctree &iOctree);
    BranchRunner (const BranchRunner &iBranchRun);
    ~BranchRunner();

    void GoToRoot();
    CATBoolean GoToFather();
    CATBoolean GoToBrother(const Position iBrotherPos);
    virtual CATBoolean GoToChild(const Position iChildPos);
#ifdef forCoverage
    CATBoolean GoToNeigh(Direction iDir);
#endif
    CATBoolean GetNeightPoints(Direction iDir, CATListOfInt &oPoints);
    CATBoolean NeighExist(Direction iDir);

  protected:
    void Init(CATPolyPointsOctree &iOctree);

    void InitGhostAscend();
    void InitGhostDescent();
    Position GhostPosInFather();
    CATBoolean GhostToFather();
    CATBoolean GhostToNeighAscend(Direction iDir, StackPosition &stackPos);
    CATBoolean GhostToNeighQuick(Direction iDir);
#ifdef forCoverage
    CATBoolean GhostToNeighSaveNode(Direction iDir);
#endif

  private:
    struct NodeData 
    {
      Node* _Node;
      double Size;
      double Origin[3];
      Position Pos;
    };

    NodeData *_branch;
    int _branchSize;
    int _posInBranch;

    NodeData *_ghostBranch;
    int _ghostBranchSize;
    int _ghostPosInBranch;
    int _ghostPosInGhostBranch;
    StackPosition _ghostBranchPos;
    NodeWalker _ghostWalk;
  };


  //-------------------------------------------------------------------------//
  //                           OCTREE Info                                   //
  //-------------------------------------------------------------------------//

  // Thread Safe
  class ExportedByCATPolyCanonicOperators Info
  {
  public:

    Info();
    Info(const Info &iInfo);
    ~Info();

    void Init();

    unsigned char Height() const;
    CATULONG64 MemSize() const;
    double MinSizeLeaf() const;
    CATULONG64 LeafCount() const;
    CATULONG64 LeafMaxPntCount() const;
    CATULONG64 LeafMinPntCount() const;

    void SetHeight(unsigned char iHeight);
    void SetMemSize(CATULONG64 iMemSize);
    void SetMinSizeLeaf(double iMinSizeLeaf);
    void SetLeafCount(CATULONG64 iLeafCount);
    void SetLeafMaxPntCount(CATULONG64 iLeafMaxPntCount);
    void SetLeafMinPntCount(CATULONG64 iLeafMinPntCount);

    void IncLeafCount(const CATULONG64 iIncVal = 1);
    void IncMemSize(const CATULONG64 iIncVal);

    void UpdateWithNewLeaf(const double iSize, const int iBranchSize,  const int iNbPnts);
    void UpdateWithNewBox();

    Info &operator= (const Info &iInfo);
    Info operator+ (const Info &iInfo);
    Info &operator+= (const Info &iInfo);

  private:
    unsigned char _maxBranchSize;
    CATULONG64 _leafCount;
    CATULONG64 _leafMinPointCount;
    CATULONG64 _leafMaxPointCount;
    double _leafSizeMin;
    CATULONG64 _memSize;


    CATCGMMutex *_MemMutex;
    CATCGMMutex *_AllButMemMutex;
  };


  //-------------------------------------------------------------------------//
  //                          OCTREE Builder                                 //
  //-------------------------------------------------------------------------//

  class BuilderCommonData
  {
  public:
    BuilderCommonData(const Strategy &iStrat, const int iMaxThread, 
      int *ioIdxs, double *ioCrds, Info &ioInfo);
    ~BuilderCommonData();

    CATBoolean ReserveThread();
    void ReleaseThread();

    int *GetIndexes() const;
    double *GetCoords() const;
    const Strategy &GetStrategy() const;
    Info &GetInfo() const;

    CATMathPoolThread *ThreadPool() const;

  private:
    int *_indexes;
    double *_coords;
    const Strategy &_IsLeaf;
    Info &_info;

    int _NbThread;
    int _MaxThread;
    CATCGMMutex *_ThreadMutex;
    //CATMutex _Mutex;

    CATMathPoolThread *_Pool;
  };

  //class BuilderPersonnalData
  //{
  //public:
  //  BuilderPersonnalData(const double *iOri, const double iSize, 
  //                       const int iBeg, const int iEnd, 
  //                       const int ioBranchSize, Node *&oNode, 
  //                       const BuilderCommonData &ioData);

  //  const double *Origin() const;
  //  const double Size() const;
  //  const int Beg() const;
  //  const int End() const;
  //  Node *& Node() const;
  //  const BuilderCommonData &Common() const;

  //  double *TmpCoords();
  //  int &TmpIdx();

  //  const int Num();

  //private:
  //  double _Ori[3], _Size;
  //  int _Beg, _End, _Height;
  //  Node *&_Node;
  //  
  //  const BuilderCommonData &_Common;

  //  double tmpCoords[3];
  //  int tmpIdx;
  //}


  class Builder  : CATBaseComputation
  {
  public:
    Builder(const double *iOri, const double iSize, 
      const int iBeg, const int iEnd, 
      const int ioBranchSize, Node *&oNode, const BuilderCommonData &ioData);
    virtual ~Builder();

    void Run (silla bid);

    void BuildParallelAtLevel(const int iLevel);

  private:
    Builder(const double *iFOri, const Position iPosInFather, 
      const double iSize, const int iBeg, const int iEnd, 
      const int ioBranchSize, Node *&oNode, const BuilderCommonData &ioData);

    void Build(const double *iOri, const double iSize, 
      const int iBeg, const int iEnd, 
      const int iHeight,  Node *&oNode);

    void SortByPos(const double *iOri, const short iXYZ, 
      const int iBeg, const int iEnd, int &oEnd, int &oBeg);
    void SortByPos(const double *iOri, const int iBeg, const int iEnd,
      int oBeg[8], int oEnd[8]);


    double _Ori[3], _Size;
    int _Beg, _End, _Height;
    Node *&_Node;

    const BuilderCommonData &_Common;

    CATBoolean _IAmAThread;
    CATBoolean _MySonAreThread;
    int _BreakLevel;
    //CATListPV _DataLevel;


    double tmpCoords[3];
    int tmpIdx;

    //debug
    int _num;
    const int Num();
  };



  //-------------------------------------------------------------------------//
  //                              OCTREE                                     //
  //-------------------------------------------------------------------------//

  CATPolyPointsOctree();
  ~CATPolyPointsOctree();

  // File 
  void Load(const char *iFileName);

  // Build 

  void Build(const int iNbPt, int *ioIndexes, double *ioCoords, Strategy &iStrategy); 

  // Modify
#ifdef forCoverage
  void Add(const double *iPnt, const int iIdx);
  void Remove(const double *iPnt, const int iIdx);
#endif

  // Gestion racine
  inline const double *RootOrigin() const;
  inline double RootSize() const;
  Node *Root();

  void RemoveRoot();

  // Info
  const Info& GetInfo() const;

  // Outils
  static void CalcChildPos(const double *iPnt, const double *iOrigin, Position &oPosition);
  static void CalcChildOri(const Position iPos, const double *iFOrigin,  const double iCSize, double *oCOrigin);

  inline static Position NeighPos(const Position iPos, const Direction);
  inline static Type NeighType(const Position iPos, const Direction);
  inline static Direction FatherDir(const Position iPos, const Direction);
 

private:

  void CalcRootOriginAndSize();
  void InitBuild(const int iNbIdx, int *ioIndexes, double *ioCoords,
    Strategy &iStrategy);
  void StartBuild();
  void FinalizeBuild();

  void SortByPos(const double *iOrigin, const short iXYZ,
    const int iBeg, const int iEnd, int &oEnd, int &oBeg);
  void SortByPos(const double *iOri, const int iBeg, const int iEnd,
    int oBeg[8], int oEnd[8]);
  Node* BuildRec(const double *iOri, const double iSize,
    const int iBeg, const int iEnd, const int ioBranchSize);

  // Modify
  CATBoolean OutOfRoot(const double *iPnt);
  CATBoolean OnlyOneChild(const Node &iNode, CATPolyPointsOctree::Position &oChild);
  CATBoolean NoChild(const Node &iNode);

  // Racine
  Node  *_root;
  double _rootOriCoords[3];
  double _rootSize;

  // Info
  Info _Info;

  // Nuage de points  
  double *_Coords;
  int *_Indexes;
  int _nbIdx;

  int tmpIdx;
  double tmpCoords[3];

  // Strategie pour la construction
  Strategy _IsLeaf;
};


//------------------------------------------------------------------------------
// INLINE Strategy
inline CATBoolean CATPolyPointsOctree::Strategy::operator()(const double *iOrigin, 
                                                     const double iSize, 
                                                     const int iNbPnt) const
{
  return IsLeaf(iOrigin, iSize, iNbPnt);
}

inline CATBoolean CATPolyPointsOctree::Strategy::IsLeaf(const double *iOrigin, 
                                                 const double iSize, 
                                                 const int iNbPnt) const
{
  switch(_strat) {
case AND : return iNbPnt <= _maxCount && iSize < _minBorne;
case OR : return iNbPnt <= _maxCount || iSize <= _minSize;
case SIZE : return iSize <= _minSize;
case COUNT : return iNbPnt <= _maxCount;
  }
  return TRUE;
}

// INLINE NodeWalker
inline CATBoolean CATPolyPointsOctree::NodeWalker::GoToChild(const Position iChildPos)
{
  if (_curNode == NULL || _curNode->IsLeaf()) return FALSE;

  _curSize /= 2;
  CATPolyPointsOctree::CalcChildOri(iChildPos, _curOrigin, _curSize, _curOrigin);
  _curNode = _curNode->GetChild(iChildPos);

  return TRUE;
}

inline CATBoolean CATPolyPointsOctree::NodeWalker::GoToChild(const double *iPntInChild)
{
  Position childPos;
  CATPolyPointsOctree::CalcChildPos(iPntInChild, _curOrigin, childPos);
  return GoToChild(childPos);
}

inline CATBoolean CATPolyPointsOctree::NodeWalker::GoToLeaf(const double *iPntInChild)
{
  while(GoToChild(iPntInChild));
  return _curNode != NULL && _curNode->IsLeaf();
}

inline CATBoolean CATPolyPointsOctree::NodeWalker::GoToLeaf(const double *iPntInChild, 
                                                     CATListOfInt &oPointIndex)
{
  if (! GoToLeaf(iPntInChild)) return FALSE;
  _curNode->GetPoint(oPointIndex);
  return TRUE;
}
//------------------------------------------------------------------------------




class ExportedByCATPolyCanonicOperators CATPolyPointsOctreeOper
{
public :

  //CATPolyPointsOctreeOper (CATCloudBody *iCloudBody) ;
  CATPolyPointsOctreeOper ();
  ~CATPolyPointsOctreeOper ();

  enum Strategy {AND, OR};

  void BuildOctree(int inbIdx, int *iIndexes, double *iCoords, const double iSize);
  void BuildOctree(int inbIdx, int *iIndexes, double *iCoords, const int iCount);
  void BuildOctree(int inbIdx, int *iIndexes, double *iCoords, const double iSize, const int iCount);
  void BuildOctree(int inbIdx, int *iIndexes, double *iCoords, const double iSize, const int iCount, const Strategy iStrat);

  void UpdateNeighbour() ;
    
  void DrawOctree(const int iLevel, CATListPV &oLine);
  int GetOctreeHeight();
  void GetOctreeSpec(unsigned char &oHeight, CATULONG64 &oNbLeaf, double &oMinSize, double &oMaxSize, 
                     CATULONG64 &oMinCount, CATULONG64 &oMaxCount, double &oTime, double &oCPUTime, CATULONG64 &oMemSize);

  void GetOctree(CATPolyPointsOctree *&oOctree) ;

  void GetPlanarSection(const CATMathPlane &iPlan, const double iTol, CATListOfInt &oIdx);
  void GetPlanarSection(const CATMathPlane &iPlan, CATPolyPointsOctree &iOctree, const double iTol, CATListOfInt &oIdx);

  void GetNeighborLeaf(const int iNumLeaf, CATListOfInt &oListOfNeighb) ;// les feuilles voisines dans les 6 directions
  void GetOneRingOfLeaf(const int iNumLeaf, CATListOfInt &oListOfNeighb) ; // toutes les feuilles voisines autour 

  void GetOneRing(const int iIdx, CATListOfInt &oNeighIdx) ; // tous les points des feuilles voisines autour de la feuille

  void GetLeaf (const int iIdx, int &oNumLeaf);
  void GetNeighborhood (const int iIdx, CATListOfInt &oNeighIdx);
  void GetNeighborhood (const int iIdx, const CATMathVector &iDir, CATListOfInt &oNeighIdx);

  void GetLeaf(int iNumLeaf, CATListOfInt &oListOfPoints) ;
  void GetAllLeaves(int &oNbLeaf, CATListOfInt *&oTabOfLeaf) ;

protected:
  void BuildOctree(int inbIdx, int *iIndexes, double *iCoords);
  void GetPlanarSection(const CATPolyPointsOctree::NodeWalker nw, const CATMathPlane &iPlan, const double iTol, 
                               CATListOfInt &oIdx);

  void ConvertVectorToDir(const CATMathVector &iDir, const CATPolyPointsOctree::Direction *&oDir, int &oNbDir);
 
private:

  // Affichage
  void DrawRec(const CATPolyPointsOctree::NodeWalker iRun, const int iLevel, CATListPV &oLine);
  void DrawCube(const double *iCenterCoords, const double size, CATListPV &oLine);
  void DrawLine(const double *iFirstCoords, const double *iSecondCoords, CATListPV &oLine);

  //CATPolyPointsBody *_Body; 
  double *_Coords;
  int *_Indexes;
  int _nbIdx; 
 
  CATBoolean _UpdateIsOK ;
  CATListOfInt *_TabOfLeaf ;
  int _NbLeaf ;
  int *_IndexOfPointsInOctree ;

  CATPolyPointsOctree *_Octree;
  CATPolyPointsOctree::Strategy _OctreeStrat;

  CATBoolean _octreeIsToDelete;

  double _buildTime, _buildCPUTime;
};


#endif






