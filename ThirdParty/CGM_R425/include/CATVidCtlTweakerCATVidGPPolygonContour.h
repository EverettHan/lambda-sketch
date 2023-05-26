#ifndef CATVidCtlTweakerCATVidGPPolygonContour_h
#define CATVidCtlTweakerCATVidGPPolygonContour_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>
#include <CATVidGPPolygonContour.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidGPPolygonContour : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidGPPolygonContour);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATVidGPPolygonContour();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetPointsByString(const CATUnicodeString& i_points);
  CATUnicodeString GetPointsByString() const;

  void SetCircleRadius(const double& i_CircleRadius);
  double GetCircleRadius() const;
  void SetSag(const double& i_Sag);
  double GetSag() const;
 
  void CreateCircleCB(const CATUnicodeString& i_eventName, const CATBaseUnknown_var & i_input, CATBaseUnknown_var & i_spArgs);
  void CreateStarCB(const CATUnicodeString& i_eventName, const CATBaseUnknown_var & i_input, CATBaseUnknown_var & i_spArgs);
  void CreatePieCB(const CATUnicodeString& i_eventName, const CATBaseUnknown_var & i_input, CATBaseUnknown_var & i_spArgs);
  void CreateDonutCB(const CATUnicodeString& i_eventName, const CATBaseUnknown_var & i_input, CATBaseUnknown_var & i_spArgs);

  void SetStarBigRadius(const double& i_StarBigRadius);
  double GetStarBigRadius() const;
  void SetStarLittleRadius(const double& i_StarLittleRadius);
  double GetStarLittleRadius() const;
  void SetStarNbBranchs(const int& i_StarNbBranchs);
  int GetStarNbBranchs() const;

  void SetPieRadius(const double& i_Radius);
  double GetPieRadius() const;
  void SetPieSag(const double& i_Sag);
  double GetPieSag() const;
  void SetPieStartAngleInDegree(const int& iStartAngleInDegree);
  int GetPieStartAngleInDegree() const;
  void SetPieAngleInDegree(const int& iAngleInDegree);
  int GetPieAngleInDegree() const;

  void SetDonutBigRadius(const double& i_bigRadius);
  double GetDonutBigRadius() const;
  void SetDonutLittleRadius(const double& i_littleRadius);
  double GetDonutLittleRadius() const;
  void SetDonutSag(const double& i_Sag);
  double GetDonutSag() const;
  void SetDonutStartAngleInDegree(const int& iStartAngleInDegree);
  int GetDonutStartAngleInDegree() const;
  void SetDonutAngleInDegree(const int& iAngleInDegree);
  int GetDonutAngleInDegree() const;

protected:

  virtual ~CATVidCtlTweakerCATVidGPPolygonContour();

  // Overriden methods
  virtual void OnValueChanged();

private:
   void CreateCircle();
   void CreateStar();
   void CreatePie();
   void CreateDonut(); 

  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidGPPolygonContour (CATVidCtlTweakerCATVidGPPolygonContour &);
  CATVidCtlTweakerCATVidGPPolygonContour& operator=(CATVidCtlTweakerCATVidGPPolygonContour& original);

private:

  double _Sag;
  double _CircleRadius;
  double _StarBigRadius;
  double _StarLittleRadius;
  int _StarNbBranchs;
  
  double _PieSag; 
  double _PieRadius;
  int _PieStartAngleInDegree;
  int _PieAngleInDegree;

  double _DonutSag; 
  double _DonutLittleRadius;
  double _DonutBigRadius;
  int _DonutStartAngleInDegree;
  int _DonutAngleInDegree;

  CATUnicodeString _pointsByString;
};

#endif // CATVidCtlTweakerCATVidGPPolygonContour_h
