#ifndef FISHER_EXACT_TEST_HH
#define FISHER_EXACT_TEST_HH

class FisherExactTest
{
	public:
		FisherExactTest(const unsigned int max_n);
		~FisherExactTest();
        double ltail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d);
        double rtail_pvalue(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d);

	private:
        struct Impl;
        Impl* impl_;
};



#endif //FISHER_EXACT_TEST_HH
