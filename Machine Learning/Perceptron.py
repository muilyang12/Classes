import numpy as np
from sklearn.datasets import make_blobs
import matplotlib.pyplot as plt

x, y = make_blobs(n_samples=50, centers=2, random_state=0, cluster_std=0.60)
y = np.where(y == 0, -1, 1)

nSamples, nFeatures = x.shape

w = np.zeros(nFeatures)
b = 0

learningRate = 0.001
epochs = 100

plt.ion()
fig, ax = plt.subplots()

ax.scatter(x[:, 0], x[:, 1], c=y, s=50, cmap="autumn")

ax.set_xlabel("Feature 1")
ax.set_ylabel("Feature 2")

ax.set_title("Perceptron")

plt.pause(3)

for epoch in range(epochs):
    for i in range(nSamples):
        if y[i] * (np.dot(x[i], w) + b) <= 0:
            dw = -(y[i] * x[i])
            db = -y[i]

            w = w - learningRate * dw
            b = b - learningRate * db

    x_boundary = np.linspace(min(x[:, 0]) - 1, max(x[:, 0]) + 1, 100)
    y_boundary = -(w[0] * x_boundary + b) / w[1]

    if epoch == epochs - 1:
        ax.plot(x_boundary, y_boundary, "b", linewidth=2)
    elif epoch % 20 == 0:
        ax.plot(x_boundary, y_boundary, "k--", linewidth=1, alpha=0.5)
        plt.pause(0.5)

plt.ioff()
plt.show()
