runnersData <- read.csv("C:/Users/Yang/Desktop/Study/Classes/Statistical Methods for Data Science/roadrace.csv", header = TRUE)
fromMaineOrAwayTable <- table(runnersData$Maine)

fromMaineOrAwayTable

barplot(
    fromMaineOrAwayTable,
    main = "Number of Runners From Maine vs Away",
    xlab = "From Maine or Away",
    ylab = "Frequency"
)

# ==================================================

runnersFromMaine <- subset(runnersData, Maine == "Maine")
runnersAway <- subset(runnersData, Maine == "Away")

timeMin <- min(runnersData$Time..minutes.)
timeMax <- max(runnersData$Time..minutes.)

hist(
    runnersFromMaine$Time..minutes.,
    main = "Histogram of Times for Runners From Maine",
    xlab = "Time (minutes)",
    xlim = c(timeMin, timeMax)
)

hist(
    runnersAway$Time..minutes.,
    main = "Histogram of Times for Runners From Away",
    xlab = "Time (minutes)",
    xlim = c(timeMin, timeMax)
)

runnersFromMaineStats <- c(
    mean = mean(runnersFromMaine$Time..minutes.),
    sd = sd(runnersFromMaine$Time..minutes.),
    min = min(runnersFromMaine$Time..minutes.),
    max = max(runnersFromMaine$Time..minutes.),
    median = median(runnersFromMaine$Time..minutes.),
    IQR = IQR(runnersFromMaine$Time..minutes.)
)

runnersFromMaineStats

runnersAwayStats <- c(
    mean = mean(runnersAway$Time..minutes.),
    sd = sd(runnersAway$Time..minutes.),
    min = min(runnersAway$Time..minutes.),
    max = max(runnersAway$Time..minutes.),
    median = median(runnersAway$Time..minutes.),
    IQR = IQR(runnersAway$Time..minutes.)
)

runnersAwayStats

# ==================================================

runnersFromMaine <- subset(runnersData, Maine == "Maine")
runnersAway <- subset(runnersData, Maine == "Away")

boxplot(
    runnersFromMaine$Time..minutes.,
    runnersAway$Time..minutes.,
    names = c("Maine", "Away"),
    main = "Boxplots of Runners' Time by Origin",
    xlab = "Origin",
    ylab = "Time (minutes)",
    outline = FALSE
)

# ==================================================

runnersMale <- subset(runnersData, Sex == "M")
runnersFemale <- subset(runnersData, Sex == "F")

boxplot(
    runnersMale$Age,
    runnersFemale$Age,
    names = c("Male", "Female"),
    main = "Boxplots of Runners' Age by Gender",
    xlab = "Gender",
    ylab = "Age",
    outline = FALSE
)

runnersMaleStats <- c(
    mean = mean(runnersMale$Age),
    sd = sd(runnersMale$Age),
    min = min(runnersMale$Age),
    max = max(runnersMale$Age),
    median = median(runnersMale$Age),
    IQR = IQR(runnersMale$Age)
)

runnersMaleStats

runnersFemaleStats <- c(
    mean = mean(runnersFemale$Age),
    sd = sd(runnersFemale$Age),
    min = min(runnersFemale$Age),
    max = max(runnersFemale$Age),
    median = median(runnersFemale$Age),
    IQR = IQR(runnersFemale$Age)
)

runnersFemaleStats

# ==================================================

accidentsData <- read.csv("C:/Users/Yang/Desktop/Study/Classes/Statistical Methods for Data Science/motorcycle.csv", header = TRUE)

accidentsStats <- c(
    mean = mean(accidentsData$Fatal.Motorcycle.Accidents),
    sd = sd(accidentsData$Fatal.Motorcycle.Accidents),
    min = min(accidentsData$Fatal.Motorcycle.Accidents),
    max = max(accidentsData$Fatal.Motorcycle.Accidents),
    median = median(accidentsData$Fatal.Motorcycle.Accidents),
    IQR = IQR(accidentsData$Fatal.Motorcycle.Accidents)
)

accidentsStats

hist(
    runnersAway$Time..minutes.,
    main = "Histogram of Fatal Motorcycle Accidents",
    xlab = "Number of Accidents",
)

boxplot(
    accidentsData$Fatal.Motorcycle.Accidents,
    main = "Boxplot of Fatal Motorcycle Accidents",
    ylab = "Number of Accidents",
    outline = FALSE
)

q1 <- quantile(accidentsData$Fatal.Motorcycle.Accidents, 0.25)
q3 <- quantile(accidentsData$Fatal.Motorcycle.Accidents, 0.75)

lowerBoundary <- q1 - 1.5 * accidentsStats["IQR"]
upperBoundary <- q3 + 1.5 * accidentsStats["IQR"]

outlierRows <- accidentsData[
    accidentsData$Fatal.Motorcycle.Accidents < lowerBoundary |
    accidentsData$Fatal.Motorcycle.Accidents > upperBoundary
]

outlierRows$County
