#ifndef FISHER_METHOD_HH
#define FISHER_METHOD_HH

class FisherMethod
{
	public:
		FisherMethod();
        ~FisherMethod();
        double combine_pvalues(const double pvalue1, const double pvalue2);
    private:
        struct Impl;
        Impl* impl_;
};

#endif // FISHER_METHOD_HH
