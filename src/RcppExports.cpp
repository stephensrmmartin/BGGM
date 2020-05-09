// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// Theta_continuous
Rcpp::List Theta_continuous(arma::mat Y, int iter, float delta, float epsilon, int prior_only, int explore, arma::mat start);
RcppExport SEXP _BGGM_Theta_continuous(SEXP YSEXP, SEXP iterSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP prior_onlySEXP, SEXP exploreSEXP, SEXP startSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type prior_only(prior_onlySEXP);
    Rcpp::traits::input_parameter< int >::type explore(exploreSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type start(startSEXP);
    rcpp_result_gen = Rcpp::wrap(Theta_continuous(Y, iter, delta, epsilon, prior_only, explore, start));
    return rcpp_result_gen;
END_RCPP
}
// sample_prior
Rcpp::List sample_prior(arma::mat Y, int iter, float delta, float epsilon, int prior_only, int explore);
RcppExport SEXP _BGGM_sample_prior(SEXP YSEXP, SEXP iterSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP prior_onlySEXP, SEXP exploreSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type prior_only(prior_onlySEXP);
    Rcpp::traits::input_parameter< int >::type explore(exploreSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_prior(Y, iter, delta, epsilon, prior_only, explore));
    return rcpp_result_gen;
END_RCPP
}
// mv_continuous
Rcpp::List mv_continuous(arma::mat Y, arma::mat X, float delta, float epsilon, int iter);
RcppExport SEXP _BGGM_mv_continuous(SEXP YSEXP, SEXP XSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    rcpp_result_gen = Rcpp::wrap(mv_continuous(Y, X, delta, epsilon, iter));
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
// mv_binary
Rcpp::List mv_binary(arma::mat Y, arma::mat X, float delta, float epsilon, int iter, float beta_prior, arma::rowvec cutpoints);
RcppExport SEXP _BGGM_mv_binary(SEXP YSEXP, SEXP XSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP iterSEXP, SEXP beta_priorSEXP, SEXP cutpointsSEXP) {
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
    rcpp_result_gen = Rcpp::wrap(mv_binary(Y, X, delta, epsilon, iter, beta_prior, cutpoints));
    return rcpp_result_gen;
END_RCPP
}
// Sigma_i_not_i
arma::mat Sigma_i_not_i(arma::mat x, int index);
RcppExport SEXP _BGGM_Sigma_i_not_i(SEXP xSEXP, SEXP indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    rcpp_result_gen = Rcpp::wrap(Sigma_i_not_i(x, index));
    return rcpp_result_gen;
END_RCPP
}
// select_col
arma::vec select_col(arma::mat x, int index);
RcppExport SEXP _BGGM_select_col(SEXP xSEXP, SEXP indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    rcpp_result_gen = Rcpp::wrap(select_col(x, index));
    return rcpp_result_gen;
END_RCPP
}
// select_row
arma::mat select_row(arma::mat x, int index);
RcppExport SEXP _BGGM_select_row(SEXP xSEXP, SEXP indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    rcpp_result_gen = Rcpp::wrap(select_row(x, index));
    return rcpp_result_gen;
END_RCPP
}
// remove_row
arma::mat remove_row(arma::mat x, int which);
RcppExport SEXP _BGGM_remove_row(SEXP xSEXP, SEXP whichSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type which(whichSEXP);
    rcpp_result_gen = Rcpp::wrap(remove_row(x, which));
    return rcpp_result_gen;
END_RCPP
}
// remove_col
arma::mat remove_col(arma::mat x, int index);
RcppExport SEXP _BGGM_remove_col(SEXP xSEXP, SEXP indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    rcpp_result_gen = Rcpp::wrap(remove_col(x, index));
    return rcpp_result_gen;
END_RCPP
}
// mv_ordinal_cowles
Rcpp::List mv_ordinal_cowles(arma::mat Y, arma::mat X, float delta, float epsilon, int iter, float MH);
RcppExport SEXP _BGGM_mv_ordinal_cowles(SEXP YSEXP, SEXP XSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP iterSEXP, SEXP MHSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< float >::type MH(MHSEXP);
    rcpp_result_gen = Rcpp::wrap(mv_ordinal_cowles(Y, X, delta, epsilon, iter, MH));
    return rcpp_result_gen;
END_RCPP
}
// mv_ordinal_albert
Rcpp::List mv_ordinal_albert(arma::mat Y, arma::mat X, int iter, float delta, float epsilon, int K);
RcppExport SEXP _BGGM_mv_ordinal_albert(SEXP YSEXP, SEXP XSEXP, SEXP iterSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP KSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    rcpp_result_gen = Rcpp::wrap(mv_ordinal_albert(Y, X, iter, delta, epsilon, K));
    return rcpp_result_gen;
END_RCPP
}
// copula
Rcpp::List copula(arma::mat z0_start, arma::mat levels, arma::vec K, arma::mat Sigma_start, int iter, float delta, float epsilon, arma::vec idx);
RcppExport SEXP _BGGM_copula(SEXP z0_startSEXP, SEXP levelsSEXP, SEXP KSEXP, SEXP Sigma_startSEXP, SEXP iterSEXP, SEXP deltaSEXP, SEXP epsilonSEXP, SEXP idxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type z0_start(z0_startSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type levels(levelsSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type K(KSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Sigma_start(Sigma_startSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    Rcpp::traits::input_parameter< float >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< float >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type idx(idxSEXP);
    rcpp_result_gen = Rcpp::wrap(copula(z0_start, levels, K, Sigma_start, iter, delta, epsilon, idx));
    return rcpp_result_gen;
END_RCPP
}
// pcor_to_cor_internal
Rcpp::List pcor_to_cor_internal(arma::cube x, int p);
RcppExport SEXP _BGGM_pcor_to_cor_internal(SEXP xSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(pcor_to_cor_internal(x, p));
    return rcpp_result_gen;
END_RCPP
}
// predictability_helper
Rcpp::List predictability_helper(arma::mat Y, arma::colvec y, arma::cube XX, arma::mat Xy, int n, int iter);
RcppExport SEXP _BGGM_predictability_helper(SEXP YSEXP, SEXP ySEXP, SEXP XXSEXP, SEXP XySEXP, SEXP nSEXP, SEXP iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::cube >::type XX(XXSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xy(XySEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    rcpp_result_gen = Rcpp::wrap(predictability_helper(Y, y, XX, Xy, n, iter));
    return rcpp_result_gen;
END_RCPP
}
// beta_helper_fast
Rcpp::List beta_helper_fast(arma::cube XX, arma::mat Xy, int p, int iter);
RcppExport SEXP _BGGM_beta_helper_fast(SEXP XXSEXP, SEXP XySEXP, SEXP pSEXP, SEXP iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type XX(XXSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xy(XySEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    rcpp_result_gen = Rcpp::wrap(beta_helper_fast(XX, Xy, p, iter));
    return rcpp_result_gen;
END_RCPP
}
// pred_helper_latent
Rcpp::List pred_helper_latent(arma::mat Y, arma::cube XX, arma::mat Xy, arma::vec quantiles, int n, int iter);
RcppExport SEXP _BGGM_pred_helper_latent(SEXP YSEXP, SEXP XXSEXP, SEXP XySEXP, SEXP quantilesSEXP, SEXP nSEXP, SEXP iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type XX(XXSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xy(XySEXP);
    Rcpp::traits::input_parameter< arma::vec >::type quantiles(quantilesSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type iter(iterSEXP);
    rcpp_result_gen = Rcpp::wrap(pred_helper_latent(Y, XX, Xy, quantiles, n, iter));
    return rcpp_result_gen;
END_RCPP
}
// KL_univariate
float KL_univariate(float var_1, float var_2);
RcppExport SEXP _BGGM_KL_univariate(SEXP var_1SEXP, SEXP var_2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< float >::type var_1(var_1SEXP);
    Rcpp::traits::input_parameter< float >::type var_2(var_2SEXP);
    rcpp_result_gen = Rcpp::wrap(KL_univariate(var_1, var_2));
    return rcpp_result_gen;
END_RCPP
}
// ppc_helper_nodewise_fast
Rcpp::List ppc_helper_nodewise_fast(arma::cube Theta, int n1, int n2, int p);
RcppExport SEXP _BGGM_ppc_helper_nodewise_fast(SEXP ThetaSEXP, SEXP n1SEXP, SEXP n2SEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< int >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< int >::type n2(n2SEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(ppc_helper_nodewise_fast(Theta, n1, n2, p));
    return rcpp_result_gen;
END_RCPP
}
// KL_divergnece_mvn
double KL_divergnece_mvn(arma::mat Theta_1, arma::mat Theta_2);
RcppExport SEXP _BGGM_KL_divergnece_mvn(SEXP Theta_1SEXP, SEXP Theta_2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Theta_1(Theta_1SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Theta_2(Theta_2SEXP);
    rcpp_result_gen = Rcpp::wrap(KL_divergnece_mvn(Theta_1, Theta_2));
    return rcpp_result_gen;
END_RCPP
}
// sum_squares
float sum_squares(arma::mat Rinv_1, arma::mat Rinv_2);
RcppExport SEXP _BGGM_sum_squares(SEXP Rinv_1SEXP, SEXP Rinv_2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Rinv_1(Rinv_1SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Rinv_2(Rinv_2SEXP);
    rcpp_result_gen = Rcpp::wrap(sum_squares(Rinv_1, Rinv_2));
    return rcpp_result_gen;
END_RCPP
}
// my_dnorm
arma::vec my_dnorm(arma::vec x, arma::vec means, arma::vec sds);
RcppExport SEXP _BGGM_my_dnorm(SEXP xSEXP, SEXP meansSEXP, SEXP sdsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type means(meansSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sds(sdsSEXP);
    rcpp_result_gen = Rcpp::wrap(my_dnorm(x, means, sds));
    return rcpp_result_gen;
END_RCPP
}
// hamming_distance
float hamming_distance(arma::mat Rinv_1, arma::mat Rinv_2, float df1, float df2, float dens, int pcors, float BF_cut);
RcppExport SEXP _BGGM_hamming_distance(SEXP Rinv_1SEXP, SEXP Rinv_2SEXP, SEXP df1SEXP, SEXP df2SEXP, SEXP densSEXP, SEXP pcorsSEXP, SEXP BF_cutSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Rinv_1(Rinv_1SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Rinv_2(Rinv_2SEXP);
    Rcpp::traits::input_parameter< float >::type df1(df1SEXP);
    Rcpp::traits::input_parameter< float >::type df2(df2SEXP);
    Rcpp::traits::input_parameter< float >::type dens(densSEXP);
    Rcpp::traits::input_parameter< int >::type pcors(pcorsSEXP);
    Rcpp::traits::input_parameter< float >::type BF_cut(BF_cutSEXP);
    rcpp_result_gen = Rcpp::wrap(hamming_distance(Rinv_1, Rinv_2, df1, df2, dens, pcors, BF_cut));
    return rcpp_result_gen;
END_RCPP
}
// correlation
float correlation(arma::mat Rinv_1, arma::mat Rinv_2);
RcppExport SEXP _BGGM_correlation(SEXP Rinv_1SEXP, SEXP Rinv_2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Rinv_1(Rinv_1SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Rinv_2(Rinv_2SEXP);
    rcpp_result_gen = Rcpp::wrap(correlation(Rinv_1, Rinv_2));
    return rcpp_result_gen;
END_RCPP
}
// ppc_helper_fast
Rcpp::List ppc_helper_fast(arma::cube Theta, int n1, int n2, int p, float BF_cut, float dens, bool ppc_ss, bool ppc_cors, bool ppc_hd);
RcppExport SEXP _BGGM_ppc_helper_fast(SEXP ThetaSEXP, SEXP n1SEXP, SEXP n2SEXP, SEXP pSEXP, SEXP BF_cutSEXP, SEXP densSEXP, SEXP ppc_ssSEXP, SEXP ppc_corsSEXP, SEXP ppc_hdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type Theta(ThetaSEXP);
    Rcpp::traits::input_parameter< int >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< int >::type n2(n2SEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    Rcpp::traits::input_parameter< float >::type BF_cut(BF_cutSEXP);
    Rcpp::traits::input_parameter< float >::type dens(densSEXP);
    Rcpp::traits::input_parameter< bool >::type ppc_ss(ppc_ssSEXP);
    Rcpp::traits::input_parameter< bool >::type ppc_cors(ppc_corsSEXP);
    Rcpp::traits::input_parameter< bool >::type ppc_hd(ppc_hdSEXP);
    rcpp_result_gen = Rcpp::wrap(ppc_helper_fast(Theta, n1, n2, p, BF_cut, dens, ppc_ss, ppc_cors, ppc_hd));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_BGGM_Theta_continuous", (DL_FUNC) &_BGGM_Theta_continuous, 7},
    {"_BGGM_sample_prior", (DL_FUNC) &_BGGM_sample_prior, 6},
    {"_BGGM_mv_continuous", (DL_FUNC) &_BGGM_mv_continuous, 5},
    {"_BGGM_trunc_mvn", (DL_FUNC) &_BGGM_trunc_mvn, 5},
    {"_BGGM_mv_binary", (DL_FUNC) &_BGGM_mv_binary, 7},
    {"_BGGM_Sigma_i_not_i", (DL_FUNC) &_BGGM_Sigma_i_not_i, 2},
    {"_BGGM_select_col", (DL_FUNC) &_BGGM_select_col, 2},
    {"_BGGM_select_row", (DL_FUNC) &_BGGM_select_row, 2},
    {"_BGGM_remove_row", (DL_FUNC) &_BGGM_remove_row, 2},
    {"_BGGM_remove_col", (DL_FUNC) &_BGGM_remove_col, 2},
    {"_BGGM_mv_ordinal_cowles", (DL_FUNC) &_BGGM_mv_ordinal_cowles, 6},
    {"_BGGM_mv_ordinal_albert", (DL_FUNC) &_BGGM_mv_ordinal_albert, 6},
    {"_BGGM_copula", (DL_FUNC) &_BGGM_copula, 8},
    {"_BGGM_pcor_to_cor_internal", (DL_FUNC) &_BGGM_pcor_to_cor_internal, 2},
    {"_BGGM_predictability_helper", (DL_FUNC) &_BGGM_predictability_helper, 6},
    {"_BGGM_beta_helper_fast", (DL_FUNC) &_BGGM_beta_helper_fast, 4},
    {"_BGGM_pred_helper_latent", (DL_FUNC) &_BGGM_pred_helper_latent, 6},
    {"_BGGM_KL_univariate", (DL_FUNC) &_BGGM_KL_univariate, 2},
    {"_BGGM_ppc_helper_nodewise_fast", (DL_FUNC) &_BGGM_ppc_helper_nodewise_fast, 4},
    {"_BGGM_KL_divergnece_mvn", (DL_FUNC) &_BGGM_KL_divergnece_mvn, 2},
    {"_BGGM_sum_squares", (DL_FUNC) &_BGGM_sum_squares, 2},
    {"_BGGM_my_dnorm", (DL_FUNC) &_BGGM_my_dnorm, 3},
    {"_BGGM_hamming_distance", (DL_FUNC) &_BGGM_hamming_distance, 7},
    {"_BGGM_correlation", (DL_FUNC) &_BGGM_correlation, 2},
    {"_BGGM_ppc_helper_fast", (DL_FUNC) &_BGGM_ppc_helper_fast, 9},
    {NULL, NULL, 0}
};

RcppExport void R_init_BGGM(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
