#ifndef CONCORDANCE_TEST_HH
#define CONCORDANCE_TEST_HH

class ConcordanceTest
{
	public:
		ConcordanceTest(const unsigned max_n);
		~ConcordanceTest();
        double rtail_pvalue(const double r, const unsigned int n);

    private:
        struct Impl;
        Impl* impl_;

};

#endif // CONCORDANCE_TEST_HH
