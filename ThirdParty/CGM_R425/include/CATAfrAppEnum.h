#ifndef CATAfrAppEnum_H
#define CATAfrAppEnum_H

// COPYRIGHT Dassault Systemes 2012
#include "CATAfrItf.h"
#include "CATSYPHashMap.h"


class ExportedByCATAfrItf CATAfrAppEnum
{
  public:

/**
    * Type of quadrant
    */
    enum Quadrant
    {
      _West =0, /*The App is in west quadrant*/
      _North =1, /*The App is in north quadrant*/
      _East=2, /*The App is in east quadrant*/
      _South = 3,/*The App is in south quadrant*/
      _None = 4
    };

        /**
    * Type of App
    */
    enum Type 
    {
      Native      = 0, /* the app starts a workbench */
      Web   = 1, /* the app launch a web page in the user browser*/
      Command = 2, /* @deprecated, used for PLM BI Essential*/
      Widget = 3, /* the app acts like a Web but this is a widget app*/
      Role = 4 /* this "app" is a role*/
    };

   /**
    * Type of Section 
    */
    enum TypeSection 
    {
      MYA      = 0, /*MyApps*/
      LMA   = 1     /* Learn More About */
    };
          /**
    * Origin of the App 
    */
    enum Origin 
    {
      MyApps=0, /*The App is come from MyApps server*/
      Packaging, /*The App is come from Packaging, used for test (TSP_PROVIDER)*/
      Development, /*The App is come from Development*/
      Unknown /*The App is come from an unknown source*/
    };


};

/**
 * Specialization of CATSYPHashMapHasher for CATAfrAppEnum::Quadrant to allow
 * using CATAfrAppEnum::Quadrant as key in CATSYPHashMap container.
 */
template <> struct CATSYPHashMapHasher<CATAfrAppEnum::Quadrant> 
{
public:
  int ComputeHash(const CATAfrAppEnum::Quadrant & i_key) {
    return static_cast<int>(i_key);
  }
};

#endif
