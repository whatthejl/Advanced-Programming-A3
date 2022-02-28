template <typename T>
double scalar_difference(T a, T b)
{
    return fabs(a.getScalarValue() - b.getScalarValue());
}

template <typename T>
bool equals(T a, T b)
{
    if (a == b)
        return true;
    return false;
}

template <typename T>
bool DSC(const T& a, const T& b)
{
  return a > b;
}

template <typename T>
bool ASC(const T& a, const T& b)
{
  return a < b;
}
