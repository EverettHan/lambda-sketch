#ifndef CATDLGCONTROL_H
#define CATDLGCONTROL_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialog.h"
#include "CATBoolean.h"


class CATString;
class CATDlgContextualMenu;

#ifndef CATDlgControl_ADD
/** @nodoc */
#define CATDlgControl_ADD
#endif

#ifndef CATDlgControl_LateADD
/** @nodoc */
#define CATDlgControl_LateADD
#endif

/** 
 * Base class for dialog controls.
 * <b>Role</b>:
 * This class is the control base class to share unit and contextual menu management. Its derived classes can be :
 * <MENU>
 * <LI>for the controls : @href CATDlgCheckButton, @href CATDlgCombo, @href CATDlgEditor, @href CATDlgMultiList, @href CATDlgPushButton,
 * @href CATDlgRadioButton, @href CATDlgScrollBar, @href CATDlgSelectorList, @href CATDlgSlider, @href CATDlgSpinner 
 * <LI>and for the indicators: @href CATDlgLabel, @href CATDlgProgress, @href CATDlgSeparator.
 * </MENU>
 * <br>
 * The parent of an instance of a class that derives from CATDlgControl must be an instance 
 * of a class that derives from @href CATDlgDocument, @href CATDlgDialog,  @href CATDlgBox and 
 * @href CATDlgToolBar. Some controls can have a @href CATDlgStatusBar or a @href CATDlgIconBox as parent.
 * <br>
 * This class can not be instantiated.
 */
class ExportedByDI0PANV2 CATDlgControl : public CATDialog
{

 public:
 
