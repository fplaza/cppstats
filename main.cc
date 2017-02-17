#include "FisherExactTest.hh"
#include "ConcordanceTest.hh"
#include "FisherMethod.hh"
#include <iostream>

int main()
{
    FisherExactTest fisher_exact_test(29);
    std::cout << fisher_exact_test.rtail_pvalue(3, 9, 13, 4) << std::endl; 
    std::cout << fisher_exact_test.ltail_pvalue(3, 9, 13, 4) << std::endl; 

    ConcordanceTest concordance_test(100);
    std::cout << concordance_test.rtail_pvalue(1.0,10) << std::endl;
    std::cout << concordance_test.rtail_pvalue(-1.0,10) << std::endl;
    std::cout << concordance_test.rtail_pvalue(0.0,10) << std::endl;
    std::cout << concordance_test.rtail_pvalue(0.0,2) << std::endl;
    std::cout << concordance_test.rtail_pvalue(0.9,10) << std::endl;
    std::cout << concordance_test.rtail_pvalue(0.8,20) << std::endl;
    

    FisherMethod fisher_method;
    std::cout << fisher_method.combine_pvalues(0.0,1.0) << std::endl;
    std::cout << fisher_method.combine_pvalues(1.0,0.0) << std::endl;
    std::cout << fisher_method.combine_pvalues(0.0,0.0) << std::endl;
    std::cout << fisher_method.combine_pvalues(1.0,1.0) << std::endl;
    std::cout << fisher_method.combine_pvalues(0.5,0.2) << std::endl;

    return 0;
}
