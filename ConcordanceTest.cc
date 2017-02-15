#include "ConcordanceTest.hh"
#include <boost/math/distributions/students_t.hpp>

double ConcordanceTest::pvalue(const double r, const unsigned int n)
{
    if (n <= 2)
        return std::numeric_limits<double>::quiet_NaN();

    const unsigned int df = n-2;
    const double t = std::sqrt(df)*r/sqrt(1-std::pow(r,2));
    boost::math::students_t student_dist(df);
    const double pvalue = 1 - cdf(student_dist, t);
    return pvalue;
}
