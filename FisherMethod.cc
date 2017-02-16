#include "FisherMethod.hh"
#include <boost/math/distributions/chi_squared.hpp>
#include <boost/math/special_functions/fpclassify.hpp>

double FisherMethod::combine_pvalues(const double pvalue1, const double pvalue2)
{
    if (boost::math::isnan(pvalue1) || boost::math::isnan(pvalue2))
    {
        return std::numeric_limits<double>::quiet_NaN();
    }

    const double score = -2.0*(std::log(pvalue1)+std::log(pvalue2));
    boost::math::chi_squared dist(4);
    const double pvalue = 1 - cdf(dist,score);
    return pvalue;
}
