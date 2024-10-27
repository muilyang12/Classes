import statistics
import numpy as np

from typing import Literal


class DecisionTree:
    def __init__(
        self, maxDepth: int = 5, criterion: Literal["entropy", "gini"] = "entropy"
    ):
        self.maxDepth = maxDepth
        self.criterion = criterion
        self.tree = None

    def fit(self, XTrain, yTrain):
        self.tree = self.buildTree(XTrain, yTrain)

    def predict(self, XTest):
        result = [self._predict(XSample, self.tree) for XSample in XTest]

        return result

    def _predict(self, XSample, node):
        if not node.left and not node.right:
            return node.value

        if XSample[node.feature] <= node.threshold:
            return self._predict(XSample, node.left)
        else:
            return self._predict(XSample, node.right)

    def buildTree(self, XTrain, yTrain, depth=0):
        if len(yTrain) == 0:
            return None

        numLabels = len(np.unique(yTrain))

        if depth >= self.maxDepth or numLabels == 1:
            leafValue = statistics.mode(yTrain)

            return self.Node(value=leafValue)

        feature, threshold = self.findBestSplit(XTrain, yTrain)

        leftIndices, rightIndices = self.splitArray(XTrain[:, feature], threshold)

        leftXTrain, rightXTrain = XTrain[leftIndices], XTrain[rightIndices]
        leftYTrain, rightYTrain = yTrain[leftIndices], yTrain[rightIndices]

        left = self.buildTree(leftXTrain, leftYTrain, depth + 1)
        right = self.buildTree(rightXTrain, rightYTrain, depth + 1)

        return self.Node(
            left=left,
            right=right,
            feature=feature,
            threshold=threshold,
        )

    def findBestSplit(self, XTrain, yTrain):
        bestInfoGain = -1
        bestFeature = None
        bestThreshold = None
        _, numFeatures = XTrain.shape

        for feature in range(numFeatures):
            possibleThresholds = np.unique(XTrain[:, feature])
            for threshold in possibleThresholds:
                leftIndices, rightIndices = self.splitArray(
                    XTrain[:, feature], threshold
                )

                leftY, rightY = yTrain[leftIndices], yTrain[rightIndices]
                currentInfoGain = self.getInformationGain(yTrain, leftY, rightY)

                if currentInfoGain > bestInfoGain:
                    bestInfoGain = currentInfoGain
                    bestFeature = feature
                    bestThreshold = threshold

        return bestFeature, bestThreshold

    def splitArray(self, array, threshold):
        leftIndices = np.where(array <= threshold)
        rightIndices = np.where(array > threshold)

        return leftIndices[0], rightIndices[0]

    def getInformationGain(self, y, leftY, rightY):
        leftYRatio = len(leftY) / len(y)

        if self.criterion == "entropy":
            prev = self.getEntropy(y)
            new = leftYRatio * self.getEntropy(leftY) + (
                1 - leftYRatio
            ) * self.getEntropy(rightY)
        elif self.criterion == "gini":
            prev = self.getGiniCoefficient(y)
            new = leftYRatio * self.getGiniCoefficient(leftY) + (
                1 - leftYRatio
            ) * self.getGiniCoefficient(rightY)

        return prev - new

    def getEntropy(self, y):
        counts = np.bincount(y)
        ps = counts / len(y)

        return -np.sum([p * np.log2(p) for p in ps if p > 0])

    def getGiniCoefficient(self, y):
        counts = np.bincount(y)
        probabilities = counts / len(y)

        return 1 - np.sum([p**2 for p in probabilities])

    class Node:
        def __init__(
            self, left=None, right=None, feature=None, threshold=None, value=None
        ):
            self.left = left
            self.right = right

            self.value = value
            self.feature = feature
            self.threshold = threshold
