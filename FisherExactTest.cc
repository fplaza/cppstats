#include "FisherExactTest.hh"
#include <cmath>
#include <algorithm> 
#include <iostream>

struct FisherExactTest::Impl
{
    Impl(const unsigned int max_num_obs);
    ~Impl();
    double log_hypergeometric_prob(const unsigned a, const unsigned b, const unsigned int c, const unsigned int d);
    double ltail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d);
    double rtail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d);
    static const double* init_log_facs(const unsigned int max_num_obs);

    const unsigned int max_num_obs_;
    const double* log_facs_;
};

FisherExactTest::Impl::Impl(const unsigned int max_num_obs)
    : max_num_obs_(max_num_obs),
    log_facs_(init_log_facs(max_num_obs))
{
}

const double* FisherExactTest::Impl::init_log_facs(const unsigned int max_num_obs)
{
    double* log_facs = new double[max_num_obs+1];
    log_facs[0] = 0;
    for(unsigned int i=1; i < max_num_obs+1; ++i) {
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

double FisherExactTest::Impl::ltail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d) {
    double pvalue=0.0;

    const unsigned int min=std::min(a,d);
    for(unsigned int i=0; i<=min; i++)
    {
        pvalue+=std::exp(log_hypergeometric_prob(a-i, b+i, c+i, d-i));
    }

    return pvalue;
}

double FisherExactTest::Impl::rtail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d) {
    double pvalue=0.0;

    const unsigned int min=std::min(c,b);
    for(unsigned int i=0; i<=min; i++)
    {
        pvalue+=std::exp(log_hypergeometric_prob(a+i, b-i, c-i, d+i));
    }

    return pvalue;
}

FisherExactTest::FisherExactTest(const unsigned int max_num_obs)
    :impl_(new Impl(max_num_obs))
{
}


FisherExactTest::~FisherExactTest()
{
    delete impl_;
}

double FisherExactTest::ltail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d)
{
    return impl_->ltail_pvalue(a, b, c, d);
}

double FisherExactTest::rtail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d)
{
    return impl_->rtail_pvalue(a, b, c, d);
}
