#include<string>

using namespace std;

enum DiagnosticsMode_e {NotSolved, Always, NotOverdefined, Never, Heal, OldAlways};
enum RigidSetDiagnosticsMode_e {WithoutDOS, Full, ExtraDOF};
enum OverdefinedDiagnosticsMode_e {Dimensional, Full};
enum VariableDependencyMode_e {Never, Solved};
enum ChiralityMode_e {Free, Keep};
enum PartialSolvingMode_e {Always, FailIfInconsistent};
enum UpdateMode_e {Evaluate, Reevaluate, EvalTransform};
enum SolvingMode_e {Standard, MinimumMove};
enum ContactsDiagnosticsMode_e {ClashDetected, Always, Never};
enum UpdateOutOfClashMode_e { None, Basic};

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