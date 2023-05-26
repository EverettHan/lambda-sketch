#ifndef _CATBasicBoxing_H
#define _CATBasicBoxing_H

// IntrospectionInfrastructure
#include <IntroInfra.h>
#include <CATSYPDeclareBoxing.h>
#include <CATSYPBoxingComparator.h>
#include <CATSYPProperties.h>

// System
#include <CATUnicodeString.h>
#include <CATString.h>
#include <CATListOfCATString.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATLISTV_CATMathPoint2Df.h>
#include <CATLISTV_CATMathPointf.h>
#include <CATLISTV_CATMathVector2Df.h>
#include <CATDataType.h>
#include <CATBinary.h>
#include <CATTime.h>
#include <CATListOfInt.h>
#include <CATListOfDouble.h>
#include <CATListOfCATUnicodeString.h>

// Mathematics
#include <CATMathPoint2D.h>
#include <CATMathPoint2Df.h>
#include <CATMathDirection2Df.h>
#include <CATMathVector2Df.h>
#include <CATMathPointf.h>
#include <CATMathPoint.h>
#include <CATMathDirection.h>
#include <CATMathDirectionf.h>
#include <CATMathVectorf.h>
#include <CATMathQuaternion.h>
#include <CATMathVector.h>
#include <CATSYPHashMap.h>
#include <CATMathLine.h>
#include <CATMathAxis.h>
#include <CATMathPlane.h>
#include <CATMathTransformation.h>
#include <CATLISTV_CATMathVector.h>
#include <CATLISTV_CATMathPlane.h>
#include <CATLISTP_CATMathAxis.h>



/**
 * Specialization of CATSYPBoxingComparator for CATMathPoint2D.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathPoint2D>
{
  int AreEqual(const CATMathPoint2D &i_value1, const CATMathPoint2D &i_value2) {
    CATSYPHashMapComparator<double> comparator;
    return (comparator.AreEqual(i_value1.GetX(), i_value2.GetX()) && comparator.AreEqual(i_value1.GetY(), i_value2.GetY()));
  }
};
/**
 * Specialization of CATSYPBoxingComparator for CATMathPoint2Df.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathPoint2Df>
{
  int AreEqual(const CATMathPoint2Df &i_value1, const CATMathPoint2Df &i_value2) {
    CATSYPHashMapComparator<float> comparator;
    return (comparator.AreEqual(i_value1.x, i_value2.x) && comparator.AreEqual(i_value1.y, i_value2.y));
  }
};
/**
 * Specialization of CATSYPBoxingComparator for CATMathDirection2Df.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathDirection2Df>
{
  int AreEqual(const CATMathDirection2Df &i_value1, const CATMathDirection2Df &i_value2) {
    CATSYPHashMapComparator<float> comparator;
    return (comparator.AreEqual(i_value1.x, i_value2.x) && comparator.AreEqual(i_value1.y, i_value2.y));
  }
};/**
 * Specialization of CATSYPBoxingComparator for CATMathVector2Df.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathVector2Df>
{
  int AreEqual(const CATMathVector2Df &i_value1, const CATMathVector2Df &i_value2) {
    CATSYPHashMapComparator<float> comparator;
    return (comparator.AreEqual(i_value1.x, i_value2.x) && comparator.AreEqual(i_value1.y, i_value2.y));
  }
};
/**
 * Specialization of CATSYPBoxingComparator for CATMathPointf.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathPointf>
{
  int AreEqual(const CATMathPointf &i_value1, const CATMathPointf &i_value2) {
    CATSYPHashMapComparator<float> comparator;
    return (comparator.AreEqual(i_value1.x, i_value2.x) && comparator.AreEqual(i_value1.y, i_value2.y) && comparator.AreEqual(i_value1.z, i_value2.z));
  }
};
template <> struct CATSYPBoxingComparator<CATMathPoint>
{
  int AreEqual(const CATMathPoint &i_value1, const CATMathPoint &i_value2) {
    CATSYPHashMapComparator<double> comparator;
    return (comparator.AreEqual(i_value1.GetX(), i_value2.GetX()) && comparator.AreEqual(i_value1.GetY(), i_value2.GetY()) && comparator.AreEqual(i_value1.GetZ(), i_value2.GetZ()));
  }
};
template <> struct CATSYPBoxingComparator<CATMathDirection>
{
  int AreEqual(const CATMathDirection &i_value1, const CATMathDirection &i_value2) {
    CATSYPHashMapComparator<double> comparator;
    return (comparator.AreEqual(i_value1.GetX(), i_value2.GetX()) && comparator.AreEqual(i_value1.GetY(), i_value2.GetY()) && comparator.AreEqual(i_value1.GetZ(), i_value2.GetZ()));
  }
};
template <> struct CATSYPBoxingComparator<CATMathDirectionf>
{
  int AreEqual(const CATMathDirectionf &i_value1, const CATMathDirectionf &i_value2) {
    CATSYPHashMapComparator<double> comparator;
    return (comparator.AreEqual(i_value1.x, i_value2.x) && comparator.AreEqual(i_value1.y, i_value2.y) && comparator.AreEqual(i_value1.z, i_value2.z));
  }
};
/**
 * Specialization of CATSYPBoxingComparator for CATMathVectorf.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathVectorf>
{
  int AreEqual(const CATMathVectorf &i_value1, const CATMathVectorf &i_value2) {
    CATSYPHashMapComparator<float> comparator;
    return (comparator.AreEqual(i_value1.x, i_value2.x) && comparator.AreEqual(i_value1.y, i_value2.y) && comparator.AreEqual(i_value1.z, i_value2.z));
  }
};
/**
 * Specialization of CATSYPBoxingComparator for CATMathQuaternion.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathQuaternion>
{
  int AreEqual(const CATMathQuaternion &i_quat1, const CATMathQuaternion &i_quat2) {
    CATSYPHashMapComparator<double> comparator;
    double scal1, x1, y1, z1;
    i_quat1.GetCoord(scal1, x1, y1, z1);
    double scal2, x2, y2, z2;
    i_quat2.GetCoord(scal2, x2, y2, z2);
    return (comparator.AreEqual(scal1, scal2) && comparator.AreEqual(x1, x2) && comparator.AreEqual(y1, y2) && comparator.AreEqual(z1, z2));
  }
};
/**
 * Specialization of CATSYPBoxingComparator for CATMathVector.
 * See CATSYPBoxingComparator documentation for details.
 */
