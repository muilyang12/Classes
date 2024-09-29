import numpy as np
from sklearn.datasets import make_blobs
import matplotlib.pyplot as plt

x, y = make_blobs(n_samples=50, centers=2, random_state=0, cluster_std=0.60)
y = np.where(y == 0, -1, 1)

nSamples, nFeatures = x.shape

w = np.zeros(nFeatures)
b = 0

lambdaParam = 0.01
learningRate = 0.01
epochs = 200

plt.ion()
fig, ax = plt.subplots()

ax.scatter(x[:, 0], x[:, 1], c=y, s=50, cmap="autumn")

ax.set_xlabel("Feature 1")
ax.set_ylabel("Feature 2")

ax.set_title("SVM")

plt.pause(3)

for epoch in range(epochs):
    for i in range(nSamples):
        condition = y[i] * (np.dot(x[i], w) + b)

        if condition < 1:
            dw = lambdaParam * w - y[i] * x[i]
            db = -y[i]

            w = w - learningRate * dw
            b = b - learningRate * db
        else:
            dw = lambdaParam * w

            w = w - learningRate * dw

    xPlotVals = np.linspace(min(x[:, 0]) - 1, max(x[:, 0]) + 1, 100)
    yPlotVals = -(w[0] * xPlotVals + b) / w[1]

    if epoch == epochs - 1:
        ax.plot(
            xPlotVals, yPlotVals, "b", linewidth=2, label=f"Epoch {epoch+1} (Final)"
        )
    elif epoch % 20 == 0:
        ax.plot(xPlotVals, yPlotVals, "k--", linewidth=1, alpha=0.5)
        plt.pause(0.5)

plt.ioff()
plt.show()
