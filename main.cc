#include "FisherExactTest.hh"
#include "ConcordanceTest.hh"
#include <iostream>

int main(int argc, char* argv[])
{
    FisherExactTest fisher_exact_test(1267);
    const double rpval= fisher_exact_test.rtail_pvalue(3, 9, 13, 4);
    std::cout << rpval << std::endl;
    const double lpval= fisher_exact_test.ltail_pvalue(3, 9, 13, 4);
    std::cout << lpval << std::endl;

    ConcordanceTest concordance_test;
    const double pval= concordance_test.pvalue(0.9,5);
    std::cout << pval << std::endl;
    return 0;
}
