// --------------------------------------------------------
// COPYRIGHT Dassault Systemes 2003
//===================================================================
// CATGeoTopoSurfacicProgressBar.h
//	
//===================================================================
//
//  Sept 2003   KTU : creation
//===================================================================

#ifndef CATGeoTopoSurfacicProgressBar_H
#define CATGeoTopoSurfacicProgressBar_H
#include "GeoPlate.h"


typedef void (*GeoTopoProgressBarEvolFunction)();

class ExportedByGeoPlate CATGeoTopoSurfacicProgressBar
{
public:

   /**
    */
   CATGeoTopoSurfacicProgressBar( );
   CATGeoTopoSurfacicProgressBar( GeoTopoProgressBarEvolFunction iFunc, unsigned short iNbTops, unsigned short iNbSteps );
   
   /**
    */
   ~CATGeoTopoSurfacicProgressBar( );
   
   /**
    */
   short Increased( unsigned short iStep );

   /**
    */
   GeoTopoProgressBarEvolFunction GetFunction() { return _func; }

   /*
    */
   short Set( GeoTopoProgressBarEvolFunction iFunc, unsigned short iNbTops, unsigned short iNbSteps );


private:
   
   GeoTopoProgressBarEvolFunction _func;      
   unsigned short _delta; 
   unsigned short _nextTop;
   unsigned short _nbTopRestant;
   unsigned short _resDelta;

};


#endif
