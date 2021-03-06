#' @title GGM: Estimation
#'
#' @description Estimate the conditional (in)dependence with either an analytic solution or efficiently
#' sampling from the posterior distribution. These methods were introduced in \insertCite{Williams2019;textual}{BGGM}.
#' The graph is selected with \code{\link{select.estimate}} and then plotted with \code{\link{plot.select}}.
#'
#' @name estimate
#'
#' @param Y  Matrix (or data frame) of dimensions \emph{n} (observations) by  \emph{p} (variables).
#'
#' @param formula An object of class \code{\link[stats]{formula}}. This allows for including
#' control variables in the model (i.e., \code{~ gender}). See the note for further details.
#'
#' @param type Character string. Which type of data for \strong{Y} ? The options include \code{continuous},
#' \code{binary}, \code{ordinal}, or \code{mixed}. Note that mixed can be used for data with only
#' ordinal variables. See the note for further details.
#'
#' @param mixed_type Numeric vector. An indicator of length \emph{p} for which varibles should be treated as ranks.
#' (1 for rank and 0 to assume normality). The default is currently to treat all integer variables as ranks
#' when \code{type = "mixed"} and \code{NULL} otherwise. See note for further details.
#'
#' @param iter Number of iterations (posterior samples; defaults to 5000).
#'
#' @param prior_sd Scale of the prior distribution, approximately the standard deviation of a beta distribution
#' (defaults to 0.50).
#'
#' @param analytic Logical. Should the analytic solution be computed (default is \code{FALSE})?
#'
#' @param progress Logical. Should a progress bar be included (defaults to \code{TRUE}) ?
#'
#' @param seed An integer for the random seed.
#'
#' @param ... Currently ignored.
#'
#' @references
#' \insertAllCited{}
#'
#'
#' @return The returned object of class \code{estimate} contains a lot of information that
#'         is used for printing and plotting the results. For users of \strong{BGGM}, the following
#'         are the useful objects:
#'
#' \itemize{
#'
#' \item \code{pcor_mat} Partial correltion matrix (posterior mean).
#'
#' \item \code{post_samp} An object containing the posterior samples.
#'
#' }
#'
#'
#' @details
#'
#' The default is to draw samples from the posterior distribution (\code{analytic = FALSE}). The samples are
#' required for computing edge differences (see \code{\link{ggm_compare_estimate}}), Bayesian R2 introduced in
#' \insertCite{gelman_r2_2019;textual}{BGGM} (see \code{\link{predictability}}), etc. If the goal is to *only* determine
#' the non-zero effects, this can be accomplished by setting \code{analytic = TRUE}. This is particularly useful
#' when a fast solution is needed (see the examples in \code{\link{ggm_compare_ppc}})
#'
#' \strong{Controlling for Variables}:
#'
#' When controlling for variables, it is assumed that \code{Y} includes \emph{only}
#' the nodes in the GGM and the control variables. Internally, \code{only} the predictors
#' that are included in \code{formula} are removed from \code{Y}. This is not behavior of, say,
#' \code{\link{lm}}, but was adopted to ensure  users do not have to write out each variable that
#' should be included in the GGM. An example is provided below.
#'
#' \strong{Mixed Type}:
#'
#'  The term "mixed" is somewhat of a misnomer, because the method can be used for data including \emph{only}
#'  continuous or \emph{only} discrete variables. This is based on the ranked likelihood which requires sampling
#'  the ranks for each variable (i.e., the data is not merely transformed to ranks). This is computationally
#'  expensive when there are many levels. For example, with continuous data, there are as many ranks
#'  as data points!
#'
#'  The option \code{mixed_type} allows the user to determine  which variable should be treated as ranks
#'  and the "emprical" distribution is used otherwise. This is accomplished by specifying an indicator
#'  vector of length \emph{p}. A one indicates to use the ranks, whereas a zero indicates to "ignore"
#'  that variable. By default all integer variables are handled as ranks.
#'
#'
#'
#' \strong{Dealing with Errors}:
#'
#' An error is most likely to arise when \code{type = "ordinal"}. The are two common errors (although still rare):
#'
#' \itemize{
#'
#' \item The first is due to sampling the thresholds, especially when the data is heavily skewed.
#'       This can result in an ill-defined matrix. If this occurs, we recommend to first try
#'       decreasing \code{prior_sd} (i.e., a more informative prior). If that does not work, then
#'       change the data type to \code{type = mixed} which then estimates a copula GGM
#'       (this method can be used for data containing \strong{only} ordinal variable). This should
#'       work without a problem.
#'
#' \item  The second is due to how the ordinal data are categorized. For example, if the error states
#'        that the index is out of bounds, this indicates that the first category is a zero. This is not allowed, as
#'        the first category must be one. This is addressed by adding one (e.g., \code{Y + 1}) to the data matrix.
#'
#' }
#'
#' @note
#'
#' \strong{Posterior Uncertainty}:
#'
#' A key feature of \bold{BGGM} is that there is a posterior distribution for each partial correlation.
#' This readily allows for visiualizing uncertainty in the estimates. This feature works
#' with all data types and is accomplished by plotting the summary of the \code{estimate} object
#' (i.e., \code{plot(summary(fit))}). Several examples are provided below.
#'
#'
#'
#' \strong{Interpretation of Conditional (In)dependence Models for Latent Data}:
#'
#' See \code{\link{BGGM-package}} for details about interpreting GGMs based on latent data
#' (i.e, all data types besides \code{"continuous"})
#'
#'
#'
#' @export
estimate  <- function(Y,
                      formula = NULL,
                      type = "continuous",
                      mixed_type = NULL,
                      analytic = FALSE,
                      prior_sd = 0.25,
                      iter = 5000,
                      progress = TRUE,
                      seed = 1,
                      ...){

  old <- .Random.seed

  set.seed(seed)

  # delta rho ~ beta(delta/2, delta/2)
  delta <- delta_solve(prior_sd)

  # sample posterior
  if(!analytic){

    if(isTRUE(progress)){

      message(paste0("BGGM: Posterior Sampling ", ...))

      }
    # continuous
    if(type == "continuous"){

      # no control
      if(is.null(formula)){

        # na omit
        Y <- as.matrix(na.omit(Y))

        # scale Y
        Y <- scale(Y, scale = F)

        # design matrix
        X <- NULL

        # nodes
        p <- ncol(Y)

        # number of variables
        n <- nrow(Y)

        start <- solve(cov(Y))

        # posterior sample
        post_samp <- .Call(
          '_BGGM_Theta_continuous',
          PACKAGE = 'BGGM',
          Y = Y,
          iter = iter + 50,
          delta = delta,
          epsilon = 0.1,
          prior_only = 0,
          explore = 1,
          start = start,
          progress =  progress
          )

        # control for variables
        } else {

          control_info <- remove_predictors_helper(list(as.data.frame(Y)),
                                                   formula = formula)

          # data
          Y <- as.matrix(scale(control_info$Y_groups[[1]], scale = F))

          # nodes
          p <- ncol(Y)

          # observations
          n <- nrow(Y)

          # model matrix
          X <- as.matrix(control_info$model_matrices[[1]])

          start <- solve(cov(Y))

        # posterior sample
        post_samp <- .Call(
          "_BGGM_mv_continuous",
          Y = Y,
          X = X,
          delta = delta,
          epsilon = 0.1,
          iter = iter + 50,
          start = start,
          progress = progress
        )
      # end control
      }

      # binary
    } else if (type == "binary") {

      # intercept only
      if (is.null(formula)) {

          # data
          Y <- as.matrix(na.omit(Y))

          # obervations
          n <- nrow(Y)

          # nodes
          p <- ncol(Y)

          X <- matrix(1, n, 1)

          formula <- ~ 1

          start <- solve(cov(Y))

        } else {

          control_info <- remove_predictors_helper(list(as.data.frame(Y)),
                                                   formula = formula)

          # data
          Y <-  as.matrix(control_info$Y_groups[[1]])

          # observations
          n <- nrow(Y)

          # nodes
          p <- ncol(Y)

          # model matrix
          X <- as.matrix(control_info$model_matrices[[1]])

          start <- solve(cov(Y))
          }

      # posterior sample
      post_samp <-  .Call(
        "_BGGM_mv_binary",
        Y = Y,
        X = X,
        delta = delta,
        epsilon = 0.1,
        iter = iter + 50,
        beta_prior = 0.0001,
        cutpoints = c(-Inf, 0, Inf),
        start = start,
        progress = progress
      )

      # ordinal
      } else if(type == "ordinal"){

      # intercept only
      if(is.null(formula)){

        # data
        Y <- as.matrix(na.omit(Y))

        # obervations
        n <- nrow(Y)

        # nodes
        p <- ncol(Y)

        # intercept only
        X <- matrix(1, n, 1)

        formula <- ~ 1

        start <- solve(cov(Y))

        } else {

          control_info <- remove_predictors_helper(list(as.data.frame(Y)),
                                                   formula = formula)

          # data
          Y <-  as.matrix(control_info$Y_groups[[1]])

          # observations
          n <- nrow(Y)

          # nodes
          p <- ncol(Y)

          # model matrix
          X <- as.matrix(control_info$model_matrices[[1]])

          start <- solve(cov(Y))

          }

        # categories
        K <- max(apply(Y, 2, function(x) { length(unique(x))   } ))

        # call c ++
        post_samp <- .Call(
          "_BGGM_mv_ordinal_albert",
          Y = Y,
          X = X,
          iter = iter + 50,
          delta = delta,
          epsilon = 0.1,
          K = K,
          start = start,
          progress = progress
        )

        } else if(type == "mixed"){

          # no control variables allowed
          if(!is.null(formula)){

            warning("formula ignored for mixed data at this time")

            control_info <- remove_predictors_helper(list(as.data.frame(Y)),
                                                     formula = formula)

            # data
            Y <-  as.matrix(control_info$Y_groups[[1]])

            formula <- NULL

            X <- NULL

          } else {

             Y <- na.omit(Y)

             X <- NULL

            }

          # default for ranks
          if(is.null(mixed_type)) {

            idx = colMeans(round(Y) == Y)

            idx = ifelse(idx == 1, 1, 0)

            # user defined
            } else {

              idx = mixed_type

              }

          # observations
          n <- nrow(Y)

          # nodes
          p <- ncol(Y)

          # rank following hoff (2008)
          rank_vars <- rank_helper(Y)

      post_samp <- .Call(
        "_BGGM_copula",
        z0_start = rank_vars$z0_start,
        levels = rank_vars$levels,
        K = rank_vars$K,
        Sigma_start = rank_vars$Sigma_start,
        iter = iter + 50,
        delta = delta,
        epsilon = 0.1,
        idx = idx,
        progress = progress
      )
      } else {

        stop("'type' not supported: must be continuous, binary, ordinal, or mixed.")
      }

    if(isTRUE(progress)){

      message("BGGM: Finished")

      }

    pcor_mat <- post_samp$pcor_mat

    results <- list(
      pcor_mat = pcor_mat,
      analytic = analytic,
      formula = formula,
      post_samp = post_samp,
      type = type,
      iter = iter,
      Y = Y,
      X = X,
      call = match.call(),
      p = p,
      n = n
    )

    #  analytic
    } else {

      if(type != "continuous"){

        warning("analytic solution only available for 'type = continuous'")
        type <- "continuous"

      }
      if(!is.null(formula)){

        stop("formula note permitted with the analytic solution")

      }

    Y <- na.omit(Y)

    # observations
    n <- nrow(Y)

    p <- ncol(Y)

    formula <- NULL

    analytic_fit <- analytic_solve(Y)

    results <- list(pcor_mat = analytic_fit$pcor_mat,
                    analytic_fit = analytic_fit,
                    analytic = analytic,
                    formula = formula,
                    type = type,
                    iter = iter,
                    Y = Y,
                    call = match.call(),
                    p = p,
                    n = n)

    } # end analytic

  .Random.seed <<- old

  returned_object <- results

  class(returned_object) <- c("BGGM",
                              "estimate",
                              "default")
  return(returned_object)

  }

