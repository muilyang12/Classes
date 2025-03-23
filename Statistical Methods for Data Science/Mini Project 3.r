set.seed(1210)

simulateThetaHat <- function(n, theta) {
    samples <- runif(n, min = 0, max = theta)

    theta1Hat <- max(samples)
    theta2Hat <- 2 * mean(samples)

    return(list(theta1Hat = theta1Hat, theta2Hat = theta2Hat))
}

simulateMSE <- function(n, theta, N) {
    mseMLE <- 0
    mseMoM <- 0

    for (i in 1:N) {
        result <- simulateThetaHat(n, theta)

        mseMLE <- mseMLE + (result$theta1Hat - theta)^2
        mseMoM <- mseMoM + (result$theta2Hat - theta)^2
    }

    mseMLE <- mseMLE / N
    mseMoM <- mseMoM / N

    return(list(mseMLE = mseMLE, mseMoM = mseMoM))
}

simulate <- function(nValues, thetaValues, N) {
    result <- data.frame(
        n = numeric(),
        theta = numeric(),
        mseMLE = numeric(),
        mseMoM = numeric()
    )

    for (n in nValues) {
        for (theta in thetaValues) {
            currentResult <- simulateMSE(n, theta, N)

            newRow <- data.frame(
                n = n,
                theta = theta,
                mseMLE = currentResult$mseMLE,
                mseMoM = currentResult$mseMoM
            )

            result <- rbind(result, newRow)
        }
    }

    return(result)
}

nValues <- c(1, 2, 3, 5, 10, 30)
thetaValues <- c(1, 5, 50, 100)
N <- 1000

result <- simulate(nValues, thetaValues, N)
result
