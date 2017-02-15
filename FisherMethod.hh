#ifndef FISHER_METHOD_HH
#define FISHER_METHOD_HH

class FisherMethod
{
	public:
		FisherMethod();
        double combine_pvalues(const double pvalue1, const double pvalue2);
};

inline FisherMethod::FisherMethod()
{
}

#endif // FISHER_METHOD_HH
