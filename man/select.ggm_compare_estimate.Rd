% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/select.ggm_compare_estimate.R
\name{select.ggm_compare_estimate}
\alias{select.ggm_compare_estimate}
\title{Select Partial Correlattion Differences for \code{ggm_compare_estimate} Objects}
\usage{
\method{select}{ggm_compare_estimate}(object, cred = 0.95, rope = NULL, ...)
}
\arguments{
\item{object}{object of class \code{ggm_compare_estimate}}

\item{cred}{credible interval width used for the decision rule}

\item{rope}{region of practical equivalence}

\item{...}{not currently used}
}
\value{
A list of class \code{select.ggm_compare_estimate}:
\code{rope} = NULL:
\itemize{
\item \code{mat_adj} adjacency matrix (one for each contrast)
\item \code{mat_pcor} selected partial correlations (one for each contrast)
\item \code{call} \code{match.call()}
\item \code{object} object of class \code{ggm_compare_estimate}
\item \code{rope} region of practical equivalence
\item \code{cred} credible interval
\item \code{prob} posterior probability
}
}
\description{
Select Partial Correlattion Differences for \code{ggm_compare_estimate} Objects
}
