% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/zero_order.R
\name{zero_order_cors}
\alias{zero_order_cors}
\title{Zero-Order Correlations}
\usage{
zero_order_cors(Y, type = "continuous", iter = 5000, mixed_type = NULL)
}
\arguments{
\item{Y}{matrix (or data frame) of dimensions \emph{n} (observations) by  \emph{p} (variables).}

\item{type}{character string. Which type of data for \strong{Y} ? The options include \code{continuous},
\code{binary}, \code{ordinal}, or \code{mixed}. See the note for further details.}

\item{iter}{number of iterations (posterior samples; defaults to 5000).}

\item{mixed_type}{numeric vector. An indicator of length p for which varibles should be treated as ranks.
(1 for rank and 0 to assume normality). The default is currently to treat all integer variables as ranks
when \code{type = "mixed"} and \code{NULL} otherwise. See note for further details.}
}
\value{
\itemize{

\item \code{R} An array including the correlation matrices
              (of dimensions \emph{p} by \emph{p} by \emph{iter})

\item \code{R_mean} Posterior mean of the correlations (of dimensions \emph{p} by \emph{p})
}
}
\description{
Estimate zero-order correlations for any type of data. Note zero-order refers to the fact that
no variables are controlled for (i.e., bivariate correlations). To our knowledge, this is the only Bayesian
implementation in \code{R} that can estiamte Pearson's,  tetrachoric (binary), polychoric
(ordinal with more than two cateogries), and rank based correlation coefficients.
}