#' @name summary.estimate
#' @title Summary method for \code{estimate.default} objects
#'
#' @param object an object of class \code{estimate}
#'
#' @param col_names logical. Should the summary include the column names (default is \code{TRUE})?
#'                  Setting to \code{FALSE} includes the column numbers (e.g., \code{1--2}).
#'
#' @param cred credible interval width
#' @param ... currently ignored


#' @seealso \code{\link{select.estimate}}
#' @return a list containing the summarized posterior distributions
#' # data
#' Y <- BGGM::bfi[, 1:5]
#' # analytic approach (sample by setting analytic = FALSE)
#' fit <- estimate(Y, analytic = TRUE)
#' summary(fit)
#' @export
summary.estimate <- function(object,
                             col_names = TRUE,
                             cred = 0.95, ...) {

  # nodes
  p <- object$p

  # identity matrix
  I_p <- diag(p)

  # lower bound
  lb <- (1 - cred) / 2

  # upper bound
  ub <- 1 - lb

  # column names
  cn <-  colnames(object$Y)


  if(is.null(cn) | isFALSE(col_names)){

    mat_names <- sapply(1:p , function(x) paste(1:p, x, sep = "--"))[upper.tri(I_p)]

  } else {

    mat_names <-  sapply(cn , function(x) paste(cn, x, sep = "--"))[upper.tri(I_p)]

  }


  if(isFALSE(object$analytic)){

    post_mean <- round(object$pcor_mat[upper.tri(I_p)], 3)

    post_sd  <- round(apply(object$post_samp$pcors[,, 51:(object$iter + 50) ], 1:2, sd), 3)[upper.tri(I_p)]

    post_lb <- round(apply( object$post_samp$pcors[,, 51:(object$iter + 50) ], 1:2, quantile, lb), 3)[upper.tri(I_p)]

    post_ub <- round(apply( object$post_samp$pcors[,, 51:(object$iter + 50) ], 1:2, quantile, ub), 3)[upper.tri(I_p)]

    dat_results <-
      data.frame(
      relation = mat_names,
      post_mean =  post_mean,
      post_sd = post_sd,
      post_lb = post_lb,
      post_ub = post_ub
    )

  colnames(dat_results) <- c(
    "Relation",
    "Post.mean",
    "Post.sd",
    "Cred.lb",
    "Cred.ub")

  } else {

    dat_results <-
      data.frame(
        relation = mat_names,
        post_mean =  object$pcor_mat[upper.tri(I_p)]
      )

    colnames(dat_results) <- c(
      "Relation",
      "Post.mean")

  }


  returned_object <- list(dat_results = dat_results,
                          object = object)


class(returned_object) <- c("BGGM", "estimate",
                            "summary_estimate",
                            "summary.estimate")
returned_object
}


