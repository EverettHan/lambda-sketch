#ifndef ECSkSolverOptions_H
#define ECSkSolverOptions_H

#include<string>

using namespace std;

enum DiagnosticsMode_e {DiagnosticsMode_NotSolved, DiagnosticsMode_Always, DiagnosticsMode_NotOverdefined, DiagnosticsMode_Never, DiagnosticsMode_Heal, DiagnosticsMode_OldAlways};
enum RigidSetDiagnosticsMode_e {RigidSetDiagnosticsMode_WithoutDOS, RigidSetDiagnosticsMode_Full, RigidSetDiagnosticsMode_ExtraDOF};
enum OverdefinedDiagnosticsMode_e {OverdefinedDiagnosticsMode_Dimensional, OverdefinedDiagnosticsMode_Full};
enum VariableDependencyMode_e {VariableDependencyMode_Never, VariableDependencyMode_Solved};
enum ChiralityMode_e {ChiralityMode_Free, ChiralityMode_Keep};
enum PartialSolvingMode_e {PartialSolvingMode_Always, PartialSolvingMode_FailIfInconsistent};
enum UpdateMode_e {UpdateMode_Evaluate, UpdateMode_Reevaluate, UpdateMode_EvalTransform};
enum SolvingMode_e {SolvingMode_Standard, SolvingMode_MinimumMove};
enum ContactsDiagnosticsMode_e {ContactsDiagnosticsMode_ClashDetected, ContactsDiagnosticsMode_Always, ContactsDiagnosticsMode_Never};
enum UpdateOutOfClashMode_e { UpdateOutOfClashMode_None, UpdateOutOfClashMode_Basic};

class ECSkSolverOptions
{
public:
    ECSkSolverOptions();

    double getLinearTolerance() {return m_dLinearTolerance;}
    void setLinearTolerance(double tolIn) {m_dLinearTolerance = tolIn;}

    double getAngularTolerance() {return m_dAngularTolerance;}
    void setAngularTolerance(double tolIn) {m_dAngularTolerance = tolIn;}

    bool getRereadHelpParameters() {return m_bRereadHelpParameters;}
    void setRereadHelpParameters(bool valIn) { m_bRereadHelpParameters = valIn;}

    bool getForceUsingSketch() {return m_bForceUsingSketch;}
    void setForceUsingSketch(bool valIn) { m_bForceUsingSketch = valIn;}

    bool getCheckUnsolvableConstraintsMode() {return m_bCheckUnsolvableConstraintsMode;}
    void setCheckUnsolvableConstraintsMode(bool valIn) { m_bCheckUnsolvableConstraintsMode = valIn;}

    bool getIncrementalMode() {return m_bIncrementalMode;}
    void setIncrementalMode(bool valIn) { m_bIncrementalMode = valIn;}

    DiagnosticsMode_e getDiagnosticsMode() { return m_eDiagnosticsMode; }
    void setDiagnosticsMode(std::string valIn);

    RigidSetDiagnosticsMode_e getRigidSetDiagnosticsMode() { return m_eRigidSetDiagnosticsMode; }
    void setRigidSetDiagnosticsMode(std::string valIn);
    
    OverdefinedDiagnosticsMode_e getOverdefinedDiagnosticsMode() { return  m_eOverdefinedDiagnosticsMode; }
    void setOverdefinedDiagnosticsMode(std::string valIn);
    
    VariableDependencyMode_e getVariableDependencyMode() { return  m_eVariableDependencyMode; }
    void setVariableDependencyMode(std::string valIn);
    
    ChiralityMode_e getChiralityMode() { return  m_eChiralityMode; }
    void setChiralityMode(std::string valIn);
    
    PartialSolvingMode_e getPartialSolvingMode() { return  m_ePartialSolvingMode; }
    void setPartialSolvingMode(std::string valIn);
    
    UpdateMode_e getUpdateMode() { return  m_eUpdateMode; }
    void setUpdateMode(std::string valIn);
    
    SolvingMode_e getSolvingMode() { return  m_eSolvingMode; }
    void setSolvingMode(std::string valIn);
    
    ContactsDiagnosticsMode_e getContactsDiagnosticsMode() { return  m_eContactsDiagnosticsMode; }
    void setContactsDiagnosticsMode(std::string valIn);
    
    UpdateOutOfClashMode_e getUpdateOutOfClashMode() { return  m_eUpdateOutOfClashMode; }
    void setUpdateOutOfClashMode(std::string valIn);
    

private:
    double m_dLinearTolerance, m_dAngularTolerance;
    bool m_bRereadHelpParameters, m_bForceUsingSketch, m_bCheckUnsolvableConstraintsMode, m_bIncrementalMode;
    DiagnosticsMode_e m_eDiagnosticsMode; //"OldAlways"
    RigidSetDiagnosticsMode_e m_eRigidSetDiagnosticsMode; //"WithoutDOS"
    OverdefinedDiagnosticsMode_e m_eOverdefinedDiagnosticsMode; //"Dimensional"
    VariableDependencyMode_e m_eVariableDependencyMode; //"Never"
    ChiralityMode_e m_eChiralityMode; //"Keep"
    PartialSolvingMode_e m_ePartialSolvingMode; //"Always"
    UpdateMode_e m_eUpdateMode; //"Evaluate"
    SolvingMode_e m_eSolvingMode; //"Standard"
    ContactsDiagnosticsMode_e m_eContactsDiagnosticsMode; //"ClashDetected"
    UpdateOutOfClashMode_e m_eUpdateOutOfClashMode; //"None"
};

#endif //ECSkSolverOptions_H