 				/**
 				 * Possible units for control.
 				 * @param Decapoise,Poise,Centipoise,Millipoise,Micropoise,LbfSecondPerSqFt,LbfSecondPerSqIn,PoundPerSecondFoot
 				 * Absolute viscosity units.
 				 * @param MeterPerSquareSecond,FootPerSquareSecond,InchPerSquareSecond
 				 * Acceleration units.
 				 * @param Radian,Degree,Grade
 				 * Angle units.
 				 * @param SquareMeter,SquareMillimeter,SquareCentimeter,SquareInch,SquareFoot
 				 * Area units.
 				 * @param KilogramPerM3,PoundPerCubicFoot,PoundPerCubicInch
 				 * Volumic mass units.
 				 * @param Fraction,Percentage,PartPerMillion
 				 * Dissolved solid fraction units.
 				 * @param Joule,WattXHour,BritishThermalUnit,PoundforceXFoot
 				 * Energy units.
 				 * @param Newton,Poundforce
 				 * Force units.
 				 * @param JoulePerKelvin,BtuPerFahrenheit
 				 * Heat capacity units.
 				 * @param Meter4,Millimeter4,Centimeter4,Inch4,Foot4
 				 * Inertia units.
 				 * @param SquareMeterPerSecond,Stoke,SquareFootPerSecond
 				 * Kinematic viscosity units.
 				 * @param Meter,Micrometer,Millimeter,Centimeter,Kilometer,Inch,Foot,FeetInchFraction64,FeetInchFraction16,FeetInchDecimal
 				 * Length units.
 				 * @param KilogramPerMeter,PoundPerFoot,PoundPerInch
 				 * Linear mass units.
 				 * @param NewtonPerMeter,PoundforcePerFoot,PoundforcePerInch
 				 * Lineic force units.
 				 * @param Kilogram,Gram,Ton,Pound
 				 * Mass units.
 				 * @param KilogramPerSecond,PoundPerHour,KilogramPerHour,PoundPerMinute
 				 * Massic flow units.
 				 * @param KilogramPerMole,GramPerMole
 				 * Molecular weight units.
 				 * @param NewtonXMeter,PoundforceXInch,NewtonXMillimeter
 				 * Moment units.
 				 * @param NewtonPerSquareMeter,Pascal,LbforcePerSquareInch
 				 * Pressure units.
 				 * @param NewtonMeterPerRadian,NewtonMMPerMradian,PoundforceInchPerRad
 				 * Angular stiffness units.
 				 * @param SlopeRatio,SlopePercentage,SlopeInCmPerM,SlopeInMMPerM,SlopeInInchPerFoot
 				 * Slope units.
 				 * @param MeterPerSecond,FootPerSecond,MilePerHour,KilometerPerHour,FootPerMinute,FootPerHour
 				 * Speed units.
 				 * @param JoulePerKgKelvin,BtuPerLbFahren
 				 * Specific heat capacity units.
 				 * @param NewtonPerSqMeter,LbforcePerSqInch
 				 * Stress units.
 				 * @param KilogramPerSqSecond,DynePerCentimeter
 				 * Surfacic tension units.
 				 * @param Kelvindegree,Celsius,Fahrenheit
 				 * Temperature units.
 				 * @param JoulePerMSecKelvin,BtuFtPerHrFt2Fahren
 				 * Thermal conductivity units.
 				 * @param Second,Hour
 				 * Time units.
 				 * @param NewtonperMeter,NewtonperMillimeter,PoundforceperFoot,PoundforceperInch
 				 * Linear stiffness units.
 				 * @param CubicMeter,CubicMillimeter,CubicCentimeter,CubicInch,CubicFoot,Liter
 				 * Volume units.
 				 * @param CubicMeterPerSecond,CubicMeterPerHour,CubicFootPerHour,USGallonPerMinute,BarrelPerHour,BarrelPerDay,CubicFootPerMinute,LiterPerSecond
 				 * Volumetric flow units.
 				 * @param Steradian
 				 * Solid angle units.
 				 * @param Number
 				 * Scalar units.
 				 * @param NewtonPerCubicMeter,LbforcePerCubicInch
 				 * VolumicForce units.
 				 * @param RadianPerSecond,DegreePerSecond,GradePerSecond
 				 * AngularVelocity units.
 				 * @param RadianPerSquareSecond,DegreePerSquareSecond,GradePerSquareSecond
 				 * AngularAcceleration units.
 				 * @param PerFahrenheit,PerCelsius
 				 * Dilatation units.
 				 * @param Herz
 				 * Frequency units.
 				 * @param KilogramPerSquareMeter,PoundPerSquareInch
 				 * SurfacicMass units.
 				 */
        enum CATDlgUnit {
          // Absolute viscosity units
          Decapoise, Poise, Centipoise, Millipoise, Micropoise, LbfSecondPerSqFt, LbfSecondPerSqIn, PoundPerSecondFoot,
          // Acceleration units
          MeterPerSquareSecond, FootPerSquareSecond, InchPerSquareSecond,
          // Angle units
          Radian, Degree, ArcMinute, ArcSecond, Grade,
          // Area units
          SquareMeter, SquareMillimeter, SquareCentimeter, SquareInch, SquareFoot,
          // Volumic mass units
          KilogramPerM3, PoundPerCubicFoot, PoundPerCubicInch,
          // Dissolved solid fraction units
          Fraction, Percentage, PartPerMillion,
          // Energy units
          Joule, WattXHour, BritishThermalUnit, PoundforceXFoot,
          // Force units
          Newton, Poundforce,
          // Heat capacity units
          JoulePerKelvin, BtuPerFahrenheit,
          // Inertia units
          Meter4, Millimeter4, Centimeter4, Inch4, Foot4,
          // Kinematic viscosity units
          SquareMeterPerSecond, Stoke, SquareFootPerSecond,
          // Length units
          Meter, Micrometer, Millimeter, Centimeter, Kilometer, Inch, Foot, FeetInchFraction64, FeetInchFraction16, FeetInchDecimal,
          // Linear mass units
          KilogramPerMeter, PoundPerFoot, PoundPerInch,
          // Lineic force units
          NewtonPerMeter, PoundforcePerFoot, PoundforcePerInch,
          // Mass units
          Kilogram, Gram, Ton, Pound,
          // Massic flow units
          KilogramPerSecond, PoundPerHour, KilogramPerHour, PoundPerMinute,
          // Molecular weight units
          KilogramPerMole, GramPerMole,
          // Moment units
          NewtonXMeter, PoundforceXInch, NewtonXMillimeter,
          // Pressure units
          NewtonPerSquareMeter, Pascal, LbforcePerSquareInch,
          // Angular stiffness units
          NewtonMeterPerRadian, NewtonMMPerMradian, PoundforceInchPerRad,
          // Slope units
          SlopeRatio, SlopePercentage, SlopeInCmPerM, SlopeInMMPerM, SlopeInInchPerFoot,
          // Speed units
          MeterPerSecond, FootPerSecond, MilePerHour, KilometerPerHour, FootPerMinute, FootPerHour,
          // Specific heat capacity units
          JoulePerKgKelvin, BtuPerLbFahren,
          // Stress units
          NewtonPerSqMeter, LbforcePerSqInch,
          // Surfacic tension units
          KilogramPerSqSecond, DynePerCentimeter,
          // Temperature units
          Kelvindegree, Celsius, Fahrenheit,
          // Thermal conductivity units
          JoulePerMSecKelvin, BtuFtPerHrFt2Fahren,
          // Time units
          Second, Hour,
          // Linear stiffness units
          NewtonperMeter, NewtonperMillimeter, PoundforceperFoot, PoundforceperInch,
          // Volume units
          CubicMeter, CubicMillimeter, CubicCentimeter, CubicInch, CubicFoot, Liter,
          // Volumetric flow units
          CubicMeterPerSecond, CubicMeterPerHour, CubicFootPerHour, USGallonPerMinute, BarrelPerHour, BarrelPerDay, CubicFootPerMinute, LiterPerSecond,
          // Solid angle units
          Steradian,
          // Scalar units
          Number,
          // VolumicForce units
          NewtonPerCubicMeter, LbforcePerCubicInch, 
          // AngularVelocity units
          RadianPerSecond, DegreePerSecond, GradePerSecond,
          // AngularAcceleration units
          RadianPerSquareSecond, DegreePerSquareSecond, GradePerSquareSecond,
          // Dilatation units
          PerFahrenheit, PerCelsius,
          // Frequency units
          Herz, 
          // SurfacicMass units
          KilogramPerSquareMeter, PoundPerSquareInch
        };


