#include "FisherMethod.hh"
#include <boost/math/distributions/chi_squared.hpp>
#include <boost/math/special_functions/fpclassify.hpp>

struct FisherMethod::Impl
{
    Impl();
    boost::math::chi_squared dist_;
};

FisherMethod::Impl::Impl()
    : dist_(4)
{}

FisherMethod::FisherMethod()
    :impl_(new Impl())
{
}

FisherMethod::~FisherMethod()
{
    delete impl_;
}


double FisherMethod::combine_pvalues(const double pvalue1, const double pvalue2)
{
    if (boost::math::isnan(pvalue1) || boost::math::isnan(pvalue2))
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
    else
    {
        const double t = -2.0*(std::log(pvalue1)+std::log(pvalue2));
        const double pvalue = 
            (boost::math::isinf(t)) ? 0.0 : 1 - cdf(impl_->dist_, t);

        return pvalue;
    }
}
