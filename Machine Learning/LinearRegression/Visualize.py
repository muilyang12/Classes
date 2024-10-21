import numpy as np
import matplotlib.pyplot as plt


class LinearRegressionVisualize:
    def __init__(self, x, y, title, xNames):
        x1Min = np.min(x[:, 0])
        x1Max = np.max(x[:, 0])
        x2Min = np.min(x[:, 1])
        x2Max = np.max(x[:, 1])
        x1Mean = np.mean(x[:, 0])
        x2Mean = np.mean(x[:, 1])

        self.x1UniformValues = np.linspace(x1Min, x1Max, 100)
        self.x2UniformValues = np.linspace(x2Min, x2Max, 100)
        x1MeanValues = np.full((100, 1), x1Mean)
        x2MeanValues = np.full((100, 1), x2Mean)

        self.x1Matrix = np.column_stack((self.x1UniformValues, x2MeanValues))
        self.x2Matrix = np.column_stack((x1MeanValues, self.x2UniformValues))

        plt.ion()

        fig, ax = plt.subplots(nrows=1, ncols=2)
        self.ax = ax

        ax[0].scatter(x[:, 0], y, color="blue", label="Actual Data")
        ax[1].scatter(x[:, 1], y, color="blue", label="Actual Data")

        fig.suptitle(title)

        ax[0].set_xlabel(xNames[0])
        ax[1].set_xlabel(xNames[1])

        plt.pause(3)

    def drawLine(self, w, b, isTempLine=False):
        yPlot1 = np.dot(self.x1Matrix, w) + b
        yPlot2 = np.dot(self.x2Matrix, w) + b

        if isTempLine:
            self.ax[0].plot(self.x1UniformValues, yPlot1, "r--", linewidth=2, alpha=0.5)
            self.ax[1].plot(self.x2UniformValues, yPlot2, "r--", linewidth=2, alpha=0.5)
        else:
            self.ax[0].plot(self.x1UniformValues, yPlot1, "red", linewidth=3.5)
            self.ax[1].plot(self.x2UniformValues, yPlot2, "red", linewidth=3.5)

        plt.pause(0.5)

    def updateDone(self):
        plt.ioff()
        plt.show()