        /**
         * Possible magnitude for controls.
         * @param AbsoluteViscosity
         * @param Acceleration
         * @param Angle
         * @param Area
         * @param VolumicMass
         * @param DissolvedSolidFraction
         * @param Energy
         * @param Force
         * @param HeatCapacity
         * @param Inertia
         * @param KinematicViscosity
         * @param Length
         * @param LinearMass
         * @param LineicForce
         * @param Mass
         * @param MassicFlow
         * @param MolecularWeight
         * @param Moment
         * @param Pressure
         * @param AngularStiffness
         * @param Slope
         * @param Speed
         * @param SpecificHeatCapacity
         * @param Stress
         * @param SurfacicTension
         * @param Temperature
         * @param ThermalConductivity
         * @param TimeMagnitude
         * @param LinearStiffness
         * @param Volume
         * @param VolumetricFlow
         * @param SolidAngle
         * @param Scalar
         * @param VolumicForce
         * @param AngularVelocity
         * @param AngularAcceleration
         * @param Dilatation
         * @param Frequency
         * @param SurfacicMass
         */
        enum CATDlgMagnitude {
          AbsoluteViscosity, Acceleration, Angle, Area, VolumicMass, DissolvedSolidFraction,
          Energy, Force, HeatCapacity, Inertia, KinematicViscosity, Length, LinearMass, LineicForce,
          Mass, MassicFlow, MolecularWeight, Moment, Pressure, AngularStiffness, Slope, Speed,
          SpecificHeatCapacity, Stress, SurfacicTension, Temperature, ThermalConductivity, TimeMagnitude,
          LinearStiffness, Volume, VolumetricFlow, SolidAngle, Scalar, VolumicForce, AngularVelocity,
          AngularAcceleration, Dilatation, Frequency, SurfacicMass
        };

