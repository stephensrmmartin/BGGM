% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/coef.estimate.R
\name{summary.coef}
\alias{summary.coef}
\title{Summarize \code{coef} Objects}
\usage{
\method{summary}{coef}(object, cred = 0.95, ...)
}
\arguments{
\item{object}{an object of class \code{coef}}

\item{cred}{credible interval width used for the decision rule}

\item{...}{Currently ignored}
}
\value{
a list of length \emph{p} including the
        summaries for each multiple regression.
}
\description{
Summarize \code{coef} Objects
}
