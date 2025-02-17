f_T <- function(t) {
  0.2 * exp(-0.1 * t) - 0.2 * exp(-0.2 * t)
}

P_T_greater_15 <- integrate(f_T, lower = 15, upper = Inf)$value
P_T_greater_15

# ==================================================

simulate_T <- function(n) {
    XA <- rexp(n, rate = 0.1)
    XB <- rexp(n, rate = 0.1)
    T_vals <- pmax(XA, XB)
    
    return(T_vals)
}

n <- 1000
Ts <- simulate_T(n)

E_T <- mean(Ts)
E_T
P_T_greater_15 <- sum(Ts > 15) / length(Ts)
P_T_greater_15

# ==================================================

hist(Ts, probability = TRUE, xlim = c(0, 60), ylim=c(0, 0.06),
     main = "Histogram of T with Density",
     xlab = "T",
     col = "lightblue")

curve(0.2 * exp(-0.1 * x) - 0.2 * exp(-0.2 * x),
      from = 0, to = 60, add = TRUE, col = "red", lwd = 2)

# ==================================================

n <- 10000

x <- runif(n)
y <- runif(n)

is_inside_circle <- (x - 0.5)^2 + (y - 0.5)^2 <= 0.25
p <- sum(is_inside_circle) / length(is_inside_circle)

estimate_pi <- 4 * p
estimate_pi