template <> struct CATSYPBoxingComparator<CATMathVector>
{
  int AreEqual(const CATMathVector &i_value1, const CATMathVector &i_value2) {
    return (i_value1.GetX()==i_value2.GetX() && i_value1.GetY()==i_value2.GetY() && i_value1.GetZ()==i_value2.GetZ());
  }
};

template <> struct CATSYPBoxingComparator<CATMathAxis>
{
  int AreEqual(const CATMathAxis &i_value1, const CATMathAxis &i_value2) {
    CATSYPBoxingComparator<CATMathPoint> comparatorPoint;
    CATSYPBoxingComparator<CATMathVector> comparatorVector;

    CATMathPoint pOrigin1 = i_value1.GetOrigin();
    CATMathPoint pOrigin2 = i_value2.GetOrigin();

    CATMathVector pDir11,pDir12,pDir13;
    i_value1.GetDirections(pDir11,pDir12,pDir13);

    CATMathVector pDir21,pDir22,pDir23;
    i_value2.GetDirections(pDir21,pDir22,pDir23);

    return (comparatorPoint.AreEqual(pOrigin1, pOrigin2) && comparatorVector.AreEqual(pDir11, pDir21) && comparatorVector.AreEqual(pDir12, pDir22) && comparatorVector.AreEqual(pDir13, pDir23));
  }
};

template <> struct CATSYPBoxingComparator<CATMathPlane>
{
  int AreEqual(const CATMathPlane &i_value1, const CATMathPlane &i_value2) {
    CATSYPBoxingComparator<CATMathPoint> comparatorPoint;
    CATSYPBoxingComparator<CATMathVector> comparatorVector;

    CATMathPoint pOrigin1 = i_value1.GetOrigin();
    CATMathPoint pOrigin2 = i_value2.GetOrigin();

    CATMathVector pDir1N;
    i_value1.GetNormal(pDir1N);

    CATMathVector pDir2N;
    i_value2.GetNormal(pDir2N);

    return (comparatorPoint.AreEqual(pOrigin1, pOrigin2) && comparatorVector.AreEqual(pDir1N, pDir2N));
  }
};

template <> struct CATSYPBoxingComparator<CATMathTransformation>
{
  int AreEqual(const CATMathTransformation &i_value1, const CATMathTransformation &i_value2) {
    double Coef1[12], Coef2[12];
    i_value1.GetCoefficients(Coef1); 
    i_value2.GetCoefficients(Coef2);
    CATSYPHashMapComparator<double> comparator;
    int i=0, result=1;
    while(i<12 && result)
    {
      if(!comparator.AreEqual(Coef1[i], Coef2[i]))
      {
        result = 0; 
        break;
      }
      i++;
    }
    return result;
  }
};


