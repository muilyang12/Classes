voltageData <- read.csv("C:/Users/Yang/Desktop/Study/Classes/Statistics for Data Science/VOLTAGE.csv", header = TRUE)

remoteData <- voltageData[voltageData$location == 0, ]$voltage
localData <- voltageData[voltageData$location == 1, ]$voltage

summary(remoteData)
summary(localData)

sd(remoteData)
sd(localData)

boxplot(remoteData, localData, names=c("Remote", "Local"), ylab = "Voltage")

xRange <- range(c(remoteData, localData))

remoteHist <- hist(remoteData, plot = FALSE, breaks = 10)
localHist  <- hist(localData, plot = FALSE, breaks = 10)
yMax <- max(c(remoteHist$counts, localHist$counts))

par(mfrow = c(1, 2))

hist(remoteData,
     main = "Remote", xlab = "Voltage",
     col = "#FFFF00", breaks = 10,
     xlim = xRange, ylim = c(0, yMax))

hist(localData,
     main = "Local", xlab = "Voltage",
     col = "#FF00FF", breaks = 10,
     xlim = xRange, ylim = c(0, yMax))

par(mfrow = c(1, 1))

# ==================================================

voltageData <- read.csv("C:/...../VOLTAGE.csv", header = TRUE)

remoteData <- voltageData[voltageData$location == 0, ]$voltage
localData <- voltageData[voltageData$location == 1, ]$voltage

fTest <- var.test(remoteData, localData)

fTest$p.value

tTest <- t.test(remoteData, localData, var.equal=fTest$p.value > 0.05, conf.level = 0.95)

tTest$p.value

tTest$conf.int

# ==================================================

vaporData <- read.csv("C:/...../VAPOR.csv", header = TRUE)

vaporData$difference <- vaporData$theoretical - vaporData$experimental

summary(vaporData$difference)

sd(vaporData$difference)

hist(vaporData$difference, main = "Difference Between Experimental and Theoretical Value", 
          xlab = "Difference", breaks = 10)

tTest <- t.test(vaporData$experimental, vaporData$theoretical, paired = TRUE, conf.level = 0.95)

tTest$p.value

tTest$conf.int
