#include "FisherMethod.hh"
#include <boost/math/distributions/chi_squared.hpp>

double FisherMethod::combine_pvalues(const double pvalue1, const double pvalue2)
{
    const double score = -2.0*(std::log(pvalue1)+std::log(pvalue2));
    boost::math::chi_squared dist(4);
    const double pvalue = 1 - cdf(dist,score);
    return pvalue;
}
