// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// rcpparma_hello_world
arma::mat rcpparma_hello_world();
RcppExport SEXP _BGGM_rcpparma_hello_world() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpparma_hello_world());
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_outerproduct
arma::mat rcpparma_outerproduct(const arma::colvec& x);
RcppExport SEXP _BGGM_rcpparma_outerproduct(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_outerproduct(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_innerproduct
double rcpparma_innerproduct(const arma::colvec& x);
RcppExport SEXP _BGGM_rcpparma_innerproduct(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_innerproduct(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_bothproducts
Rcpp::List rcpparma_bothproducts(const arma::colvec& x);
RcppExport SEXP _BGGM_rcpparma_bothproducts(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_bothproducts(x));
    return rcpp_result_gen;
END_RCPP
}
// mvn_continuous
Rcpp::List mvn_continuous(arma::mat Y, arma::mat X, float delta, float epsilon, int iter);
RcppExport SEXP _BGGM_mvn_continuous(SEXP YSEXP, SEXP XSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    rcpp_result_gen = Rcpp::wrap(mvn_continuous(Y, X, delta, epsilon, iter));
    return rcpp_result_gen;
END_RCPP
}
// trunc_mvn
Rcpp::List trunc_mvn(arma::mat mu, arma::mat rinv, arma::mat z, arma::mat y, arma::rowvec cutpoints);
RcppExport SEXP _BGGM_trunc_mvn(SEXP muSEXP, SEXP rinvSEXP, SEXP zSEXP, SEXP ySEXP, SEXP cutpointsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type rinv(rinvSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type z(zSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type cutpoints(cutpointsSEXP);
    rcpp_result_gen = Rcpp::wrap(trunc_mvn(mu, rinv, z, y, cutpoints));
    return rcpp_result_gen;
END_RCPP
}
// mvn_binary
Rcpp::List mvn_binary(arma::mat Y, arma::mat X, float delta, float epsilon, int iter, float beta_prior, arma::rowvec cutpoints);
RcppExport SEXP _BGGM_mvn_binary(SEXP YSEXP, SEXP XSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP iterSEXP, SEXP beta_priorSEXP, SEXP cutpointsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< float >::type beta_prior(beta_priorSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type cutpoints(cutpointsSEXP);
    rcpp_result_gen = Rcpp::wrap(mvn_binary(Y, X, delta, epsilon, iter, beta_prior, cutpoints));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_BGGM_rcpparma_hello_world", (DL_FUNC) &_BGGM_rcpparma_hello_world, 0},
    {"_BGGM_rcpparma_outerproduct", (DL_FUNC) &_BGGM_rcpparma_outerproduct, 1},
    {"_BGGM_rcpparma_innerproduct", (DL_FUNC) &_BGGM_rcpparma_innerproduct, 1},
    {"_BGGM_rcpparma_bothproducts", (DL_FUNC) &_BGGM_rcpparma_bothproducts, 1},
    {"_BGGM_mvn_continuous", (DL_FUNC) &_BGGM_mvn_continuous, 5},
    {"_BGGM_trunc_mvn", (DL_FUNC) &_BGGM_trunc_mvn, 5},
    {"_BGGM_mvn_binary", (DL_FUNC) &_BGGM_mvn_binary, 7},
    {NULL, NULL, 0}
};

RcppExport void R_init_BGGM(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
