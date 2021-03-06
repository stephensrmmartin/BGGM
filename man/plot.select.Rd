% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plot.select.R
\name{plot.select}
\alias{plot.select}
\title{Network Plot for \code{select} Objects}
\usage{
\method{plot}{select}(
  x,
  layout = "circle",
  pos_col = "#009E73",
  neg_col = "#D55E00",
  node_size = 10,
  edge_magnify = 1,
  groups = NULL,
  palette = "Set3",
  ...
)
}
\arguments{
\item{x}{object of class \code{select}.}

\item{layout}{a character string specifying the graph layout (default is \code{circle}). See \link[sna]{gplot.layout}.}

\item{pos_col}{a character string specifying the color for the positive edges.}

\item{neg_col}{a character string specifying the color for the negative edges.}

\item{node_size}{numeric. Node size.}

\item{edge_magnify}{numeric. A value that is multiplied by the edge weights. This can increase (> 1) or
derease (< 1) the line widths.}

\item{groups}{a character string of length \emph{p} (the number of nodes in the model). This indicates
groups of nodes that should be the same color (e.g., clusters).}

\item{palette}{a character string sepcifying the palette for the \code{groups} color (default is \code{Set3}). See
\href{http://www.cookbook-r.com/Graphs/Colors_(ggplot2)/}{palette options here}.}

\item{...}{additional options passed to \link[GGally]{ggnet2}}
}
\value{
object of class \code{ggplot}
}
\description{
Network Plot for \code{select} Objects
}
