import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

from SVM import SVM

XTrain, yTrain = make_blobs(n_samples=50, centers=2, random_state=0, cluster_std=0.60)
yTrain = np.where(yTrain == 0, -1, 1)

plt.ion()

fig, ax = plt.subplots()

ax.set_title("SVM")

ax.set_xlabel("Feature 1")
ax.set_ylabel("Feature 2")

ax.set_xlim(min(XTrain[:, 0]) - 0.25, max(XTrain[:, 0]) + 0.25)
ax.set_ylim(min(XTrain[:, 1]) - 0.25, max(XTrain[:, 1]) + 0.25)

ax.scatter(XTrain[:, 0], XTrain[:, 1], c=yTrain, s=50, cmap="autumn")

plt.pause(3)

xPlotVals = np.linspace(min(XTrain[:, 0]), max(XTrain[:, 0]), 100)


def plotDecisionBoundary(currentW, currentB, isLast):
    yPlotVals = -(currentW[0] * xPlotVals + currentB) / currentW[1]

    if isLast:
        ax.plot(xPlotVals, yPlotVals, "b", linewidth=2)
    else:
        ax.plot(xPlotVals, yPlotVals, "k--", linewidth=1, alpha=0.5)
        plt.pause(0.5)


svm = SVM(learningRate=0.01, lambdaParam=0.01, epochs=200)
svm.fit(XTrain, yTrain, callback=plotDecisionBoundary)

plt.ioff()
plt.show()