print_summary_estimate <- function(x, ...) {
    cat("BGGM: Bayesian Gaussian Graphical Models \n")
    cat("--- \n")
    cat("Type:",  x$object$type, "\n")
    cat("Analytic:", x$object$analytic, "\n")
    cat("Formula:", paste(as.character(x$formula), collapse = " "), "\n")
    # number of iterations
    cat("Posterior Samples:", x$object$iter, "\n")
    # number of observations
    cat("Observations (n):\n")
    # number of variables
    cat("Nodes (p):", x$object$p, "\n")
    # number of edges
    cat("Relations:", .5 * (x$object$p * (x$object$p - 1)), "\n")
    cat("--- \n")
    cat("Call: \n")
    print(x$object$call)
    cat("--- \n")
    cat("Estimates:\n")
    print(x$dat_results, row.names = F)
    cat("--- \n")
}


print_estimate <- function(x, ...){
  cat("BGGM: Bayesian Gaussian Graphical Models \n")
  cat("--- \n")
  cat("Type:",  x$type, "\n")
  cat("Analytic:", x$analytic, "\n")
  cat("Formula:", paste(as.character(x$formula), collapse = " "), "\n")
  # number of iterations
  cat("Posterior Samples:", x$iter, "\n")
  # number of observations
  cat("Observations (n):\n")
  # number of variables
  cat("Nodes (p):", x$p, "\n")
  # number of edges
  cat("Relations:", .5 * (x$p * (x$p-1)), "\n")
  cat("--- \n")
  cat("Call: \n")
  print(x$call)
  cat("--- \n")
  cat("Date:", date(), "\n")
}



