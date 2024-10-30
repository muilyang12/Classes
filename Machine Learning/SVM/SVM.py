import numpy as np
from sklearn.datasets import make_blobs
import matplotlib.pyplot as plt


class SVM:
    def __init__(self, learningRate=0.01, lambdaParam=0.01, epochs=200):
        self.w = None
        self.b = None

        self.learningRate = learningRate
        self.lambdaParam = lambdaParam
        self.epochs = epochs

    def fit(self, XTrain, yTrain, callback=None):
        nSamples, nFeatures = XTrain.shape

        self.w = np.zeros(nFeatures)
        self.b = 0

        yTransformed = np.where(yTrain <= 0, -1, 1)

        for epoch in range(self.epochs):
            for idx, xTrainI in enumerate(XTrain):
                condition = yTransformed[idx] * (np.dot(xTrainI, self.w) + self.b)

                if condition < 1:
                    dw = self.lambdaParam * self.w - yTransformed[idx] * xTrainI
                    db = -yTransformed[idx]
                else:
                    dw = self.lambdaParam * self.w
                    db = 0

                self.w -= self.learningRate * dw
                self.b -= self.learningRate * db

            if callback:
                if epoch == self.epochs - 1:
                    callback(currentW=self.w.copy(), currentB=self.b, isLast=True)
                elif epoch % 20 == 0:
                    callback(currentW=self.w.copy(), currentB=self.b, isLast=False)

    def predict(self, XTest):
        return np.sign(np.dot(XTest, self.w) + self.b)