				/**
				 * Returns the contextual menu of the control if any.
				 */
        CATDlgContextualMenu* GetContextualMenu();

  			/**
  			 * Sets the unit to be used for the value displayed.
  			 * @param iUnit
  			 * The unit to set.
  			 */
        void SetUnit(CATDlgUnit iUnit);

  			/**
  			 * Returns the unit to be used for the value displayed.
  			 */
        CATDlgUnit GetUnit();

  			/**
  			 * Sets the precision to be used for the value displayed.
  			 * @param iPrecision
  			 * The precision to set.
  			 * @param iDecimalPrecision
                         * <br>
                         * <b>Legal values:</b>
                         * <dl>
                         * <dt><tt>TRUE</tt><dd> the precision gives the number of digits to appear after the decimal point character. </DD></dt>
                         * <dt><tt>FALSE</tt><dd> the precision gives the number of significative digits. (default)</dd></dt>
                         * </dl>
  			 */
        void SetPrecision(int iPrecision, CATBoolean iDecimalPrecision=FALSE);

  			/**
  			 * Returns the precision to be used for the value displayed.
  			 */
        int GetPrecision();

  			/**
  			 * Sets the magnitude to be used for the value displayed.
  			 * @param iMagnitude
  			 * The magnitude to set.
  			 */
        void SetMagnitude(CATDlgMagnitude iMagnitude);

  			/**
  			 * Returns the magnitude to be used for the value displayed.
  			 */
        CATDlgMagnitude GetMagnitude();

        /**
         * Associates an icon to a Dialog control object.
         *
         * Once defined such an icon overrides any definition done by SetIconName or by name in a resource file.
         * This method is relevant for CATDlgPushButton, CATDlgCheckButtons and CATDlgRadioButtons objects ONLY. 
         *   
         * @param iBitmap
         *  The bitmap representing the icon.
         *  The length expected is (iWidth+7)/8 * iHeight.
         *  Providing a NULL value removes a previous definition.
         * @param iWidth
         *  The width of the icon.
         * @param iHeight
         *  The height of the icon.
         * @param iBackRed
         *  The red component of the background color, in the <tt>0-255</tt> range.
         * @param iBackGreen
         *  The green component of the background color, in the <tt>0-255</tt> range.
         * @param iBackBlue
         *  The blue component of the background color, in the <tt>0-255</tt> range.
         * @param iForeRed
         *  The red component of the foreground color, in the <tt>0-255</tt> range.
         * @param iForeGreen
         *  The green component of the foreground color, in the <tt>0-255</tt> range.
         * @param iForeBlue
         *  The blue component of the foreground color, in the <tt>0-255</tt> range.
         */
        void SetIconBitmap (const unsigned char* iBitmap, int iWidth, int iHeight,
                            unsigned char iBackRed=255, unsigned char iBackGreen=255, unsigned char iBackBlue=255,
                            unsigned char iForeRed=0, unsigned char iForeGreen=0, unsigned char iForeBlue=0);

        /**
        * @nodoc
        * Useful for Record/Replay in special cases
        */
        void DefineContentsAsFilePath();
        /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;

protected:

			/** 
			 * Constructs a CATDlgControl.
			 * @param iParent
			 *   The parent of the control.
			 * @param iObjectName
			 *   The name of the control.
			 * @param iStyle
			 *   The style of the control.
			 */
        CATDlgControl( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgControl();

        /** @nodoc */
        CATDlgControl_ADD
};

/** @nodoc */
CATDlgControl_LateADD

#endif
