#' Compute Regression Parameters for \code{estimate} Objects
#'
#'  There is a direct correspondence between the inverse covariance matrix and
#'  multiple regression \insertCite{kwan2014regression,Stephens1998}{BGGM}. This readily allows
#'  for converting the GGM paramters to regression coefficients. All data types are supported.
#'
#'
#' @name coef.estimate
#'
#' @param object An Object of class \code{estimate}
#'
#' @param iter Number of iterations (posterior samples; defaults to the number in the object).
#'
#' @param ... Not currently used.
#'
#' @references
#' \insertAllCited{}
#'
#' @return An object of class \code{coef}, containting two lists.
#'
#'
#' \itemize{
#'
#' \item \code{betas} A list of length \emph{p}, each containing a \emph{p} - 1 by \code{iter} matrix of
#' posterior samples
#'
#' \item \code{object} An object of class \code{estimate} (the fitted model).
#' }
#'
#' @examples
#' \donttest{
#' # note: iter = 250 for demonstrative purposes
#'
#' #########################################
#' ### example 1: continuous and ordinal ###
#' #########################################
#' # data
#' Y <- ptsd
#'
#' # continuous
#'
#' # fit model
#' fit <- estimate(Y, type = "continuous")
#'
#' # regression
#' reg <- coef(fit)
#'
#' # summary(reg)
#'
#'
#' # ordinal
#'
#' # fit model (note + 1, due to zeros)
#' fit <- estimate(Y + 1, type = "ordinal")
#'
#' # summarize the partial correlations
#' reg <- coef(fit)
#'
#' # summary
#' summary(reg)
#'
#' #########################
#' ### example 2: binary ###
#' #########################
#' # data
#' Y <- women_math
#'
#' # fit model
#' fit <- estimate(Y, type = "binary")
#'
#' # summarize the partial correlations
#' reg <- coef(fit)
#'
#' # summary
#' summary(reg)
#'
#' ########################################
#' ### example 3: control  with formula ###
#' ########################################
#' # (the following works with all data types)
#'
#' # controlling for gender
#' Y <- bfi
#'
#' # Y contains two control variables
#' # (gender and education)
#'
#' # the following is incorrect, as education is
#' # automatically included in Y !
#'
#' incorrect <- estimate(Y, formula = ~ gender)
#'
#' # to control for only gender
#' # (remove education)
#'
#' Y <- subset(Y, select = - education)
#'
#'  # fit model
#' fit <- estimate(Y, formula = ~ gender,
#'                 iter = 250)
#'
#' # regression
#' reg <- coef(fit)
#'
#' # summary
#' summary(reg)
#'
#'
#' # control for an intercation (for some reason ?)
#' # (gender by education)
#'
#' # data
#' Y <- bfi
#'
#' # fit model
#' fit <- estimate(Y, formula = ~ gender * education,
#'                 iter = 250)
#'
#' # regression
#' reg <- coef(fit)
#'
#' # summary
#' summary(reg)
#'
#' ########################################
#' ### example 4: control  with "mixed" ###
#' ########################################
#' # control with mixed data approach
#' # (all variables included in Y)
#'
#' # data
#' Y <- bfi
#'
#' # fit model
#' fit <- estimate(Y, type = "mixed",
#'                 iter = 250)
#'
#' # regression
#' reg <- coef(fit)
#'
#' # summary
#' summary(reg)
#'
#' }
#' @export
coef.estimate <- function(object, iter = NULL,...) {

  # check for object class
  if(is(object, "estimate") | is(object, "explore")){

    # check for default
    if(!is(object, "default")){

      stop(paste0("\nclass not supported. must be an object\n",
                  "from either the 'explore' or 'estimate' functions"))
    }

    # nodes
    p <- object$p

    # all posterior samples
    if(is.null(iter)){

      iter <- object$iter

    }

    # pcor to cor
    cors <- pcor_to_cor(object, iter = iter)$R

    # betas

    pb <- utils::txtProgressBar(min = 0, max = p, style = 3)

    betas <- lapply(1:p, function(x) {

    beta_p <- .Call("_BGGM_beta_helper_fast",
                    XX = cors[-x, -x,],
                    Xy = cors[x, -x,],
                    p = p - 1,
                    iter = iter
                    )$coefs

    utils::setTxtProgressBar(pb, x)

    beta_p

    })

  } else {

    stop("class not currently supported")

  }

  # remove samples so
  # object does not become huge
  object$post_samp <- 0

  returned_object <- list(betas = betas, object = object)
  class(returned_object) <- c("BGGM", "coef")
  returned_object
}



