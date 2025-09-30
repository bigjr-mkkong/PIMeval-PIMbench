#ifndef LAVA_PIM_TLB_H
#define LAVA_PIM_TLB_H

#include <stddef.h>

// #define HMT_ENABLE
#define HMT_SZ  64

#define HMT_TTRANS  1
#define HMT_ETRANS  1

#ifdef HMT_ENABLE
#define GETSET(T, N) \
  T get_##N() const { return N; };  \
  void set_##N(T x) { N = x; }
#else
#define GETSET(T, N) \
  T get_##N() const { return (T)0; };  \
  void set_##N(T x) { N = (T)0; }
#endif


struct HMT{
    public:
    HMT() :\
        m_ttrans(0.0),\
        m_etrans(0.0) \
    {};

    GETSET(double, m_ttrans)
    GETSET(double, m_etrans)

    private:
    double m_ttrans;
    double m_etrans;
};

#endif