#' Plot \code{summary.estimate} Objects
#'
#' @param x an object of class \code{summary.estimate}
#' @param size Numeric. The size for the points.
#' @param color color of error bar
#' @param width width of error bar cap
#' @param ... currently ignored
#'
#' @return an object of class \code{ggplot}
#' @export
plot.summary.estimate <- function(x, color = "black",
                                  size = 2,
                                  width = 0, ...){

    dat_temp <- x$dat_results[order(x$dat_results$Post.mean,
                                         decreasing = F), ]

    dat_temp$Relation <-
      factor(dat_temp$Relation,
             levels = dat_temp$Relation,
             labels = dat_temp$Relation)


   if(isFALSE(x$object$analytic)){
    ggplot(dat_temp,
           aes(x = Relation,
               y = Post.mean)) +

      geom_errorbar(aes(ymax = dat_temp[, 4],
                        ymin = dat_temp[, 5]),
                    width = width,
                    color = color) +
      geom_point(size = size) +
      xlab("Index") +
      theme(axis.text.x = element_text(
        angle = 90,
        vjust = 0.5,
        hjust = 1
      ))
   } else {

     ggplot(dat_temp,
            aes(x = Relation,
                y = Post.mean)) +
       geom_point(size = size) +
       xlab("Index") +
       theme(axis.text.x = element_text(
         angle = 90,
         vjust = 0.5,
         hjust = 1
       ))
     }
}