template <> struct CATSYPBoxingComparator<CATMathLine>
{
  int AreEqual(const CATMathLine &i_value1, const CATMathLine &i_value2) {
    CATSYPBoxingComparator<CATMathPoint> comparatorPoint;
    CATSYPBoxingComparator<CATMathVector> comparatorVector;

    CATMathPoint pOrigin1 = i_value1.GetOrigin();
    CATMathPoint pOrigin2 = i_value2.GetOrigin();

    CATMathVector pDir1 = i_value1.GetDirection();
    CATMathVector pDir2 = i_value2.GetDirection();

    return (comparatorPoint.AreEqual(pOrigin1, pOrigin2) && comparatorVector.AreEqual(pDir1, pDir2));
  }
};

inline int operator == (const CATMathVectorf &iVector1, const CATMathVectorf &iVector2)
{
	return ( iVector1.x==iVector2.x && iVector1.y==iVector2.y && iVector1.z==iVector2.z) ;
}
inline int operator != (const CATMathVectorf &iVector1, const CATMathVectorf &iVector2)
{
	return ( !(iVector1==iVector2) );
}

/*inline int operator == (const CATAngle &iAngle1, const CATAngle &iAngle2)
{
	return ( iAngle1==iAngle2 ) ;
}
inline int operator != (const CATAngle &iAngle1, const CATAngle &iAngle2)
{
	return ( !(iAngle1==iAngle2) );
}*/


// C++ types
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, int );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, float );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, double );

// System
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATLONG64 );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATULONG64 );
CATSYP_DECLARE_BOXING(ExportedByIntroInfra, CATUnicodeChar);

//Migration necessaire de StudioAssembleUI\StudioAssembleEditors.m\src\StugTreeViewController.cpp pour ne plus utiliser le constructeur, mais la m�thode Box.
class ExportedByIntroInfra CATBoxingOfCATUnicodeString : public CATISYPValues
{
	CATDeclareClass;
public:
	CATBoxingOfCATUnicodeString(const CATUnicodeString &iValue);
	~CATBoxingOfCATUnicodeString();
	const CATUnicodeString _value;
	static CATBaseUnknown_var Box(const CATUnicodeString &iValue);
	static HRESULT Unbox(const CATBaseUnknown_var &i_spReference, CATUnicodeString &oValue);
	int Equals(const CATBaseUnknown_var& i_spCBU);
	const char* GetType()
	{
		return "CATUnicodeString";
	}
	int BinaryStream(CATSYPCodedOutputStream &i_outputStream);
	static CATBoxingOfCATUnicodeString *BinaryUnstream(CATSYPCodedInputStream &i_inputStream);
private:
	CATBoxingOfCATUnicodeString(const CATBoxingOfCATUnicodeString &iValue) PREVENT_IMPLEMENTATION;
};
//CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATUnicodeString );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATString );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListOfCATString );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListOfCATUnicodeString );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListValCATBaseUnknown_var);
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATBinary);
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATTime);

// Mathematics
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathPointf );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathPoint );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathLine );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathAxis );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathPlane );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathDirection );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathDirectionf );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathPoint2D );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathPoint2Df );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathDirection2Df );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathVector2Df );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathVectorf );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathVector );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATAngle );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathQuaternion );

// This one had been commented for an KNOWN reason (yes, there was a good one ?)
// ProductStructureUI\PrivateInterfaces\CATPrsMoveBarModel.h declare it already.
// Migration path :
//- Phase 1 :
//Tu ajoutes la d�claration dans CATBasicBoxing.h sous un define non activ� (� nous donner)
//#if TONDEFINE
//                Ton code
//#endif
//
//-	Phase 2 : j�inclus dans CATPrsMoveBarModel.h 
//
//#include �CATBasicBoxing.h�
//#if TONDEFINE
//                rien
//#else
//Mo
//#endifn code
//
//-	Phase 3 :
//                Tu actives ton define dans CATBasicBoxing.h
//#define TONDEFINE
//
//-	Phase 4 :
//                Quand phase 3 en R216rel :
//                On ne conserve que l�inclusion de ton header 
//#include � CATBasicBoxing.h � 
//#if TONDEFINE
//                rien
//#else
//Mon code
//#endif
//
//- Phase 5 :
//Quand phase 4 en R216rel :
//Tu supprimes de CATBasicBoxing.hc
//#define TONDEFINE
//
//
#define CATBasicBoxing_PSUI_Migration 1
#ifdef CATBasicBoxing_PSUI_Migration
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATMathTransformation );
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListOfInt);
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListValCATMathVector);
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListValCATMathPlane);
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListPtrCATMathAxis);
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATListOfDouble);
#endif

// IntrospectionInfrastructure
CATSYP_DECLARE_BOXING( ExportedByIntroInfra, CATSYPProperties );

CATSYP_DECLARE_BOXING_WITH_ALIAS(ExportedByIntroInfra, vector_double, std::vector<double>);

#endif