#' Compute Regression Parameters for \code{explore} Objects
#'
#'  There is a direct correspondence between the inverse covariance matrix and
#'  multiple regression \insertCite{kwan2014regression,Stephens1998}{BGGM}. This readily allows
#'  for converting the GGM paramters to regression coefficients. All data types are supported.
#'
#' @name coef.explore
#'
#' @param object An Object of class \code{estimate}
#'
#' @param iter Number of iterations (posterior samples; defaults to the number in the object).
#'
#' @param ... Not currently used.
#'
#' @references
#' \insertAllCited{}
#'
#' @return An object of class \code{coef}, containting two lists.
#'
#' \itemize{
#'
#' \item \code{betas} A list of length \emph{p}, each containing a \emph{p} - 1 by \code{iter} matrix of
#' posterior samples
#'
#' \item \code{object} An object of class \code{explore} (the fitted model).
#' }
#'

#' @export
coef.explore <- function(object, iter = NULL,...) {

  # check for object class
  if(is(object, "estimate") | is(object, "explore")){

    # check for default
    if(!is(object, "default")){

      stop(paste0("\nclass not supported. must be an object\n",
                  "from either the 'explore' or 'estimate' functions"))
    }

    # nodes
    p <- object$p

    # all posterior samples
    if(is.null(iter)){

      iter <- object$iter

    }

    # pcor to cor
    cors <- pcor_to_cor(object, iter = iter)$R

    # betas

    pb <- utils::txtProgressBar(min = 0, max = p, style = 3)

    betas <- lapply(1:p, function(x) {

      beta_p <- .Call("_BGGM_beta_helper_fast",
                      XX = cors[-x, -x,],
                      Xy = cors[x, -x,],
                      p = p - 1,
                      iter = iter
      )$coefs

      utils::setTxtProgressBar(pb, x)

      beta_p

    })

  } else {

    stop("class not currently supported")

  }

  # remove samples so
  # object does not become huge
  object$post_samp <- 0

  returned_object <- list(betas = betas, object = object)
  class(returned_object) <- c("BGGM", "coef")
  returned_object
}



print_coef <- function(x,...){
  # nodes
  p <- length(x$betas)

  # column names
  cn <- colnames(x$object$Y)

  cat("BGGM: Bayesian Gaussian Graphical Models \n")
  cat("--- \n")
  cat("Type:", x$object$type, "\n")
  cat("Formula:", paste(as.character(x$object$formula), collapse = " "), "\n")
  cat("--- \n")
  cat("Call: \n")
  print(x$object$call)
  cat("--- \n")
  cat("Coefficients: \n \n")

  if(is.null(cn)) {

    cn <- 1:p

  }

  for (i in seq_len(p)) {
    # print outcome
    cat(paste0(cn[i], ": \n"))

    # coefs for node i
    coef_i <- data.frame(t(round(colMeans(x$betas[[i]]), 3)))

    # predictor names
    colnames(coef_i) <- cn[-i]

    # print coefs
    print(coef_i, row.names = FALSE)
    cat("\n")
  }
}



#' Summarize \code{coef} Objects
#'
#' @param object an object of class \code{coef}
#' @param cred credible interval width used for the decision rule
#' @param ... Currently ignored
#'
#' @return a list of length \emph{p} including the
#'         summaries for each multiple regression.
#' @export
#'
summary.coef <- function(object,
                         cred = 0.95,
                         ...){

  lb <- (1 - cred) / 2
  ub <- 1 - lb
  p <- object$object$p

  post_mean <- t(sapply(1:p, function(x)  apply(object$betas[[x]], MARGIN = 2, mean )))
  post_sd   <- t(sapply(1:p, function(x)  apply(object$betas[[x]], MARGIN = 2, sd)))
  post_lb   <- t(sapply(1:p, function(x)  apply(object$betas[[x]], MARGIN = 2, quantile, lb)))
  post_ub   <- t(sapply(1:p, function(x)  apply(object$betas[[x]], MARGIN = 2, quantile, ub)))

  res_i <- list()
  for(i in 1:p){
    res_i[[i]] <- round(data.frame(post_mean = post_mean[i,],
                                   post_sd = post_sd[i,],
                                   post_lb = post_lb[i,],
                                   post_ub  = post_ub[i,]), 3)

  }


  returned_object <- list(summaries = res_i,
                          object = object)

  class(returned_object) <- c("BGGM", "coef", "summary.coef")
  returned_object
}



print_summary_coef <- function(x,...){

  # node names
  cn <- colnames(x$object$object$Y)

  # nodes
  p <- ncol(x$object$object$Y)

  # check for column names
  if(is.null(cn)) {

    cn <- 1:p

  }
  cat("BGGM: Bayesian Gaussian Graphical Models \n")
  cat("--- \n")
  cat("Type:", x$object$object$type, "\n")
  cat("Formula:", paste(as.character(x$object$object$formula), collapse = " "), "\n")
  cat("--- \n")
  cat("Call: \n")
  print(x$object$object$call)
  cat("--- \n")
  cat("Coefficients: \n \n")

  for(i in seq_len(p)){
    cat(paste0( cn[i], ": \n"))
    summ_i <- x$summaries[[i]]
    colnames(summ_i) <- c("Post.mean", "Post.sd", "Cred.lb", "Cred.ub")
    print( cbind.data.frame(Node = cn[-i], summ_i), row.names = FALSE)
    cat("\n")
  }

}



