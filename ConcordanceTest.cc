#include "ConcordanceTest.hh"
#include <boost/math/distributions/students_t.hpp>
#include <boost/math/special_functions/fpclassify.hpp>

struct ConcordanceTest::Impl
{
    Impl(const unsigned max_n);
    const unsigned max_n_;
    const std::vector<boost::math::students_t> dists;
    static const std::vector<boost::math::students_t> init_dists(const unsigned max_n);
};

ConcordanceTest::Impl::Impl(const unsigned max_n)
    : max_n_(max_n),
    dists(init_dists(max_n))
{
}

const std::vector<boost::math::students_t> ConcordanceTest::Impl::init_dists(const unsigned max_n)
{
    std::vector<boost::math::students_t> dists;

    for (unsigned int n = 3; n <= max_n; ++n)
    {
        const unsigned int df = n-2;
        dists.push_back(boost::math::students_t(df));
    }

    return dists;
}
ConcordanceTest::ConcordanceTest(const unsigned max_n)
    :impl_(new Impl(max_n))
{
}

ConcordanceTest::~ConcordanceTest()
{
    delete impl_;
}

double ConcordanceTest::rtail_pvalue(const double r, const unsigned int n)
{
    if (boost::math::isnan(r) || n <= 2)
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
    else if (r == 1.0)
    {
        return 0.0;
    }
    else if (r == -1.0)
    {
        return 1.0;
    }
    else
    {
        const unsigned int df = n-2;
        const double t = std::sqrt(df)*r/sqrt(1-std::pow(r,2));
        const double pvalue =  1 - cdf(impl_->dists[df-1], t);
        return pvalue;
    }
}
