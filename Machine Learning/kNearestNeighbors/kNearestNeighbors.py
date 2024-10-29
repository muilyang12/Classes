import numpy as np
import heapq
import statistics
from data import X_train, y_train, X_test, y_test

from sklearn import metrics


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


knn = KNN(7)
knn.fit(X_train, y_train)
yTrainPred = knn.predict(X_train)
yPred = knn.predict(X_test)

print("Train Accuracy:", metrics.accuracy_score(y_train, yTrainPred))
print("Accuracy:", metrics.accuracy_score(y_test, yPred))
