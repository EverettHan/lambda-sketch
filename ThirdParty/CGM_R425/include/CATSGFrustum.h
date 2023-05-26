#ifndef CATSGFRUSTUM_H
#define CATSGFRUSTUM_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATSGGenVec3.h"
#include "CATAABox.h"

class CAT3DViewpoint;

//namespace CATSG
//{
//    class ExportedBySGComposites CATSGFrustumData
//    {
//    private:
//        CATSG::CATSGDPoint _verticies[8];
//        double _a[6];
//        double _b[6]; 
//        double _c[6];
//        double _d[6];
//
//    public:
//        CATSGFrustumData(){}
//
//        CATSGFrustumData(const double (&iA)[6], const double (&iB)[6], const double (&iC)[6], const double (&iD)[6]);
//        CATSGFrustumData(double iNear, double iFar, double iFovInDegree, double iHWRatio, const CATSG::CATSGDVec3& iUp, const CATSG::CATSGDPoint& iEye, const CATSG::CATSGDVec3& iSight);
//
//        void GetVerticies(CATSG::CATSGDPoint (&oVerticies)[8]) const;
//        void GetPlanes(double (&oA)[6], double (&oB)[6], double (&oC)[6], double (&oD)[6]) const;
//
//        bool SetFromViewpoint(CAT3DViewpoint* iViewpoint);
//
//        bool GetAABox(CATAABox& oBox) const;
//
//        bool Intersect(const CATAABox& iBox) const;
//        bool Intersect(const CATSG::CATSGDVec3& center, float radius) const;
//    };
//}

#endif//SG_COMPOSITES_MULTIOS
#endif//CATSGFRUSTUM_H
