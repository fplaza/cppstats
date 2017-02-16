#include "ConcordanceTest.hh"
#include <boost/math/distributions/students_t.hpp>
#include <boost/math/special_functions/fpclassify.hpp>

double ConcordanceTest::rtail_pvalue(const double r, const unsigned int n)
{
    if (boost::math::isnan(r) || n <= 2)
        return std::numeric_limits<double>::quiet_NaN();

    const unsigned int df = n-2;
    const double t = std::sqrt(df)*r/sqrt(1-std::pow(r,2));
    boost::math::students_t student_dist(df);
    const double pvalue = 1 - cdf(student_dist, t);
    return pvalue;
}
