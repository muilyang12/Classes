from typing import Literal
import numpy as np


class DecisionTree:
    def __init__(
        self, maxDepth: int = 5, criterion: Literal["entropy", "gini"] = "entropy"
    ):
        self.maxDepth = maxDepth
        self.criterion = criterion
        self.tree = None

    def fit(self, XTrain, yTrain):
        pass

    def predict(self, XTest):
        pass

    def getInformationGain(self, y, leftY, rightY):
        leftYRatio = len(leftY) / len(y)

        if self.criterion == "entropy":
            prev = self.getEntropy(y)
            new = leftYRatio * self.getEntropy(leftY) + (
                1 - leftYRatio
            ) * self.getEntropy(rightY)
        elif self.criterion == "gini":
            prev = self.getEntropy(y)
            new = leftYRatio * self.getEntropy(leftY) + (
                1 - leftYRatio
            ) * self.getEntropy(rightY)

        return prev - new

    def getEntropy(self, y):
        counts = np.bincount(y)
        ps = counts / len(y)

        return -np.sum([p * np.log2(p) for p in ps])
