#include "FisherExactTest.hh"
#include <cmath>
#include <algorithm> 
#include <iostream>

struct FisherExactTest::Impl
{
    Impl(const unsigned int max_n);
    ~Impl();
    double log_hypergeometric_prob(const unsigned a, const unsigned b, const unsigned int c, const unsigned int d);
    static const double* init_log_facs(const unsigned int max_n);

    const unsigned int max_n_;
    const double* log_facs_;
};

FisherExactTest::Impl::Impl(const unsigned int max_n)
    : max_n_(max_n),
    log_facs_(init_log_facs(max_n))
{
}

const double* FisherExactTest::Impl::init_log_facs(const unsigned int max_n)
{
    double* log_facs = new double[max_n+1];
    log_facs[0] = 0;
    for(unsigned int i=1; i < max_n+1; ++i) {
        log_facs[i] = log_facs[i-1] + std::log(static_cast<double>(i));
    }

    return log_facs;
}

FisherExactTest::Impl::~Impl()
{
    delete[] log_facs_;
}

inline double FisherExactTest::Impl::log_hypergeometric_prob(const unsigned a, const unsigned b, const unsigned int c, const unsigned int d)
{
  return log_facs_[a+b] + log_facs_[c+d] + log_facs_[a+c] + log_facs_[b+d]
    - log_facs_[a] - log_facs_[b] - log_facs_[c] - log_facs_[d] - log_facs_[a+b+c+d];
}

FisherExactTest::FisherExactTest(const unsigned int max_n)
    :impl_(new Impl(max_n))
{
}


FisherExactTest::~FisherExactTest()
{
    delete impl_;
}

double FisherExactTest::ltail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d)
{
    double pvalue=0.0;

    const unsigned int min=std::min(a,d);
    for(unsigned int i=0; i<=min; i++)
    {
        pvalue+=std::exp(impl_->log_hypergeometric_prob(a-i, b+i, c+i, d-i));
    }

    return pvalue;
}

double FisherExactTest::rtail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d)
{
    double pvalue=0.0;

    const unsigned int min=std::min(c,b);
    for(unsigned int i=0; i<=min; i++)
    {
        pvalue+=std::exp(impl_->log_hypergeometric_prob(a+i, b-i, c-i, d+i));
    }

    return pvalue;
}
