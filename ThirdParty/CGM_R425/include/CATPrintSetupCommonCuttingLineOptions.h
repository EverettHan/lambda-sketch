#ifndef CATPrintSetupCommonCuttingLineOptions_H
#define CATPrintSetupCommonCuttingLineOptions_H

class CATPrintSetupCommonCuttingLineOptions
{
public:
  void SetOffset(double iOffset);
  double GetOffset() const;

  void SetMinLength(double iMinLength);
  double GetMinLength() const;

  bool operator==(CATPrintSetupCommonCuttingLineOptions const& iOptions) const;
  bool operator!=(CATPrintSetupCommonCuttingLineOptions const& iOptions) const;

private:
  double _offset = 0.;
  double _minLength = 0.;
};

inline void CATPrintSetupCommonCuttingLineOptions::SetOffset(double iOffset)
{
  _offset = iOffset;
}

inline double CATPrintSetupCommonCuttingLineOptions::GetOffset() const
{
  return _offset;
}

inline void CATPrintSetupCommonCuttingLineOptions::SetMinLength(double iMinLength)
{
  _minLength = iMinLength;
}

inline double CATPrintSetupCommonCuttingLineOptions::GetMinLength() const
{
  return _minLength;
}

inline bool CATPrintSetupCommonCuttingLineOptions::operator==(CATPrintSetupCommonCuttingLineOptions const& iOptions) const
{
  return _offset == iOptions._offset && _minLength == iOptions._minLength;
}

inline bool CATPrintSetupCommonCuttingLineOptions::operator!=(CATPrintSetupCommonCuttingLineOptions const& iOptions) const
{
  return !(*this == iOptions);
}

#endif // !CATPrintSetupCommonCuttingLineOptions_H
