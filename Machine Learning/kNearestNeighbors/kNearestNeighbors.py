import numpy as np
import heapq
import statistics


class KNN:
    def __init__(self, k=3):
        self.k = k

    def fit(self, XTrain, yTrain):
        self.XTrain = XTrain
        self.yTrain = yTrain

    def predict(self, XTest):
        predictions = []
        for x in XTest:
            predictions.append(self._predict(x))

        return predictions

    def _predict(self, x):
        distances = []
        for xTrainElem, yTrainElem in zip(self.XTrain, self.yTrain):
            heapq.heappush(
                distances, (self.getEuclideanDistance(x, xTrainElem), yTrainElem)
            )

        result = []

        for _ in range(self.k):
            __, yResult = heapq.heappop(distances)
            result.append(int(yResult))

        mostCommonY = statistics.mode(result)

        return mostCommonY

    def getEuclideanDistance(self, x1, x2):
        return np.sqrt(np.sum((x1 - x2) ** 2))
