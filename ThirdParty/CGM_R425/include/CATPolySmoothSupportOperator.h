#ifndef CATPolySmoothSupportOperator_H
#define CATPolySmoothSupportOperator_H

#include "AdvTopoOpeItf.h"

#include "CATMathVector.h"
#include "CATMathTransformation.h"
#include "CATCGMSharedPtr.h"
#include "CATMathPoint2D.h"

#include <vector>


class CATIPolyMesh;
class CATPolyPolygon2D;

/**
* Class that build the polyhedral "fillet" - a mesh from a set of polygons offseted
*/
class ExportedByAdvTopoOpeItf CATPolySmoothSupportOperator
{
  public: 

    void SetGMTolerance(const CATTolerance& iTolerance);
    void SetHeight(double iH);
    double GetHeight() const ;
    void SetOffset(double iOffest) ;
    double GetOffset()const ;
    //void SetDirection(CATMathVector iDirection) ;
    //CATMathVector GetDirection() const  ;
    
    //void SetScalingParam(double ScaleX,double scaleY, CATMathPoint2D & ScalingCenter);
    
    void SetTransformation(CATMathTransformation iTransfo);
    CATMathTransformation GetTransformation() const;

    void SetCloseBottom(bool iClose,CATPolyPolygon2D * iToRemove=nullptr);
    void SetCloseTop(bool iClose);
    bool GetCloseBottom() const;
    bool GetCloseTop() const;
    
    
    virtual CATCGMSharedPtr<CATIPolyMesh> Run(
      std::vector<CATMathPoint> iBotPoints,std::vector<CATMathPoint> iTopPoints,
      std::vector<CATPolyPolygon2D*> * oBorders =nullptr) ;
    
  protected:
    virtual double ComputeOffsetFromZ(double h) = 0;

    CATPolyPolygon2D * Analyse(std::vector<CATMathPoint> & iBotPoints,std::vector<CATMathPoint> &iTopPoints, bool & oInside,std::vector<CATMathVector> &oDirections);
    
    //data 
    const CATTolerance* _GMTolerance = nullptr;
    double _Height = 5.0;
    double _Offset = 5.0;
    CATMathVector _Direction = CATMathVector(0,0,1);
    CATMathTransformation _Transfo;
    double _ScaleRatioX=1;
    double _ScaleRatioY=1;
    double _ScaleStartX=0;
    double _ScaleStartY=0;
    CATMathPoint2D _ScalingCenter;

    bool _CloseBot=false;
    bool _CloseTop=false;
    CATPolyPolygon2D* _CloseBotRemove=nullptr;

};


#endif //CATPolySmoothSupportOperator_H
